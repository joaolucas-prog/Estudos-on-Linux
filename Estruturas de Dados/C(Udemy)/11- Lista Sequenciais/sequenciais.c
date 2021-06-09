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

Pessoa * addFimListaSequancial(Pessoa *listaPessoa, int *tamanhoLista, char nome[255], int rg) {
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

int main() {

    Pessoa *listaPessoa;
    int escolha = 1;
    int tamanhoLista = 0;
    int rg;
    char *nome;
    while(escolha < 9 && escolha > 0) {
        //system("clear");
        imprimePessoas(listaPessoa,tamanhoLista);
        printf("Escolha uma opção: \n");
        printf("1 - Adicionar inicio\n");
        printf("2 - Adicionar fim\n");
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
            printf("%s", nome);
            listaPessoa = addFimListaSequancial(listaPessoa, &tamanhoLista, nome, rg);
            break;
        }
    }
    return 0;
}