#include <stdio.h>
#include <stdlib.h>

void main() {
  
  int value1,value2,value3,result;
  printf("Multipicacao de 3 numeros \n");
  printf("Digite 3 numeros separados por espaço\n");
  scanf("%d %d %d",&value1,&value2,&value3);
  result = value1 * value2 * value3;
  printf("Resultado : %d",result);
}
