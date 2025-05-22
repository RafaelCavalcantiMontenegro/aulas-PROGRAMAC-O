/* feof = acabou os dados do arquivo
    wb criar um arquivo (sempre substitui/ destroi o anterior)
    rb, cria 
    fseek( arq, qtd_bytes, posição);
    fwrite(&NUMEROS,sizeof(int), tamanho, arq);
    fread(&NUMEROS,sizeof(int), tamanho, arq);
 */



#include <stdio.h>

#define TAM 10

int main() {
    int NUMEROS = [1,2,3,4,5,6,7,8,9,10]
    int status;
    FILE *arq = fopen("numerosVetor.bin", "rb");

    if (arq == NULL) {
        printf("não conseguiu");
        return 1;

    }

    status = fwrite(&NUMEROS,sizeof(int), TAM, arq);
    
    if (status == TAM) {
        printf("num1 gravado com sucesso\n");
    }


    if (fclose(arq) == 0) {
        printf("fechou com sucesso\n");

    }else {
        printf("nn fechou com sucesso\n");
    }


    status = fread(&NUMEROS,sizeof(int), TAM, arq);

    if (status != TAM) {
        printf("erro ao ler o vetor\n");
    }
    
    
    


    if (fclose(arq) == 0) {
        printf("fechou com sucesso\n");

    }else {
        printf("nn fechou com sucesso\n");
    }


    return 0;
}