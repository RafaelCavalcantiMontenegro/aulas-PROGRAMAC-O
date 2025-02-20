// %d significa valor inteiro
// %2.f serve para valores float
// %c serve para caracteres
// scanf é o input do C

#include <stdio.h>

int main(){
    int n1;
    double n2;
    char letra = 'a', letra2 = 'b';
    printf("digite o valor inteiro:");
    scanf("%d", &n1);

    printf("digite o valor real:");
    scanf("%lf", &n2);

    printf("n1 = %d e n2 = %.2f\n", n1, n2);
    printf("letra = %c e letra2 = %c\n", letra, letra2);
    return 0;
}