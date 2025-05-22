#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int idade;
    struct no *prox;
} no;

void push (no **pilha, int valor) {
    no *novono = (no *)malloc(sizeof(no));
    novono->idade = valor;
    novono->prox=*pilha;
    *pilha = novono;
}

int pop(no **pilha){
    if(*pilha == NULL){
        printf("Impossível remover, pilha vazia!\n");
        return -1;
    }else{
        int id;
        no *aux = *pilha;
        id = aux -> idade;
        *pilha = (*pilha) -> prox;
        free(aux);
        return id;    
    }
}


void printPilha (no *pilha) {
    no *aux = pilha;
    printf("COMEÇO | ");
    while(aux != NULL){
        printf("%d -> ", aux->idade);
        aux = aux->prox; 
    }
    printf("NULL");
    printf(" | FINAL\n");
}

int main() {
    no *pilha = NULL;
    push(&pilha, 15);
    push(&pilha, 30);
    push(&pilha, 45);
    push(&pilha, 60);
    printPilha(pilha);
    
    printf("Item removido: %d\n", pop(&pilha));
    
    printPilha(pilha);
    
    return 0;
}