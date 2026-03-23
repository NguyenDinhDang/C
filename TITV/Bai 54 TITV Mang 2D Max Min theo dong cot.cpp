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

int minRow(int arr[100][100], int m, int n, int row){
	int min= arr[row][0];
	for(int i=0; i<n; i++){
		if(min> arr[row][i]) min = arr[row][i];
	}
	return min;
}

int minCol(int arr[100][100], int m, int n, int col){
	int min= arr[0][col];
	for(int i=0; i<n; i++){
		if(min> arr[i][col]) min = arr[i][col];
	}
	return min;
}

int maxRow(int arr[100][100], int m, int n, int row){
	int max= arr[row][0];
	for(int i=0; i<n; i++){
		if(max< arr[row][i]) max = arr[row][i];
	}
	return max;
}
int maxCol(int arr[100][100], int m, int n, int col){
	int max= arr[0][col];
	for(int i=0; i<n; i++){
		if(max< arr[i][col]) max = arr[i][col];
	}
	return max;
}

int main(){
	inputMatrix(arr, &m, &n);
	outputMatrix(arr, m, n);
	printf("\nMin row = %d, Min collum = %d",minRow(arr, m, n, 1), minCol(arr, m, n, 1));
	printf("\nMax row = %d, Max collum = %d",maxRow(arr, m, n, 1), maxCol(arr, m, n, 1));
}
