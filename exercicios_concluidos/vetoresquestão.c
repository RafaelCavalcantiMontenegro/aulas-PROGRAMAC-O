#include <stdio.h>

int main() {
    int numero[100]; 
    int soma = 0;
    int mult = 1;
    int menor;  

    
    for (int i = 0; i < 5; i++) {
        printf("Digite um número: ");
        scanf("%d", &numero[i]);

        
        if (numero[i] % 2 == 1) {
            mult *= numero[i]; 
        }
        
        
        if (numero[i] % 2 == 0) {
            soma += numero[i];  
        }
    } 

    
    menor = numero[0];  
    for (int i = 1; i < 5; i++) {
        if (numero[i] < menor) {
            menor = numero[i];  
        }
    }

    
    printf("A soma de todos os números pares é: %d\n", soma);
    printf("O produto de todos os números ímpares é: %d\n", mult);
    printf("O menor número é: %d\n", menor);

    return 0;
}
