#include <stdio.h>

int main(){
	int a, giai_thua;
	
	do{
		printf("Nhap vao a: ");
		scanf("%d", &a);
	} while (a<0);
	
	giai_thua=1;
	for (int i=1; i<=a; i++){
		giai_thua = giai_thua*i;
		printf("%d! = %d\n", i, giai_thua);
	}
}