#include <stdio.h>
#include <stdlib.h>

/*Elabore um algoritmo e um programa em C que leia os coeficientes a e b de uma função
 de 1º grau e calcule x para y=0 ( y=ax+b), imprimindo o resultado na tela.*/

int main()
{
    double a, b, x;
    printf("Entre com a e b, respectivamente: \n");
    scanf("%lf%lf", &a, &b);
    x = -b/a;
    printf("\nPara y = %.3fx + %.3f, x == %.3f\n", a, b, x);
    return 0;
}
