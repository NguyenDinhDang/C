#include <stdio.h>

int main(){
	int n;
	printf("Nhap vao so n: ");
	scanf("%d", &n);
	
	switch(n){
		case 1:
			printf("\n Chu nhat");
			break;
		case 2:
			printf("\n Thu hai");
		    break;
		case 3:
			printf("\n Thu ba");
			break; 
		case 4:
			printf("\n Thu tu");
		    break;
		case 5:
			printf("\n Thu nam");
			break; 
		case 6:
			printf("\n Thu sau");
		    break;
		case 7:
			printf("\n Thu bay");
			break; 
		default:
			printf("Nhap vao n khong dung");
	}	
}