#include <stdio.h>
#include <stdlib.h>


/*
3) Uma empilhadeira carrega caixas de 7, 5, 3 toneladas. Há três pilhas A, B, C. A pilha A é onde se 
encontram todas as caixas que chegam no depósito. Com um detalhe: caixas maiores não podem ser 
empilhadas sobre caixas menores. Elabore um programa que efetue o controle das caixas, de forma 
que caso uma caixa de maior peso do que uma que já está em A deva ser empilhada, então, todas as 
caixas que estão em A são movidas para as pilhas auxiliares B (contendo somente caixa de 5 
toneladas) e C (contendo somente caixas de 3 toneladas) até que se possa empilhar a nova caixa. 
Depois, todas as caixas são movidas de volta para a pilha A

*/

typedef struct element {
    int valor;
    struct element *prox;
} NO;


typedef struct pilha {
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

    if(pilha->tam > 0) { // Existe elementos na Pilha
        lixo = pilha->inicio;
        valor = lixo->valor;

        pilha->inicio = pilha->inicio->prox;
        free(lixo);

    } else {
        pilha->inicio = NULL;
        printf("Não há elementos na pilha!\n");

    }

    pilha->tam--;
    return valor;

}


void imprimir(Pilha *pilha) {
    NO *aux = pilha->inicio;

    while(aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }

}


Pilha *iniciar_pilha() {
    Pilha *aux = (Pilha*) malloc(sizeof(Pilha));
    aux->inicio = NULL;
    aux->tam = 0;
    return aux;
}


void Pesos(Pilha *A, Pilha *B, Pilha *C, int peso) {
    // Regras: Pilha deve finalizar na Pilha A,
    // B: somente caixa de 5 toneladas
    // C: somente caixa de 3 toneladas

    if(A->inicio == NULL) {
        empilhar(A, peso);

    } else if(A->inicio->valor >= peso){
        empilhar(A, peso);

    
    } else { // O peso é menor que os que já estão empilhados
        int valor;
        while(A->inicio != NULL && A->inicio->valor < peso) {
            if(A->inicio->valor == 5) {
                valor = desempilhar(A);
                add(valor, B);

            }  else if(A->inicio->valor == 3) {
                valor = desempilhar(A);
                add(C, valor);

            }

        while (B->inicio != NULL && A->inicio->valor >= B->inicio->valor){   
            int valorB = remover(B);
            add(valorB, A);
        }

        }
        while (C->inicio != NULL && A->inicio->valor >= C->inicio->valor){
            int valorC = remover(C);
            add(valorC, A);
        }

        }
        empilhar(A, peso);

        
    }



int main() {
    Pilha *A = iniciar_pilha();
    Pilha *B = iniciar_pilha();
    Pilha *C = iniciar_pilha();



    return 0;
}