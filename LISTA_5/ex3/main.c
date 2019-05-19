#include <stdio.h>
#include <stdlib.h>
#define INDEX 5
/*3.  Construa uma estrutura aluno com nome, numero de matrıcula e curso. Leia do usuario
a informacao de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na tela*/

typedef struct aluno {
    char nome[50+1];
    unsigned long int matricula;
    char curso[30+1];
} AL;

int main(){
    AL alunos[INDEX];

    for(int i = 0; i < INDEX; i++){
        printf("[%d]\tCADASTRO DE ALUNO:\n\t", i+1);
        printf("NOME: "); scanf("%[^\n]s", alunos[i].nome);
        printf("\tMATRICULA: "); scanf("%lu", &alunos[i].matricula);
        printf("\tCURSO: "); fflush(stdin); scanf("%[^\n]s", alunos[i].curso);
        printf("------------------------------\n\n");
        fflush(stdin);
    }

    printf("ALUNOS CADASTRADOS NO SISTEMA...\n\n");
    for(int i = 0; i < INDEX; i++){
        printf("[%d]\n\t", i+1);
        printf("NOME: %s\n", alunos[i].nome);
        printf("\tMATRICULA: %lu\n", alunos[i].matricula);
        printf("\tCURSO: %s\n", alunos[i].curso);
        printf("------------------------------\n\n");
    }

    system("pause");
    return 0;
}