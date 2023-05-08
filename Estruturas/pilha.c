#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// Pilhas basicamente �: O elemento que ao adicionado fica no topo

typedef struct new_element {
    int valor;
    struct new_element *prox;

} NODE;


typedef struct {
    NODE *start;
    int tam;

} Pilha;


void addElementsOfPilha(Pilha *pilha, int value) {
    NODE *new = (NODE*) malloc(sizeof(NODE));
    new->valor = value;
    new->prox = NULL;

    if(pilha->start == NULL) {
        pilha->start = new;

    } else {
        new->prox = pilha->start;
        pilha->start = new;

    }

    pilha->tam++;

}



int removeElementsOfPilha(Pilha *pilha) {
    NODE *trash;
    int value = -1;

    if(pilha->tam > 0) {
        trash = pilha->start;
        value = trash->valor;
        pilha->start = pilha->start->prox;
        free(trash);
        pilha->tam--;
    
    } else {
        printf("Pilha vazia!\n");
    }

    return value;
    
}


void printElements(Pilha *pilha) {
    NODE *aux = pilha->start;

    while(aux != NULL) {
        printf("O valor � %d\n", aux->valor);
        aux = aux->prox;
    }

}




int main() {
    setlocale(LC_ALL, "Portuguese");
    Pilha pilha;
    pilha.start = NULL;
    pilha.tam = 0;

    addElementsOfPilha(&pilha, 1);
    addElementsOfPilha(&pilha, 2);
    addElementsOfPilha(&pilha, 3);
    addElementsOfPilha(&pilha, 4);
    removeElementsOfPilha(&pilha);
    removeElementsOfPilha(&pilha);
    printElements(&pilha);

    return 0;

}


