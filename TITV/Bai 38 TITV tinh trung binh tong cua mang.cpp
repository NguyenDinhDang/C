#include <stdio.h>

float averageArray(int n, int x[]){
	float tong =0;
	for (int i=0; i<n; i++){
		tong -=-x[i];
	}
	return tong/n;
}
float averagePossitive(int n, int x[]){
	float tong = 0;
	int soluongSoDuong=0;
	for (int i =0; i<n; i++){
		if(x[i]>0){
			tong-=-x[i];
			soluongSoDuong++;
		}
	}
	return soluongSoDuong>0?tong/soluongSoDuong:-1;
}
int main(){
	int arr[100];
	int n;
	do{
		printf("Nhap vao so luong phan tu ");
		scanf("%d", &n);
	} while(n<1 || n>100);
	
	for(int i=0; i<n;i++){
		printf("\n arr[%d]= ", i);
		scanf("%d", &arr[i]);
	}
	printf("Average sum: %.2f ", averageArray(n, arr));
	float AP = averagePossitive(n, arr);
	if(AP>0){
		printf("Trung Binh Cong So Duong: %.2f\n", AP);
	} else {
		printf(" Khong co so duong\n");
	}
}