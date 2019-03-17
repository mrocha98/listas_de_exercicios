#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Elabore  um algoritmo e um programa em C que leia a medida dos três lados de um triângulo
e determine se o triângulo é acutângulo, obtusângulo ou retângulo, imprimindo o resultado na tela.
*/

//aproveitando codigo do ex 3 xD
int triangulo_pode_existir(double a, double b, double c){
    int condicao_1 = (a > abs(b - c)) && (a < b + c);
    int condicao_2 = (b > abs(a - c)) && (b < a + c);
    int condicao_3 = (c > abs(a - b)) && (c < a + b);
    return condicao_1 && condicao_2 && condicao_3;
}

int descobre_maior(double a, double b, double c){
    double maior = a;
    if(b > maior)
        maior = b;
    if(c > maior)
        maior = c;
    return maior;
}

int descobre_menor(double a, double b, double c){
    double menor = a;
    if(b < menor)
        menor = b;
    if(c < menor)
        menor = c;
    return menor;
}

int descobre_meio_termo(double a, double b, double c){
    double maior = descobre_maior(a, b, c);
    double menor = descobre_menor(a, b, c);
    if(a != maior && a != menor)
        return a;
    if(b != maior && b != menor)
        return b;
    return c;
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
        if(todos_iguais)
            printf("Esses valores formam um triangulo acutangulo\n");
        else{
            double maior = descobre_maior(a, b, c);
            double menor = descobre_menor(a, b, c);
            double meio = descobre_meio_termo(a, b, c);

            double quad_maior = pow(maior, 2);
            double quad_meio = pow(meio, 2);
            double quad_menor = pow(menor, 2);

            int eh_retangulo = (quad_maior == quad_meio + quad_menor);
            int eh_obtusangulo = (quad_maior > quad_meio + quad_menor);

            if(eh_retangulo)
                printf("Esses valores formam um triangulo retangulo\n");
            else if(eh_obtusangulo)
                printf("Esses valores formam um triangulo obtusangulo\n");
            else
                printf("Esses valores formam um triangulo acutangulo\n");
        }
    }
    return 0;
}
