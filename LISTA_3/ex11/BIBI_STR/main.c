#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caracteres.h"

/*11)  Considerando o código do projeto BBI_STR que referes-e ao uso de biblioteca e strings, 
adicione à biblioteca "caracteres.h" e implemente  mais essas funções:
a) int conta_vogais (char s[]);
b) void substitui_vogais_por_asterisco(char s[]); 
c) void conta_consoante( (char s[])
Modifique a  função main.c de forma  a permitir o  teste das novas funcionalidade da biblioteca.*/

void msg(){
    printf("\tMENU DE OPCOES\n");
    printf("1. Contar caracteres\n");
    printf("2. Substituir caracter por *\n");
    printf("3. Contar vogais\n");
    printf("4. Substituir vogais por *\n");
    printf("5. Contar consoantes\n");
    printf("6. Voltar os nomes ao normal\n");
    printf("7. Trocar caractere\n|\n->\t");
}

void printa_nomes(char s[][10+1]){
    for(int i = 0; i < 3; i++){
        printf("%s\n", s[i]);
    }
}

int main(){
    char s[3][10+1], s_backup[3][10+1];
    char letra;
    printf("Digite nomes:\n");
    for(int i = 0; i < 3; i++){
        printf("NOME %d:\t", i+1);
        scanf("%s", s[i]);
        strcpy(s_backup[i], s[i]);
    }

    printf("Entre com um caracter:\t"); scanf(" %c", &letra);
    int op = 0;
    char continuar;
    fflush(stdin);
    do{
        msg();
        scanf("%d", &op);
        switch (op){
            case 1:
                for(int i = 0; i < 3; i++){
                    printf("%s:\t%d caracteres\n", s[i], conta_caracter(s[i], letra));
                }
            break;
            case 2:
                for(int i = 0; i < 3; i++){
                    substitui_caracter(s[i], letra);
                }
                printa_nomes(s);
            break;
            case 3:
                for(int i = 0; i < 3; i++){
                    printf("%s: %d vogais\n", s[i], conta_vogais(s[i]));
                }
            break;
            case 4:
                printf("Novos nomes: \n");
                for(int i = 0; i < 3; i++){
                    substitui_vogais_por_asterisco(s[i]);
                    printa_nomes(s);
                }
            break;
            case 5:
                for(int i = 0; i < 3; i++){
                    printf("%s: %d consoantes\n", s[i], conta_consoante(s[i]));
                }
            break;
            case 6:
                for(int i = 0; i < 3; i++){
                    strcpy(s[i], s_backup[i]);
                }
                printf("Nomes voltaram ao normal...\n");
            break;
            case 7:
                fflush(stdin);
                scanf(" %c", &letra);
            break;
            default:
                printf("\nOpcao invalida...\n");
        }
        fflush(stdin);
        printf("Continuar? [S/N]\t"); scanf(" %c", &continuar);
    }while(continuar == 's' || continuar == 'S');
    printf("Saindo...\n");
    system("pause");
    return 0;
}
