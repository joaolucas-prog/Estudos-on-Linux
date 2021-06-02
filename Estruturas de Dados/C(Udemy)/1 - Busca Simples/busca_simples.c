#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10
// o Algoritimo de busca simples ou busca sequencial ele busca o valor passando de valor em valor em uma lista ou vetor
// Por questões de estudo vou considerar que todo vetor possuirá tamanho fixo em 10

void printArray(int array[TAM]){
  for(int count = 0; count < TAM ; count++){
    printf("%d ",array[count]);
  }
}

int find(int value,int array[TAM],int *index){
  for(int count = 0; count < TAM ; count++){
    if(value == array[count]){
      *index = count;
      return 1;
    }
  }
  return 0;
}

int main(){
  int array[TAM] = {12,32,43,65,67,23,93,51,7,0};
  int index,value;

  printArray(array);

  printf("Escolha o numero para encontrar o index\n");
  scanf("%d",&value);
  if (find(value,array,&index) == 1) {
    printf("Valor encontrado na posicao %d",index);
  } else {
    printf("Valor nao encontrado");
  }
  
  return 0;
}
