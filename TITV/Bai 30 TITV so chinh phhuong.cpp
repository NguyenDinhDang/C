#include <stdio.h>
#include <math.h>

// so chinh phuong la so co the khai can 

int kiem_tra_so_chinh_phuong(int x){
	int khai_can = (int)sqrt(x);
	if (pow(khai_can, 2)==x) return 1;
	else  // trả về 1 nếu là số chính phương, 0 là không 
	return 0;
}

int main(){
	int n;
	do {
		printf("Nhap n=");
		scanf("%d", &n);
	} while (n<1);
	
	for (int i=2; i<n; i++){ 
		//int kt = kiem_tra_so_nguyen_to(i);
		if (kiem_tra_so_chinh_phuong(i)){
			printf("%d ", i);
		}
	}
	return 0;
}