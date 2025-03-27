//matrizes, temos um [] para linhas e outro para colunas, resultado n[][]
// printf("%d", n[1][3])

#include <stdio.h>

const int i = 4;

const int j = 3;

void matriz(int m[][],int i,int j) {
    
    for (int i = 0; i < 4; i +=1){
        for (int j = 0; j < 3; j +=1) {
            printf("digite a matriz n[%d][%d]", i +1, j +1);
            scanf("%d", &m[i][j]);

        }
    }
    
}
void imprimir(matriz, i, j){
    for (int i = 0; i < 4; i +=1){
        for (int j = 0; j < 3; j +=1) {
            print("%d\t", &m[i][j]);
        }
        printf("\n");
    }        
}

int main ( ) {
    matriz(m[][], i, j);
    imprimir(matriz, i, j);
    prinf(imprimir);

    return 0;
}