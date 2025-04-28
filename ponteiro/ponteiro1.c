// endereço de memória
// para declarar ponteiro, tipo *nomevariavel


#include <stdio.h>

// para alterar a o endereço é necessário colocar o "&" na variavel "numero" dentro da função alterarValor e adicionar o * ma variavel n.


/*
int alterarValor(int n);
int alterarValor1(int *n);


int main() {

    int numero = 10;

    printf("numero = %d\n", numero);
    alterarValor(numero);
    printf("numero = %d\n", numero);
    
    //alterar endereço
    printf("\n");

    printf("altera o endereço");

    printf("\n");

    int numero1 = 10;
    
    printf("numero = %d\n", numero1);
    alterarValor1(&numero1);
    printf("numero = %d\n", numero1);
    
    return 0;


}
*/
int alterarValor(int n) {
    n = 15;
}


int alterarValor1(int *n) {
    *n = 15;
}

void trocar (int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;

}

int main() {
    int numero2 = 10, numero3 = 20;
    printf("numero2 = %d - numero3 = %d\n", numero2, numero3);
    trocar(&numero2, &numero3);
    printf("numero2 = %d - numero3 = %d\n", numero2, numero3);
    return 0;
}

