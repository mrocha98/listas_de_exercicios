#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

char gabarito[10];

void define_gabarito(){
    printf("-----------\tDEFININDO RESPOSTAS NO GABARITO\t-----------\n");
    char alternativa;
    for(int i = 0; i < 10; i++){
        printf("%d.\t", i+1);
        scanf(" %c", &alternativa);
        gabarito[i] = alternativa;
    }
    printf("\n------------------------------------------------------------\n");
}

void printa_gabarito(){
    printf("-----------\tGABARITO\t-----------\n");
    for(int i = 0; i < 10; i++){
        printf("%d.\t%c\n", i+1,gabarito[i]);
    }
    printf("\n-----------------------------------------------\n");
}

void cadastra_respostas(A *AL){
    printf("RESPOSTAS...\n");
    for(int i = 0; i < 10; i++){
        printf("%d. \t", i+1); scanf(" %c", &AL->respostas[i]);
    }
    printf("\n\n");
}

void printa_respostas(A *AL){
    printf("RESPOSTAS...\n");
    for(int i = 0; i < 10; i++){
        printf("%d.\t%c\n", i+1, AL->respostas[i]);
    }
    printf("\n");
}

int calcula_nota(A *AL){
    int nota = 0;
    for(int i = 0; i < 10; i++){
        if(gabarito[i] == AL->respostas[i])
            nota++;
    }
    return nota;
}

int aluno_foi_aprovado(A *AL){
    return (AL->nota >= 7);
}

int percentual_aprovacao(A *AL1, A *AL2, A *AL3){
    int soma = 0;
    printf("%d %d %d\n", AL1->aprovado, AL2->aprovado, AL3->aprovado);
    if((AL1->aprovado) == 1)
        soma++;
    printf("\n\t%d\t", soma);
    if((AL2->aprovado) == 1)
        soma++;
    printf("\t%d\t", soma);
    if((AL3->aprovado) == 1)
        soma++;
    printf("\t%d\n", soma);
    return ((soma * 100) / 3);
}

void cadastra_aluno(A *AL){
    printf("\n----------------------- CADASTRO ---------------------------\n");
    char aux[TAM_NOME];
    printf("NOME: ");
    memset(AL->nome, '\0', sizeof(AL->nome));
    scanf("%s", aux);
    strcpy(AL->nome, aux);
    free(AL->nome);
    printf("MATRICULA: ");
    scanf("%d", &AL->matricula);
    cadastra_respostas(*&AL);
    int nota = calcula_nota(*&AL);
    *&AL->nota = {nota};
    int aprovado = aluno_foi_aprovado(*&AL);
    *&AL->aprovado = {aprovado};
    printf("\n------------------------------------------------------------\n");
}

void printa_dados_aluno(A *AL){
    printf("\n------------------------------------------------------------\n");
    printf("NOME: %s\n", AL->nome);
    printf("MATRICULA: %d\n", AL->matricula);
    printf("NOTA: %d\n", AL->nota);
    char apr[10+1];
    memset(apr, '\0', sizeof(apr));
    if(AL->aprovado == 1)
        strcpy(apr, "APROVADO");
    else 
        strcpy(apr, "REPROVADO");
    printf("SITUACAO: %s\n", apr);
    printa_respostas(*&AL);
    printf("\n------------------------------------------------------------\n");
}


