#include <stdio.h>
#include <stdlib.h>

/*SALÁRIO                                 AUMENTO %
Maiores que R$ 15000,00                       10%
De R$ 7500,00 a R$ 15000,00               20%
De R$ 1000,00 a R$ 7500,00                30%
Menores que R$1000,00                       40%*/

double descobre_percentual(double salario){
    if(salario < 1000)
        return 0.4;
    else if(salario >= 100 && salario < 7500)
        return 0.3;
    else if(salario >= 7500 && salario < 15000)
        return 0.2;
    return 0.1;
}

double calcula_novo_salario(double salario, double percentual){
    return (1 + percentual) * salario;
}

void novo_salario(){
    double salario, percentual;
    printf("Entre com o salario: R$"); scanf("%lf", &salario);
    percentual = descobre_percentual(salario);
    printf("Novo salario: R$%.2f\n\n\n", calcula_novo_salario(salario, percentual));
}
