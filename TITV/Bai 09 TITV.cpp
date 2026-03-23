#include <stdio.h>

int main(){
	int a, b, max, min;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	
	max = (a>b)?a:b;
	min = (a<b)?a:b;
	
	printf("MIN = %d\n", min);
	printf("MAX = %d\n", max);
}