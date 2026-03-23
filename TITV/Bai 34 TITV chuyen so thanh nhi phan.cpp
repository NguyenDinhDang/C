#include <stdio.h>

void printNhiPhan(int x){
	if(x==0) return;
	else {
		int r = x%2;
		printNhiPhan(x/2);
		printf("%d", r);
	}
}

int main(){
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	} while (n<0);
	printNhiPhan(n);
}