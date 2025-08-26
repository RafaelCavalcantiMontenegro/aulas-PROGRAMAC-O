#include <stdio.h>
#include <time.h>
int i, j;



void preencherVetorAleatorio(int v[i]) {
    for (int i = 0; i < tam; i += 1) {
   //   v[i] = rand() % 1000 + 1;
      inserirOrdenado(v, rand() % 1000 + 1, i);
    }
}

// insere o elemento que está certo no meio dos que estão errados para ordenar o código
void insercao (int v[i])
for (int i = 0; i < tam; i += 1) { 
    tmp = v[i]; //variavel temporaria
    j = i - 1; // margem de checagem
    while ( j > 0 && v[j] > tmp) {
        v[j + 1] = v[j]; // copia a variavel do vetor j e cola no elemento seguinte
        j = j - 1; // faz o j voltar uma casa
    }
    v[j + 1] = tmp; // transforma o elemento seguinte a j no valor maior, deixando ordenado
}

void imprimirVetor(int v[i]) {
    for (int i = 0; i < tam; i += 1) {
      printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {

    insercao(int v[i]);
    return 0;
}