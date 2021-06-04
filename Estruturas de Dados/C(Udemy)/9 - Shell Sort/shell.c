#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10
/*
O shell sort, às vezes chamaado de “ordenação por incrementos diminutos”, 
melhora a ordenação por inserção ao quebrar a lista original em um número menor
de sublistas, as quais são ordenadas usando a ordenação por inserção. A 
forma única como essas sublistas são escolhidas é a chave para o shell sort. 
Em vez de quebrar a lista em sublistas de itens contíguos, o shell sort usa um 
incremento i, às vezes chamado de gap, para criar uma sublista escolhendo todos 
os itens que estão afastados i itens uns dos outros.
*/
void printArray(int array[TAM]) {
  for(int count = 0; count < TAM ; count++){
    printf("%d ",array[count]);
  }
  printf("\n");
}

void shell_sort(int array[TAM]) {
    int i, j, atual;
    int h = 1;

    while(h < TAM) {
        h = (h * 3 ) + 1;
    }

    while (h > 1) {
        h = h / 3;

        for(i = h; i < TAM; i++) {
            atual =  array[i];
            j = i - h ;
        
            while(j >= 0 && atual < array[j]) {
                array[j + h] = array[j];
                j = j - h;
            }
            array[j + h] = atual;
        }
    }
}

void main() {
    int array[TAM] = {10,2,8,3,6,5,7,3,9,1};
    shell_sort(array);
    printArray(array);
}