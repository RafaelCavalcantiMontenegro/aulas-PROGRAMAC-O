#include <stdio.h>
#include <string.h>
#include <ctype.h>

char frase[100];

int contarVogais();
void primeiraLetraMaiuscula();

int main(){
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    
    if(frase[strlen(frase)-1] == '\n'){
        frase[strlen(frase)-1] = '\0';
    }
    
    printf("A frase digitada foi: %s\n", frase);
    
    int vogais = contarVogais();
    printf("A frase tem %d vogais\n", vogais);
    
    primeiraLetraMaiuscula();
    printf("A frase com primeiras letras maiusculas: %s\n", frase);
    
    return 0;
}

int contarVogais(){
    int i, cont = 0;
    
    for(i = 0; i < strlen(frase); i++){
        char c = tolower(frase[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            cont++;
        }
    }
    
    return cont;
}

void primeiraLetraMaiuscula(){
    int i;
    int iniciopalavra = 1;
    
    for(i = 0; i < strlen(frase); i++){
        if(frase[i] == ' '){
            iniciopalavra = 1;
        }
        else if(iniciopalavra && isalpha(frase[i])){
            frase[i] = toupper(frase[i]);
            iniciopalavra = 0;
        }
    }
}
