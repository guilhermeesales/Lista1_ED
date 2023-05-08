#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int valor;
    struct element *prox;

} NO;


typedef struct fila_filho {
    NO *inicio;
    NO *fim;
    int tam;
    struct fila_filho *prox;

} Fila_filho; 


typedef struct fila_pai {
    Fila_filho *inicio;
    Fila_filho *fim;
    int tam;

} Fila_pai;



void empilharValoresPilhaFilho (Fila_filho *fila_filho, int valor){
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(fila_filho->inicio == NULL) {
        fila_filho->inicio = novo;
        fila_filho->fim = novo;

    } else {
        fila_filho->fim->prox = novo;
        fila_filho->fim = novo;  

    }

    fila_filho->tam++;

}


void empilharFilaPai(Fila_pai *fila_pai, Fila_filho *fila_filho) {
    if(fila_pai->inicio == NULL) {
        fila_filho->prox = NULL;
        fila_pai->inicio = fila_filho;
        fila_pai->fim = fila_filho;

    } else {
        fila_pai->fim->prox = fila_filho;
        fila_pai->fim = fila_filho;
            
    }

    fila_pai->tam++;

}


void imprimirFilaFilho(Fila_filho *fila_filho) {
    NO *aux = fila_filho->inicio;

    while(aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }

}


void imprimirFilaPai(Fila_pai *fila_pai) {
    Fila_filho *aux = fila_pai->inicio;
    int cont = 1;

    while(aux != NULL) {
        printf("Imprimindo fila %d\n", cont);
        imprimirFilaFilho(aux);
        aux = aux->prox;
        cont++;

    }

}


Fila_filho *iniciar_fila_filho() {
    Fila_filho *aux = (Fila_filho*) malloc(sizeof(Fila_filho));
    aux->inicio = NULL;
    aux->fim = NULL;
    aux->tam = 0;
    return aux;


}

Fila_pai *iniciar_fila_pai() {
    Fila_pai *aux = (Fila_pai *) malloc(sizeof(Fila_pai));
    aux->inicio = NULL;
    aux->fim = NULL;
    aux->tam = 0;
    return aux;


}



int main() {
    Fila_filho *fila_filho1 = iniciar_fila_filho();
    Fila_filho *fila_filho2 = iniciar_fila_filho();
    Fila_pai *fila_pai = iniciar_fila_pai();

    empilharValoresPilhaFilho(fila_filho1, 1);
    empilharValoresPilhaFilho(fila_filho1, 2);
    empilharValoresPilhaFilho(fila_filho2, 3);
    empilharValoresPilhaFilho(fila_filho2, 4);

    empilharFilaPai(fila_pai, fila_filho1);
    empilharFilaPai(fila_pai, fila_filho2);

    imprimirFilaPai(fila_pai);


    return 0;
}

