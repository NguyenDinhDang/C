#include <stdio.h>

int main(){
	int a = 5;
	int b = 5;
	
	printf("%d \n", a++); // tăng giá trị của a sau khi thực hiện câu lệnh 
	printf("%d \n", a);   // đây là giá trị của a sau khi tăng
	printf("%d \n", ++a); // Tăng giá trị của a ngay khi thực hiện câu lệnh 
	
	printf("%d \n", a++); 
	printf("%d \n", a);   
	printf("%d \n", ++a);
}