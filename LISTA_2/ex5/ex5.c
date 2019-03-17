#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ex5.h"

void envelhecer(int anos, PESSOA *p){
    printf("%s tinha %d anos...\n", p->nome, p->idade);
    for(int i = 0; i < anos; i++){
        printf("\t");
        crescer(p);
    }
    printf("... agora tem %d anos\n\n", p->idade);
}

void engordar(float kg, PESSOA *p){
    printf("%s teve o peso alterado de %f para ", p->nome, p->peso);
    p->peso += kg;
    printf("%f\n\n", p->peso);
}

void emagrecer(float kg, PESSOA *p){
    printf("%s teve o peso alterado de %f para ", p->nome, p->peso);
    p->peso -= kg;
    printf("%f\n\n", p->peso);
}

void crescer(PESSOA *p){
    printf("%s teve a altura alterada de %f para ", p->nome, p->altura);
    if((p->idade) < 21)
        p->altura += 0.005;
    printf("%f\n\n", p->altura);
}

float Imc(float peso, float altura){
    return peso / pow(altura, 2);
}

void cria_pessoa(PESSOA *p){
    printf("----------\tCADASTRO\t----------\n");
    char str_nome[20+1];
    printf("NOME:\t"); scanf("%s", str_nome);
    strcpy(p->nome, str_nome);
    printf("\nIDADE:\t"); scanf("%d", &(p->idade));
    printf("\nPESO:\t"); scanf("%f", &(p->peso));
    printf("\nALTURA:\t"); scanf("%f", &(p->altura));
    printf("\n\n----------CADASTRO EFETUADO----------\n\n");
}

void relatorio(PESSOA *p){
    printf("NOME: %s\n", p->nome);
    printf("IDADE: %d\n", p->idade);
    printf("PESO: %.2f\n", p->peso);
    printf("ALTURA: %.2f\n", p->altura);
}