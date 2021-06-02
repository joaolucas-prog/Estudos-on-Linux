#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10
//O Selection sort procura em todo o array o menor valor , ao encontrar esse menor valor
// ele troca com o primeiro , repetindo esses passos até o array está ordenado
void printArray(int array[TAM]) {
  for(int count = 0; count < TAM ; count++){
    printf("%d ",array[count]);
  }
  printf("\n");
}

void selection_sort(int array[TAM]) {
    int posicaoMenor, aux, i, j;
    for(i = 0; i < TAM; i++) {
        posicaoMenor = i;
        for (j = i + 1; j < TAM; j++) {
            if(array[j] < array[i]){
                posicaoMenor = j;
            }            
        }
        if(posicaoMenor != i){
            aux = array[i];
            array[i] = array[posicaoMenor];
            array[posicaoMenor] = aux;
        }
        printArray(array);
    }
}
void main() {
    int array[TAM] = {10,9,8,7,6,5,4,3,2,1};
    selection_sort(array);
    printArray(array);
}