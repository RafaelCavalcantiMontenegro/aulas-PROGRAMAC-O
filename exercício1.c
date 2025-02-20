#include <stdio.h>

int main() {

    double n1;
    double n2;
    double x;
    
    printf("digite o primeiro valor");
    scanf("%lf", &n1);

    printf("digite o segundo valor");
    scanf("%lf", &n2);

    x = ((n2 - n1)/n1) *100;

    printf("percentual %.2f\n", x);

    return 0;
}