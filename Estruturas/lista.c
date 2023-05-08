#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


typedef struct novo {
    int valor;
    struct novo *prox;
    struct novo *ant;

} NO;

typedef struct {
    NO *inicio;
    NO *fim;
    int tam;

} Lista;


void inserirElementos(Lista *lista, int pos, int valor) {
    NO *novo_elemento = (NO*) malloc(sizeof(NO));
    novo_elemento->valor = valor;
    novo_elemento->ant = NULL;
    novo_elemento->prox = NULL;

    if(pos >= 0 && pos <= lista->tam) {
        if(lista->inicio == NULL && lista->fim == NULL) {
            lista->inicio = novo_elemento;
            lista->fim = novo_elemento;
        } else {
             // Lista inicio guarda um endereço reservado com o malloc

            if(pos == 0) { // inicio
                novo_elemento->prox = lista->inicio;
                lista->inicio->ant = novo_elemento;
                lista->inicio = novo_elemento;

            } else if(pos == lista->tam) { // Final da lista
                lista->fim->prox = novo_elemento;
                novo_elemento->ant = lista->fim;
                lista->fim = novo_elemento;

            } else { // Meio da lista
                NO *aux = lista->inicio;

                for(int i = 0; i < pos; i++) {
                    aux = aux->prox;
                }

                // Operação 1
                novo_elemento->prox = aux;
                novo_elemento->ant = aux->ant;
                // Operação 2
                aux->ant->prox = novo_elemento;
                aux->ant = novo_elemento;

              
            }
        
        }
        lista->tam++;

    }

}


int removerElementos(Lista *lista, int pos) {
    NO *lixo; 
    int valor;

    if(pos >= 0 && pos <= lista->tam) {
        if(pos == 0) { // Inicio
            lixo = lista->inicio;
            valor = lixo->valor;
            lista->inicio = lista->inicio->prox;
            
        } else if(pos == lista->tam) { // Final
            lixo = lista->fim;
            valor = lixo->valor;
            lista->fim = lista->fim->ant;
           
        } else { // Meio 
            for(int i = 0; i < pos; i++) {
                lixo = lixo->prox;
            }

            valor = lixo->valor;
            // Operação 1
            lixo->ant->prox = lixo->prox;
            // Operação 2
            lixo->prox->ant = lixo->ant;
        
        }
        
        free(lixo);
        lista->tam--;
        return valor;


    }


}


void imprimir(Lista *lista) {
    NO *aux = lista->inicio;

    while(aux != NULL) {    
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }

    printf("Tamanho da lista: %d\n", lista->tam);
}



int main() {
    setlocale(LC_ALL, "Portuguese");
    Lista lista;
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;

    inserirElementos(&lista, 0, 1);
    inserirElementos(&lista, 0, 2);
    inserirElementos(&lista, 0, 3);
    inserirElementos(&lista, 0, 4);
    inserirElementos(&lista, 1, 5);
    inserirElementos(&lista, 5, 10);
    removerElementos(&lista, 0);
    removerElementos(&lista, 2);
    removerElementos(&lista, 1);
    imprimir(&lista);

    return 0;

    // 100% works

}