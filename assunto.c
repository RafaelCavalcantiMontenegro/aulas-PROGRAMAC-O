#include <stdio.h>

int ehprimo(int num) {
    int qtdDivisores = 0 ;
    for (int divisor = 1; divisor <= num; divisor += 1 ) {
        if (num % divisor == 0) {
            qtdDivisores += 1;
        }
    }
    return qtdDivisores == 2;
}
