#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void CriarVetor(int tamanho, int vetor[]) {
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho < 3 || tamanho > 50) {
        printf("Tamanho inválido!\n");
        return 1;
    }

    int vetor[tamanho];
    srand(time(NULL));

    
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
        
    }
    
}

void VetorOrdenado(int v[], int tamanho, int x) {
    int pos = 0;
    while (pos < tamanho && x > v[pos]) {
        pos++;
    }
    for (int i = tamanho; i > pos; i--) {
        v[i] = v[i - 1];
    }
    v[pos] = x;
}

int BuscarBinario(int vetor[], int tamanho, int numero){
    printf("Digite um número para buscar: ");
    scanf("%d", &numero);
    int inicio = 0, fim = tamanho - 1, meio;
    while (inicio <= fim){
        meio = (inicio + fim) / 2;
        if (numero < vetor[meio]) {
            fim = meio - 1;
        } else if (numero > vetor[meio]) {
            inicio = meio +1;
        } else {
            return meio; // Retorna a posição do número encontrado
        }
    }
    return -1; // Número não encontrado
}

void removerValor(int vetor[], int *cont, int valor){
    int pos = BuscarBinario(vetor, *cont, valor);
    if (*cont == 0) {
        printf("Vetor vazio!\n");
        return;
    }
    if (pos >= 0) {
        for (int i = pos; i < *cont - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        (*cont)--;
        printf("Remocao efetuada com sucesso!\n");
    } else {
        printf("Valor nao encontrado!\n");
    }
}

void imprimirVetor(vetor[i]) {
    for (int i = 0; i < tamanho; i += 0){
        printf("%d",v[i]);
    }
}




int main() {
    

    CriarVetor(tamanho, vetor[]);
    VetorOrdenado(vetor[], tamanho, x);
    int resultado = BuscarBinario(vetor, tamanho, numero);
    
    if (resultado != -1) {
        printf("Número encontrado na posição %d\n", resultado);
    } else {
        printf("Número não encontrado\n");
    }
    for (int i = 0; i < tamanho; i++) {  
        if (vetor[i] == resultado) {
            removerValor(vetor, &tamanho, resultado);  
        }
    }

    return 0;
}
