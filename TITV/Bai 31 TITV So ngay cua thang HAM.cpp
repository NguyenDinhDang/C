#include <stdio.h>

// cho biết tháng đó có bao nhiêu ngày 
// tính xem ngày đó là ngày thứ bao nhiêu trong năm 
// tìm ngày trước ngày vừa nhập(ngày, tháng, năm)
// tìm ngày kế ngày vừa nhập
//(sử dụng hàm)
int ngay_cua_thang(int thang, int nam){
	switch(thang){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		case 2:
			return (nam%4==0 && nam%100!=0)?29:28;
			break;
		default:
			return -1;
	}
}

int ngay_bao_nhieu(int ngay, int thang, int nam){
	int ntn= 0;
	for( int i = 1; i<thang;i++){
		ntn= ntn+ ngay_cua_thang(thang, nam);
	}
	ntn = ntn +ngay;
	return ntn;
} 
void ngay_truoc_do(int ngay, int thang, int nam){
	if (ngay==1){
		if (thang==1){
			ngay=31;
			thang=12;
			nam--;
		}else{
			thang--;
			ngay = ngay_cua_thang(thang, nam);
		}
	else if (ngay)
}

void ngay_truoc_do(int ngay, int thang, int nam){
	if (ngay==30){
		if (thang==12){
			ngay=1;
			thang=1;
			nam++;
		}else{
			thang+=1;
			ngay = ngay_cua_thang(thang, nam);
		}
	
	} else {
		ngay--;
	}
	printf("Ngay truoc do %d/%d/%d", ngay, thang, nam);
}
int main() {
    int ngay, thang, nam;
    do {
        printf("Nhap ngay, thang, nam: ");
        scanf("%d%d%d", &ngay, &thang, &nam);
    } while (ngay<1 || ngay>31 || thang<1 || thang>12 || nam<1);

    printf("So ngay cua thang do la %d\n", ngay_cua_thang(thang, nam));
    
    printf("Ngay nay cach ngay do la %d\n", ngay_bao_nhieu(ngay, thang, nam));
    
    ngay_truoc_do( ngay, thang, nam);
    return 0;
}