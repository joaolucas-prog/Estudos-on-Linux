#include <stdio.h>
#include <stdlib.h>

void main() {
  int value = 10;

  for(value; value <= 20; value += 2){
    printf("\n%d",value);
  }
  value = 10;

  while(value <= 20){
    printf("\n%d",value);
    value+=2;
  }
  value = 10;
  do {
    printf("\n%d",value);
    value+=2;
  }while(value <=20);
}
