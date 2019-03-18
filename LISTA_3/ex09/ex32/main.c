#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Leia uma cadeia de caracteres no formato “DD/MM/AAAA” e copie o dia,
mes e ano para 3 variaveis inteiras. Antes disso, verifique se as barras estao 
no lugar certo, e se DD, MM e AAAA sao númericos.*/

typedef struct DATA {
    char str[10+1];
    int dia;
    int mes;
    int ano;
} D;

int barras_nas_posicoes_corretas(char str[]){
    int barra_D_M = (str[2] == '/');
    int barra_M_A = (str[5] == '/');
    return barra_D_M && barra_M_A;
}

int sao_numericos(char str[]){
    for(int i = 0; i < strlen(str); i++){
        if(i == 2 || i == 5)
            continue;
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

/*
D = 0
D = 1
/ = 2
M = 3
M = 4
/ = 5
A = 6
A = 7
A = 8
A = 9
*/

int main(){
    D d;
    char data[10+1];
    printf("DD/MM/AAAA:\t"); 
    scanf("%s", data);
    strcpy(d.str, data);
    if(barras_nas_posicoes_corretas(d.str) && sao_numericos(d.str)){
        int dia = atoi(&d.str[0]);
        int mes = atoi(&d.str[3]);
        int ano = atoi(&d.str[6]);
        d.dia = dia;
        d.mes = mes;
        d.ano = ano;
        printf("DIA: %d\nMES: %d\nANO: %d\n\n", d.dia, d.mes, d.ano);
    }else{
        printf("ERRO, FORMATACAO INVALIDA...\n");
    }
    system("pause");
    return 0;
}