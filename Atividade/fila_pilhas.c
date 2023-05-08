#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int valor;
    struct element *prox;

} NO;

typedef struct pilha {
    NO * topo;
    int tam;
    struct pilha *prox;

} Pilha;

typedef struct fila {
    Pilha *inicio;
    Pilha *fim;
    int tam;


} Fila; 


void empilharPilha(Pilha *pilha, int valor) {
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(pilha->topo == NULL) {
        pilha->topo = novo;

    } else {
        novo->prox = pilha->topo;
        pilha->topo = novo;

    }

    pilha->tam++;

}

void empilharFila(Fila *fila, Pilha *pilha) {
    if(fila->inicio == NULL) {
        pilha->prox = NULL;
        fila->inicio = pilha;
        fila->fim = pilha;

    } else {
        pilha->prox = fila->fim;
        fila->inicio = pilha;

    }

}


void imprimirPilha(Pilha *pilha) {
    NO *aux = pilha->topo;

    while(aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }

}


void imprimirFila(Fila *fila) {
    Pilha *aux = fila->inicio;
    int cont = 1;

    while(aux != NULL) {
        printf("Imprimindo a Fila %d\n", cont);
        imprimirPilha(aux);
        aux = aux->prox;
        cont++;
    }
}


Pilha *iniciar_pilha() {
    Pilha *aux = malloc(sizeof(Pilha));
    aux->topo = NULL;
    aux->tam = 0;
    return aux;


}

Fila *iniciar_fila() {
    Fila *aux = malloc(sizeof(Fila));
    aux->inicio = NULL;
    aux->fim = NULL;
    aux->tam = 0;
}


int main() {
    Pilha *pilha1 = iniciar_pilha();
    Pilha *pilha2 = iniciar_pilha();
    Fila *fila = iniciar_fila();

    empilharPilha(pilha1, 1);
    empilharPilha(pilha1, 2);
    empilharPilha(pilha2, 3);
    empilharPilha(pilha2, 4);

    empilharFila(fila, pilha1);
    empilharFila(fila, pilha2);

    imprimirFila(fila);


    return 0;
}