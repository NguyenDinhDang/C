#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

/* ── Constants & Enums ── */
#define MAX_SERVERS 50

typedef enum {
    DIST_EXPONENTIAL = 1,
    DIST_LOGNORMAL   = 2
} DistributionType;

typedef enum {
    SYS_BANK = 1,       /* Single Queue, Multiple Servers */
    SYS_SUPERMARKET = 2 /* Multiple Queues (Random Choice) */
} SystemTopology;

typedef struct {
    DistributionType type;
    double param1;
    double param2;
} ServiceDistribution;

typedef struct {
    double mean_Wq;       
    double mean_W;        
    double mean_Lq;       
    double mean_L;        
    double rho;           
    double renege_rate;   
} SimResult;

/* ── Distribution samplers ── */
static double exponential_sample(double rate) {
    double u;
    do { u = (double)rand() / RAND_MAX; } while (u == 0.0 || u == 1.0);
    return -log(1.0 - u) / rate; 
}

static double lognormal_sample(double mu_log, double sigma_log) {
    double u1, u2, z;
    do { u1 = (double)rand() / RAND_MAX; } while (u1 == 0.0);
    u2 = (double)rand() / RAND_MAX;
    z = sqrt(-2.0 * log(u1)) * cos(2.0 * 3.14159265358979 * u2);
    return exp(mu_log + sigma_log * z);
}

static double draw_service_time(const ServiceDistribution *dist) {
    if (dist->type == DIST_LOGNORMAL)
        return lognormal_sample(dist->param1, dist->param2);
    return exponential_sample(dist->param1);
}

/* ── Main simulation engine ── */
static SimResult run_simulation(long num_customers, double max_patience,
                                double lambda, int num_servers,
                                const ServiceDistribution *svc,
                                SystemTopology topology, long warmup) {
    double server_free[MAX_SERVERS] = {0};
    double server_busy_time[MAX_SERVERS] = {0};
    
    double current_time = 0.0;
    double total_Wq_served = 0.0;
    double total_W_served  = 0.0;
    
    long count_served = 0;
    long count_renege = 0;
    long count_valid  = 0;

    for (long i = 0; i < num_customers; i++) {
        current_time += exponential_sample(lambda);
        int best = 0;

        if (topology == SYS_BANK) {
            for (int j = 1; j < num_servers; j++) {
                if (server_free[j] < server_free[best]) {
                    best = j;
                }
            }
        } else {
            best = rand() % num_servers;
        }

        double potential_wait = server_free[best] - current_time;
        if (potential_wait < 0.0) potential_wait = 0.0;

        if (i >= warmup) {
            count_valid++;
            if (potential_wait > max_patience) {
                count_renege++;
                continue; 
            }
        }

        double s = draw_service_time(svc);
        double start_service = current_time + potential_wait;
        server_free[best] = start_service + s;
        
        if (i >= warmup) {
            server_busy_time[best] += s;
            total_Wq_served += potential_wait;
            total_W_served  += (potential_wait + s);
            count_served++;
        }
    }

    SimResult result = {0};
    if (count_served > 0) {
        result.mean_Wq = total_Wq_served / count_served;
        result.mean_W  = total_W_served / count_served;
        
        double total_sim_time = current_time; 
        double lambda_eff = count_served / total_sim_time;
        
        result.mean_Lq = lambda_eff * result.mean_Wq;
        result.mean_L  = lambda_eff * result.mean_W;
        
        double sum_busy = 0;
        for(int j=0; j<num_servers; j++) sum_busy += server_busy_time[j];
        result.rho = sum_busy / (num_servers * total_sim_time);
    }
    
    if (count_valid > 0) {
        result.renege_rate = (double)count_renege / count_valid;
    }

    return result;
}

