/*
Atividade de HEAP @GuilhermeSales - 540451

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8

int size = MAX_SIZE;


int T[MAX_SIZE];
int n = 0;


void subir(int i){
    int j = i/2;  
    if(j >= 1){
        if(T[i] > T[j]){
            int aux = T[i];
            T[i] = T[j];
            T[j] = aux;
            subir(j);
        }
    }
}

void descer(int i, int n) {
    /*
        Observações: SE o elemento é o primeiro, então 2*1 é filho da esquerda e 2*1+1 é o filho da direita
    */
    int j = 2*i;

    if(j <= n) {  // Se não estoura a lista, entra!
        if(j < n) {
            if(T[j+1] > T[j]) { // Verifica Se o filho da direita é maior que o da esquerda
                j++; 
            }
        }
    
        if(T[i] < T[j]) { // Se a raiz for menor que o filho, faz a alteração
            int aux = T[i];
            T[i] = T[j];
            T[j] = aux;
            descer(j,n); // Processo Recursivo
        }

    }

}


void inserir(int chave) { 
    if(n < MAX_SIZE) {
        T[n+1] = chave;
        n++;
    }
    subir(n);

}


int remover() {
    int valor = -1;
    if(n != 0){
        valor = T[1];
        T[1] = T[n];
        T[n] = 0;
        n--;
        size--;
        
        descer(1,n);   
        
    } 

    return valor;
}

void printRemover() {
    printf("O valor removido foi: %d\n", remover());

}


int main() {
    int qtdRemovido;
    // Oito inserções
    inserir(10);
    inserir(50);
    inserir(30);
    inserir(1);
    inserir(5);
    inserir(20);
    inserir(17);
    inserir(11);
    // Duas remoções
    printRemover();    
    printRemover();
  
    printf("Array da MAX-HEAP:");
    for(int i=0; i<size; i++) {
        printf(" %d,", T[i+1]);
    }


    return 0;
}