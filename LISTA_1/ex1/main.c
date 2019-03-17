#include <stdio.h>
#include <stdlib.h>

/*
*Elabore  um algoritmo e um programa a em C que leia o tamanho do lado de um retângulo
*e calcule o perímetro e área, imprimindo o resultado na tela
*/

double calcula_perimetro(double l1, double l2){
    return (2 * l1 + 2 * l2);
}

double calcula_area(double l1, double l2){
    return l1 * l2;
}

int main(){
    double lado1, lado2, area, perimetro;
    printf("LADO 1: "); scanf("%lf", &lado1);
    printf("LADO 2: "); scanf("%lf", &lado2);
    area = calcula_area(lado1, lado2);
    perimetro = calcula_perimetro(lado1, lado2);
    printf("PERIMETRO: %.2f\tAREA: %.2f\n", perimetro, area);
    return 0;
}
