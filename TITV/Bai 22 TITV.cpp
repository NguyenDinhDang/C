#include <stdio.h>

int main(){
	int n;
	int tong =0;
	printf("Nhap n: ");
	scanf("%d", &n);
	
	int i=0;
	while (i<=n){
		tong = tong + i;
		i++;
		printf("i = %d\n", i);
	}
	printf("\nTong = %d", tong);
}