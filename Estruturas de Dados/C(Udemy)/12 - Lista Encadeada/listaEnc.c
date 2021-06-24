#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rg;
    char name[255];
}Person;

struct PersonList {
    Person person;
    struct PersonList *next;
};

void clearScream() {
    system("cls"); //windows
    system("clear"); //linux
}

int sizePersonList(struct PersonList *person) {
    int count = 0;
    struct PersonList *aux = person;
    if (aux != NULL) {
        count += 1;
        while (aux->next != NULL) {
            aux = aux->next;
            count += 1;
        }   
    }
    return count;
}

Person createPerson(int rg, char *name) {
    Person newPerson;
    newPerson.rg = rg;
    strcpy(newPerson.name, name);
    return newPerson;
}

void printPersonList(struct PersonList *person) {
    struct PersonList *aux = person; 
    if (aux != NULL) {
        printf("| Nome: %s Rg: %d ->", aux->person.name, aux->person.rg);
        while (aux->next != NULL) {
            aux = aux->next;
            printf(" Nome: %s Rg: %d ->", aux->person.name, aux->person.rg);
        }
        printf(" NULL |\n");
    }
}

struct PersonList * addFirst(struct PersonList *personList, int rg, char *name) {
    int size = sizePersonList(personList);
    Person newPerson = createPerson(rg , name);
    struct PersonList *newPersonList = malloc((size + 1) * sizeof(struct PersonList));
    newPersonList->person = newPerson;
    newPersonList->next = personList;
    return newPersonList;
}

struct PersonList * addLast(struct PersonList *personList, int rg, char *name) {
    if (personList == NULL) {
        return addFirst(personList, rg, name);
    }
    int size = sizePersonList(personList);
    Person newPerson = createPerson(rg , name);
    struct PersonList *newPersonList = malloc((size + 1) * sizeof(struct PersonList));
    newPersonList->person = newPerson;
    newPersonList->next = NULL;
    struct PersonList *aux = personList;
    while (aux != NULL) {
        if (aux->next == NULL) {
            aux->next = newPersonList;
            return personList;
        }
        aux = aux->next;
    }
}

struct PersonList * addIndex(struct PersonList *personList, int index, int rg, char *name) {
    if (personList == NULL || index == 0) {
        return addFirst(personList, rg, name);
    }
    int size = sizePersonList(personList);
    Person newPerson = createPerson(rg , name);
    struct PersonList *newPersonList = malloc((size + 1) * sizeof(struct PersonList));
    newPersonList->person = newPerson;
    newPersonList->next = NULL;
    if (index >= size) {
        return addLast(personList, rg, name);
    }
    struct PersonList *aux = personList;
    for (int i = 0; i < index - 1; i++) {
       aux = aux->next;
    }
    struct PersonList *aux2 = aux->next;
    aux->next = newPersonList;
    newPersonList->next = aux2;
    return personList;
}

struct PersonList * removeFirst(struct PersonList *personList) {
    int size = sizePersonList(personList);
    if (size <= 1) {
        return NULL;
    }
    return personList->next;
}

struct PersonList * removeLast(struct PersonList *personList) {
    int size = sizePersonList(personList);
    if (size <= 1) {
        return NULL;
    }
    struct PersonList *newPersonList = personList;
    for (int i = 0; i < size - 2; i ++) {
        newPersonList = newPersonList->next;
    }
    newPersonList->next = NULL;
    return personList;
}

struct PersonList * removeIndex(struct PersonList *personList, int index) {
    int size = sizePersonList(personList);
    struct PersonList *newPersonList = personList;
    if (personList == NULL) {
        return NULL;
    }
    if(index == 0) {
        return removeFirst(personList);
    } 
    if(index == size -1){
        return removeLast(personList);
    }
    if(index >= size) {
        return personList;
    }
    for (int i = 0; i < index - 1; i++) {
        newPersonList = newPersonList->next;
    }
    struct PersonList *aux = newPersonList->next;
    newPersonList->next = aux->next;
    return personList;
}

void searchNameByRg(struct PersonList *personList, int rg) {
    int size = sizePersonList(personList);
    struct PersonList *aux = personList;
    if(personList == NULL) {
        printf("Lista Vazia\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        if(aux->person.rg == rg) {
            printf("%s\n",aux->person.name);
            return;
        }
        aux = aux->next;
    }
    printf("Nome nao encontrado\n");
}


int main() {
    int option = 1;
    int rg, index;
    char *name;
    struct PersonList *personList = NULL;

    while (option < 8 && option > 0) {
        
        printPersonList(personList);

        printf("Escolha uma opcao\n");
        printf("1 - Adicionar ao inicio da lista\n");
        printf("2 - Adicionar ao fim da lista\n");
        printf("3 - Adicionar ao indice X\n");
        printf("4 - Remover o primeiro\n");
        printf("5 - Remover o ultimo\n");
        printf("6 - Remover o x elemento\n");
        printf("7 - Buscar nome pelo RG\n");
        scanf("%d",&option);

        clearScream();
        
        switch (option){
            case 1:    
                printf("Escolha um nome\n");
                scanf("%s", name);
                getchar();
                printf("Escolha um rg\n");
                scanf("%d", &rg);
                personList = addFirst(personList, rg, name);
                break;
            
            case 2:
                printf("Escolha um nome\n");
                scanf("%s", name);
                getchar();
                printf("Escolha um rg\n");
                scanf("%d", &rg);
                personList = addLast(personList, rg, name);
                break;

            case 3:
                printf("Escolha a posicao\n");
                scanf("%d", &index);
                printf("Escolha um nome\n");
                scanf("%s", name);
                getchar();
                printf("Escolha um rg\n");
                scanf("%d", &rg);
                personList = addIndex(personList, index, rg, name);
                break;
            
            case 4:
                personList = removeFirst(personList);
                break;

            case 5:
                personList = removeLast(personList);
                break;

            case 6:
                printf("Escolha a posicao\n");
                scanf("%d", &index);
                personList = removeIndex(personList, index);
                break;
            case 7:
                printf("Digite o Rg\n");
                scanf("%d", &rg);
                searchNameByRg(personList,rg);
            
            default:
                break;

        }
    }
    return 0;
}