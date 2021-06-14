#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rg;
    char name[255];
}Person;

struct PersonList{
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
    if(aux != NULL) {
        count += 1;
        while (aux->next != NULL) {
            aux = aux->next;
            count += 1;
        }   
    }
    return count;
}

Person createPerson(int rg, char *name){
    Person newPerson;
    newPerson.rg = rg;
    strcpy(newPerson.name, name);
    return newPerson;
}

struct PersonList * addFirst(struct PersonList *personList, int rg, char *name){
    int size = sizePersonList(personList);
    Person newPerson = createPerson(rg , name);
    struct PersonList *newPersonList = malloc((size + 1) * sizeof(struct PersonList));
    newPersonList->person = newPerson;
    newPersonList->next = personList;
    return newPersonList;
}

void printPersonList(struct PersonList *person) {
    struct PersonList *aux = person; 
    if(aux != NULL) {
        printf("| Nome: %s Rg: %d ->", aux->person.name, aux->person.rg);
        while (aux->next != NULL) {
            aux = aux->next;
            printf(" Nome: %s Rg: %d ->", aux->person.name, aux->person.rg);
        }
        printf(" NULL |\n");
    }
}

int main() {
    int option = 1;
    int rg;
    char *name;
    struct PersonList *personList = NULL;

    while(option < 8 && option > 0) {
        
        printPersonList(personList);

        printf("Escolha uma opcao\n");
        printf("1 - Adicionar ao inicio da lista\n");
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
            
            default:
                break;

        }
    }
    return 0;
}