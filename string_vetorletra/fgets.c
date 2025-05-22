#include <stdio.h>
#include <string.h>

#define TAM_NOME 20;

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    double peso;
}


int main() {

    struct Pessoa pessoa;

    char str[100];  // Buffer para armazenar a entrada como string
    

    printf("Digite um numero: ");
    fgets(str, 100, stdin);  // Lê a entrada como string


    printf("O numero digitado foi %d, ", );

    return 0;
}


void lerstring (struct Pessoa, *pessoa) {
    fgets(str, 100, stdin);

}
