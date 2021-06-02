#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10
//O quick sort procura em todo o array o menor valor , ao encontrar esse menor valor
// ele troca com o primeiro , repetindo esses passos até o array está ordenado
void printArray(int array[TAM]) {
  for(int count = 0; count < TAM ; count++){
    printf("%d ",array[count]);
  }
  printf("\n");
}

void quick_sort(int array[TAM]) {

}
void main() {
    int array[TAM] = {10,9,8,7,6,5,4,3,2,1};
    quick_sort(array);
    printArray(array);
}