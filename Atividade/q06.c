#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int valor;
    struct element *prox;

} NO;


typedef struct {
    NO *inicio;
    int tam;

} Pilha;


void empilhar(Pilha *pilha, int valor) {
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(pilha->inicio == NULL) {
        pilha->inicio = novo;

    } else {
        novo->prox = pilha->inicio;
        pilha->inicio = novo;

    }

    pilha->tam++;

} 


int desempilhar(Pilha *pilha) {
    NO *lixo;
    int valor; 

    if(pilha->tam > 0) {
        lixo = pilha->inicio;
        valor = lixo->valor;
        pilha->inicio = pilha->inicio->prox;

    } else {
        pilha->inicio = NULL;
    }

    free(lixo);
    pilha->tam--;
    return valor;
}


void imprimir(Pilha *pilha) {
    NO *aux = pilha->inicio;

    while(aux != NULL) {
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }

}

Pilha *iniciar() {
    Pilha *aux = malloc(sizeof(Pilha));
    aux->inicio = NULL;
    aux->tam = 0;
    return aux;
}

void removerPorChave(Pilha *pilha, int chave) {
    Pilha *pilha_aux = iniciar();
    int encontrado = 0;

    while(pilha->inicio != NULL) {
        int valor = desempilhar(pilha);
        if(valor != chave) {
            empilhar(pilha_aux, valor);

        } else {
            encontrado = 1;
        }

    }

    if(encontrado) {
        while(pilha_aux->inicio != NULL) {
            int valor = desempilhar(pilha_aux);
            empilhar(pilha, valor);
        }

    } else {
        printf("Nao achamos esse valor na Pilha!");
    }
    
}

  

int main() {
    Pilha *pilha = iniciar();

    empilhar(pilha, 3);
    empilhar(pilha, 5);
    empilhar(pilha, 7);
    empilhar(pilha, 8);


    removerPorChave(pilha, 7);
    imprimir(pilha);
    

    return 0;
}