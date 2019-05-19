#include <stdio.h>
#include <stdlib.h>

/*8. Faça um programa que armazene em um registro de dados (estrutura composta) os dados de um funcionario 
de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF,Data de Nascimento, Codigo do Setor onde trabalha (0-99), 
Cargo que ocupa (string de ate 30 caracteres) e Salario. Os dados devem ser digitados pelo usuario, armazenados na 
estrutura e exibidos na tela.*/

typedef struct data {
    int dia;
    int mes;
    int ano;
} DATE;

typedef struct funcionario {
    char nome[30+1];
    int idade;
    char sexo;
    char cpf[14+1];
    DATE dataNasc;
    int codigoSetor;
    char cargo[30+1];
    float salario;
} F;

F func;

void cadastra(){
    printf("NOME: "); fflush(stdin); scanf("%[^\n]s", func.nome);
    printf("IDADE: "); scanf("%d", &func.idade);
    printf("SEXO: [M/F]\t"); fflush(stdin); scanf(" %c", &func.sexo);
    printf("CPF: "); fflush(stdin); scanf("%[^\n]s", func.cpf);
    printf("DATA DE NASCIMENTO\nDIA: "); scanf("%d", &func.dataNasc.dia);
    printf("MES: "); scanf("%d", &func.dataNasc.mes);
    printf("ANO: "); scanf("%d", &func.dataNasc.ano);
    printf("CODIGO SETOR: "); scanf("%d", &func.codigoSetor);
    printf("CARGO: "); fflush(stdin); scanf("%[^\n]s", func.cargo); fflush(stdin);
}

void printaFuncionario(){
    printf("\nNOME: %s\n", func.nome);
    printf("IDADE: %d\n", func.idade);
    printf("SEXO: %c\n", func.sexo);
    printf("CPF: %s\n", func.cpf);
    printf("DATA NASC:\t%d/%d/%d\n", func.dataNasc.dia, func.dataNasc.mes, func.dataNasc.ano);
    printf("CODIGO SETOR: %d\n", func.codigoSetor);
    printf("CARGO: %s\n\n", func.cargo);
}

int main(){
    cadastra();
    printaFuncionario();
    system("pause");
    return 0;
}