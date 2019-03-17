#include <stdio.h>
#include <stdlib.h>

/*Elabore  um algoritmo e um programa em C que leia a medida dos três lados de um triângulo
e determine se o triângulo é equilátero, isósceles ou escaleno, imprimindo o resultado na tela.
*/

//aproveitando codigo do ex 3 xD
int triangulo_pode_existir(double a, double b, double c){
    int condicao_1 = (a > abs(b - c)) && (a < b + c);
    int condicao_2 = (b > abs(a - c)) && (b < a + c);
    int condicao_3 = (c > abs(a - b)) && (c < a + b);
    return condicao_1 && condicao_2 && condicao_3;
}

int main()
{
    double a, b, c;
    printf("a: "); scanf("%lf", &a);
    printf("b: "); scanf("%lf", &b);
    printf("c: "); scanf("%lf", &c);
    if(!triangulo_pode_existir(a,b,c))
        printf("Esses valores nao podem formar um triangulo\n");
    else{
        int todos_iguais = (a == b && a == c && b == c);
        int todos_diferentes = (a != b && a != c && b != c);
        if(todos_iguais)
            printf("Esses valores formam um triangulo equilatero\n");
        else if(todos_diferentes)
            printf("Esses valores formam um triangulo escaleno\n");
        else
            printf("Esses valores formam um triangulo isosceles\n");
    }
    return 0;
}
