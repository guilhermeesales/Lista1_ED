#include <stdio.h>
#include <stdlib.h>

/*

O token é um valor inteiro positivo
Regra: quanto maior o token, maior a prioridade
Lista não ordenada

*/


typedef struct element {
    int valor;
    struct element *prox;
    struct element *ant;
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
    novo->ant = NULL;

    if(fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;

    } else {
        // 1, 2, 5, 10, 20, 100
        fila->fim->prox = novo;
        novo->ant = fila->fim;
        fila->fim = novo;

    }
    fila->tam++;

}

int maiorValor(Fila *fila) {
    NO *aux = fila->inicio;
    int maior_valor = aux->valor;

    while(aux != NULL) {
        if(aux->valor > maior_valor) {
            maior_valor = aux->valor;
        }
        aux = aux->prox;

    }
    
    return maior_valor;

}


int removerComPrioridade(Fila *fila){
    NO *lixo;
    int valor;
    int maior_valor = maiorValor(fila);


    if(fila->tam > 0) {
        if(fila->inicio->valor == maior_valor) { // Remover no inicio
            lixo = fila->inicio;
            valor = lixo->valor;
            fila->inicio = fila->inicio->prox;
    
        } else if(fila->fim->valor == maior_valor) { // Remover no fim
            lixo = fila->fim; 
            valor = lixo->valor;
            fila->fim = fila->fim->ant;
            fila->fim->prox = NULL;

        } else { // Remover no meio
            lixo = fila->inicio;

            while(lixo->valor != maior_valor) {
                lixo = lixo->prox;
            }

            valor = lixo->valor;
            lixo->ant->prox = lixo->prox;
            lixo->prox->ant = lixo->ant;

        }
        fila->tam--;
        free(lixo);
        return valor;





    }
}

void teste(Fila *fila) {
    printf("%d", fila->fim->ant->valor);


}


void imprimir(Fila *fila) {
    if (fila->tam == 0) {
        printf("Fila vazia!\n");
        return;
    }
    NO *aux = fila->inicio;

    while(aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    printf("O tamanho da fila e %d\n", fila->tam);
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

    empilharFila(fila, 350);
    empilharFila(fila, 10);
    empilharFila(fila, 1);
    empilharFila(fila, 12);
    empilharFila(fila, 20);
    empilharFila(fila, 400);
    empilharFila(fila, 50);
    empilharFila(fila, 100);
    removerComPrioridade(fila);
    removerComPrioridade(fila);
    removerComPrioridade(fila);
    removerComPrioridade(fila);
    removerComPrioridade(fila);
    imprimir(fila);
    


    return 0;
}