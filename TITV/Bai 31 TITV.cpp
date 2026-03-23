#include <stdio.h>

void swap_thamtri(int a, int b){
	int temp =a;
	a=b;
	b=temp;
}
void swap_thamchieu(int &a, int &b){
	int temp =a;
	a=b;
	b=temp;
}
int main(){
	int a, b;
	printf("Nhap a, b: ");
	scanf("%d%d", &a, &b);
	
	printf("Gia tri ban dau a=%d, b=%d\n", a, b);
	swap_thamtri(a, b);
	printf("Gia tri 1 a=%d, b=%d\n", a, b);
	swap_thamchieu(a, b);
	printf("Gia tri 2 a=%d, b=%d\n", a, b);
}