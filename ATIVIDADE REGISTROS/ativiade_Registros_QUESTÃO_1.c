#include <stdio.h>
#include <string.h>

#define ESTADOS 26

typedef struct {
    char nomes[40];
    int acidentes;
    int veiculos;
} Estados;


//LETRA A

void NOMES_ESTADOS(Estados coleta[]) {
    char lista_de_estados[ESTADOS][40] = {
        "Acre", "Alagoas", "Amapa", "Amazonas", "Bahia", "Ceara",
        "Espirito Santo", "Goias", "Maranhao", "Mato Grosso", "Mato Grosso do Sul",
        "Minas Gerais", "Para", "Paraiba", "Parana", "Pernambuco", "Piaui", "Rio de Janeiro",
        "Rio Grande do Norte", "Rio Grande do Sul", "Rondonia", "Roraima", "Santa Catarina", "Sao Paulo",
        "Sergipe", "Tocantins"
    };

    for (int i = 0; i < ESTADOS; i++) {
        strcpy(coleta[i].nomes, lista_de_estados[i]);
        printf("--- Estado: %s\n", coleta[i].nomes);
        printf("--- Veículos: ");
        scanf("%d", &coleta[i].veiculos);
        printf("--- Acidentes: ");
        scanf("%d", &coleta[i].acidentes);
    }
}

//LETRA B
void MenorEMaior(Estados coleta[], int *menor, int *maior) {
    *menor = 0;
    *maior = 0;
    for (int i = 1; i < ESTADOS; i++) {
        if (coleta[i].acidentes > coleta[*maior].acidentes) {
            *maior = i;
        }
        if (coleta[i].acidentes < coleta[*menor].acidentes) {
            *menor = i;
        }
    }
}   

//LETRA C
float Percentual(Estados estado) {
    if (estado.veiculos == 0) return 0; 
    return (estado.acidentes * 100.0) / estado.veiculos;
}

//LETRA D

int MediaAcidentes(Estados coleta[]) {
    int media = 0;
    for (int i = 0; i < ESTADOS; i +=1) {
        media +=coleta[i].acidentes;
    
    }
    return media / ESTADOS;
}

//LETRA E
void ACIMA_MediaAcidentes(Estados coleta[], int media) {
    for (int i = 0; i < ESTADOS; i +=1) {
        if (coleta[i].acidentes > media) {
            printf("%s está acima da média de acidentes",coleta[i].nomes);
        }
    
    }
}


int main() {
    Estados coleta[ESTADOS];
    int menor, maior;
    int media;
    
    
    NOMES_ESTADOS(coleta);
    MenorEMaior(coleta, &menor, &maior);

    printf("%s é o estado com menor numero de acidentes: %d\n", coleta[menor].nomes, coleta[menor].acidentes);
    printf("%s é o estado com maior numero de acidentes: %d\n", coleta[maior].nomes, coleta[maior].acidentes);

    printf("\nPercentual de acidentes por veículo em cada estado:\n");
    for (int i = 0; i < ESTADOS; i++) {
        float porcentagem = Percentual(coleta[i]);
        printf("%s: %.2f%%\n", coleta[i].nomes, porcentagem);
    }

    media = MediaAcidentes(coleta);

    printf("MEDIA DE ACIDENTES: %d\n", media);
    
    ACIMA_MediaAcidentes(coleta, media);



    return 0;
}