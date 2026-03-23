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

void change2Row(int arr[100][100], int m, int n, int row1, int row2){
	for(int i=0; i<n; i++){
		int temp= arr[row1][i];	
		arr[row1][i]=arr[row2][i];
		arr[row2][i]=temp;
	}
}

void change2Col(int arr[100][100], int m, int n, int col1, int col2){
	for(int i=0; i<m; i++){
		int temp= arr[i][col1];	
		arr[i][col1]=arr[i][col2];
		arr[i][col2]=temp;
	}
}

int main(){
	inputMatrix(arr, &m, &n);
	outputMatrix(arr, m, n);
	change2Row(arr, m, n, 1, 2);
	outputMatrix(arr, m, n);
	change2Col(arr, m, n, 1, 2);
	outputMatrix(arr, m, n);
}