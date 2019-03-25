#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendario_permanente.h"

int get_a(int mes){
    return ((12 - mes)/10);
}

int get_b(int mes, int ano){
    return (ano - get_a(mes));
}

int get_c(int mes){
    return (mes + (12 * get_a(mes)));
}

int get_d(int mes, int ano){
    return (int) (get_b(mes, ano) / 100);
}

int get_e(int mes, int ano){
    return (int) (get_d(mes, ano) / 4);
}

int get_f(int mes, int ano){
    return (2 - get_d(mes, ano) + get_e(mes, ano));
}

int get_g(int mes, int ano){
    return (int) (365.25 * get_b(mes, ano));
}

int get_h(int mes){
    return (int) (30.6001 * (get_c(mes) + 1));
}

int get_i(int dia, int mes, int ano){
    return (get_f(mes, ano) + get_g(mes, ano) + get_h(mes) + dia + 5);
}

int get_j(int dia, int mes, int ano){
    return (get_i(dia, mes, ano) % 7);
}

void imprime_dia(int dia, int mes, int ano){
    int j = get_j(dia, mes, ano);
    char dia_semana[3+1];
    switch(j){
        case 0:
            strcpy(dia_semana, "SAB");
        break;
        case 1:
            strcpy(dia_semana, "DOM");
        break;
        case 2:
            strcpy(dia_semana, "SEG");
        break;
        case 3:
            strcpy(dia_semana, "TER");
        break;
        case 4:
            strcpy(dia_semana, "QUA");
        break;
        case 5:
            strcpy(dia_semana, "QUI");
        break;
        case 6:
            strcpy(dia_semana, "SEX");
        break;
    }
    printf("%02d/%02d/%04d foi %s\n", dia, mes, ano, dia_semana);
}