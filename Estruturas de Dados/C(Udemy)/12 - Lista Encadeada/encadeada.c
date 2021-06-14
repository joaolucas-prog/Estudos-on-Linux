#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

int main() {
    struct Node *listaEncadeada;

    struct Node *primeiroValor = malloc(sizeof(struct Node));
    primeiroValor->value = 1;
    primeiroValor->next = NULL;

    listaEncadeada = primeiroValor;

    struct Node *segundoValor = malloc(sizeof(struct Node));
    segundoValor->value = 2;
    segundoValor->next = NULL;

    listaEncadeada->next = segundoValor;
    
    struct Node *terceiro = malloc(sizeof(struct Node));
    terceiro->value = 3;
    terceiro->next = NULL;
     
    listaEncadeada->next->next = terceiro;
    
    while(listaEncadeada != NULL) {
        printf("%d ",listaEncadeada->value);
        listaEncadeada = listaEncadeada->next;
    }

    return 0;
}
