#include <stdio.h>

int main() {
    int num_pessoas, idade, idade_mais_pesada = 0;
    char sexo;
    double peso, soma_pesos_homens = 0, total_mulheres_menos_50 = 0;
    int count_homens_menos_30 = 0, total_mulheres = 0;
    double media_peso_homens_menos_30 = 0, percentual_mulheres_menos_50 = 0;
    double peso_maximo = 0;
    
    printf("Quantas pessoas serao entrevistadas? ");
    scanf("%d", &num_pessoas);
    
    for (int i = 0; i < num_pessoas; i++) {
        printf("\nPessoa %d:\n", i + 1);
        
        printf("Sexo (M/F): ");
        scanf(" %c", &sexo);
        
        printf("Idade: ");
        scanf("%d", &idade);
        
        printf("Peso: ");
        scanf("%lf", &peso);
        
        // Verifica a pessoa mais pesada
        if (peso >= peso_maximo) {
            peso_maximo = peso;
            idade_mais_pesada = idade;
        }
        
        // Calcula média de peso dos homens com menos de 30 anos
        if (sexo == 'M' || sexo == 'm') {
            if (idade < 30) {
                soma_pesos_homens += peso;
                count_homens_menos_30+=1;
            }
        }
        
        // Calcula percentual de mulheres com menos de 50 kg
        if (sexo == 'F' || sexo == 'f') {
            total_mulheres+=1;
            if (peso < 50) {
                total_mulheres_menos_50+=1;
            }
        }
    }
    
    // Calcula a média de peso dos homens com menos de 30 anos
    if (count_homens_menos_30 > 0) {
        media_peso_homens_menos_30 = soma_pesos_homens / count_homens_menos_30;
    }
    
    // Calcula o percentual de mulheres com menos de 50 kg
    if (total_mulheres > 0) {
        percentual_mulheres_menos_50 = (total_mulheres_menos_50 / total_mulheres) * 100;
    }
    
    // Exibe os resultados
    printf("\nResultados:\n");
    printf("Idade da pessoa mais pesada: %d anos\n", idade_mais_pesada);
    if (count_homens_menos_30 > 0) {
        printf("Media de peso dos homens com menos de 30 anos: %.2lf kg\n", media_peso_homens_menos_30);
    } else {
        printf("Nenhum homem com menos de 30 anos foi registrado.\n");
    }
    if (total_mulheres > 0) {
        printf("Percentual de mulheres com menos de 50 kg: %.2lf%%\n", percentual_mulheres_menos_50);
    } else {
        printf("Nenhuma mulher foi registrada.\n");
    }
    
    return 0;
}
