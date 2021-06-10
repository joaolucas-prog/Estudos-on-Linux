#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Listas sequencias são listas em que seu valor no armazenamento da memória são sequenciais
//como exemplo os arrays

typedef struct {
    char nome[255];
    int rg;
}Pessoa;

void imprimePessoas(Pessoa *listaPessoa, int tamanhoLista) {
    int cont;
    for(cont = 0; cont < tamanhoLista; cont++){
        printf("Nome: %s\n", listaPessoa[cont].nome);
        printf("Rg: %d\n", listaPessoa[cont].rg );
    }
}

Pessoa * addInicioListaSequancial(Pessoa *listaPessoa, int *tamanhoLista, char *nome, int rg) {
    Pessoa *novaListaSeq = malloc((*tamanhoLista + 1) * sizeof(Pessoa));
    int cont;
    strcpy(novaListaSeq[0].nome, nome);
    novaListaSeq[0].rg = rg;

    for(cont = 0; cont < *tamanhoLista; cont++) {
        strcpy(novaListaSeq[cont + 1].nome, listaPessoa[cont].nome);
        novaListaSeq[cont + 1].rg = listaPessoa[cont].rg;
    }
    *tamanhoLista += 1;
    return novaListaSeq;
}

Pessoa * addFimListaSequancial(Pessoa *listaPessoa, int *tamanhoLista, char *nome, int rg) {
    Pessoa *novaListaSeq = malloc((*tamanhoLista + 1) * sizeof(Pessoa));
    int cont;

    for(cont = 0; cont < *tamanhoLista; cont++) {
        strcpy(novaListaSeq[cont].nome, listaPessoa[cont].nome);
        novaListaSeq[cont].rg = listaPessoa[cont].rg;
    }

    strcpy(novaListaSeq[*tamanhoLista].nome, nome);
    novaListaSeq[*tamanhoLista].rg = rg;
    *tamanhoLista += 1;
    return novaListaSeq;
}

Pessoa * addXListaSequancial(Pessoa *listaPessoa, int *tamanhoLista, char *nome, int rg, int posicao) {
    Pessoa *novaListaSeq = malloc((*tamanhoLista + 1) * sizeof(Pessoa));
    int cont;
    for(cont = 0; cont < posicao; cont++) {
        strcpy(novaListaSeq[cont].nome, listaPessoa[cont].nome);
        novaListaSeq[cont].rg = listaPessoa[cont].rg;
    }
    strcpy(novaListaSeq[posicao].nome, nome);
    novaListaSeq[posicao].rg = rg;

    for(cont = posicao + 1; cont < *tamanhoLista + 1; cont++) {
        strcpy(novaListaSeq[cont].nome, listaPessoa[cont-1].nome);
        novaListaSeq[cont].rg = listaPessoa[cont-1].rg;
    }
    *tamanhoLista += 1;
    return novaListaSeq;
}

Pessoa * removeInicioSeq(Pessoa *listaPessoa, int *tamanhoLista){
    Pessoa *novaListaSeq = malloc((*tamanhoLista - 1) * sizeof(Pessoa));
    int cont;
    for (cont = 1; cont < *tamanhoLista; cont++) {
        strcpy(novaListaSeq[cont - 1].nome, listaPessoa[cont].nome);
        novaListaSeq[cont - 1].rg = listaPessoa[cont].rg;
    }
    *tamanhoLista -= 1;
    return novaListaSeq;
}

Pessoa * removeFimSeq(Pessoa *listaPessoa, int *tamanhoLista){
    Pessoa *novaListaSeq = malloc((*tamanhoLista - 1) * sizeof(Pessoa));
    int cont;
    for (cont = 0; cont < *tamanhoLista - 1; cont++) {
        strcpy(novaListaSeq[cont].nome, listaPessoa[cont].nome);
        novaListaSeq[cont].rg = listaPessoa[cont].rg;
    }
    *tamanhoLista -= 1;
    return novaListaSeq;
}

