#include <stdio.h>
#include <stdlib.h>
#define QTD_ALUNOS 10

/*6. Faca um programa que realize a leitura dos seguintes dados relativos a um conjunto dealunos: 
Matricula, Nome, Codigo da Disciplina, Nota1 e Nota2. Considere uma turma de ate 10 alunos. Apos ler 
todos os dados digitados, e depois de armazena-los em um vetor de estrutura, exibir na tela a listagem 
final dos alunos com as suas respectivas medias finais (use uma media ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).*/

typedef struct notas {
    float n1;
    float n2;
    float media;
} N;

typedef struct aluno {
    int matricula;
    char nome[25+1];
    int codigoDisciplina;
    N notas;
    int aprovado;
} AL;

AL alunos[QTD_ALUNOS];

float calculaMedia(float n1, float n2){
    return ((n1 + n2 * 2)/3);
}

int alunoFoiAprovado(float media){
    return (media >= 6);
}

void listaAlunos(){
    for(int i = 0; i < QTD_ALUNOS; i++){
        printf("MATRICULA: %d\n", alunos[i].matricula);
        printf("ALUNO: %s\n", alunos[i].nome);
        printf("CODIGO DISCIPLINA: %d\n", alunos[i].codigoDisciplina);
        printf("NOTA 1: %.2f\n", alunos[i].notas.n1);
        printf("NOTA 2: %.2f\n", alunos[i].notas.n2);
        printf("MEDIA: %.2f\n", alunos[i].notas.media);
        if(alunos[i].aprovado)
            printf("SITUACAO: APROVADO\n\n");
        else
            printf("SITUACAO: REPROVADO\n\n");
    }
}

void cadastraAlunos(){
    for(int i = 0; i < QTD_ALUNOS; i++){
        printf("MATRICULA: "); scanf("%d", &alunos[i].matricula);
        printf("ALUNO: "); fflush(stdin); scanf("%[^\n]s", alunos[i].nome);
        printf("CODIGO DISCIPLINA: "); scanf("%d", &alunos[i].codigoDisciplina);
        printf("NOTA 1: "); scanf("%f", &alunos[i].notas.n1);
        printf("NOTA 2: "); scanf("%f", &alunos[i].notas.n2);
        alunos[i].notas.media = calculaMedia(alunos[i].notas.n1, alunos[i].notas.n2);
        alunos[i].aprovado = alunoFoiAprovado(alunos[i].notas.media);
        printf("\n");
    }
}

int main(){
    cadastraAlunos();
    listaAlunos();
    system("pause");
    return 0;
}