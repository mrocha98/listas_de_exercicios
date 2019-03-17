#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex7.h"

//a
void ler_s1(STR *string){
    printf("Entre com a String 1: ");
    char temp [20+1];
    scanf("%s", temp);
    strcpy(string->S1, temp);   
}

void ler_s2(STR *string){
    printf("Entre com a String 2: ");
    char temp [20+1];
    scanf("%s", temp);
    strcpy(string->S2, temp);
}

//b
void imprime_tamanho_S1(STR *string){
    int tamanho = strlen(string->S1);
    printf("TAMANHO: %d\n", tamanho);
}

//c
int compara(STR *string){
    ler_s2(&*string);
    int len_s1 = strlen(string->S1);
    int len_s2 = strlen(string->S2);
    if(len_s1 != len_s2){
        printf("Strings diferentes\n");
        return 0;
    }
    for(int i = 0; i < len_s1; i++){
        if(string->S1[i] != string->S2[i]){
            printf("Strings diferentes\n");
            return 0;
        }
    }
    printf("Strings iguais\n");
    return 1;
}

//d
void concatena(STR *string){
    ler_s2(&*string);
    printf("%s\n", strcat(string->S1,string->S2));
}

//e
void inverte(STR *string){
    int len = strlen(string->S1);
    for(int i = len - 1; i >= 0; i--){
        printf("%c", string->S1[i]);
    }
    printf("\n");
}

//f
int conta_caracter(STR *string, char c){
    int cont = 0;
    for(int i = 0; i < strlen(string->S1); i++){
        if(string->S1[i] == c)
            cont++;
    }
    return cont;
}

//g
void substitui_primeira_ocorrencia(STR *string, char c1, char c2){
    for(int i = 0; i < strlen(string->S1); i++){
        if(string->S1[i] == c1){
            string->S1[i] = c2;
            break;
        }
    }
    printf("%s\n", string->S1);
}
