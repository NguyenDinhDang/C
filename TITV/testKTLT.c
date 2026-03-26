#include <stdio.h>
#include <string.h>

//g++ "testKLT.c" -o main; ./main 

int main(){
  int arrInt[] = {2, 3, 6};
  char arrString[][2] = { "S", "Z", "T", "W" };
  int sumEven = 0;
  int arrIntLength = sizeof(arrInt)/sizeof(int);

  for(int i=0; i < arrIntLength; i++) {
    if(arrInt[i] % 2 == 0) {
        sumEven += arrInt[i];
    }
    arrString[i][1] = sumEven + '0';
  }

  printf("%s", arrString[1]);
}