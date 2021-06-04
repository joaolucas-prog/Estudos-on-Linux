#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10
/*O quicksort adota a estratégia de divisão e conquista. A estratégia consiste em 
rearranjar as chaves de modo que as chaves "menores" precedam as chaves "maiores". 
Em seguida o quicksort ordena as duas sublistas de chaves menores e maiores recursivamente 
até que a lista completa se encontre ordenada. [3]Os passos são:

    -Escolha um elemento da lista, denominado pivô;
    -Particiona: rearranje a lista de forma que todos os elementos anteriores ao pivô 
     sejam menores que ele, e todos os elementos posteriores ao pivô sejam maiores que ele. 
     Ao fim do processo o pivô estará em sua posição final e haverá duas sub listas não 
     ordenadas. Essa operação é denominada partição;
    -Recursivamente ordene a sub lista dos elementos menores e a sub lista dos elementos 
     maiores;
*/
void printArray(int array[TAM]) {
  for(int count = 0; count < TAM ; count++){
    printf("%d ",array[count]);
  }
  printf("\n");
}

void quick_sort(int array[TAM], int inicio, int fim) {
  int esq,dir,pivo,meio,aux;
  esq = inicio;
  dir = fim;
  meio = (int) (esq + dir ) / 2;
  pivo = array[meio];

  while(dir > esq) {

    while(array[esq] < pivo) {
      esq += 1;
    }

    while (array[dir] > pivo) {
      dir -= 1;
    }

    if(esq <= dir) {
      aux = array[esq];
      array[esq] = array[dir];
      array[dir] = aux;
      esq += 1;
      dir -= 1;
    }
    printArray(array);
  }
  if(inicio <  dir) {
    quick_sort(array,inicio,dir);
  }
  if(esq < fim) {
    quick_sort(array,esq,fim);
  }


}

void main() {
    int array[TAM] = {10,2,8,3,6,5,7,3,9,1};
    quick_sort(array,0,TAM - 1);
    printArray(array);
}