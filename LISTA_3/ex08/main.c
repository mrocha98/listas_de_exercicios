#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

/*8) Faça um programa para corrigir uma prova com 10 questões de múltipla escolha (a, b, c, d ou e), em uma turma com 3 alunos. Cada questão vale 1 ponto. Leia o gabarito, e para cada aluno leia sua matrícula (número inteiro) e suas respostas. Calcule e escreva, para cada aluno, sua matrícula, suas respostas, e sua nota. O percentual de aprovação, assumindo média 7.0.*/

int main(){
    define_gabarito();
    A a1, a2, a3;
    cadastra_aluno(&a1);
    cadastra_aluno(&a2);
    cadastra_aluno(&a3);
    printa_dados_aluno(&a1);
    printa_dados_aluno(&a2);
    printa_dados_aluno(&a3);
    printf("PERCENTUAL DE APROVACAO: %d%%\n", percentual_aprovacao(&a1, &a2, &a3));
    system("pause");
    return 0;
}


