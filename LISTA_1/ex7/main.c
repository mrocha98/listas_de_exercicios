#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Elabore  um algoritmo e um programa em C que leia peso
e altura de uma pessoa e calcule o IMC, imprimindo o resultado na tela. */

//referência: http://www.calculoimc.com.br/como-calcular/
double calcula_imc(double peso, double altura){
    return peso/pow(altura, 2);
}

int main()
{
    double peso, altura;
    printf("Entre com seu peso em KG: "); scanf("%lf", &peso);
    printf("Entre com sua altura em M: "); scanf("%lf", &altura);
    printf("Seu IMC eh de %.2f\n", calcula_imc(peso, altura));
    return 0;
}
