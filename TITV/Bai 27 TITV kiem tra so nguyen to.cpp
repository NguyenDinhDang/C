/*return FUNTION_NAME (parameter list) {
            //body of the funtion
}
*/
#include <stdio.h>
#include <math.h>

int kiem_tra_snt(int x){
	if (x<=1) 
		return 0;
	for (int i=2; i<=x-1; i++){
		if (x%i==0)
			return 0;
	}
	return 1;
}
int main(){
	// Nhap lieu
	int n;
	printf("Nhap vao n= ");
	scanf("%d", &n);
	
	//Goi ham
	int kt = kiem_tra_snt(n);
	//Xu li
	if (kt==0){
		printf("Khong phai so nguyen to");
	} else {
		printf("La so nguyen to");
	}
}
