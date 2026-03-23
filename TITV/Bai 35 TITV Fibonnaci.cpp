#include <stdio.h>
int Fibonnaci(int x){       //x=10 
	if (x==0 || x==1 || x==2) return 1;
	else {
		return Fibonnaci(x-1) + Fibonnaci(x-2);
		
	}
}
int main(){
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	} while (n<0);
	Fibonnaci(n);
	printf("Fibonnaci(%d) = %d\n", n, Fibonnaci(n) );
}