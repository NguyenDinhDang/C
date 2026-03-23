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

double averageSum(int arr[100][100], int m, int n){
	if(m<=0||n<=0) return 0;
	
	int sum =0;
	for(int i =0; i<m; i++){
		for(int j=0; j<n; j++){
			sum += arr[i][j];
		}
	}
	double averageSum = (double)sum/(m*n);
	
	return averageSum;
}

double averageDivisibleFor5(int arr[100][100], int m, int n){
	if(m<=0||n<=0) return 0;
	
	int sumDivisibleFor5 =0;
	int amountDivisibleFor5 = 0;
	
	for(int i =0; i<m; i++){
		for(int j=0; j<n; j++){
			if((arr[i][j]%5)==0){
				amountDivisibleFor5++;
				sumDivisibleFor5 += arr[i][j];
			}
		}
	}
	
	double averageSum = 0;
	if(amountDivisibleFor5>0) averageSum=(double)sumDivisibleFor5/amountDivisibleFor5;
	return averageSum;
}

int main(){
	
	inputMatrix(arr, &m, &n);
	outputMatrix(arr, m, n);
	printf("Average Sum = %.2f\n",averageSum(arr, m, n));
	printf("Average Sum Divisibe For 5 = %.2f",averageDivisibleFor5(arr, m, n));
	return 0;
}