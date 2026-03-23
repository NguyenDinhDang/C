#include <stdio.h>

int arr[100][100];
int array[10000];
int m,n, k;

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

void convert2Dto1D(int arr[100][100], int m, int n, int array[10000], int &k){
	int index = 0;
	k = m*n;
	for(int i =0; i<m;i++){
		for(int j=0; j<n; j++){
			array[index] = arr[i][j];
			index++;
		}
	}
}

void outputArray1D(int array[10000], int n){
	printf("\nMang mot chieu:");
	for(int i=0; i<n; i++){
		printf("%d ", array[i]);
	}
	
}

int main(){
	inputMatrix(arr, &m, &n);
	outputMatrix(arr, m, n);
	convert2Dto1D(arr, m, n, array, k);
	outputArray1D(array, k);
}
