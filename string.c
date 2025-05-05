// representar caracter nulo: \0
//código ASCII 48



#include <stdio.h>


const int TAM = 10;

void lerStr(char *str, int count);

    int main(){
        char nome [TAM];
        printf("Digite seu nome: ");

        lerStr(nome, TAM);

        mystrcpy(nome, "Maria José");
        printf("O nome digitado foi: \"%s\" \n", nome);  

        
        return 0;

    }

void lerStr(char *str, int count){
    fgets(str, count, stdin);
    int tam = strlen(str);
    if (str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}


void mystrcpy (char *str1, char *str2) {
    int i = 0;
    while(str2[i] != '\0'){
        str1[i] = str2[i];
        i +=1;

    }
    str1[i] = '\0';
}