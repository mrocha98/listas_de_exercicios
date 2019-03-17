#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INSENTO 1903.98

int descobre_faixa(double salario){
    if(salario <= INSENTO)
        return 1;
    else if(salario >= 1903.99 && salario < 2826.66)
        return 2;
    else if(salario >= 2826.66 && salario < 3751.06)
        return 3;
    else if(salario >= 3751.06 && salario < 4664.68)
        return 4;
    return 5;
}

double descobre_aliquota(double salario){
    int faixa = descobre_faixa(salario);
    switch(faixa){
    case 1:
        return 0.0;
    case 2:
        return 0.075;
    case 3:
        return 0.15;
    case 4:
        return 0.225;
    case 5:
        return 0.275;
    }
}

double descobre_deducao(double salario){
    int faixa = descobre_faixa(salario);
    switch(faixa){
    case 1:
        return 0.0;
    case 2:
        return 142.8;
    case 3:
        return 354.8;
    case 4:
        return 636.13;
    case 5:
        return 869.36;
    }
}

double calcula_ir(double salario, double aliquota, double deducao){
    return ((salario * aliquota) - deducao);
}

void imposto(){
    double aliquota, deducao, salario, ir;
    printf("CALCULO DO IR\nEntre com seu salario: R$"); scanf("%lf", &salario);
    salario = abs(salario);
    deducao = descobre_deducao(salario);
    aliquota = descobre_aliquota(salario);
    ir = calcula_ir(salario, aliquota, deducao);
    printf("IR Mensal: %.2f\n\n\n", ir);
}

