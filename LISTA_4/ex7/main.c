#include <stdio.h>
#include <stdlib.h>

/*7- Use estrutura
typedef struct
{
char nome[31];
int idade;
} PESSOA;
e elabore um programa para cadastrar 10 pessoas.*/

typedef struct pessoa {
    char nome[30+1];
    int idade;
} PESSOA;

PESSOA lista[10];

void cadastra_pessoa(int pos){
    printf("NOME:\t\t"); scanf("%[^\n]s", lista[pos].nome); fflush(stdin);
    printf("IDADE:\t\t"); scanf("%d", &lista[pos].idade);
}

void listar_pessoa(int pos){
    printf("\n[%d]...\n", pos+1);
    printf("\tNOME:\t\t%s\n", lista[pos].nome);
    printf("\tIDADE:\t\t%d\n", lista[pos].idade);
    printf("-----------------------------\n");
}

void listar_todas(int pos){
    for(int i = 0; i < pos; i++){
        listar_pessoa(i);
    }
}

void txt_menu(){
    printf("\n------\tMENU\t------\n");
    printf("1. Cadastrar pessoa\n");
    printf("2. Listar pessoas\n");
    printf("3. Sair\n|\n|->\t");
}

void menu(){
    int op, pos=0;
    while(1){
        txt_menu();
        fflush(stdin);
        scanf("%d", &op);
        fflush(stdin);
        switch(op){
            case 1: cadastra_pessoa(pos); pos++; break;
            case 2: listar_todas(pos); break;
            case 3: printf("Saindo...\n"); return;
            default: printf("Opcao invalida...\n");
        }
    }
}

int main(){
    menu();
    system("pause");
    return 0;
}