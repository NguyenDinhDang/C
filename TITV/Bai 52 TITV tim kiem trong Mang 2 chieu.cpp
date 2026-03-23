#include <stdio.h>

int arr[100][100];
int m,n;

void xuatMaTran(int arr[100][100], int m, int n){
	printf("Ma tran la:\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("[%d]",arr[i][j]);
		}
		printf("\n");
	}
}

void nhapMaTran(int arr[100][100], int *m, int *n){
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

int findKey(int arr[100][100], int m, int n, int key){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==key){
				return 1;
			}
		}
	}
	return 0;
}

void findFuntion(int arr[100][100], int m, int n){
	int choose;
	do{
		int key;
		printf("Nhap key can tim: ");
		scanf("%d",&key);

		if(findKey(arr,m,n,key)){
			printf("Key co trong ma tran");
		}
		else{
			printf("Khong tim thay key");
		}

		printf("\nNhap so bat ki de tiep tuc, 0 de thoat: ");
		scanf("%d",&choose);

	}while(choose!=0);
}

int main(){

	nhapMaTran(arr,&m,&n);
	xuatMaTran(arr,m,n);
	findFuntion(arr,m,n);

	return 0;
}