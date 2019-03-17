#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

/*3) Faça um programa que leia, via teclado, cinco números inteiros, calcule e mostre, 
conforme escolha do usuário:

a) O maior número dentre eles;
b) O menor número dentre eles.
c) a média aritmética entre eles;
d) a mediana entre eles;
e) a moda entre eles.
Use uma função para cada item.*/

int main(){
    int index = 5;
    int array[index];

    alimenta_vetor(array, index);
    printf("MAIOR: %d\n", encontra_maior(array, index));
    printf("MENOR: %d\n", encontra_menor(array, index));
    printf("MEDIA: %.3f\n", calcula_media(array, index));
    printf("MEDIANA: %.2f\n", descobre_mediana(array, index));
    printf("MODA: %d\n", descobre_moda(array, index));
    system("pause");
    return 0;
}