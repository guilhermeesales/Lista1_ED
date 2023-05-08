#include <stdio.h>
#include <stdlib.h>


typedef struct element {
    int valor;
    struct element *prox;

} NO;

typedef struct fila {
    NO *Inicio;
    NO *Fim;
    int tam;

    struct fila *prox;

} Fila;


typedef struct pilha{
    Fila *topo;
    int tam;


} Pilha;


void empilharFila(Fila *fila, int valor) {
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(fila->Inicio == NULL) {
        fila->Inicio = novo;
        fila->Fim = novo;

    } else {
        fila->Fim->prox = novo;
        fila->Fim = novo;

    }

    fila->tam++;


}

void empilharPilha(Pilha *pilha, Fila *fila) {
    if(pilha->topo == NULL) {
        fila->prox = NULL;
        pilha->topo = fila;

    } else {
        fila->prox = pilha->topo;
        pilha->topo = fila;

    }

    pilha->tam++;


}


int desempilharFila(Fila *fila) {
    NO *lixo;
    int valor;

    if(fila->tam > 0) {
        lixo = fila->Inicio;
        valor = lixo->valor;
        fila->Inicio = fila->Inicio->prox;
        free(lixo);
    }

    fila->tam--;
    return valor;

}


void imprimirFila(Fila *fila) {
    NO *aux = fila->Inicio;

    while(aux!=NULL) {
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }

}

void imprimirPilha(Pilha *pilha) {
    Fila *aux = pilha->topo;
    int cont = 1;

    while(aux != NULL) {
        printf("Imprimindo a lista %d\n", cont);
        imprimirFila(aux);
        aux = aux->prox;
        cont++;
    }

}


Fila *iniciar_fila() {
    Fila *aux = malloc(sizeof(Fila));
    aux->Inicio = NULL;
    aux->tam = 0;
    return aux;

}

Pilha *iniciar_pilha() {
    Pilha *aux = malloc(sizeof(Pilha));
    aux->topo = NULL;
    aux->tam = 0;
    return aux;
}


int main() {
    Fila *fila1 = iniciar_fila();
    Fila *fila2 = iniciar_fila();
    Pilha *pilha = iniciar_pilha();
  

    empilharFila(fila1, 1);
    empilharFila(fila1, 2);
    empilharFila(fila2, 3);
    empilharFila(fila2, 4);

    empilharPilha(pilha, fila1);
    empilharPilha(pilha, fila2);


    imprimirPilha(pilha);

}