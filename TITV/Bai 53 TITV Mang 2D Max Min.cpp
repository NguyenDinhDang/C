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

int findMax(int arr[100][100], int m, int n){
	int max = arr[0][0];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(max<arr[i][j]) max = arr[i][j];
		}
	}
	return max;
}
int findMin(int arr[100][100], int m, int n){
	int min = arr[0][0];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(min>arr[i][j]) min = arr[i][j];
		}
	}
	return min;
}
int main(){
	
	inputMatrix(arr, &m, &n);
	outputMatrix(arr, m, n);
	printf("Max = %d\n",findMax(arr, m, n));
	printf("Min = %d",findMin(arr, m, n));
	return 0;
}