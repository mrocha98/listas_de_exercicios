#include <stdio.h>
#include <stdlib.h>
#ifndef INDEX
#define INDEX 5
#endif // INDEX

/*4.  Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matrıcula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
(a)  Permita ao usuario entrar com os dados de 5 alunos.
(b)  Encontre o aluno com maior nota da primeira prova.
(c)  Encontre o aluno com maior media geral.
(d)  Encontre o aluno com menor media geral
(e)  Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovacao.*/

typedef struct notas {
    float nota1;
    float nota2;
    float nota3;
    float media;
} N;

typedef struct aluno {
    char nome[50+1];
    unsigned long int matricula;
    N notas;
    int aprovado;
} AL;

AL alunos[INDEX];

float calculaMedia(float n1, float n2, float n3){
    return ((n1+n2+n3)/3.0);
}

void cadastraAluno(int i){
    printf("[%d]\tCADASTRO DE ALUNO:\n\t", i+1);
    printf("NOME: "); scanf("%[^\n]s", alunos[i].nome);
    printf("\tMATRICULA: "); scanf("%lu", &alunos[i].matricula);

    float n1, n2, n3;
    printf("\tNOTA PROVA 1: "); scanf("%f", &n1); alunos[i].notas.nota1 = n1;
    printf("\tNOTA PROVA 2: "); scanf("%f", &n2); alunos[i].notas.nota2 = n2;
    printf("\tNOTA PROVA 3: "); scanf("%f", &n3); alunos[i].notas.nota3 = n3;
    printf("------------------------------\n\n");

    alunos[i].notas.media = calculaMedia(n1, n2, n3);
    alunos[i].aprovado = (alunos[i].notas.media >= 6);
    fflush(stdin);
}

void printaAluno(int i){
    printf("[%d]\n\t", i+1);
    printf("NOME: %s\n", alunos[i].nome);
    printf("\tMATRICULA: %lu\n", alunos[i].matricula);
    printf("\tNOTA PROVA 1: %.1f\n", alunos[i].notas.nota1);
    printf("\tNOTA PROVA 2: %.1f\n", alunos[i].notas.nota2);
    printf("\tNOTA PROVA 3: %.1f\n", alunos[i].notas.nota3);
    printf("\tMEDIA: %.1f\n", alunos[i].notas.media);
    printf("\tSITUACAO: "); if(alunos[i].aprovado) printf(" APROVADO\n"); else printf(" REPROVADO\n");
    printf("------------------------------\n\n");
}

int encontraMaiorPrimeira(){
    float maior = alunos[0].notas.nota1;
    int index_maior = 0;
    for(int i = 1; i < INDEX; i++){
        if(alunos[i].notas.nota1 > maior){
            maior = alunos[i].notas.nota1;
            index_maior = i;
        }
    }
    return index_maior;
}

int encontraMaiorMedia(){
    float maior = alunos[0].notas.media;
    int index_maior = 0;
    for(int i = 1; i < INDEX; i++){
        if(alunos[i].notas.media > maior){
            maior = alunos[i].notas.media;
            index_maior = i;
        }
    }
    return index_maior;
}

int encontraMenorMedia(){
    float menor = alunos[0].notas.media;
    int index_menor = 0;
    for(int i = 1; i < INDEX; i++){
        if(alunos[i].notas.media < menor){
            menor = alunos[i].notas.media;
            index_menor = i;
        }
    }
    return index_menor;
}

int main()
{
    for(int i = 0; i < INDEX; i++){
        cadastraAluno(i);
    }
    printf("\nALUNOS CADASTRADOS NO SISTEMA...\n\n");
    for(int i = 0; i < INDEX; i++){
        printaAluno(i);
    }
    int maiorNota1, maiorMedia, menorMedia;
    maiorNota1 = encontraMaiorPrimeira();
    maiorMedia = encontraMaiorMedia();
    menorMedia = encontraMenorMedia();

    //printf("%d,%d,%d\n", maiorNota1, maiorMedia, menorMedia);
    printf("A MAIOR NOTA DA PROVA 1 FOI %.1f DO ALUNO %s\n", alunos[maiorNota1].notas.nota1, alunos[maiorNota1].nome);
    printf("A MAIOR MEDIA FOI %.1f DO ALUNO %s\n", alunos[maiorMedia].notas.media, alunos[maiorMedia].nome);
    printf("A MENOR MEDIA FOI %.1f DO ALUNO %s\n", alunos[menorMedia].notas.media, alunos[menorMedia].nome);
    system("pause");
    return 0;
}