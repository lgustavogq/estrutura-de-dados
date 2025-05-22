#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int idade;
    struct no *prox;
} no;

void push (no **fila, int valor) {
    no *novono = (no *)malloc(sizeof(no));
    novono->idade = valor;
    novono->prox=NULL;
    no *aux = *fila;
    if(aux == NULL){
        *fila = novono;
    }
    else{
        while (aux->prox != NULL){
            aux=aux->prox;
        }   
        aux->prox=novono;
    }
}

int pop(no **fila){
    if(*fila == NULL){
        printf("Impossível remover, pilha vazia!\n");
        return -1;
    }else{
        int id;
        no *aux = *fila;
        id = aux -> idade;
        *fila = (*fila) -> prox;
        free(aux);
        return id;    
    }
}

void printFila (no *fila) {
    no *aux = fila;
    printf("COMEÇO | ");
    while(aux != NULL){
        printf("%d -> ", aux->idade);
        aux = aux->prox; 
    }
    printf("NULL");
    printf(" | FINAL\n");
}

int main() {
    no *fila = NULL;
    
    push(&fila, 15);
    push(&fila, 30);
    push(&fila, 45);
    push(&fila, 60);
    push(&fila, 75);
    push(&fila, 90);
    
    printFila(fila);
    
    printf("Item removido: %d\n", pop(&fila));
    
    printFila(fila);
    
    return 0;
}