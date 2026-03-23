#include <stdio.h>
#include <math.h>
//tìm tất cả các số nhỏ hơn n 
int kiem_tra_so_nguyen_to(int x){
	if(x<=1) return 0;
	for (int j=2; j<=sqrt(x); j++){
		if (x%j==0) return 0;
	} // trả về 1 nếu là số nguyên tố, 0 là không 
	return 1;
}

int main(){
	int n;
	do {
		printf("Nhap n=");
		scanf("%d", &n);
	} while (n<1);
	
	for (int i=2; i<n; i++){ 
		//int kt = kiem_tra_so_nguyen_to(i);
		if (kiem_tra_so_nguyen_to(i)){
			printf("%d ", i);
		}
	}
	return 0;
}