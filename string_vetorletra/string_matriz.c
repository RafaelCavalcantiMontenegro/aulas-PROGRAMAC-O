#include <stdio.h>
#include <string.h>

void lerStr(char *str, int count);

int main(){
    int const TAM_NOMES = 10;
    int const QTD_PESSOAS = 5;
    char nomes[QTD_PESSOAS][TAM_NOMES];
    
    

    for (int i = 0; i <  QTD_PESSOAS; i +=1) {
        printf("Digite um nome[%d]: ", i +1);
        lerStr(nomes[i], TAM_NOMES);

    }

    printf("Quantidade de nomes:\n ");
    for (int i = 0; i < TAM_NOMES; i +=1) {
        printf("nomes[%d] = %s\n", i , nomes[i]);
    }
    return 0;
}

void lerStr(char *str, int count) {
    fgets(str, count, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
      str[tam - 1] = '\0';
    }
  }