Pessoa * removeXSeq(Pessoa *listaPessoa, int *tamanhoLista, int posicao){
    Pessoa *novaListaSeq = malloc((*tamanhoLista - 1) * sizeof(Pessoa));
    int cont;
    for (cont = 0; cont < *tamanhoLista - 1; cont++) {
        if(cont < posicao) {
            strcpy(novaListaSeq[cont].nome, listaPessoa[cont].nome);
            novaListaSeq[cont].rg = listaPessoa[cont].rg;
        } else {
            strcpy(novaListaSeq[cont].nome, listaPessoa[cont + 1].nome);
            novaListaSeq[cont].rg = listaPessoa[cont + 1].rg;
        }
    }
    
    *tamanhoLista -= 1;
    return novaListaSeq;
}

int main() {

    Pessoa *listaPessoa;
    int escolha = 1;
    int tamanhoLista = 0;
    int rg,posicao;
    char *nome;
    while(escolha < 9 && escolha > 0) {
        system("clear");
        imprimePessoas(listaPessoa,tamanhoLista);
        printf("\nEscolha uma opção: \n");
        printf("1 - Adicionar inicio\n");
        printf("2 - Adicionar fim\n");
        printf("3 - Adicionar na posicao x\n");
        printf("4 - Remove Inicio\n");
        printf("5 - Remove Fim\n");
        printf("6 - Remove posicao x\n");
        scanf("%d",&escolha);
        switch (escolha)
        {
            case 1:
                printf("Digite uma nome : \n");
                scanf("%s",nome);
                getchar();
                printf("digite um rg: \n");
                scanf("%d",&rg);
                listaPessoa = addInicioListaSequancial(listaPessoa, &tamanhoLista, nome, rg);    
                break;
            
            case 2:
                printf("Digite uma nome : \n");
                scanf("%s",nome);
                getchar();
                printf("digite um rg: \n");
                scanf("%d",&rg);
                listaPessoa = addFimListaSequancial(listaPessoa, &tamanhoLista, nome, rg);
                break;
            case 3:
                printf("Digite um indice: \n");
                scanf("%d",&posicao);
                printf("Digite uma nome : \n");
                scanf("%s",nome);
                getchar();
                printf("digite um rg: \n");
                scanf("%d",&rg);
                if(posicao == 0) {
                    listaPessoa = addInicioListaSequancial(listaPessoa, &tamanhoLista, nome, rg);    

                } else if(posicao >= tamanhoLista) {
                    listaPessoa = addFimListaSequancial(listaPessoa, &tamanhoLista, nome, rg);
                } else {
                    listaPessoa = addXListaSequancial(listaPessoa, &tamanhoLista, nome, rg, posicao);
                }
                break;
            case 4:
                if(tamanhoLista == 0) {
                    printf("Lista vazia");
                } else {
                    listaPessoa = removeInicioSeq(listaPessoa, &tamanhoLista);
                }
                break;
            case 5:
                if(tamanhoLista == 0) {
                    printf("Lista vazia\n");
                } else {
                    listaPessoa = removeFimSeq(listaPessoa, &tamanhoLista);
                }
                break;
            case 6:
                printf("Digite um indice: \n");
                scanf("%d",&posicao);
                if(tamanhoLista == 0) {
                    printf("Lista vazia\n");
                } else {
                    if(posicao == 0) {
                        listaPessoa = removeInicioSeq(listaPessoa, &tamanhoLista);
                    } else if(posicao == tamanhoLista -1) {
                        listaPessoa = removeFimSeq(listaPessoa, &tamanhoLista);
                    } else if(posicao >= tamanhoLista) {
                        printf("Indice nao existe\n");
                    } else {
                        listaPessoa = removeXSeq(listaPessoa, &tamanhoLista, posicao);
                    }
                }
                break;
        }
    }
    return 0;
}