#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int idade;
    struct no *prox;
} no;

void inserirInicio (no **lista, int valor) {
    no *novono = (no *)malloc(sizeof(no));
    novono->idade = valor;
    novono->prox=*lista;
    *lista = novono;
}

void inserirFinal (no **lista, int valor) {
    no *novono = (no *)malloc(sizeof(no));
    novono->idade = valor;
    novono->prox=NULL;
    no *aux = *lista;
    if(aux == NULL){
        *lista = novono;
    }
    else{
        while (aux->prox != NULL){
            aux=aux->prox;
        }   
        aux->prox=novono;
    }
}

void deletarNo(no **lista, int valor){
    no *aux = *lista;
    no *auxant = *lista;
    
    if(aux == NULL){
        printf("Lista está vazia\n");
    }else{
        if(aux -> idade == valor){
            *lista = aux->prox;
            free(aux);
        }else{
            while(aux != NULL && aux->idade != valor){
                auxant = aux;
                aux = aux -> prox;
            }
            if(aux == NULL){
                printf("Valor %d não está na lista\n", valor);   
            }else{
                auxant->prox = aux -> prox;
                free(aux);    
            }
        }
    }
}

void printList (no *lista) {
    no *aux = lista;
    printf("COMEÇO | ");
    while(aux != NULL){
        printf("%d -> ", aux->idade);
        aux = aux->prox; 
    }
    printf("NULL");
    printf(" | FINAL\n");
}

int main() {
    no *lista = NULL;
    inserirFinal(&lista, 10);
    inserirInicio(&lista, 20);
    inserirFinal(&lista, 30);
    inserirInicio(&lista, 40);
    inserirFinal(&lista, 50);

    printList(lista);

    return 0;
}
