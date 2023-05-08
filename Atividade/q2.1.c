#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


typedef struct fila {
    int value;
    struct fila *prox;

} NODE;


typedef struct {
    NODE *start, *end;
    int tam;

} Fila;


void addElementsOfFila(Fila *fila, int value) {
    NODE *new = (NODE*) malloc(sizeof(NODE));
    new->value = value;
    new->prox = NULL;

    if(fila->start == NULL) {
        fila->start = new;
        fila->end = new;

    } else {
        fila->end->prox = new;
        fila->end = new; 

    }

    fila->tam++;

}


int removeElementsOfFila(Fila *fila) {
    NODE *trash;
    int value = -1;

    if(fila->tam > 0) {
        trash = fila->start;
        value = trash->value;
        fila->start = fila->start->prox;
        free(trash);
        fila->tam--;


    } else {
        printf("A lista está vazia!\n");
    }


    return value;

}


void printElements(Fila *fila) {
    NODE *aux = fila->start;

    while(aux != NULL) {
        printf("O valor e: %d\n", aux->value);
        aux = aux->prox;

    }
} 


int sizeOfFila(Fila *fila) {
    return fila->tam;
}


int main() {
    Fila *fila;
    fila->start = NULL;
    fila->end = NULL;
    fila->tam = 0;


    addElementsOfFila(fila, 1);
    addElementsOfFila(fila, 2);
    addElementsOfFila(fila, 3);
    addElementsOfFila(fila, 4);
    removeElementsOfFila(fila);
    printElements(fila);


}
