#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*ax² + bx + c = 0*/

double calcula_delta(double a, double b, double c){
    double delta = pow(b, 2) - 4 * a * c;
    if(delta < 0)
        return -1;
    return delta;
}

double calcula_x1(double a, double b, double c){
    double delta = calcula_delta(a, b, c);
    return (-b + sqrt(delta))/(2*a);
}

double calcula_x2(double a, double b, double c){
    double delta = calcula_delta(a, b, c);
    return (-b - sqrt(delta))/(2*a);
}

int main()
{
    double a, b, c;
    printf("Entre com os valores de a, b e c, respectivamente: \n"); scanf("%lf%lf%lf", &a, &b, &c);
    int todos_valores_nulos = (a == 0 && b == 0 && c == 0);
    if(todos_valores_nulos){
        printf("Valores nulos...\n");
        exit(1);
    }
    int delta_negativo = (calcula_delta(a, b, c) == -1);
    if(delta_negativo)
        printf("Delta negativo! As raizes nao pertencem aos nums reais!\n");
    else{
        printf("X1: %.3f\n", calcula_x1(a, b, c));
        printf("X2: %.3f\n", calcula_x2(a, b, c));
    }
    return 0;
}
