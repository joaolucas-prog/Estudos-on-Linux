#include <stdio.h>
#include <stdlib.h>

void main() {
  int a,b,c;
  char letra;
  scanf("%c",&letra);
  printf("o caracter digitado foi : %c \n",letra);
  getchar();
  printf("Digite os valores dos lados do triangulo\n");
  scanf("%d %d %d",&a,&b,&c);
  getchar();
  if(a == b && b == c){
    printf("Triangulo equilatero\n");
  } else {
    printf("Nao e um triangulo equilatero\n");
  }
}
