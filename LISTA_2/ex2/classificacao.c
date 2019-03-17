#include <stdio.h>
#include <stdlib.h>

/*SALÁRIO CLASSIFICAÇÃO
Até R$ 7000,00 Mal remunerado
Maiores que R$ 7000,00 Bem remunerado*/

int analisa_remuneracao(double salario){
    if(salario <= 7000)
        return 0;
    return 1;
}

void classificacao(){
    double salario;
    printf("Entre com o salario: R$"); scanf("%lf", &salario);
    int bem_remunerado = analisa_remuneracao(salario);
    if(bem_remunerado)
        printf("Bem remunerado!\n\n\n");
    else
        printf("Mal remunerado!\n\n\n");
}
