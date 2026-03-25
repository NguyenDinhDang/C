#include <stdio.h>
#include <string.h>

int main(){
    int number = 3;
char result[10];
switch (number) {
  case 2:
    strcpy(result, "3");
  case 3:
    strcpy(result, "4");            
  case 4:
    strcpy(result, "2");
    break;
  default:
    strcpy(result, "NoValue");
}
printf("%s", result);
}