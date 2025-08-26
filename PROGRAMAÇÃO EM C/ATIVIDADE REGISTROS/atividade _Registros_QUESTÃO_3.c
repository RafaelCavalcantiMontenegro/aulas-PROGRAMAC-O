#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTAS 100

typedef struct {
    int numero;
    char nome[50];
    char cpf[15];
    char telefone[15];
    float saldo;
} Conta;

Conta corrente[MAX_CONTAS];
Conta poupanca[MAX_CONTAS];
int qtd_corrente = 0;
int qtd_poupanca = 0;

// LETRA A
int buscar(Conta cadastro[], int tamanho, int numero_conta) {
    if (tamanho == 0) return -1; // Cadastro vazio
    for (int i = 0; i < tamanho; i++) {
        if (cadastro[i].numero == numero_conta) {
            return i; 
        }
    }
    return -2;
}

// LETRA B
void cadastrarConta(Conta cadastro[], int *tamanho) {
    if (*tamanho >= MAX_CONTAS) {
        printf("Limite de contas atingido!\n");
        return;
    }
    
    int numero;
    printf("\nNúmero da conta: ");
    scanf("%d", &numero);
    
    int pos = buscar(cadastro, *tamanho, numero);
    if (pos >= 0) {
        printf("Erro: Número de conta já existe!\n");
        return;
    }
    
    Conta nova;
    nova.numero = numero;
    
    printf("Nome do titular: ");
    scanf(" %[^\n]s", nova.nome);
    printf("CPF: ");
    scanf("%s", nova.cpf);
    printf("Telefone: ");
    scanf("%s", nova.telefone);
    nova.saldo = 0.0;
    
    cadastro[*tamanho] = nova;
    (*tamanho)++;
    printf("Conta cadastrada com sucesso!\n");
}

// LETRA C
void consultarSaldo(Conta cadastro[], int tamanho) {
    int numero;
    printf("\nNúmero da conta: ");
    scanf("%d", &numero);
    
    int pos = buscar(cadastro, tamanho, numero);
    if (pos == -1) {
        printf("Cadastro vazio!\n");
    } else if (pos == -2) {
        printf("Conta não encontrada!\n");
    } else {
        printf("Saldo: R$ %.2f\n", cadastro[pos].saldo);
    }
}

// LETRA D
void depositar(Conta cadastro[], int tamanho) {
    int numero;
    printf("\nNúmero da conta: ");
    scanf("%d", &numero);
    
    int pos = buscar(cadastro, tamanho, numero);
    if (pos < 0) {
        printf(pos == -1 ? "Cadastro vazio!\n" : "Conta não encontrada!\n");
        return;
    }
    
    float valor;
    printf("Valor do depósito: R$ ");
    scanf("%f", &valor);
    
    if (valor > 0) {
        cadastro[pos].saldo += valor;
        printf("Depósito realizado! Novo saldo: R$ %.2f\n", cadastro[pos].saldo);
    } else {
        printf("Valor inválido para depósito!\n");
    }
}

// LETRA E
void sacar(Conta cadastro[], int tamanho) {
    int numero;
    printf("\nNúmero da conta: ");
    scanf("%d", &numero);
    
    int pos = buscar(cadastro, tamanho, numero);
    if (pos < 0) {
        printf(pos == -1 ? "Cadastro vazio!\n" : "Conta não encontrada!\n");
        return;
    }
    
    float valor;
    printf("Valor do saque: R$ ");
    scanf("%f", &valor);
    
    if (valor <= 0) {
        printf("Valor inválido para saque!\n");
    } else if (valor > cadastro[pos].saldo) {
        printf("Saldo insuficiente!\n");
    } else {
        cadastro[pos].saldo -= valor;
        printf("Saque realizado! Novo saldo: R$ %.2f\n", cadastro[pos].saldo);
    }
}

// LETRA F
void listarContas(Conta cadastro[], int tamanho, const char *tipo) {
    printf("\n=== CONTAS %s ===\n", tipo);
    if (tamanho == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }
    
    for (int i = 0; i < tamanho; i++) {
        printf("\nConta: %d", cadastro[i].numero);
        printf("\nTitular: %s", cadastro[i].nome);
        printf("\nTelefone: %s", cadastro[i].telefone);
        printf("\n-------------------\n");
    }
}

// Menu de seleção de conta
void menuConta(Conta cadastro[], int *tamanho, const char *tipo) {
    int opcao;
    do {
        printf("\n=== %s ===", tipo);
        printf("\n1. Cadastrar nova conta");
        printf("\n2. Consultar saldo");
        printf("\n3. Fazer depósito");
        printf("\n4. Fazer saque");
        printf("\n5. Listar contas");
        printf("\n6. Voltar");
        printf("\nOpção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarConta(cadastro, tamanho);
                break;
            case 2:
                consultarSaldo(cadastro, *tamanho);
                break;
            case 3:
                depositar(cadastro, *tamanho);
                break;
            case 4:
                sacar(cadastro, *tamanho);
                break;
            case 5:
                listarContas(cadastro, *tamanho, tipo);
                break;
            case 6:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 6);
}


int main() {
    int opcao;
    
    do {
        printf("\n=== BANCO DINHEIRO CERTO ===");
        printf("\n1. Conta Corrente");
        printf("\n2. Conta Poupança");
        printf("\n3. Sair");
        printf("\nOpção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                menuConta(corrente, &qtd_corrente, "CORRENTE");
                break;
            case 2:
                menuConta(poupanca, &qtd_poupanca, "POUPANÇA");
                break;
            case 3:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 3);

    return 0;
}