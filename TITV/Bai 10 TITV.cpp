#include <stdio.h>
#include <math.h>


int main(){
	
	float a, b, x;
	
	printf("Phuong trinh ax + b = 0\n");
	printf("Nhap a: "); scanf("%f", &a);
	printf("Nhap b: "); scanf("%f", &b);
	
	x = (-b) / a;
	printf("Nghiem phuong trinh x = %.2f", x);
}