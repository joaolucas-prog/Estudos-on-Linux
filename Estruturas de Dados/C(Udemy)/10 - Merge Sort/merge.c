#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10
/*
Sua ideia básica consiste em Dividir (o problema em vários subproblemas e resolver 
esses subproblemas através da recursividade) e Conquistar (após todos os subproblemas 
terem sido resolvidos ocorre a conquista que é a união das resoluções dos subproblemas). 
Como o algoritmo Merge Sort usa a recursividade, há um alto consumo de memória e tempo de 
execução, tornando esta técnica não muito eficiente em alguns problemas. 
*/
void printArray(int array[TAM]) {
  for(int count = 0; count < TAM ; count++){
    printf("%d ",array[count]);
  }
  printf("\n");
}

void merge(int array[TAM], int indiceEsquerdo, int meio, int indiceDireito){
    int n1 = meio - indiceEsquerdo + 1;
    int n2 = indiceDireito - meio;
    int vetorEsquerdo[n1],vetorDireito[n2];
    int i, j ,k;

    for(i = 0; i < n1 ; i++) {
        vetorEsquerdo[i] = array[indiceEsquerdo + i];
    } 
    for(j = 0; j < n2; j++) {
        vetorDireito[j] = array[meio + 1 + j];
    }
    i = 0;
    j = 0;
    k = indiceEsquerdo;

    while(i < n1 && j < n2) {
        if(vetorEsquerdo[i] <= vetorDireito[j]) {
            array[k] = vetorEsquerdo[i];
            i++;
        } else {
            array[k] = vetorDireito[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        array[k] = vetorEsquerdo[i];
        i++;
        k++;
    }
    while(j < n2) {
        array[k] = vetorDireito[j];
        j++;
        k++;
    }
}

void merge_sort(int array[TAM], int indiceEsquerdo, int indiceDireito) {
    if(indiceEsquerdo < indiceDireito) {
        int meio = indiceEsquerdo + (indiceDireito - indiceEsquerdo) / 2;
        merge_sort(array,indiceEsquerdo,meio);
        merge_sort(array,meio+1,indiceDireito);
        printArray;
        merge(array,indiceEsquerdo,meio,indiceDireito);
    }
}
void main() {
    int array[TAM] = {10,2,8,3,6,5,7,3,9,1};
    merge_sort(array,0,TAM - 1);
    printArray(array);
}