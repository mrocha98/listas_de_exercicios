#include <stdio.h>
#include <stdlib.h>
#include "ir.h"
#include "classificacao.h"
#include "novo_salario.h"

void opcoes(){
    printf("\n==========\tMENU\t==========\n");
    printf("1.\tImposto\n2.\tNovo Salario\n3.\tClassificacao\n");
    printf("==================================\n\n>");
}

void menu(){
    char c;
    int n;
    do{
        opcoes();
        scanf("%d", &n);
        switch(n){
            case 1:
                imposto();
                break;
            case 2:
                novo_salario();
                break;
            case 3:
                classificacao();
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        printf("Continuar? [S/N]\n>"); scanf(" %c", &c);
    }while(c == 'S' || c == 's');
}
