
#include <stdio.h>
#include <stdlib.h>

/*
1. Escreva um trecho de codigo para fazer a criacao dos novos tipos de dados 
conforme solicitado abaixo:
• Horario: composto de hora, minutos e segundos. 
• Data: composto de dia, mes e ano. 
• Compromisso: composto de uma data, horario e texto que descreve o compromisso. 
*/

typedef struct horario {
    int hora;
    int minutos;
    int segundos;
} HOUR;

typedef struct data {
    int dia;
    int mes;
    int ano;
} DATE;

typedef struct compromisso {
    HOUR h;
    DATE d;
    char descricao[50+1];
} COMP;

int main()
{
    COMP c;
    printf("HORA: ");       scanf("%d", &c.h.hora); 
    printf("MINUTOS: ");    scanf("%d", &c.h.minutos);
    printf("SEGUNDOS: ");   scanf("%d", &c.h.segundos);
    printf("DIA: ");        scanf("%d", &c.d.dia);
    printf("MES: ");        scanf("%d", &c.d.mes);
    printf("ANO: ");        scanf("%d", &c.d.ano);
    printf("DESCRICAO: ");  fflush(stdin); gets(c.descricao);
    
    printf("HORA: %d\n", c.h.hora); 
    printf("MINUTOS: %d\n", c.h.minutos);
    printf("SEGUNDOS: %d\n", c.h.segundos);
    printf("DIA: %d\n", c.d.dia);
    printf("MES: %d\n", c.d.mes);
    printf("ANO: %d\n", c.d.ano);
    printf("DESCRICAO: %s\n\n", c.descricao);
    system("pause");
    return 0;
}