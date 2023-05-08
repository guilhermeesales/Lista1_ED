#include <stdio.h>
#include <stdlib.h>

/*

O token é um valor inteiro positivo
Regra: quanto maior o token, maior a prioridade
Lista ordenada

*/


typedef struct element {
    int valor;
    struct element *prox;

} NO;

typedef struct fila {
    NO *inicio;
    NO *fim;
    int tam;

} Fila;


void empilharFila(Fila *fila, int valor) {
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;

    } else {
        NO *aux;
        if(fila->inicio->valor < novo->valor) { // Inicio
            // 5, 6, 8, 10
            novo->prox = fila->inicio;
            fila->inicio = novo;


        } else if(fila->fim->valor > novo->valor) {  // Fim
            // 10, 8, 6, 5
            fila->fim->prox = novo;
            fila->fim = novo;


        } else {
            // 10, 6, 8, 5
            aux = fila->inicio;

            while(aux->prox->valor > novo->valor) {
                aux = aux->prox;
            }

            
            novo->prox = aux->prox;
            aux->prox = novo;


        }
            

        }

        fila->tam++; 

    }


int removerPrioridade(Fila *fila) {
    NO *lixo;
    int valor;

    if(fila->tam > 0) {
        lixo = fila->inicio;
        valor = lixo->valor;

        fila->inicio = fila->inicio->prox;

        free(lixo);

    }

    fila->tam--;
    return valor;

}


        


void imprimir(Fila *fila) {
    NO *aux = fila->inicio;
    while(aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    printf("O tamanho da fila e: %d\n", fila->tam);

}


Fila *iniciar_fila() {
    Fila *aux = (Fila*) malloc(sizeof(Fila));
    aux->inicio = NULL;
    aux->fim = NULL;
    aux->tam = 0;
    return aux;

}


int main() {
    Fila *fila = iniciar_fila();

    empilharFila(fila, 200);
    empilharFila(fila, 1);
    empilharFila(fila, 10);
    empilharFila(fila, 6);
    empilharFila(fila, 100);
    removerPrioridade(fila);

    imprimir(fila);



    return 0;
}

