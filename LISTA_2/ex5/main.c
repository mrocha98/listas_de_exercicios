#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex5.h"

/*5) Faça um programa que contenha as seguintes características
a) variáveis -> char nome[20], int idade, float peso e float altura
b) funções -> void envelhecer(int anos), void engordar(float kg),
 void emagrecer(float kg), void crescer(), float Imc (float peso,  float altura)
Obs: Por padrão, a cada ano que a pessoa envelhece, sendo a idade dela menor que 21 anos,
ela deve crescer 0,5 cm.
A função main fornecerá um menu para que o usuário escolha a opção desejada.*/

void opcoes(){
    printf("-------------------------------------\n");
    printf("1. Alterar dados\n2. Envelhecer\n3. Engordar\n4. Emagrecer\n5. Crescer\n6. IMC\n\n>");
}

int main(){
    PESSOA p;
    int op, anos;
    char continuar;
    float kg;
    cria_pessoa(&p);
    do{
        opcoes();
        scanf("%d", &op);
        switch (op)
        {   
            case 1:
                cria_pessoa(&p);
                break;
            case 2:
                printf("Quantos anos? "); scanf("%d", &anos);
                envelhecer(anos, &p);
                break;
            case 3:
                printf("Quantos KG? "); scanf("%f", &kg);
                engordar(kg, &p);
                break;
            case 4:
                printf("Quantos KG? "); scanf("%f", &kg);
                emagrecer(kg, &p);
                break;
            case 5:
                crescer(&p);
                break;
            case 6:
                printf("IMC: %.2f\n\n", Imc(p.peso, p.altura));
                break;    
            default:
                printf("Opcao invalida...\n");
                break;
        }
        printf("Continuar? [S/N] "); scanf(" %c", &continuar);
    }while(continuar == 'S' || continuar == 's');
    printf("\n\nsaindo....\n");
    system("pause");
    return 0;
}
