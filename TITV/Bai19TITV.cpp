#include <stdio.h>
#include <math.h>

/*
kiem tra co tao thanh tam giac khong
kiem tra co phai tam giac can khong 
tinh va xuat ra chu vi 
tinh va xuat ra dien tich
*/
//tam giac
void nhap_he_so(float *xA, float *yA, float *xB, float *yB, float *xC, float *yC);
void tinh_canh(float xA, float yA, float xB, float yB, float xC, float yC, float *AB, float *AC, float *BC);
void kiem_tra_tam_giac(float AB, float AC, float BC);
float tinh_chu_vi(float AB, float AC, float BC);
float tinh_dien_tich(float AB, float AC, float BC);
void in_ket_qua(float AB, float AC, float BC, float chu_vi, float dien_tich);

// ax+b=0
void nhap_du_lieu(float *a, float *b);
void xet_truong_hop(float a, float b);
void tra_ve_du_lieu(float a, float b, float x);

// ax^2 + bx + c = 0
void nhap_lieu(float *a, float *b, float *c);
float tinh_toan(float a, float b, float c);
 
int main() {
	int chon;
	printf("   |--------------Menu---------------|\n");
	printf("   |Nhap lua chon tinh:              |\n");
	printf("   |Nhap 1: xet tam giac             |\n");
	printf("   |Nhap 2: tinh ax+b=0              |\n");
	printf("   |Nhap 3: la tinh ax^2 + bx +c =0  |\n");
	printf("   |Nhap so 0 de ket thuc            |\n");
	printf("   |---------------------------------|\n");
	printf("Chon : ");
	scanf("%d", &chon);
	switch(chon){
		case 1:			
		    float xA, yA, xB, yB, xC, yC;
		    float AB, AC, BC;
		    float chu_vi, dien_tich;
		
		    nhap_he_so(&xA, &yA, &xB, &yB, &xC, &yC);
		
		    tinh_canh(xA, yA, xB, yB, xC, yC, &AB, &AC, &BC);
		
		    kiem_tra_tam_giac(AB, AC, BC);
		
		    dien_tich = tinh_dien_tich(AB, AC, BC);
		
		    in_ket_qua(AB, AC, BC, chu_vi, dien_tich);
		    break;
		case 2:{
			
			float a, b;
			nhap_du_lieu(&a, &b);
			xet_truong_hop(a, b);
		}
			break;
		case 3: {
			
			float a, b, c;
			nhap_lieu(&a, &b, &c);
			tinh_toan(a, b, c);
		}
			break;
		default:
			printf("Nhap sai lua chon");
	}	

    return 0;
}
//ham nhap
void nhap_he_so(float *xA, float *yA, float *xB, float *yB, float *xC, float *yC) {
	printf("Nhap xA: ");scanf("%f", xA);
	printf("Nhap yA: ");scanf("%f", yA);
		
	printf("Nhap xB: ");scanf("%f", xB);
	printf("Nhap yB: ");scanf("%f", yB);	
	
	printf("Nhap xC: ");scanf("%f", xC);
	printf("Nhap yC: ");scanf("%f", yC);
}
// tinh toan so lieu
void tinh_canh(float xA, float yA, float xB, float yB, float xC, float yC, float *AB, float *AC, float *BC){
	*AB = sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));
    *AC = sqrt(pow(xC - xA, 2) + pow(yC - yA, 2));
    *BC = sqrt(pow(xC - xB, 2) + pow(yC - yB, 2));
}
void kiem_tra_tam_giac(float AB, float AC, float BC){
	float radA = acos((AC*AC + AB*AB - BC*BC)/(2*AC*AB));
	float radB = acos((BC*BC + AB*AB - AC*AC)/(2*AB*BC));
	float radC = acos((AC*AC + BC*BC - AB*AB)/(2*AC*BC));
	
	float degA = (radA * 180.0) / M_PI;
	float degB = (radB * 180.0) / M_PI;
	float degC = (radC * 180.0) / M_PI;

	if (AB+AC>BC && AC+BC>AB && BC+AB>AC){
		printf("Day la tam giac\n");
		
		if (AB==AC && AC==BC){
			printf("Day la tam giac deu\n");
		} else if ((ceil(degA)==90 && AB==AC || ceil(degB)==90 && BC==AB || ceil(degC)==90 && AC==BC )){
			printf("Day la tam giac vuong can\n");
		} else if (AB==AC || AB==BC || AC==BC){
			printf("Day la tam giac can\n");
		} else if (ceil(degA)==90 || ceil(degB)==90 || (degC)==90){
			printf("Day la tam giac vuong\n");
		}
	} else {
		printf("Day khong phai tam giac\n");
	}
}
float tinh_chu_vi(float AB, float AC, float BC){
	return AB + AC + BC;
}
float tinh_dien_tich(float AB, float AC, float BC){
	float p = (AB+AC+BC)/2.0;
	return sqrt(p*(p-AB)*(p-AC)*(p-BC));
}
void in_ket_qua(float AB, float AC, float BC, float chu_vi, float dien_tich){
	printf("Do dai AB: %.2f\n", AB);
    chu_vi = tinh_chu_vi(AB, AC, BC);
	printf("Do dai AC: %.2f\n", AC);
	printf("Do dai BC: %.2f\n", BC);
	printf("Chu vi: %.2f\n", chu_vi);
	printf("Dien tich: %.2f\n", dien_tich);
}

//ax+b=0
void nhap_du_lieu(float *a, float *b){
	printf("Nhap a: ");
	scanf("%f", a);
	printf("Nhap b: ");
	scanf("%f", b);
}
void xet_truong_hop(float a, float b){
	if (a==0) {
		printf("ERROR!");
	} else {
		if (b==0){
			printf("x = 0");
		} else {
			printf("x = -%.2f/%.2f = %.2f", a, b, -b/a);
		}
	}
}
void nhap_lieu(float *a, float *b, float *c){
	printf("Nhap a: "); scanf("%f", a);
	printf("Nhap b: "); scanf("%f", b);
	printf("Nhap c: "); scanf("%f", c);
}
float tinh_toan( float a, float b, float c){
	float delta = pow(b, 2) - 4 * a * c;
	if (delta <0){
		printf("Phuong trinh vo nghiem");
	} else if (delta == 0){
		printf("x1 = x2 = %.1f", -b/2*a );
	} else {
		float x1 = (-b+sqrt(delta))/2*a;
		float x2 = (-b-sqrt(delta))/2*a;
		printf("Phuong trinh co nghiem x1 = %.3f, x2 = %.3f", x1, x2);
	}
}