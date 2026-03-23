#include <stdio.h>
void soNguyenTo(int n){
	int so_nguyen_to;
	for(int i = 2; i<=n; i++){
		so_nguyen_to =1;
		for(int j = 2;j*j<=i; j++){
			if(i%j==0){
				so_nguyen_to =0;
				break;
			} 
		}
		if(so_nguyen_to) printf("La so nguyen to");
		else printf("Khong phai la so nguyen to");
	}
}

void triangleStar(int n){
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			printf("*");
		}
		printf("\n");
	}
}

double tongPhanSo(int n){
	double tong = 0;
	for(int i=1; i<=n;i++){
		tong += 1.0/i;
	}
	return tong;
}


int main(){
	soNguyenTo(5);
	printf("\n");
	triangleStar(5);
	printf("\n");
	printf("%.4lf ", tongPhanSo(5));
}