/* ── Interactive CLI ── */
int main(void) {
    srand((unsigned int)time(NULL));
    
    long num_customers, warmup;
    double max_patience, lambda;
    int num_servers;
    
    ServiceDistribution svc_exp;
    ServiceDistribution svc_lognorm;

    printf("=== HE THONG MO PHONG HANG DOI TOAN DIEN (MONTE CARLO) ===\n\n");

    printf("1. Nhap so luong khach hang can mo phong (VD: 10000): ");
    scanf("%ld", &num_customers);
    
    printf("2. Nhap so luong khach hang Warm-up (VD: 1000): ");
    scanf("%ld", &warmup);

    printf("3. Nhap thoi gian kien nhan toi da (phut, VD: 15): ");
    scanf("%lf", &max_patience);

    printf("4. Nhap so luong may chu/quay phuc vu cho he thong 'c' (VD: 3): ");
    scanf("%d", &num_servers);

    printf("5. Nhap toc do den trung binh cua khach (lambda - khach/phut, VD: 1.4): ");
    scanf("%lf", &lambda);

    printf("\n--- THIET LAP PHAN PHOI PHUC VU ---\n");
    
    // Thiet lap phan phoi M (Exponential)
    svc_exp.type = DIST_EXPONENTIAL;
    printf("[M] Nhap toc do phuc vu trung binh (mu - khach/phut, VD: 0.8): ");
    scanf("%lf", &svc_exp.param1);
    
    // Thiet lap phan phoi G (Log-Normal)
    svc_lognorm.type = DIST_LOGNORMAL;
    printf("\n[G] Nhap tham so cho Log-Normal:\n");
    printf("    -> Nhap mu_log (VD: 0.5): ");
    scanf("%lf", &svc_lognorm.param1);
    printf("    -> Nhap sigma_log (VD: 0.2): ");
    scanf("%lf", &svc_lognorm.param2);

    printf("\n[~] Dang tinh toan luu luong va mo phong he thong...\n");
    
    // LUỒNG 1: MÔ PHỎNG HỆ THỐNG NGÂN HÀNG (SYS_BANK - 1 Hàng đợi chung)
    SimResult r_bank_mm1 = run_simulation(num_customers, max_patience, lambda, 1, &svc_exp, SYS_BANK, warmup);
    SimResult r_bank_mg1 = run_simulation(num_customers, max_patience, lambda, 1, &svc_lognorm, SYS_BANK, warmup);
    SimResult r_bank_mmc = run_simulation(num_customers, max_patience, lambda, num_servers, &svc_exp, SYS_BANK, warmup);
    SimResult r_bank_mgc = run_simulation(num_customers, max_patience, lambda, num_servers, &svc_lognorm, SYS_BANK, warmup);

    // LUỒNG 2: MÔ PHỎNG HỆ THỐNG SIÊU THỊ (SYS_SUPERMARKET - Nhiều hàng đợi độc lập)
    SimResult r_super_mm1 = run_simulation(num_customers, max_patience, lambda, 1, &svc_exp, SYS_SUPERMARKET, warmup);
    SimResult r_super_mg1 = run_simulation(num_customers, max_patience, lambda, 1, &svc_lognorm, SYS_SUPERMARKET, warmup);
    SimResult r_super_mmc = run_simulation(num_customers, max_patience, lambda, num_servers, &svc_exp, SYS_SUPERMARKET, warmup);
    SimResult r_super_mgc = run_simulation(num_customers, max_patience, lambda, num_servers, &svc_lognorm, SYS_SUPERMARKET, warmup);


    /* --- BÁO CÁO PHẦN I: NGÂN HÀNG --- */
    printf("\n==================================== PHAN I: MO HINH NGAN HANG (SINGLE QUEUE) ====================================\n");
    printf("%-23s | %-18s | %-18s | %-18s | %-18s\n", "Chi so", "M/M/1 (Bank)", "M/G/1 (Bank)", "M/M/c (Bank)", "M/G/c (Bank)");
    printf("------------------------|--------------------|--------------------|--------------------|--------------------\n");
    printf("%-23s | %-18d | %-18d | %-18d | %-18d\n", "So luong Server (c)", 1, 1, num_servers, num_servers);
    printf("%-23s | %6.2f %%           | %6.2f %%           | %6.2f %%           | %6.2f %%\n", "Khach bo cuoc (Renege)", r_bank_mm1.renege_rate * 100, r_bank_mg1.renege_rate * 100, r_bank_mmc.renege_rate * 100, r_bank_mgc.renege_rate * 100);
    printf("%-23s | %6.2f %%           | %6.2f %%           | %6.2f %%           | %6.2f %%\n", "Hieu suat may chu(Rho)", r_bank_mm1.rho * 100, r_bank_mg1.rho * 100, r_bank_mmc.rho * 100, r_bank_mgc.rho * 100);
    printf("%-23s | %6.3f phut        | %6.3f phut        | %6.3f phut        | %6.3f phut\n", "Wq (Thoi gian cho TB)", r_bank_mm1.mean_Wq, r_bank_mg1.mean_Wq, r_bank_mmc.mean_Wq, r_bank_mgc.mean_Wq);
    printf("%-23s | %6.3f phut        | %6.3f phut        | %6.3f phut        | %6.3f phut\n", "W  (TG trong he thong)", r_bank_mm1.mean_W, r_bank_mg1.mean_W, r_bank_mmc.mean_W, r_bank_mgc.mean_W);
    printf("%-23s | %6.3f khach       | %6.3f khach       | %6.3f khach       | %6.3f khach\n", "Lq (Do dai hang doi TB)", r_bank_mm1.mean_Lq, r_bank_mg1.mean_Lq, r_bank_mmc.mean_Lq, r_bank_mgc.mean_Lq);
    printf("%-23s | %6.3f khach       | %6.3f khach       | %6.3f khach       | %6.3f khach\n", "L  (So khach trong HT)", r_bank_mm1.mean_L, r_bank_mg1.mean_L, r_bank_mmc.mean_L, r_bank_mgc.mean_L);
    printf("=========================================================================================================\n");

    /* --- BÁO CÁO PHẦN II: SIÊU THỊ --- */
    printf("\n==================================== PHAN II: MO HINH SIEU THI (MULTIPLE QUEUES) ====================================\n");
    printf("%-23s | %-18s | %-18s | %-18s | %-18s\n", "Chi so", "M/M/1 (Super)", "M/G/1 (Super)", "M/M/c (Super)", "M/G/c (Super)");
    printf("------------------------|--------------------|--------------------|--------------------|--------------------\n");
    printf("%-23s | %-18d | %-18d | %-18d | %-18d\n", "So luong Server (c)", 1, 1, num_servers, num_servers);
    printf("%-23s | %6.2f %%           | %6.2f %%           | %6.2f %%           | %6.2f %%\n", "Khach bo cuoc (Renege)", r_super_mm1.renege_rate * 100, r_super_mg1.renege_rate * 100, r_super_mmc.renege_rate * 100, r_super_mgc.renege_rate * 100);
    printf("%-23s | %6.2f %%           | %6.2f %%           | %6.2f %%           | %6.2f %%\n", "Hieu suat may chu(Rho)", r_super_mm1.rho * 100, r_super_mg1.rho * 100, r_super_mmc.rho * 100, r_super_mgc.rho * 100);
    printf("%-23s | %6.3f phut        | %6.3f phut        | %6.3f phut        | %6.3f phut\n", "Wq (Thoi gian cho TB)", r_super_mm1.mean_Wq, r_super_mg1.mean_Wq, r_super_mmc.mean_Wq, r_super_mgc.mean_Wq);
    printf("%-23s | %6.3f phut        | %6.3f phut        | %6.3f phut        | %6.3f phut\n", "W  (TG trong he thong)", r_super_mm1.mean_W, r_super_mg1.mean_W, r_super_mmc.mean_W, r_super_mgc.mean_W);
    printf("%-23s | %6.3f khach       | %6.3f khach       | %6.3f khach       | %6.3f khach\n", "Lq (Do dai hang doi TB)", r_super_mm1.mean_Lq, r_super_mg1.mean_Lq, r_super_mmc.mean_Lq, r_super_mgc.mean_Lq);
    printf("%-23s | %6.3f khach       | %6.3f khach       | %6.3f khach       | %6.3f khach\n", "L  (So khach trong HT)", r_super_mm1.mean_L, r_super_mg1.mean_L, r_super_mmc.mean_L, r_super_mgc.mean_L);
    printf("=========================================================================================================\n");

    return 0;
}