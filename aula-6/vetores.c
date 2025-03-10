// vetores: tipo vetor [capacidade];
// acesso : vetor[indice]
#include <stdio.h>

const int QTD_ALUNOS = 5;


int main() {

    double notas[5];
    double somatorio = 0.0, media;

    for (int i = 0; i < QTD_ALUNOS; i += 1) {
        printf("Digite a mota %d: ", i + 1);
        scanf("%lf", &notas[i]);
        somatorio += notas[i];
    }
    
    
    media = somatorio / QTD_ALUNOS;
    printf("\nMedia da turma: %2.f\n", media);

    printf("\nImpressao de todas as notas da turma\n");
    for (int i = 0; i < QTD_ALUNOS; i += 1) {
        printf("Nota %d:%.2f\n", i +1, notas[i]);
        
    }
    printf("\nImpressao de todas as notas acima da media da turma\n");
    for (int i = 0; i < QTD_ALUNOS; i += 1) {
      if (notas[i] > media) {
        printf("Nota %d: %.2f\n", i + 1, notas[i]);
      }
    }
  return 0;
}