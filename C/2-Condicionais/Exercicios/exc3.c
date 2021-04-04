#include <stdio.h>
#include <stdlib.h>

void main() {
  float value1,value2;
  int option;
  printf("Digite os dois valores da operacao\n");
  scanf("%f %f", &value1, &value2);
  getchar();
  printf("Escolha qual operacao voce quer realizar\n");
  printf("1 - Somar\n");
  printf("2 - Substrair\n");
  printf("3 - Multiplicacao\n");
  printf("4 - Divisao\n");
  scanf("%d",&option);
  getchar();
  switch(option) {
    case 1:
      printf("resultado: %f",value1 + value2);
      break;
    case 2:
      printf("resultado: %f",value1 - value2);
      break;
    case 3:
      printf("resultado: %f",value1 * value2);
      break;
    case 4:
      printf("resultado: %f",value1 / value2);
      break;
    default:
      printf("operacao invalida");
      break;
  }  
}
