#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10

//Essa aula de fila achei bem porcaria, a fila fica totalmente não funcional
//escreverei o código apenas por questao de estudo mas irei refazer todas as estruturas
//de dados a partir de uma fonte melhor (livro + fabio akita) em outro momento

bool fila_vazia(int frente, int tras) {
    if(frente > tras){
        return true;
    }
    return false;
}

bool fila_cheia(int tras) {
    if(tras == TAM -1){
        return true;
    }
    return false;
}

void enfileira(int fila[TAM], int valor, int *tras){
    if(fila_cheia(*tras)){
        printf("fila cheia");
        return;
    }
    *tras += 1;
    fila[*tras] = valor;
}

void desenfileira(int fila[TAM], int *frente, int tras) {
    if(fila_vazia(*frente, tras)) {
        printf("fila vazia");
    }
    fila[*frente] = 0;
    *frente += 1;
}

void main() {

    int fila[TAM] = {0,0,0,0,0,0,0,0,0,0};
    int frente,tras;
    frente = 0;
    tras = -1;
    //vou nem escrever mais nada nem compilar , coisa horrorosa essa aula.
}