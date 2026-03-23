#include <stdio.h>

int main(){
	/*
	int i;
	for(i=0;i<=9 ;i++ ){
		printf("\n%d",i);
	}
	*/
	
	int n;
	printf("Nhap n:\n");
	scanf("%d", &n);
	for (int i=0; i<=n; i++){
		printf("%d", i);
	}
}