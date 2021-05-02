#include <stdio.h>
#include <stdlib.h>

void main() { 
  //Calcular media de um vetor

  int i,size;
  printf("Digite o tamanho do array \n");
  scanf("%d",&size);
  int array[size];
  float totalValue = 0;

   for(i = 0; i < size; i++){
     printf("Digite o valor do array na posição %d\n",i);
     scanf("%d",&array[i]); 
  }
  
  for(i = 0; i < size; i++){
    totalValue += array[i]; 
  }
  
  printf("A media do array e: %.2f",totalValue/size);

}
