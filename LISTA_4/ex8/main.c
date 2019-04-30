#include <stdio.h>
#include <stdlib.h>
#define TAM_NOME 20+1
#define TAM_RG 12+1

/*8- Crie um programa, utilizando um vetor de struct que guarda o nome, RG e ano de nascimento de, no máximo, 10 pessoas. 
O programa permite as seguintes funcionalidades, conforme escolha do usuário:
a - Cadastrar uma pessoa;
b - Calcular a idade de uma pessoa selecionada pelo usuário;
c - Listar pessoas que nasceram a partir de um determinado ano;
d - Listar pessoas que nasceram antes de um determinado ano;
e- Encontrar o nome de uma pessoa com determinado RG;
s- Sair.
O programa deverá ser executado em loop até o usuário digitar a opção s. Implemente funções para as opções disponíveis*/

typedef struct pessoa {
    char nome[TAM_NOME];
    char rg[TAM_RG];
    int ano_nasc;
} P;

P lista[10];

void cadastrar_pessoa(int pos){
    printf("NOME: "); scanf("%[^\n]s", lista[pos].nome); fflush(stdin);
    printf("RG: "); scanf("%[^\n]s", lista[pos].rg); fflush(stdin);
    printf("ANO NASCIMENTO: "); scanf("%d", &lista[pos].ano_nasc);
}

int calcular_idade(int ano_atual, int ano_pessoa){
    return ano_atual - ano_pessoa;
}

void listar_pessoa(int pos){
    printf("[%d]\n", pos);
    printf("NOME: %s\n", lista[pos].nome);
    printf("RG: %s\n", lista[pos].rg);
    printf("ANO NASCIMENTO: %d\n----------\n", lista[pos].ano_nasc);
}

void listar_todas_pessoas(int pos){
    for(int i = 0; i < pos; i++){
        listar_pessoa(i);
    }
}

void listar_apartir_ano(int pos, int ano){
    for(int i = 0; i < pos; i++){
        if((int)lista[i].ano_nasc >= ano)
            listar_pessoa(i);
    }
}

void listar_abaixo_ano(int pos, int ano){
    for(int i = 0; i < pos; i++){
        if((int)lista[i].ano_nasc < ano)
            listar_pessoa(i);
    }
}

void encontra_pessoa(int pos, char rg[]){
    for(int i = 0; i < pos; i++){
        if(lista[i].rg == rg)
            printf("%s\n", lista[i].nome);
    }
}

void txt_menu(){
    printf("a. Cadastrar uma pessoa\n");
    printf("b. Calcular idade de uma dada pessoa\n");
    printf("c. Listar todas pessoas que nasceram apartir de um dado ano\n");
    printf("d. Listar todas pessoas que nasceram antes de um dado ano\n");
    printf("e. Encontrar o nome de uma pessoa apartir de um dado RG\n");
    printf("s. Sair\n|\n|->\t");
}

void menu(){
    int n, ano, pos = 0;
    char op;
    char rg[TAM_RG];
    while(1){
        txt_menu();
        scanf(" %c", &op);
        fflush(stdin);
        switch (op){
        case 'a':
            cadastrar_pessoa(pos); pos++; break;
        case 'b':
            listar_todas_pessoas(pos);
            scanf("%d", &n);
            printf("Ano atual: "); scanf("%d", &ano);
            printf("%d anos\n", calcular_idade(ano, (int)lista[n].ano_nasc));
        break;
        case 'c':
            scanf("%d", &ano);
            listar_apartir_ano(pos, ano);
        break;
        case 'd':
            scanf("%d", &ano);
            listar_abaixo_ano(pos, ano);
        break;
        case 'e':
            scanf("%[^\n]s", rg);
            encontra_pessoa(pos, rg);
        break;
        case 's':
            printf("saindo...\n\n");
            return;
        default: printf("\nOpcao invalida...\n"); break;
        }
    }
}

int main(){
    menu();
    system("pause");
    return 0;
}