#include <stdio.h>
#include <string.h>

struct Produto {
    int codigo;
    char nome[50];
    double preco;
};

typedef struct Produto Produto;


void selectionSortPreco(Produto p[], int n) {
    int i, j, troca;
    Produto temp;

    for (i = 0; i < n - 1; i++) {
        troca = i;
        for (j = i + 1; j < n; j++) {
            if (p[j].preco < p[troca].preco) {
                troca = j;
            }
        }
        
        if (troca != i) {
            temp = p[i];
            p[i] = p[troca];
            p[troca] = temp;
        }
    }
}


int main() {
    int n;
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); 

    Produto produtos[n];

    for (int i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Código: ");
        scanf("%d", &produtos[i].codigo);
        getchar(); 

        printf("Nome: ");
        fgets(produtos[i].nome, 50, stdin);
        
        int len = strlen(produtos[i].nome);
        if (produtos[i].nome[len - 1] == '\n') {
            produtos[i].nome[len - 1] = '\0';
        }

        printf("Preço: ");
        scanf("%lf", &produtos[i].preco);
        getchar(); 
    }

    
    selectionSortPreco(produtos, n);

    printf("\nProdutos ordenados por preço:\n");
    for (int i = 0; i < n; i++) {
        printf("Código: %d | Nome: %s | Preço: R$ %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }

    return 0;
}
