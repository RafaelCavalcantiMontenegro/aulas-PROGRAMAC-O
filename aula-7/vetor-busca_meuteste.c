#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int QTD;

void preencherVetorAleatório(int vetor[QTD]) {
    for (int i = 1; i <= QTD; i += 1 ) {
        vetor[i] = rand() +1;
    }
}

void imprimirvetor(int vetor[QTD]) {
    for (int i = 1; i <= QTD; i += 1 ) {
        printf("vetores: %d\n", vetor[i]);
        printf("\n");
    }
}

void busca(int vetor[QTD], int x) {
    for (int i = 0; i <= QTD; i += 1) {
        if (vetor[i] == x) {
            return i;
        }
    }
}



int main() {
    int numero[QTD];
    int numeros;
    srand(time(NULL));
    printf("RAND_MAX = %d\n", RAND_MAX);
    for(int i = 1; i <= 100; i += 1) {
        printf("Aleatório = %d\t", rand() % 1000 + 1);
    preencherVetorAleatório(numeros);
    imprimirvetor(numeros);
    }

    
    
    

    
        
    
    return 0;
}
