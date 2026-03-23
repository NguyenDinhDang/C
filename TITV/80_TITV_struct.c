#include <stdio.h>
//g++ "80_TITV_struct.c" -o main; ./main 
struct Date{
    int day;
    int month;
    int year;
};

void inputDate(struct Date &d)
{
    printf("Nhap vao ngay:");
    scanf("%d", &d.day);
    printf("\nNhap vao thang:");
    scanf("%d", &d.month);
    printf("\nNhap vao nam:");
    scanf("%d", &d.year);
};

void printDate(struct Date d){
    printf("%d/%d/%d", d.day, d.month, d.year);
}
void checkDate(struct Date d){
    if(d.day<0||d.month<0||d.year<0) return 0;
    if(d.month >12) return 0;
    if(d.month==2){
        if(d.day>28) return 0;
    }
}
int main(){
    struct Date mydate;
    inputDate(mydate);
    printf("\n---\n");
    printDate(mydate);
}