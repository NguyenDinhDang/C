#include <stdio.h>
#include <string.h>

//g++ "testKLT.c" -o main; ./main 

int main(){
  char arrCourseName[][11] = {"JavaScript", "NodeJS", "Python"};
  int numCourses = sizeof(arrCourseName) / sizeof(arrCourseName[0]);

  for (int i = 0; i < numCourses; i++) {
    printf("%s ", arrCourseName[i]);
  }
}