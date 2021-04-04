#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  //responsavel por alimentar o aleatorio de forma diferente
  srand((unsigned)time(NULL));
  
  int aleatorio = rand() % 3; // valor entre 0 e 2
  printf("valor : %d\n",aleatorio);

  aleatorio = (rand() % 5) + 1; //valor entre 1 e 5
  printf("valor : %d\n",aleatorio);

}
