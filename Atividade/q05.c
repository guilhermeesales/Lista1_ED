#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
5) Faça um programa que leia uma sequência de caracteres a exiba criptograficamente segundo as 
seguintes regras:
→ Toda não consoante é exibida diretamente
→ Toda sequência de consoantes é exibida na ordem inversa obtida
*/

typedef struct element {
    char word;
    struct element *prox;

} NO;


typedef struct {
    NO *inicio;
    int tam;

} Pilha;


typedef struct {
    NO *inicio;
    NO *fim;
    int tam;

} Fila;

void empilharPilha(Pilha *pilha, char valor) {
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->word = valor;
    novo->prox = NULL;

    if(pilha->inicio == NULL) {
        pilha->inicio = novo;

    } else {
        novo->prox = pilha->inicio;
        pilha->inicio = novo;

    }

    pilha->tam++;

}

char desempilhar(Pilha *pilha) {
    NO *lixo;
    char valor;     

    if(pilha->tam > 0) {
        lixo = pilha->inicio;
        valor = lixo->word;
        pilha->inicio = pilha->inicio->prox;
        free(lixo);
        
    } else {
        pilha->inicio = NULL;
    }

    pilha->tam--;
    return valor;

}


void imprimir(Pilha *pilha) {
    NO *aux = pilha->inicio;

    while(aux != NULL) {
        printf("%c\n", aux->word);
        aux = aux->prox;
    }

}

Pilha * iniciar_pilha() {
    Pilha *aux = malloc(sizeof(Pilha));
    aux->inicio = NULL;
    aux->tam = 0;
    return aux;
}


void inverterPalavras(char letra[2], char aux_palavra[100], Pilha *pilha) {
    char valor;
    if(pilha->inicio == NULL) { // Não houve empilhamento
        strcat(aux_palavra, letra);
    } else {
        while(pilha->inicio != NULL) {
            valor = desempilhar(pilha);
            char temp[2] = {valor, '\0'};
            strcat(aux_palavra, temp);

        }
        strcat(aux_palavra, letra);

    }   

}


int main() {
    Pilha *pilha = iniciar_pilha();
    char palavra[100];
    char aux_palavra[100] = "";
    int cont = 0;

    printf("\nDigite a palavra que deseja para criptografar: ");
    scanf("%s", palavra);

    while(cont < strlen(palavra)) {
        // vogais
        if(palavra[cont] == 'a') {
           inverterPalavras("a", aux_palavra, pilha);
           
        } 
               
        else if(palavra[cont] == 'e') {
            inverterPalavras("e", aux_palavra, pilha);


        } else if(palavra[cont] == 'i') {
            inverterPalavras("i", aux_palavra, pilha);


        } else if(palavra[cont] == 'o') {
            inverterPalavras("o", aux_palavra, pilha);


        } else if(palavra[cont] == 'u') {
            inverterPalavras("u", aux_palavra, pilha);


        } else { // é uma consoante
            int tam = strlen(palavra)-1;
            char valor;
            empilharPilha(pilha, palavra[cont]);
            if(palavra[tam] == pilha->inicio->word) {
                while(pilha->inicio!=NULL) {
                    valor = desempilhar(pilha);
                    char temp[2] = {valor, '\0'};
                    strcat(aux_palavra, temp);
                    
                }
            }
           
        }

        cont++;
    }
    
    printf("A palavra criptografada e: %s", aux_palavra);
    
    return 0;
}