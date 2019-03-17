#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Elabore um algoritmo e um programa em C que leia a medida dos três lados de um triângulo
e calcule o perímetro e área, imprimindo o resultado na tela. */

/*
| b - c | < a < b + c
| a - c | < b < a + c
| a - b | < c < a + b
referencia = https://mundoeducacao.bol.uol.com.br/matematica/condicao-existencia-um-triangulo.html
*/
int triangulo_pode_existir(double a, double b, double c){
    int condicao_1 = (a > abs(b - c)) && (a < b + c);
    int condicao_2 = (b > abs(a - c)) && (b < a + c);
    int condicao_3 = (c > abs(a - b)) && (c < a + b);
    return condicao_1 && condicao_2 && condicao_3;
}

double calcula_perimetro(double a, double b, double c){
    return a + b + c;
}

/*
*utilizei a formula de heron, pois ela se aplica em qualquer tipo de triangulo
*referencia: https://www.todamateria.com.br/area-do-triangulo/
*/
double calcula_area(double a, double b, double c){
    double p = calcula_perimetro(a, b, c)/2.0;
    double p_menos_a = p - a;
    double p_menos_b = p - b;
    double p_menos_c = p - c;
    double s = sqrt(p * p_menos_a * p_menos_b * p_menos_c);
    return s;
}

int main()
{
    double a, b, c;
    printf("a: "); scanf("%lf", &a);
    printf("b: "); scanf("%lf", &b);
    printf("c: "); scanf("%lf", &c);
    if(triangulo_pode_existir(a,b,c))
        printf("PERIMETRO: %.3f\tAREA: %.3f", calcula_perimetro(a,b,c), calcula_area(a,b,c));
    else
        printf("Nao eh possivel formar um triangulo com esses valores...\n");
    return 0;
}
