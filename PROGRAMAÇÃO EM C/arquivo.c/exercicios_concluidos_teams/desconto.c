#include <stdio.h>

int main() {
    int categoria;
    int quantidade;
    double preco;
    double desconto;
    double resultado;

    
    printf("Qual o preço do produto?\n");
    scanf("%lf", &preco);

    
    printf("Qual a categoria do seu produto?\n");
    scanf("%d", &categoria);

    
    double categoria_desconto = 0;
    if (categoria == 1) {  // 10%
        categoria_desconto = 10.0 / 100;
    }
    else if (categoria == 2) {  // 15%
        categoria_desconto = 15.0 / 100;
    }
    else {  // 8%
        categoria_desconto = 8.0 / 100;
    }

    
    printf("Qual a quantidade de produtos?\n");
    scanf("%d", &quantidade);

    
    double quantidade_desconto = 0;
    if (quantidade <= 2) {  // 2%
        quantidade_desconto = 2.0 / 100;
    }
    else if (quantidade <= 10) {  // 5%
        quantidade_desconto = 5.0 / 100;
    }
    else {  // 10%
        quantidade_desconto = 10.0 / 100;
    }

    
    desconto = preco * (quantidade_desconto + categoria_desconto);
    resultado = preco * quantidade - desconto;

    
    printf("Preço total sem desconto: %.2lf\n", preco * quantidade);
    printf("Preço total com desconto: %.2lf\n", resultado);
    printf("Seu desconto foi de: %.2lf\n", desconto);

    return 0;
}
