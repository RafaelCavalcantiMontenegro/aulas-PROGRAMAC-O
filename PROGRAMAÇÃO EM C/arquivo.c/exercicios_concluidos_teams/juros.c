#include <stdio.h>

double valor_multa;//valor da multa
int diasAtraso; //dias de pagamento atrasados
double taxa; //taxa de juros mensais
double valor_conta; //valor básico da conta
int meses_juros; //dias de juros já convertidos
double valor_final; //valor final a ser pago
double apenas_juros; //valor do juros isolado


int main() {
    printf("fale o número de dias de atraso:\n"); //tempo de atraso
    scanf("%d", &diasAtraso);
    
    meses_juros = diasAtraso/30;

    printf("digite o valor da conta:\n");   //valor da conta
    scanf("%lf", &valor_conta);

    printf("digite o valor da multa:\n");   //valor da multa
    scanf("%lf", &valor_multa);

    printf("digite o valor da taxa de juros:\n"); // valor do juros
    scanf("%lf", &taxa);

    apenas_juros = (valor_conta)*(1 + taxa)*(diasAtraso);

    if (diasAtraso < 45) {
    

        valor_final = apenas_juros + valor_conta + valor_multa;
            printf("o valor a ser pago será\n%2.f\n", valor_final);
    }

}