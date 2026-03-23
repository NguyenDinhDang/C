#include <stdio.h>

//năm nhuận là năm chia hết cho 400 hoặc chia hết cho 4 mà không chua hết cho 100 

int main(){
	int nam, thang;
	printf("Nhap vao nam: ");
	scanf("%d", &nam);
	printf("Nhap vao thang: ");
	scanf("%d", &thang);
	
	switch(thang){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("Co 31 ngay");
			break;
		
		case 4:
		case 6:
		case 9:
		case 11:
			printf("Co 31 ngay");
			break;
		case 2:
			if ((nam%400==0) || (nam%4==0 && nam%100 != 0)){
				printf("Nam nay la nam nhuan\n");
				printf("Thang nay co 29 ngay");
			} else{
				printf("Thang nay co 28 ngay");
				
			}
			break;
		default:
			printf("Ban nhap du lieu khong dung");
	}
}