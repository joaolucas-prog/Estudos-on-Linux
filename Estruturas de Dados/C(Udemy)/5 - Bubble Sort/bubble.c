#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10
// A estrutura do bubble sort compara o 1 elemento com o seu próximo e verifica se é maior
// caso seja ele troca de lugar e repete o processo até chegar na ultima posição ou encontrar
// algum elemento que seja maior
void printArray(int array[TAM]) {
  for(int count = 0; count < TAM ; count++){
    printf("%d ",array[count]);
  }
}

void main() {
    int bubble[TAM] = {10,0,8,11,6,13,4,5,2,1};
    int x,y,aux;

    for(x = 0; x < TAM; x++) {
        for( y = x + 1; y < TAM; y++) {
            if(bubble[x] > bubble[y]) {
                aux = bubble[x];
                bubble[x] = bubble[y];
                bubble[y] = aux;
            }
        }
    }

    printArray(bubble);
}