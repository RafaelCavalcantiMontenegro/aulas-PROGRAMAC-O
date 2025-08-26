#include <stdio.h>
#include <string.h>

#define TAM_NOME 30

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    double peso;
};

void lerStr(char *str, int count);

void lerPessoa(struct Pessoa, *pessoa);

int main() {

    struct Pessoa pessoa1, pessoa2;
    printf("------ Digitação Pessoa 1 ------\n");
    lerPessoa(&pessoa1);

    printf("------ Digitação Pessoa 2 ------\n");
    lerPessoa(&pessoa2);


    printf("------ Interpretação da pessoa 1 ------\n");
    imprimirPessoa(pessoa1);

    printf("------ Interpretação da pessoa 2 ------\n");
    imprimirPessoa(pessoa2);
    return 0;
}


void lerStr(char *str, int count) {
    fgets(str, count, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
      str[tam - 1] = '\0';
    }
  }

  void lerPessoa(struct Pessoa, *pessoa) {
    char tempStr[TAM_TEMP]`;
    printf("Digite nome: ");
    lerStr(pessoa->nome, TAM_NOME);
    printf("Digite idade: ");
    scanf("%d", &pessoa->.idade);
    printf("DIgite peso: ");
    scanf("%lf", &pessoa->.peso);
    lerStr(tempStr, TAM_TEMP);
  }

  imprimirPessoa(struct Pessoa) {
    
    printf("%c, %d anos, %lf KG", Pessoa.nome, Pessoa.idade, Pessoa.peso);

    
    printf("%c, %d anos, %lf KG", Pessoa.nome, Pessoa.idade, Pessoa.peso);
  }