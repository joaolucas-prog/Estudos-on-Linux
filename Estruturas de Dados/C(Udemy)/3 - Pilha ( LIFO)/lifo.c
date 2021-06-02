#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define TAM 10
// uma pilha lifo significa ( last in , first out) ou seja o último valor a entrar nela
// deve ser o primeiro a sair


bool pilha_vazia(int topo) {
    if(topo == -1) {
        return true;
    }
    return false;
}

bool pilha_cheia(int topo) {
    if(topo == TAM -1) {
        return true;
    }
    return false;
}

void push(int pilha[], int valor, int *topo) {
    if(pilha_cheia(*topo)) {
       printf("A pilha está cheia\n"); 
    } else {
        *topo += 1;
        pilha[*topo] = valor;
    }
}
int pop(int pilha[], int *topo) {
    if(pilha_vazia(*topo)) {
        printf("A pilha está vazia\n");
    } else {
        int valor_removido = pilha[*topo];
        pilha[*topo] = 0;
        *topo -= 1;
        return valor_removido;
    }
}
int pilha_get(int pilha[], int topo) {
    if(pilha_vazia(topo)){
        return 0;
    }
    return pilha[topo];
}

int pilha_size(int *topo){
    return *topo + 1;
}

void print_pilha(int pilha[]){
    for(int i = 0; i < TAM ; i++) {
        printf("%d ",pilha[i]);
    }
    printf("\n");
}
int main() {
    int pilha[TAM]={0,0,0,0,0,0,0,0,0,0};
    int topo = -1; 
    
    print_pilha(pilha);
    printf("Topo :%d\n", topo);
    push(pilha, 5, &topo);
    print_pilha(pilha);
    printf("%d\n",pilha_size(&topo));
    printf("Topo :%d\n", topo);
    push(pilha, 7, &topo);
    printf("Pilha get: %d\n", pilha_get(pilha, topo));
    print_pilha(pilha);
    printf("Topo :%d\n", topo);
    push(pilha, 9, &topo);
    print_pilha(pilha);
    printf("Topo :%d\n", topo);
    int remove = pop(pilha, &topo);
    printf("Valor removido %d\n", remove);
    print_pilha(pilha);
    printf("Topo :%d\n",topo);

    return 0;
}