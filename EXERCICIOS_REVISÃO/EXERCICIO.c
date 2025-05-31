#include <stdio.h>
#include <string.h>
char frase;

lista = ("a","e","i","o", "u");

int main(){
    printf("Digite uma frase: ");
    scanf("%c", &frase);
    printf("A frase digitada foi: %c", frase);
    VOGAIS(frase);
}


void VOGAIS(frase) {
    int cont = 0;
    for (int i = 0; i <= strlen(frase); i +=1) {
        if (frase[i] == lista ) {
            cont +=1;

        }
    }
    printf("%d", cont);
}