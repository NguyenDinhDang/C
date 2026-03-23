#include <stdio.h>

int main(){
	int a, b, uscln;
	printf("Nhap a: b: \n ");
	scanf("%d%d", &a, &b);
	
	if (a==0 || b==0){
		uscln = (a+b);
	} else {
		while (a!=b){
			if (a>b){ 
				a = a-b;
			} else {
				b= b-a;
			}
		}
		uscln = a;
	}
	printf("USCLN = %d", uscln);
}