#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex7.h"

/*7) Faça um programa que contenha um menu com as seguintes opções:

(a) Ler uma string S1 (tamanho máximo 20 caracteres);
(b) Imprimir o tamanho da string S1;
(c) Comparar a string S1 com uma nova string S2 fornecida pelo usuário e imprimir o resultado da comparação;
(d) Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenação;
(e) Imprimir a string S1 de forma reversa;
(f) Contar quantas vezes um dado caractere aparece na string S1. Esse caractere deve ser informado pelo usuário;
(g) Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2. Os caracteres C1 e C2 serão lidos via teclado.
 */

void msg(){
    printf("=================================================================\n");
    printf("(a) Ler uma string S1 (tamanho máximo 20 caracteres)\n");
    printf("(b) Imprimir o tamanho da string S1;\n");
    printf("(c) Comparar a string S1 com uma nova string S2\n");
    printf("(d) Concatenar a string S1 com uma nova string S2\n");
    printf("(e) Imprimir a string S1 de forma reversa;\n");
    printf("(f) Contar quantas vezes um dado caractere aparece na string S1.\n");
    printf("(g) Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2.\n\n>");
}

void menu(STR *string){
    ler_s1(&*string);
    char continuar;
    char op;
    do{
        msg();
        scanf(" %c", &op);
        switch(op){
            case 'a':
                ler_s1(&*string);
                break;
            case 'b':
                imprime_tamanho_S1(&*string);
                break;
            case 'c':
                compara(&*string);
                break;
            case 'd':
                concatena(&*string);
                break;
            case 'e':
                inverte(&*string);
                break;
            case 'f':
                char c;
                scanf(" %c", &c);
                printf("%d vezes\n", conta_caracter(&*string, c));
                break;
            case 'g':
                char c1, c2;
                scanf(" %c", &c1);
                scanf(" %c", &c2);
                substitui_primeira_ocorrencia(&*string, c1, c2);
                break;
            default:
                printf("Opcao invalida...\n");
                break;
        }
        printf("Continuar? [S/N]\t"); scanf(" %c", &continuar);
    }while(continuar == 'S' || continuar == 's');
}

int main(){
    STR s;
    menu(&s);
    printf("\nsaindo....\n");
    system("pause");
    return 0;
}