#include <stdio.h>
#include <stdlib.h>

void main() {
  
  float grade1,grade2,grade3,result;

  printf("Digite as tres notas : \n");
  scanf(" %f %f %f",&grade1,&grade2,&grade3);

  result = (grade1 + grade2 + grade3)/3;

  if(result >= 7) {
    printf("Aprovado media %.2f",result);
  }else{
    printf("Reprovado media %.2f",result);
  }
}
