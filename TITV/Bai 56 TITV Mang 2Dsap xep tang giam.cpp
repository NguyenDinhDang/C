#include <stdio.h>

int arr[100][100];
int m,n;

void outputMatrix(int arr[100][100], int m, int n){
	printf("Ma tran la:\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("[%d]",arr[i][j]);
		}
		printf("\n");
	}
}

void inputMatrix(int arr[100][100], int *m, int *n){
	do{
		printf("Nhap so hang va so cot: ");
		scanf("%d%d", m, n);
	}while(*m<=0 || *n<=0);

	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			printf("Arr[%d][%d] = ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void increaseSort(int arr[100][100], int m, int n){
	int k = m*n;
	for(int i=0; i<k-1; i++){
		for(int j=i+1; j<k;j++){
			if(arr[i/n][i%n]>arr[j/n][j%n]){
				swap(&arr[i/n][i%n], &arr[j/n][j%m]);
			}
		}
	}
}

void decreaseSort(int arr[100][100], int m, int n){
	int k = m*n;
	for(int i=0; i<k-1; i++){
		for(int j=i+1; j<k;j++){
			if(arr[i/n][i%n]<arr[j/n][j%n]){
				swap(&arr[i/n][i%n], &arr[j/n][j%m]);
			}
		}
	}
}

int main(){
	inputMatrix(arr, &m, &n);
	outputMatrix(arr, m, n);
	increaseSort(arr, m, n);
	printf("Ma tran da sap xep tang la:\n");
	outputMatrix(arr, m, n);
	decreaseSort(arr, m, n);
	printf("Ma tran da sap xep giam la:\n");
	outputMatrix(arr, m, n);
}
