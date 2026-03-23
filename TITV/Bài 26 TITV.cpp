#include <stdio.h>

int main(){
	int n;
	
	Nhap:
		printf("Nhap vao n=");
		scanf("%d", &n);
	if (n<=0) goto Nhap;
	
	printf("Day la so le\n");
	for(int i; i<=n; i++){
		if (i%2==0) continue;
		printf("%d\n", i);
	}
}