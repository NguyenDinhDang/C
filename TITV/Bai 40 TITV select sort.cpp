#include <stdio.h>

void sapxeptang(int x[], int n){
	for(int i=0; i<n-1; i++){
		int indexMin = i;
		for(int j=i+1; j<n; j++){
			if(x[j]<x[indexMin]) 
				indexMin = j;                    // 5 4 3 7 
		}				
							
		int temp = x[i];
		x[i] = x[indexMin];
		x[indexMin] = temp;
		
		for(int k=0; k<n; k++){
			printf("%d ", x[k]);
		}
		printf("\n");
	}
}

void sapxepgiam(int x[], int n){
	for(int i=0; i<n-1; i++){
		int indexMax = i;
		for(int j=i+1; j<n; j++){
			if(x[j]>x[indexMax]) 
				indexMax = j;                    // 5 4 3 7 
		}				
							
		int temp = x[i];
		x[i] = x[indexMax];
		x[indexMax] = temp;
		
		for(int k=0; k<n; k++){
			printf("%d ", x[k]);
		}
		printf("\n");
	}
}

void printArray(int x[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", x[i]);
	}
	printf("\n");
}

int main(){
	int array[100], n;
	do{
		printf("Nhap vao so luong phan tu:");
		scanf("%d", &n);
	} while(n>=100 || n<0);
	
	for(int i=0; i<n;i++){
		printf("Array[%d] = ",i);
		scanf("%d", &array[i]);

	}
	sapxeptang(array, n);
	printf("Mang tang dan: ");
	printArray(array, n);
	
	sapxepgiam(array, n);
	printf("Mang giam dan: ");
	printArray(array, n);
	
}