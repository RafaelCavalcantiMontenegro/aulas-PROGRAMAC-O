#include <stdio.h>
#include <string.h>

struct livro {
  char titulo[100];
  char autor[100];
  char editora[100];
  int anopublicado;
  int qtdpaginas;
};

void preencherVetor(struct livro livros[], int QTD_LIVROS) {
  for (int i = 0; i < QTD_LIVROS; i++) {
    printf("Digite o titulo do livro %d: ", i + 1);
    fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);
    livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0';
   
    printf("Digite o autor do livro %d: ", i + 1);
    fgets(livros[i].autor, sizeof(livros[i].autor), stdin);
    livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0';
   
    printf("Digite a editora do livro %d: ", i + 1);
    fgets(livros[i].editora, sizeof(livros[i].editora), stdin);
    livros[i].editora[strcspn(livros[i].editora, "\n")] = '\0';
   
    printf("Digite o ano de publicacao do livro %d: ", i + 1);
    scanf("%d", &livros[i].anopublicado);
   
    printf("Digite a quantidade de paginas do livro %d: ", i + 1);
    scanf("%d", &livros[i].qtdpaginas);
    getchar(); // limpar o buffer
    printf("\n");
  }
}

void imprimirvetor(struct livro livros[], int QTD_LIVROS) {
  for(int i = 0; i < QTD_LIVROS; i++) {
    printf("Livro %d:\n", i + 1);
    printf("Titulo: %s\n", livros[i].titulo);
    printf("Autor: %s\n", livros[i].autor);
    printf("Editora: %s\n", livros[i].editora);
    printf("Ano de publicacao: %d\n", livros[i].anopublicado);
    printf("Quantidade de paginas: %d\n", livros[i].qtdpaginas);
    printf("\n");
  }
}

int buscarPorTitulo(struct livro livros[], int QTD_LIVROS, char titulo[]) {
  for(int i = 0; i < QTD_LIVROS; i++) {
    if(strcmp(livros[i].titulo, titulo) == 0) {
      return i;
    }
  }
  return -1;
}

void ordenarPorTitulo(struct livro livros[], int QTD_LIVROS) {
  for (int i = 0; i < QTD_LIVROS - 1; i++) {
    int trocou = 0; // flag para verificar se houve troca
    for (int j = 0; j < QTD_LIVROS - 1 - i; j++) {
      if (strcmp(livros[j].titulo, livros[j + 1].titulo) > 0) {
        struct livro temp = livros[j];
        livros[j] = livros[j + 1];
        livros[j + 1] = temp;
        trocou = 1;
      }
    }
    // Se nenhuma troca foi feita, a lista já está ordenada
    if (!trocou) {
      break;
    }
  }
}


int buscaBinariaPorTitulo(struct livro livros[], int QTD_LIVROS, char titulo[]) {
  int inicio = 0;
  int fim = QTD_LIVROS - 1;
 
  while(inicio <= fim) {
    int meio = (inicio + fim) / 2;
    int comparacao = strcmp(livros[meio].titulo, titulo);
   
    if(comparacao == 0) {
      return meio;
    } else if(comparacao < 0) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
  return -1;
}

int main() {
  int QTD_LIVROS;
 
  printf("Quantos livros deseja cadastrar? ");
  scanf("%d", &QTD_LIVROS);
  getchar(); // limpar buffer
 
  struct livro biblioteca[QTD_LIVROS];
 
  
  preencherVetor(biblioteca, QTD_LIVROS);
 
  
  printf("\n=== LIVROS CADASTRADOS ===\n");
  imprimirvetor(biblioteca, QTD_LIVROS);
 
  
  char tituloBusca[100];
  printf("Digite o titulo para buscar: ");
  fgets(tituloBusca, sizeof(tituloBusca), stdin);
  tituloBusca[strcspn(tituloBusca, "\n")] = '\0';
 
  int posicao = buscarPorTitulo(biblioteca, QTD_LIVROS, tituloBusca);
  if(posicao != -1) {
    printf("Livro encontrado na posicao %d\n", posicao);
  } else {
    printf("Livro nao encontrado\n");
  }
 
  
  printf("\n=== ORDENANDO POR TITULO ===\n");
  ordenarPorTitulo(biblioteca, QTD_LIVROS);
  imprimirvetor(biblioteca, QTD_LIVROS);
 
  
  printf("Digite o titulo para busca binaria: ");
  fgets(tituloBusca, sizeof(tituloBusca), stdin);
  tituloBusca[strcspn(tituloBusca, "\n")] = '\0';
 
  posicao = buscaBinariaPorTitulo(biblioteca, QTD_LIVROS, tituloBusca);
  if(posicao != -1) {
    printf("Livro encontrado na posicao %d (busca binaria)\n", posicao);
  } else {
    printf("Livro nao encontrado (busca binaria)\n");
  }
 
  return 0;
}
