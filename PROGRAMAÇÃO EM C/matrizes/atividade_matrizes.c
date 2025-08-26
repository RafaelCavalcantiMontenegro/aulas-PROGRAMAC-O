#include <stdio.h>


const int qtdlinhas = 100;

const int qtdcolunas = 200;

int intervalos(int min, int max) {
    int numero;

    do {

    
    scanf("%d", &numero);

    }while (numero < 1 || numero > 200);

    return numero;
}


void preencherVetor(int vetor[][qtdcolunas], int linhas, int colunas){
    int valor;
    for (int j = 0; j < colunas; j +=1){
        for (int i = 0; i < linhas; i +=1){
            printf("matriz[%d][%d]", i + 1, j + 1 );
            scanf("%d", &vetor[i][j]);
        }
    }
}

void imprimirVetor(int vetor[][qtdcolunas], int linhas, int colunas) {
    for (int j = 0; j < colunas; j += 1) {
        for (int i = 0; i < linhas; i +=1) {
            printf("%d\t", vetor[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int linhas, colunas;
    int vetor[qtdlinhas][qtdcolunas];
    printf("digite o numero de linhas\n");
    linhas = intervalos(1,qtdlinhas);
    printf("digite o numero de colunas\n");
    colunas = intervalos(1,qtdcolunas);
    preencherVetor(vetor,linhas,colunas);
    imprimirVetor(vetor, linhas, colunas);

    return 0;
}