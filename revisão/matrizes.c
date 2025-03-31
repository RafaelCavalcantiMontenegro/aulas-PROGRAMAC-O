#include <stdio.h>

const int qtdlinhas = 100;
const int qtdcolunas = 200;

// Função para garantir que o número esteja dentro de um intervalo
int intervalo(int min, int max) {
    int num;
    do {
        printf("Digite um valor entre %d e %d: ", min, max);
        scanf("%d", &num);
    } while (num < min || num > max);
    return num;
}

// Função para preencher a matriz
void matriz(int m[][qtdcolunas], int linhas, int colunas) {
    for (int a = 0; a < linhas; a++) {
        for (int b = 0; b < colunas; b++) {
            printf("Digite o valor para a matriz m[%d][%d]: ", a + 1, b + 1);
            scanf("%d", &m[a][b]);
        }
    }
}

// Função para imprimir a matriz
void imprimir(int m[][qtdcolunas], int linhas, int colunas) {
    for (int a = 0; a < linhas; a++) {
        for (int b = 0; b < colunas; b++) {
            printf("%d\t", m[a][b]);
        }
        printf("\n");
    }
}

int main() {
    int m[qtdlinhas][qtdcolunas];  // Matriz com tamanho máximo fixado
    int linhas, colunas;
    
    // Solicita o número de linhas e colunas
    printf("Digite o número de linhas (máximo %d):\n", qtdlinhas);
    linhas = intervalo(1, qtdlinhas);

    printf("Digite o número de colunas (máximo %d):\n", qtdcolunas);
    colunas = intervalo(1, qtdcolunas);

    // Preenche a matriz
    matriz(m, linhas, colunas);

    // Imprime a matriz
    printf("\nMatriz inserida:\n");
    imprimir(m, linhas, colunas);

    return 0;
}
