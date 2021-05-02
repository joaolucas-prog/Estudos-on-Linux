#include <stdio.h>
#include <stdlib.h>

void main() {
  
  int matriz[2][2],aux1,aux2,x,y;

  for(y = 0; y < 2; y++){
    for(x = 0; x < 2 ; x++) {
      printf("Digite o valor da Matriz [%d] [%d]\n",y,x);
      scanf("%d", &matriz[y][x]);
    }
  }
  
  aux1 = matriz[0][0];
  aux2 = matriz[0][1];
  matriz[0][0] = matriz[1][0];
  matriz[0][1] = matriz[1][1];
  matriz[1][0] = aux1;
  matriz[1][1] = aux2;

  printf("Matriz final:\n");
  for(y = 0; y < 2; y++){
    for(x = 0; x < 2 ; x++) {
      printf("|%d| ",matriz[y][x]);
    }
    printf("\n");
  }

}
