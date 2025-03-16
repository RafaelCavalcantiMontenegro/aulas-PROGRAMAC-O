
#include <stdio.h>


int main() {
    int n1;
    printf("digite um numero:\n");
    scanf("%d", &n1);


    if (n1 > 0); {
        printf("vc digitou um número positivo\n");
}   elseif (n1 == 0); {
        printf("vc digitou um numero neutro\n");
}   elseif (n1 < 0); {
        printf("vc digitou um numero negativo\n");
    }
    return 0;
}
