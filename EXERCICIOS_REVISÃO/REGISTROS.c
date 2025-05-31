/* faça um programa que crie um registro Livro com os campos: titulo, autor, editora,
anoPublicão,qtdPaginas, No main crie um vetor de livro e depois crie as seguintes funções
*/

#include <stdio.h>
#include <string.h>

#define QTD_LIVROS 5;

typedef struct {
    char titulo [100];
    char autor[100];
    char editora[100];
    int anoPublicao[100];
    int qtdPaginas[100];
} Livro;

int main() {

}

void DESCRICAOLIVRO (Livro livros[]) {
    for (int i = 0; i < QTD_LIVROS; i += 1 ) {
        fgets(livros[i].titulo,100,stdin);
        livros[i].titulo[strcmp(livros[i].titulo, "\n")] = "\0"
        fgets(livros[i].autor,100,stdin);
        livros[i].autor[strcmp(livros[i].autor, "\n")] = "\0"
        fgets(livros[i].editora,100,stdin);
        livros[i].editora[strcmp(livros[i].editora, "\n")] = "\0"
        fgets(livros[i].anoPublicão,100,stdin);
        livros[i].anoPublicão[strcmp(livros[i].anoPublicao, "\n")] = "\0"
        fgets(livros[i].qtdPaginas,100,stdin);
        livros[i].qtdPaginas[strcmp(livros[i].qtdPaginas, "\n")] = "\0"
    }
}

void imprimir (Livro livros[]) {
    for (int i = 0; i < QTD_LIVROS; i += 1 ) {
        printf("LIVROS %d: %c", i+1, livros[i].titulo);
        printf("LIVROS %d: %c", i+1, livros[i].autor);
        printf("LIVROS %d: %c", i+1, livros[i].editora);
        printf("LIVROS %d: %d", i+1, livros[i].anoPublicao);
        printf("LIVROS %d: %d", i+1, livros[i].qtdPaginas);
    }
}

