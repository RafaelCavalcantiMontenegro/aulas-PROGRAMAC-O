#include <stdio.h>
#include <string.h>

#define ESTADOS 26



typedef struct {
    char nomes[40];
    int acidentes;
    int veiculos;
}Estados;

// QUESTÃO 1 LETRA A

void NOMES_ESTADOS(Estados coleta[]) {
    char lista_de_estados[ESTADOS][40] = {"Acre", "Alagoas", "Amapa", "Amazonas", "Bahia", "Ceara",
        "Espirito Santo", "Goias", "Maranhao", "Mato Grosso", "Mato Grosso do Sul",
        "Minas Gerais", "Para", "Paraiba", "Parana", "Pernambuco", "Piaui", "Rio de Janeiro",
        "Rio Grande do Norte", "Rio Grande do Sul", "Rondonia", "Roraima", "Santa Catarina", "Sao Paulo",
        "Sergipe", "Tocantins"
    };

    for (int i = 0; i < ESTADOS; i += 1) {
        strcpy(coleta[i].nomes, lista_de_estados[i] );
        printf("--- Estado: %s\n", coleta[i].nomes);
        printf("--- Veículos: ");
        scanf("%d", &coleta[i].veiculos);
        printf("--- Acidentes: ");
        scanf("%d", &coleta[i].acidentes);
    }
}

//QUESTÃO 1 LETRA B

void MenorEMaior(Estados coleta[], int *menor, int *maior) {
    
    *menor = 0;
    *maior = 0;
    for (int i = 1; i < ESTADOS; i +=1 ) {
        if (coleta[i].acidentes > coleta[*maior].acidentes) {
            *maior = i;
        }

        if (coleta[i].acidentes > coleta[*menor].acidentes) {
            *menor = i;
        }

    }
}   

//QUESTÃO 1 LETRA C

float Percentual(Estados coleta) {
    return (coleta.acidentes * 100.0) / coleta.veiculos;
}



int main() {
    Estados coleta[ESTADOS];
    int menor, maior;

    NOMES_ESTADOS(coleta);
    MenorEMaior(coleta, &menor, &maior);


    printf("%s é o estado com menor numero de acidentes: %d", coleta[menor].nomes, menor);

    return 0;
}
