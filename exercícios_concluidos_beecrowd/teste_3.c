#include <stdio.h>

int main() {
    int par[5], impar[5];  
    int capacidade_par = 0, capacidade_impar = 0;  
    int numeros[15];  

   
    for (int i = 0; i < 15; i++) {
        scanf("%d", &numeros[i]);
    }

    
    for (int i = 0; i < 15; i++) {
        if (numeros[i] % 2 == 0) {  
            par[capacidade_par] = numeros[i];
            capacidade_par++;

            if (capacidade_par == 5) {  
                for (int j = 0; j <= 4; j++) {
                    printf("par[%d] = %d\n", j, par[j]);
                }
                capacidade_par = 0;  
            }
        } else {  
            impar[capacidade_impar] = numeros[i];
            capacidade_impar++;

            if (capacidade_impar == 5) {  
                for (int j = 0; j <= 4; j++) {
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                capacidade_impar = 0;  
            }
        }
    }

    
    for (int j = 0; j < capacidade_impar; j++) {
        printf("impar[%d] = %d\n", j, impar[j]);
    }

    for (int j = 0; j < capacidade_par; j++) {
        printf("par[%d] = %d\n", j, par[j]);
    }

    return 0;
}
