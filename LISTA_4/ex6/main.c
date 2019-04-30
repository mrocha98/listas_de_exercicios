#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 100
#define TAM_NOME 20+1
#define TAM_HORA 5+1

/*6-Uma igreja deseja cadastrar os casamentos ocorridos. Usando a linguagem C e struct, implemente:
a) uma função de cadastro capaz de armazenar nome da noiva, nome do noivo, nomes do pai e da mãe de 
cada cônjuge, dia, mês, ano e hora da cerimônia.
b) uma função que lista todas as cerimônias ocorridas em uma determinada data, passada como parâmetro.
c) uma função que fornece o nome do futuro cônjuge, a partir do nome de um dos nubentes.
d)  uma função que fornece a data e o horário da cerimônia, a partir dos nomes dos noivos.
e) main(): oferece menu para o usuário escolher a operação desejada.*/

typedef struct conjuge {
    char nome_conjuge[TAM_NOME];
    char nome_pai[TAM_NOME];
    char nome_mae[TAM_NOME];
} CON;

typedef struct data {
    int dia;
    int mes;
    int ano;
    char hora[TAM_HORA];
} D;

typedef struct casamento {
    CON noivo;
    CON noiva;
    D data;
} CAS;

CAS lista[LIMITE];

void cadastra_noivo(int pos){
    printf("\n--- DADOS DO NOIVO:\n");    fflush(stdin);
    printf("\tNOME DO NOIVO:\t\t\t");   scanf("%[^\n]s", lista[pos].noivo.nome_conjuge); fflush(stdin);
    printf("\tNOME DA MAE:\t\t\t");     scanf("%[^\n]s", lista[pos].noivo.nome_mae); fflush(stdin);
    printf("\tNOME DO PAI:\t\t\t");     scanf("%[^\n]s", lista[pos].noivo.nome_pai); fflush(stdin);
}

void cadastra_noiva(int pos){
    printf("\n--- DADOS DA NOIVA:\n");    fflush(stdin);
    printf("\tNOME DA NOIVA:\t\t\t");   scanf("%[^\n]s", lista[pos].noiva.nome_conjuge); fflush(stdin);
    printf("\tNOME DA MAE:\t\t\t");     scanf("%[^\n]s", lista[pos].noiva.nome_mae); fflush(stdin);
    printf("\tNOME DO PAI:\t\t\t");     scanf("%[^\n]s", lista[pos].noiva.nome_pai); fflush(stdin);
}

void cadastra_data(int pos){
    printf("\n--- DADOS DA DATA:\n");    fflush(stdin);
    printf("\tDIA:\t\t\t");   scanf("%d", &lista[pos].data.dia); fflush(stdin);
    printf("\tMES:\t\t\t");   scanf("%d", &lista[pos].data.mes); fflush(stdin);
    printf("\tANO:\t\t\t");   scanf("%d", &lista[pos].data.ano); fflush(stdin);
    printf("\tHORA:\t\t\t");   scanf("%[^\n]s", lista[pos].data.hora); fflush(stdin);
}

void cadastra_casamento(int pos){
    if(pos >= LIMITE)
        printf("Quantidade maxima de casamentos cadastrados...\n\n");
    else{
        cadastra_noivo(pos);
        cadastra_noiva(pos);
        cadastra_data(pos);
    }
}

void lista_cerimonia(int pos){
    printf("\n[%d]...\n", pos+1);
    printf("\tNOIVO: %s\n", lista[pos].noivo.nome_conjuge);
    printf("\tMAE DO NOIVO: %s\n", lista[pos].noivo.nome_mae);
    printf("\tPAI DO NOIVO: %s\n", lista[pos].noivo.nome_pai);
    printf("\tNOIVA: %s\n", lista[pos].noiva.nome_conjuge);
    printf("\tMAE DO NOIVO: %s\n", lista[pos].noiva.nome_mae);
    printf("\tPAI DO NOIVO: %s\n", lista[pos].noiva.nome_pai);
    printf("\tDATA: %d/%d/%d\n", lista[pos].data.dia, lista[pos].data.mes, lista[pos].data.ano);
    printf("\tHORARIO: %s\n", lista[pos].data.hora);
}

void lista_todas_cerimonias(int pos){
    for(int i = 0; i < pos; i++){
        lista_cerimonia(i);
    }
}

void listar_conforme_data(int pos, int dia, int mes, int ano){
    for(int i = 0; i < pos; i++){
        if(dia == lista[i].data.dia && mes == lista[i].data.mes && ano == lista[i].data.ano)
            lista_cerimonia(i);
    }
}

void fornecer_nome_conjuge(int pos, char nome[]){
    for(int i = 0; i < pos; i++){
        if(lista[i].noiva.nome_conjuge == nome){
            printf("%s\n", lista[i].noivo.nome_conjuge);
            return;
        }else if(lista[i].noivo.nome_conjuge == nome){
            printf("%s\n", lista[i].noiva.nome_conjuge);
            return;
        }
    }
    printf("Nenhuma informacao encontrada...\n\n");
}

void fornecer_datahora(int pos, char noiva[], char noivo[]){
    for(int i = 0; i < pos; i++){
        if(lista[i].noiva.nome_conjuge == noiva && lista[i].noivo.nome_conjuge == noivo){
            printf("DATA: %d/%d/%d\t", lista[i].data.dia, lista[i].data.mes, lista[i].data.ano);
            printf("HORARIO: %s\n", lista[i].data.hora);
            return;
        }
    }
    printf("Nenhuma informacao encontrada...\n\n");
}

void txt_menu(){
    printf("1. Cadastrar casamento\n");
    printf("2. Listar cerimonias ocorridas em uma dada data\n");
    printf("3. Fornecer nome do conjuge apartir de um nome dado\n");
    printf("4. Fornecer data e horario da cerimonia apartir do nome dos noivos\n");
    printf("5. Listar todas cerimonias cadastradas\n");
    printf("6. Sair\n");
    printf("|\n|->\t");
}

void menu(){
    int pos = 0;
    int op = 0;
    int dia, mes, ano;
    char hora[TAM_HORA];
    char nome1[TAM_NOME], nome2[TAM_NOME];
    while(1){
        txt_menu();
        scanf("%d", &op);
        fflush(stdin);
        switch (op){
        case 1: cadastra_casamento(pos); pos++; break;
        case 2: printf("DIA MES E ANO:\n"); scanf("%d%d%d", &dia, &mes, &ano); listar_conforme_data(pos, dia, mes, ano); break;
        case 3: printf("NOME:\t"); scanf("%[^\n]s", nome1); fornecer_nome_conjuge(pos, nome1); break;
        case 4: 
            printf("NOME NOIVA:\t"); scanf("%[^\n]s", nome1); fflush(stdin); 
            printf("NOME NOIVO:\t"); scanf("%[^\n]s", nome2); fflush(stdin); 
            fornecer_datahora(pos, nome1, nome2); 
        break;
        case 5: lista_todas_cerimonias(pos); break;
        case 6: printf("\nsaindo...\n\n"); return;
        default: printf("\nOpcao invalida...\n\n"); break;
        }
    }
}

int main(){
    menu();
    system("pause");
    return 0;
}