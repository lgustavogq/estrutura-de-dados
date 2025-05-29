#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *NUM, int tam){
    printf("Array:");
    for(int k = 0; k < tam; k++){
        printf(" %d", NUM[k]);
    }
    printf("\n");
}

void troca(int *NUM, int i, int j){
    int aux = NUM[i];
    NUM[i] = NUM[j];
    NUM[j] = aux;
}

void bubble_sort(int *NUM, int tam){
    for(int j = 0; j <= tam - 2; j++){
        for(int i = 0; i <= tam - 2 - j; i++){
            if(NUM[i] > NUM[i + 1])
                troca(NUM, i, i+1);
        }
    }
}

void selection_sort(int *NUM, int tam){
    for(int j = 0; j < tam-2; j++){
        int ind_min = j;
        for(int i = j + 1; i <= tam - 1; i++){
            if(NUM[i] < NUM[ind_min])
                ind_min = i;
        }
        troca(NUM, j, ind_min);
    }
    
}

void insertion_sort(int *NUM, int tam){
    for(int i = 1; i <= tam - 1; i++){
        int j = i;
        while(NUM[j] < NUM[j - 1] && j > 0){
            troca(NUM, j, j - 1);
            j--;
        }
    }
}

int main(){
    // Inicializa o randomizador para usar valores diferentes
    srand(time(NULL));
    
    // Usuário declara qual o tamanho do vetor
    int tamanhoVetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);
    
    // Inicializa a variável com o espaço de memória necessário do vetor
    int *NUM = (int*)malloc(tamanhoVetor*sizeof(int));
    
    // Adiciona valores aleatórios ao vetor
    for(int k = 0; k < tamanhoVetor; k++){
        NUM[k] = rand() % 100 + 1;
    }
    
    // Imprime o vetor não ordenado
    printArray(NUM, tamanhoVetor);
    
    // Metódos de ordenação
    // BUBBLE SORT: percorre o vetor verificando valores adjacentes e movendo os maiores valores e colocando ao final
    bubble_sort(NUM, tamanhoVetor);
    
    // SELECTION SORT: percorre o vetor verificando o menor valor e move o menor valor à casa certa 
    selection_sort(NUM, tamanhoVetor);
    
    // INSERTION SORT: percorre o vetor e o separa entre uma parte ordenada e outra não ordenado e a cada iteração verifica o vetor ordenado e move o valor não ordenado para o índice certo
    insertion_sort(NUM, tamanhoVetor);
    
    // Imprime o vetor ordenado
    printArray(NUM, tamanhoVetor);
    
    return 0;
}