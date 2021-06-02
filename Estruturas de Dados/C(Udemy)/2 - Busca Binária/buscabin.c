#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define TAM 10

//uma busca binaria ele necessita que o array passado esteja ordenado
//ela utiliza do conceito dividir para conquistar, em que ela busca no meio do array o valor
//caso não encontre ela ajusta seus limites laterais e faz uma nova busca pelo novo meio
//do array

int busca_binaria(int value, int array[], int *index) {
    int esquerda = 0;
    int direita = TAM - 1;
    int meio;

    while(esquerda <= direita) {
        meio = (esquerda + direita)/2;
    
        if(value == array[meio]) {
            *index = meio;
            return 1;
        }
        if(value < array[meio]) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    
    return -1;
}

int main(){
    
    int array[TAM] = {1,2,3,12,32,43,65,67,93,99};
    int index,value;

    printf("Escolha o numero para encontrar o index\n");
    scanf("%d",&value);
    if (busca_binaria(value,array,&index) == 1) {
      printf("Valor encontrado na posicao %d",index);
    } else {
      printf("Valor nao encontrado");
    }
    return 0;
}