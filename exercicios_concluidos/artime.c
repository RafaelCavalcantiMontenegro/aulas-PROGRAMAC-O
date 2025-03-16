#include <stdio.h>

int valor_inicial;
int crescimento;
int termos;

int main() {

    printf("Digite um valor inicial:\n");
    scanf("%d", &valor_inicial);

    printf("Digite um índice de crescimento:\n");
    scanf("%d", &crescimento);

    printf("Digite o número de termos:\n");
    scanf("%d", &termos);

    
    for (int i = 0; i < termos; i += 1) {
        printf("%d", valor_inicial); 
        if (i < termos - 1) {
            printf(", "); 
        }
        valor_inicial += crescimento; 
    }

    
    return 0;
}
