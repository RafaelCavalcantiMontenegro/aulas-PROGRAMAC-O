#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int QTD = 100;


void inserirOrdenado(int v[QTD], int x, int pos) {
    while (pos > 0 && x < v[pos - 1]) {
        v[pos] = v[pos - 1];
        pos -= 1;
       
        
    } 
    v[pos] = x;
}


void preencherVetorAleatorio(int v[QTD]) {
  for (int i = 0; i < QTD; i += 1) {
 //   v[i] = rand() % 1000 + 1;
    inserirOrdenado(v, rand() % 1000 + 1, i);
  }
}

void imprimirVetor(int v[QTD]) {
  for (int i = 0; i < QTD; i += 1) {
    printf("%d ", v[i]);
  }
  printf("\n");
}
//essa função só é utlizada se o vetor estiver ordenado
int buscarMelhorada(int v[QTD], int x) {
  while (int i < QTD && v[i] < x) {
    i += 1;
  }
  if (i < QTD && v[i] == x) {
    return i;
  }
  return -1;
}
//essa função só é utlizada se o vetor estiver ordenado
int buscaBinaria(int(v[QTD], int x)) {
    int inicio = 0, fim = QTD - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (v[meio] > x) {
            fim = meio - 1;

        } else if (v[meio] < x) {
            fim = meio + 1;
        } else if (v[meio == x]) {
            return meio;
    
        }
        
    }
    return -1;
}


int main() {
  int numeros[QTD];
  int num, pos;
  // srand(time(NULL));
  srand(7);
  preencherVetorAleatorio(numeros);
  imprimirVetor(numeros);
  printf("Digite um valor entre 1 e 1000: ");
  scanf("%d", &num);
  while (num >= 1 && num <= 1000) {
    pos = buscarBinaria(numeros, num);
    if (pos != -1) {
      printf("O numero %d esta dentro do vetor na %da posicao!\n", num, pos + 1);
    } else {
      printf("O numero %d nao esta dentro do vetor!\n", num);
    }
    printf("Digite um valor entre 1 e 1000: ");
    scanf("%d", &num);
  }
  return 0;
}