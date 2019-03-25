#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendario_permanente.h"

/*5) Faça um programa que simule um calendário permanente, isto é, o usuário digitará uma data e o programa 
retornará o dia da semana correspondente àquela data digitada. 
Dica: Use uma matriz bidimensional para armazenar os nomes dos dias da semana.
Algoritmo:
A = o inteiro de [(12 - Mês) ÷ 10]
B = Ano - A
C = Mês + (12 x A)
D = o inteiro de (B ÷ 100)
E = o inteiro de (D ÷ 4)
F = 2 - D + E
G = o inteiro de (365,25 x B)
H = o inteiro de [30,6001 x (C + 1)]
I = F + G + H + Dia + 5
J = o resto de (I ÷ 7), onde 0=SAB 1=DOM 2=SEG 3=TER 4=QUA 5=QUI 6=SEX*/

int main(){
    int dia, mes, ano;
    printf("Entre com o dia, mes e ano, respecitvamente:\n");
    scanf("%d%d%d", &dia, &mes, &ano);
    imprime_dia(dia, mes, ano);
    system("pause");
    return 0;
}