#include <stdio.h>
#include <stdlib.h>
#ifndef PI
#define PI 3.1415
#endif
#include <math.h>

/*1–Faça um programa que use uma estrutura para armazenar os atributos de uma circunferência C,isto é,
raio e centro. O programa deve permitir as seguintes funcionalidades: a) calcular comprimento da circunferência
b) calcular a área do círculo envolto pela circunferência. Use funções.
*/

float calcula_area(float raio){
    return (pow(raio, 2) * PI);
}

float calcula_perimetro(float raio){
    return (PI * 2 * raio);
}

int main(){
    float raio;
    scanf("%f", &raio);
    printf("RAIO: %.2f\tPERIMETRO: %.2f\tAREA: %.2f\n", raio, calcula_perimetro(raio), calcula_area(raio));
    system("pause");
    return 0;
}
