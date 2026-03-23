#include <stdio.h>

int giaithua(int n){
	if (n==0||n==1) return 1;
	if(n!=1) return n * giaithua(n-1);
}

int main(){
	int n, GiaiThua;
	do{
		printf("Nhap n:");
		scanf("%d", &n);
		
	} while (n<0);
	
	GiaiThua = giaithua(n);
	printf("%d! = %d", n, GiaiThua);
}