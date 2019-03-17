#ifndef _HEADER_H_
#define _HEADER_H_

const int TAM_NOME = 20+1;

typedef struct ALUNO{
    char nome[TAM_NOME];
    int matricula;
    char respostas[10];
    int nota;
    int aprovado;
}A;


void define_gabarito();
void printa_gabarito();
void cadastra_respostas(A *AL);
void printa_respostas(A *AL);
void cadastra_aluno(A *AL);
void printa_dados_aluno(A *AL);
int calcula_nota(A *AL);
int aluno_foi_aprovado(A *AL);
int percentual_aprovacao(A *AL1, A *AL2, A *AL3);

#endif

