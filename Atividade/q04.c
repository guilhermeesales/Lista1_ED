#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


/*
Implemente uma calculadora p?s-fixada, contendo as opera??es b?sicas (+, -, *, /). Dica: nota??o 
p?s-fixada ? aquela que se digita primeiro os numero depois os operandos (1 2 - 4 5 + * = -9).
*/

typedef struct calc {
    float num;
    struct calc *prox;

} NO;


typedef struct {
    NO *topo;
    int tam;

} Pilha;


void Empilhar(Pilha *pilha, float num) {
    NO *value = (NO*) malloc(sizeof(NO));
    value->num = num;
    value->prox = NULL;

    if(pilha->topo == NULL) {
        pilha->topo = value;
        pilha->tam++;


    } else {
        value->prox = pilha->topo;
        pilha->topo = value;
        pilha->tam++;


    }


}


int desempilhar(Pilha *pilha) {
    NO *lixo;
    int valor;

    if(pilha->tam > 0) {
        lixo = pilha->topo;
        valor = lixo->num;
        pilha->topo = pilha->topo->prox;
        free(lixo);
        pilha->tam--;
        return valor;

    } 
    


}

float saida(Pilha *pilha) {
    return pilha->topo->num;
}

void criarPilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->tam = 0;
}




int main() {
    setlocale(LC_ALL, "Portuguese");
    Pilha *pilha = malloc(sizeof(NO));
    criarPilha(pilha);
    float num1, num2;
    char n[80];
  
    
    printf("Calculadora Pos-Fixada:\n");
    do {

        printf("Insira a expressao para solucao: ");
        scanf("%s", &n);
        
        switch(*n){
            case '+':
                num1 = desempilhar(pilha);
                num2 = desempilhar(pilha);
                Empilhar(pilha, num2 + num1);
                break;

            case '-':
                num1 = desempilhar(pilha);
                num2 = desempilhar(pilha);
                Empilhar(pilha, num2 - num1);
                break;
            
            case '*':
                num1 = desempilhar(pilha);
                num2 = desempilhar(pilha);
                Empilhar(pilha, num2 * num1);
                break;

            case '/':
                num1 = desempilhar(pilha);
                num2 = desempilhar(pilha);
                Empilhar(pilha, num2 / num1);
                break;

            case 'q':
                break;

            default:
                Empilhar(pilha, atoi(n));
                break;
        }



    } while(*n!='q');

    printf("O resultado e: %f\n", saida(pilha));
    
    return 0;
}








