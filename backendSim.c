#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N_CUST 10000
#define WARMUP 1000

// Sinh số ngẫu nhiên theo phân phối Mũ (Exponential)
double exponential(double rate) {
    double u;
    do {
        u = (double)rand() / RAND_MAX;
    } while (u == 0 || u == 1);
    return -log(u) / rate;
}

// Sinh số ngẫu nhiên theo phân phối Đều (Uniform)
double uniform(double a, double b) {
    double u = (double)rand() / RAND_MAX;
    return a + u * (b - a);
}

// Hàm lõi mô phỏng hàng đợi với đầy đủ thông số
void simulate(const char* name, double lam, double mu, int c, char dist, FILE* file) {
    double* arrivals = (double*)malloc(N_CUST * sizeof(double));
    double* services = (double*)malloc(N_CUST * sizeof(double));
    double* servers = (double*)calloc(c, sizeof(double)); 
    
    // 1. Sinh thời gian đến và thời gian phục vụ
    arrivals[0] = exponential(lam);
    for(int i = 1; i < N_CUST; i++) {
        arrivals[i] = arrivals[i-1] + exponential(lam);
    }
    
    for(int i = 0; i < N_CUST; i++) {
        if(dist == 'M') services[i] = exponential(mu);
        else if(dist == 'G') services[i] = uniform(7.0, 9.0); 
    }
    
    // Các biến lưu trữ tổng để tính trung bình
    double total_Wq = 0, total_W = 0;
    double total_service_time = 0;
    double max_end_time = 0;
    
    // 2. Xử lý logic hàng đợi
    for(int i = 0; i < N_CUST; i++) {
        // Tìm quầy trống sớm nhất
        int min_idx = 0;
        for(int j = 1; j < c; j++) {
            if(servers[j] < servers[min_idx]) {
                min_idx = j;
            }
        }
        
        // Tính toán các mốc thời gian
        double start_time = (arrivals[i] > servers[min_idx]) ? arrivals[i] : servers[min_idx];
        double wq = start_time - arrivals[i]; // Wq: Thời gian chờ
        double w = wq + services[i];          // W: Thời gian trong hệ thống (chờ + phục vụ)
        
        // Cập nhật trạng thái quầy
        servers[min_idx] = start_time + services[i];
        
        // Tìm thời điểm kết thúc cuối cùng của toàn bộ mô phỏng
        if(servers[min_idx] > max_end_time) {
            max_end_time = servers[min_idx];
        }
        
        total_service_time += services[i];
        
        // Bỏ qua giai đoạn warm-up để số liệu ổn định
        if(i >= WARMUP) {
            total_Wq += wq;
            total_W += w;
        }
    }
    
    // 3. Tính toán các chỉ số trung bình
    int valid_cust = N_CUST - WARMUP;
    double avg_Wq = total_Wq / valid_cust;
    double avg_W = total_W / valid_cust;
    
    // Định luật Little
    double avg_Lq = lam * avg_Wq; 
    double avg_L = lam * avg_W;   
    
    // Hệ số sử dụng hệ thống (Tổng thời gian bận / Tổng thời gian hệ thống hoạt động)
    double rho = total_service_time / (c * max_end_time);
    
    // 4. In ra màn hình console định dạng đẹp
    printf("%-7s | Wq= %5.2f | W= %5.2f | Lq= %5.2f | L= %5.2f | Rho= %4.2f\n", 
           name, avg_Wq, avg_W, avg_Lq, avg_L, rho);
           
    // 5. Ghi vào file CSV (Cập nhật thêm cột)
    fprintf(file, "%s,%.2f,%.2f,%.2f,%.2f,%.2f\n", name, avg_Wq, avg_W, avg_Lq, avg_L, rho);
    
    // Giải phóng bộ nhớ
    free(arrivals);
    free(services);
    free(servers);
}

int main() {
    srand(time(NULL)); // Khởi tạo seed ngẫu nhiên
    
    FILE *f = fopen("results_full.csv", "w");
    if (f == NULL) return 1;
    
    // Cập nhật header cho file CSV
    fprintf(f, "Model,Wq,W,Lq,L,Rho\n"); 
    
    printf("BAT DAU CHAY MO PHONG (N = 10,000 khach)...\n");
    printf("-----------------------------------------------------------------------\n");
    printf("Mo hinh | Wq (phut) | W (phut)  | Lq (ng) | L (ng)  | Su dung (Rho)\n");
    printf("-----------------------------------------------------------------------\n");
    
    simulate("M/M/1", 0.1, 0.125, 1, 'M', f);
    simulate("M/G/1", 0.1, 0.125, 1, 'G', f);
    simulate("M/M/2", 0.1, 0.125, 2, 'M', f);
    simulate("M/G/2", 0.1, 0.125, 2, 'G', f);
    
    printf("-----------------------------------------------------------------------\n");
    
    fclose(f);
    return 0;
}