#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10
// A estrutura de dados do insertion sort irá inserir o novo elemento na sua posição
// exata no array, então o primeiro apenas insere , no segundo ele compara com o que
// existe se for maior arrasta o anterior para frente e insere o novo, e faz isso até o
// final
void printArray(int array[TAM]) {
  for(int count = 0; count < TAM ; count++){
    printf("%d ",array[count]);
  }
}

void insertion_sort(int array[TAM]) {
    int i, j ,atual;

    for(i = 1; i < TAM; i++) {
        atual =  array[i];
        j = i - 1 ;
        while(j >= 0 && atual < array[j]) {
            array[j + 1] = array[j];
            
            j = j - 1;
        }
        array[j + 1] = atual;
    }
}
void main() {
    int array[TAM] = {10,9,8,7,6,5,4,3,2,1};
    insertion_sort(array);
    printArray(array);
}