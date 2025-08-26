#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_CONTEUDO 100
#define MAX_GENERO_CONTEUDO 100
#define MAX_USUARIO 100
#define MAX_FAVORITOS 100

typedef struct {
    int id;
    char conteudo[MAX_NOME_CONTEUDO];
    char genero[MAX_GENERO_CONTEUDO];
} Conteudo;

typedef struct {
    int id;
    char nome[MAX_USUARIO];
    int conteudos_favoritos[MAX_FAVORITOS];
    int num_favoritos;
} Usuario;

void adicionar_conteudo(FILE *conteudo_file);
void adicionar_usuario(FILE *user_file);
void listar_conteudos(FILE *conteudo_file);
void listar_usuarios(FILE *user_file);
void adicionar_favorito(FILE *conteudo_file, FILE *user_file);
void listar_usuarios_com_favoritos(FILE *user_file, FILE *conteudo_file);

int main() {
    FILE *conteudo_file, *user_file;

    conteudo_file = fopen("conteudos.bin", "rb+");
    if (!conteudo_file) conteudo_file = fopen("conteudos.bin", "wb+");

    user_file = fopen("usuarios.bin", "rb+");
    if (!user_file) user_file = fopen("usuarios.bin", "wb+");

    if (!conteudo_file || !user_file) {
        printf("Erro ao abrir os arquivos binários.\n");
        return 1;
    }

    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar um Conteúdo\n");
        printf("2. Adicionar um Usuário\n");
        printf("3. Listar os Conteúdos\n");
        printf("4. Listar os Usuários\n");
        printf("5. Adicionar aos Favorito\n");
        printf("6. Listar Usuários com Favoritos\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_conteudo(conteudo_file);
                break;
            case 2:
                adicionar_usuario(user_file);
                break;
            case 3:
                listar_conteudos(conteudo_file);
                break;
            case 4:
                listar_usuarios(user_file);
                break;
            case 5:
                adicionar_favorito(conteudo_file, user_file);
                break;
            case 6:
                listar_usuarios_com_favoritos(user_file, conteudo_file);
                break;
            case 7:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 7);

    fclose(conteudo_file);
    fclose(user_file);

    return 0;
}

void adicionar_conteudo(FILE *conteudo_file) {
    Conteudo conteudo = {0};
    printf("\n=== Adicionar Conteúdo ===\n");
    printf("ID: ");
    scanf("%d", &conteudo.id);
    printf("Título: ");
    getchar();
    fgets(conteudo.conteudo, MAX_NOME_CONTEUDO, stdin);
    strtok(conteudo.conteudo, "\n");
    printf("Gênero: ");
    fgets(conteudo.genero, MAX_GENERO_CONTEUDO, stdin);
    strtok(conteudo.genero, "\n");

    fseek(conteudo_file, 0, SEEK_END);
    fwrite(&conteudo, sizeof(Conteudo), 1, conteudo_file);
    fflush(conteudo_file);
}

void listar_conteudos(FILE *conteudo_file) {
    Conteudo conteudo;
    rewind(conteudo_file);
    printf("\n=== Lista de Conteúdos ===\n");
    while (fread(&conteudo, sizeof(Conteudo), 1, conteudo_file)) {
        printf("ID: %d, Título: %s, Gênero: %s\n", conteudo.id, conteudo.conteudo, conteudo.genero);
    }
}

void adicionar_usuario(FILE *user_file) {
    Usuario usuario = {0};
    printf("\n=== Adicionar Usuário ===\n");
    printf("ID: ");
    scanf("%d", &usuario.id);
    printf("Nome: ");
    getchar();
    fgets(usuario.nome, MAX_USUARIO, stdin);
    strtok(usuario.nome, "\n");
    usuario.num_favoritos = 0;

    fseek(user_file, 0, SEEK_END);
    fwrite(&usuario, sizeof(Usuario), 1, user_file);
    fflush(user_file);
}

void listar_usuarios(FILE *user_file) {
    Usuario usuario;
    rewind(user_file);
    printf("\n=== Lista de Usuários ===\n");
    while (fread(&usuario, sizeof(Usuario), 1, user_file)) {
        printf("ID: %d, Nome: %s, Número de Favoritos: %d\n", usuario.id, usuario.nome, usuario.num_favoritos);
    }
}

void adicionar_favorito(FILE *conteudo_file, FILE *user_file) {
    Usuario usuario;
    Conteudo conteudo;
    int usuario_id, conteudo_id;
    int encontrado = 0;

    printf("\n=== Adicionar Conteúdo Favorito ===\n");
    printf("ID do usuário: ");
    scanf("%d", &usuario_id);

    rewind(user_file);
    while (fread(&usuario, sizeof(Usuario), 1, user_file)) {
        if (usuario.id == usuario_id) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado.\n");
        return;
    }

    printf("Usuário encontrado: %s\n", usuario.nome);
    listar_conteudos(conteudo_file);

    printf("ID do conteúdo para adicionar como favorito: ");
    scanf("%d", &conteudo_id);

    rewind(conteudo_file);
    encontrado = 0;
    while (fread(&conteudo, sizeof(Conteudo), 1, conteudo_file)) {
        if (conteudo.id == conteudo_id) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Conteúdo não encontrado.\n");
        return;
    }

    if (usuario.num_favoritos >= MAX_FAVORITOS) {
        printf("O usuário já atingiu o limite de favoritos.\n");
        return;
    }

    usuario.conteudos_favoritos[usuario.num_favoritos++] = conteudo_id;

    fseek(user_file, -sizeof(Usuario), SEEK_CUR);
    fwrite(&usuario, sizeof(Usuario), 1, user_file);
    fflush(user_file);

    printf("Conteúdo '%s' adicionado aos favoritos de '%s'.\n", conteudo.conteudo, usuario.nome);
}

void listar_usuarios_com_favoritos(FILE *user_file, FILE *conteudo_file) {
    Usuario usuario;
    Conteudo conteudo;

    rewind(user_file);
    printf("\n=== Usuários e seus Conteúdos Favoritos ===\n");

    while (fread(&usuario, sizeof(Usuario), 1, user_file)) {
        printf("\nUsuário: %s (ID: %d)\n", usuario.nome, usuario.id);
        if (usuario.num_favoritos == 0) {
            printf("  Nenhum conteúdo favorito cadastrado.\n");
            continue;
        }
        printf("  Conteúdos favoritos:\n");
        for (int i = 0; i < usuario.num_favoritos; i++) {
            int id_fav = usuario.conteudos_favoritos[i];
            rewind(conteudo_file);
            int encontrado = 0;
            while (fread(&conteudo, sizeof(Conteudo), 1, conteudo_file)) {
                if (conteudo.id == id_fav) {
                    printf("    - %s (%s)\n", conteudo.conteudo, conteudo.genero);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("    - Conteúdo com ID %d não encontrado.\n", id_fav);
            }
        }
    }
}






