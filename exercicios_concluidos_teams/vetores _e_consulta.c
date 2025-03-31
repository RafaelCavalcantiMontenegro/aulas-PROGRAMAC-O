#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CriarVetor(int vetor[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }
}

void OrdenarVetor(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int x = vetor[i];
        int pos = i;
        
        while (pos > 0 && x < vetor[pos - 1]) {
            vetor[pos] = vetor[pos - 1];
            pos--;
        }
        vetor[pos] = x;
    }
}

void inserirOrdenado(int vetor[], int *tamanho, int x) {
    if (*tamanho >= 50) {
        printf("Vetor cheio! Não é possível inserir.\n");
        return;
    }
    
    int pos = *tamanho;
    while (pos > 0 && x < vetor[pos - 1]) {
        vetor[pos] = vetor[pos - 1];
        pos--;
    }
    vetor[pos] = x;
    (*tamanho)++;
}

int BuscarBinario(int vetor[], int tamanho, int numero) {
    int inicio = 0, fim = tamanho - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == numero) {
            return meio;
        } else if (vetor[meio] > numero) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;
}

void removerValor(int vetor[], int *tamanho, int valor) {
    if (*tamanho == 0) {
        printf("Vetor vazio!\n");
        return;
    }
    
    int pos = BuscarBinario(vetor, *tamanho, valor);
    if (pos == -1) {
        printf("Valor não encontrado!\n");
        return;
    }
    
    for (int i = pos; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
    printf("Remoção efetuada com sucesso!\n");
}

void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    int x;
    int numero;
    int resultado;
    
    printf("Digite o tamanho do vetor entre 3 e 50: ");
    scanf("%d", &tamanho);
    
    if (tamanho < 3 || tamanho > 50) {
        printf("Tamanho inválido!\n");
        return 1;
    }

    int vetor[50]; 

    CriarVetor(vetor, tamanho);
    printf("Vetor gerado aleatoriamente:\n");
    imprimirVetor(vetor, tamanho);

    OrdenarVetor(vetor, tamanho);
    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    printf("Digite um número para buscar: ");
    scanf("%d", &numero);
    
    resultado = BuscarBinario(vetor, tamanho, numero);
    if (resultado != -1) {
        printf("Número encontrado na posição %d\n", resultado);
        removerValor(vetor, &tamanho, numero);
        printf("Vetor após remoção:\n");
        imprimirVetor(vetor, tamanho);
    } else {
        printf("Número não encontrado\n");
    }

    printf("Digite um valor para inserir: ");
    scanf("%d", &x);
    inserirOrdenado(vetor, &tamanho, x);
    printf("Vetor após inserção:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}