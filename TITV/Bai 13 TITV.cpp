#include <stdio.h>

int main(){
	// nhap vao gio, xuat ra sang hay toi 
	/* 1h->11h sáng
	   12h -> 18h chiều 
	   19h -> 24h tối */
	int n;
	printf("Nhap vao gio: ");
	scanf("%d", &n);
	if (n>0){
		if (n>=1 && n<=11) {
			printf("Good moring");
		} else if (n>=12 && n<=18) {
			printf("Good afternoon");
		} else{
			printf("Good night");
		}
	} else if (n>24){
		printf(" ERROR ");	
	}
}