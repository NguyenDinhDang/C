#include <stdio.h>

int Min(int x[], int n){
	int min=x[0];
	for(int i=0; i<n;i++){
		if (min>x[i]) 
			min = x[i];
	} 
	return min;
}
// 5 6 4 3 8
int Max(int x[], int n){
	int max=x[0];
	for(int i=0; i<n;i++){
		if (max<x[i]) 
			max = x[i];
	} 
	return max;
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
	
	printf("Max = %d\n", Max(array, n));
	printf("Min = %d\n", Min(array, n));
}