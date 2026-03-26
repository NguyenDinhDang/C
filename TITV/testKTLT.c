#include <stdio.h>
#include <string.h>

//g++ "testKLT.c" -o main; ./main 

int main(){
  char* arrString[] = { "Z", "S", "B" };
  int arrStringLength = sizeof(arrString) / sizeof(char*);

  char result[10] = "";

  for (int i = 0; i < arrStringLength; i++) {
    strcat(result, arrString[i]);
    if (i < arrStringLength - 1) {
        strcat(result, "/");
    }
  }

  printf("%s%d", result, arrStringLength);
}