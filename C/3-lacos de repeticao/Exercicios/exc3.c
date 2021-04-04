#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main() {
  int valueScan,value;
  bool isPrime = true;
  printf("Digite um numero\n");
  scanf("%d",&valueScan);
  if(valueScan > 1) {
    for(value = valueScan -1; value > 1; value--) {
      if((valueScan % value) == 0){
        isPrime = false;
        break;
      }
    } 
  }else {
    isPrime = false;
  }
  if(isPrime) {
    printf("Primo"); 
  }else {
    printf("Nao e primo");
  }
}
