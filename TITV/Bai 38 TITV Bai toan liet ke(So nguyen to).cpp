#include <stdio.h>
#include <math.h>
//Bai toan liet ke

int testConditional(int x){
	return (x%2==0 && x%3==0); 
}
int Mersense(int n){
	if(n<=1) return 0;
	for(int i =2; i<=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}
int main(){
	int n, array[100];
	do{
		scanf("%d", &n); // nhap so phan tu vao mang
	} while (n<1 || n>100);
	
	//Nhap vao phan tu vao mang 
	for(int i= 0; i<n;i++){
		scanf("%d", &array[i]);
	}
	printf("Cac so chan chia het cho 3: ");
	for(int i =0; i<n; i++){
		if(testConditional(array[i]))
			printf("%d ", array[i]);
	}
	printf("\nCac so nguyen to la: ");
	for(int i=0; i<n; i++){
			if(Mersense(array[i]))
				printf("%d ", array[i]);
	}
	return 0;
}