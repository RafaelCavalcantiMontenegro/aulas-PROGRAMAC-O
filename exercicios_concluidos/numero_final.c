#include <stdio.h>

int main() {
    int contagem[10] = {0}; // Array para contar os dígitos finais (0 a 9)
    int numero, i;
    
    printf("Digite 1000 numeros:\n");
    for (i = 0; i < 1000; i+= 1) {
        scanf("%d", &numero);
        contagem[numero % 10]+= 1; // Incrementa o contador do último dígito
    }
    
    // Imprime a tabela
    printf("\nQuantidade de numeros terminados em cada digito:\n");
    for (i = 0; i < 10; i+= 1) {
        printf("Numeros terminados em %d: %d\n", i, contagem[i]);
    }
    
    return 0;
}
