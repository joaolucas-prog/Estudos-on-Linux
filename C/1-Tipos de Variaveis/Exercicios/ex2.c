#include <stdio.h>
#include <stdlib.h>

void main() {
  
  float value1,value2;

  printf("Calculo do valor absoluto entre a sutração de dois numeros\n");
  printf("Digite os numeros separados por virgula\n");
  scanf("%f %f",&value1,&value2);
  printf("Valor absoluto entre %.2f e %.2f = %d",value1 , value2 , abs(value1 - value2));
}
