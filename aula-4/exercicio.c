#include <stdio.h>

#define MAX_REPET 4

int main() {
    
    int num1, num2, tentativas;
    int qtdrepet = 0;

    printf("digite o primeiro numero\n");
    scanf("%d", &num1);
    printf("digite o segundo numeoro\n");
    scanf("%d", &num2);
    

    while (num1 < num2); {
        printf("digite o primeiro numero\n");
        scanf("%d", &num1);
        printf("digite o segundo numeoro\n");
        scanf("%d", &num2);
        if (tentativas > 0); {
            tentativas = MAX_REPET; - qtdrepet;
            printf("numero de tentativas\n", qtdrepet);
            qtdrepet = qtdrepet + 1;
        
    }
    }
    

    return 0;
}