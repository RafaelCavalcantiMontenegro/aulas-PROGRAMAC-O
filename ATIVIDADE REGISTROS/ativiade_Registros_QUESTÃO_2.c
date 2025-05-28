#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUTOS 40

typedef struct {
    int codigo;
    char descricao[50];
    float valor_unitario;
    int quantidade_estoque;
} Produto;

Produto estoque[MAX_PRODUTOS];
int total_produtos = 0;

// LETRA A
void cadastrarProduto() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    
    Produto novo;
    printf("\n--- Cadastro de Novo Produto ---\n");
    
    // VERIFICAÇÃO DO CÓDIGO
    int codigo_existente;
    do {
        codigo_existente = 0;
        printf("Código: ");
        scanf("%d", &novo.codigo);
        
        for (int i = 0; i < total_produtos; i++) {
            if (estoque[i].codigo == novo.codigo) {
                printf("Código já existente! Tente outro.\n");
                codigo_existente = 1;
                break;
            }
        }
    } while (codigo_existente);
    
    printf("Descrição: ");
    scanf(" %[^\n]s", novo.descricao);
    printf("Valor Unitário: R$ ");
    scanf("%f", &novo.valor_unitario);
    printf("Quantidade em Estoque: ");
    scanf("%d", &novo.quantidade_estoque);
    
    estoque[total_produtos] = novo;
    total_produtos++;
    
    printf("Produto cadastrado com sucesso!\n");
}

// LETRA B
void alterarValor() {
    int codigo;
    printf("\n--- Alteração de Valor ---\n");
    printf("Código do produto: ");
    scanf("%d", &codigo);
    
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Produto: %s\n", estoque[i].descricao);
            printf("Valor atual: R$ %.2f\n", estoque[i].valor_unitario);
            printf("Novo valor: R$ ");
            scanf("%f", &estoque[i].valor_unitario);
            printf("Valor atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

// LETRA C
float informarValor(int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            return estoque[i].valor_unitario;
        }
    }
    return -1; 
}

//LETRA D
int informarEstoque(int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            return estoque[i].quantidade_estoque;
        }
    }
    return -1; 
}

// LETRA E
void realizarVenda() {
    int codigo, quantidade;
    printf("\n--- Realizar Venda ---\n");
    printf("Código do produto: ");
    scanf("%d", &codigo);
    
    int estoque_atual = informarEstoque(codigo);
    if (estoque_atual == -1) {
        printf("Produto não encontrado!\n");
        return;
    }
    
    if (estoque_atual == 0) {
        printf("Produto sem estoque disponível!\n");
        return;
    }
    
    printf("Quantidade desejada: ");
    scanf("%d", &quantidade);
    
    if (quantidade <= estoque_atual) {
        for (int i = 0; i < total_produtos; i++) {
            if (estoque[i].codigo == codigo) {
                estoque[i].quantidade_estoque -= quantidade;
                float total = quantidade * estoque[i].valor_unitario;
                printf("Venda realizada! Total: R$ %.2f\n", total);
                return;
            }
        }
    } else {
        char opcao;
        printf("Quantidade insuficiente em estoque!\n");
        printf("Deseja comprar todo o estoque disponível (%d unidades)? (S/N): ", estoque_atual);
        scanf(" %c", &opcao);
        
        if (toupper(opcao) == 'S') {
            for (int i = 0; i < total_produtos; i++) {
                if (estoque[i].codigo == codigo) {
                    float total = estoque_atual * estoque[i].valor_unitario;
                    estoque[i].quantidade_estoque = 0;
                    printf("Venda realizada! Total: R$ %.2f\n", total);
                    return;
                }
            }
        } else {
            printf("Venda cancelada!\n");
        }
    }
}


void exibirMenu() {
    printf("\n=== PAPELARIA ESCOLAR ===\n");
    printf("1. Cadastrar novo produto\n");
    printf("2. Alterar valor unitário\n");
    printf("3. Consultar valor unitário\n");
    printf("4. Consultar estoque\n");
    printf("5. Realizar venda\n");
    printf("6. Sair\n");
    printf("Opção: ");
}

int main() {
    int opcao;
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
                
            case 2:
                alterarValor();
                break;
                
            case 3: {
                int codigo;
                printf("Código do produto: ");
                scanf("%d", &codigo);
                float valor = informarValor(codigo);
                if (valor == -1) {
                    printf("Produto não encontrado!\n");
                } else {
                    printf("Valor unitário: R$ %.2f\n", valor);
                }
                break;
            }
                
            case 4: {
                int codigo;
                printf("Código do produto: ");
                scanf("%d", &codigo);
                int qtd = informarEstoque(codigo);
                if (qtd == -1) {
                    printf("Produto não encontrado!\n");
                } else {
                    printf("Quantidade em estoque: %d\n", qtd);
                }
                break;
            }
                
            case 5:
                realizarVenda();
                break;
                
            case 6:
                printf("Saindo do sistema...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    return 0;
}