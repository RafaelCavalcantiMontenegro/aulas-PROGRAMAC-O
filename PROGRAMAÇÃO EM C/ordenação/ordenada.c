#include <stdio.h>


void insert(int vetor[], int tamanho) {
    int troca;
    for (int i = 1; i < tamanho; i += 1 ) {
        int proximo = i, atual = proximo - 1
        while (proximo != 0 && vetor[proximo] < vetor[atual] ) {
            troca = vetor[atual];
            vetor[atual] = vetor[proximo];
            vetor[proximo] = troca;
        
        }
    }
}
