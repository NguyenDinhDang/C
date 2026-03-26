#include <stdio.h>
#include <string.h>

//g++ "testKLT.c" -o main; ./main 

int main(){
  int arrInt[] = {6, 5, 4, 3, 2, 1};

  printf("%d", arrInt[arrInt[arrInt[arrInt[2]]]]);

}