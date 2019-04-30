#include <stdio.h>
#include <stdlib.h>

/*5-Uma maternidade deseja cadastrar os nascimentos ocorridos. Usando a linguagem C e struct, implemente:
a) uma função de cadastro capaz de armazenar nome da criança, nome do pai, nome da mãe, dia, mês, ano e hora de nascimento, 
massa e altura do recém-nascido.
b) uma função que lista os nomes de todos os bebês nascidos em uma determinada data, passada como parâmetro.
c) uma função que lista os nomes de todos os bebês que nasceram com massa abaixo de determinado valor passado como parâmetro;
d)uma função que lista os nomes de todos os bebês que nasceram com massa acima dede determinado valor passado como parâmetro;
e) main(): oferece menu para o usuário escolher a operação desejada.*/

typedef struct recem_nascido{
    char nome_crianca[20+1];
    char nome_pai[20+1];
    char nome_mae[20+1];
    int dia_nasc;
    int mes_nasc;
    int ano_nasc;
    char hora_nasc[5+1];
    float massa;
    float altura;
} CRIANCA;

CRIANCA cadastradas[100];

void cadastra(int pos){
    printf("NOME DA CRIANCA:\t\t\t");       scanf("%[^\n]s", cadastradas[pos].nome_crianca);    fflush(stdin);
    printf("NOME DO PAI:\t\t\t\t");         scanf("%[^\n]s", cadastradas[pos].nome_pai);        fflush(stdin);
    printf("NOME DA MAE:\t\t\t\t");         scanf("%[^\n]s", cadastradas[pos].nome_mae);        fflush(stdin);
    printf("DIA DO NASCIMENTO:\t\t\t");     scanf("%d", &cadastradas[pos].dia_nasc);
    printf("MES DO NASCIMENTO:\t\t\t");     scanf("%d", &cadastradas[pos].mes_nasc);
    printf("ANO DO NASCIMENTO:\t\t\t");     scanf("%d", &cadastradas[pos].ano_nasc);
    printf("HORA DO NASCIMENTO:\t\t\t");    scanf("%s", cadastradas[pos].hora_nasc);            fflush(stdin);
    printf("MASSA DA CRIANCA:\t\t\t");      scanf("%f", &cadastradas[pos].massa);
    printf("ALTURA DA CRIANCA:\t\t\t");     scanf("%f", &cadastradas[pos].altura);
}

void printa_dados(int pos){
    printf("\n[%d]...\n", pos+1);
    printf("\tNOME DA CRIANCA:\t\t\t%s\n", cadastradas[pos].nome_crianca);
    printf("\tNOME DO PAI:\t\t\t\t%s\n", cadastradas[pos].nome_pai);
    printf("\tNOME DA MAE:\t\t\t\t%s\n", cadastradas[pos].nome_mae);
    printf("\tDATA DO NASCIMENTO:\t\t\t%d/%d/%d - %sHrs\n", cadastradas[pos].dia_nasc,cadastradas[pos].mes_nasc,cadastradas[pos].ano_nasc,cadastradas[pos].hora_nasc);
    printf("\tMASSA DA CRIANCA:\t\t\t%.2f KG\n", cadastradas[pos].massa);
    printf("\tALTURA DA CRIANCA:\t\t\t%.2f M\n", cadastradas[pos].altura);
    printf("----------------------------------------------------------------------------\n");
}

void printa_tudo(int pos){
    for(int i = 0; i < pos; i++){
        printa_dados(i);
    }
}

void printa_nascidos_conforme_data(int pos, int dia, int mes, int ano){
    for(int i = 0; i < pos; i++){
        int achou = (cadastradas[i].dia_nasc == dia && cadastradas[i].mes_nasc == mes && cadastradas[i].ano_nasc == ano);
        if(achou) printa_dados(i);
    }
}

void printa_bebes_abaixo_massa(int pos, float massa){
    for(int i = 0; i < pos; i++){
        int achou = (cadastradas[i].massa <= massa);
        if(achou) printa_dados(i);
    }
}

void printa_bebes_acima_massa(int pos, float massa){
    for(int i = 0; i < pos; i++){
        int achou = (cadastradas[i].massa >= massa);
        if(achou) printa_dados(i);
    }
}

void txt_menu(){
    printf("\n-----------------------------------\tMENU\t-----------------------------------\n");
    printf("1. Cadastrar bebe\n");
    printf("2. Listar todos bebes\n");
    printf("3. Listar todos bebes nascidos em uma data fornecida\n");
    printf("4. Listar todos bebes com massa abaixo de um dado valor\n");
    printf("5. Listar todos bebes com massa acima de um dado valor\n");
    printf("6. Sair\n");
    printf("|\n|-->");
}

void menu(){
    int pos = 0, op;
    int dia, mes, ano;
    float massa;
    do{
        txt_menu();
        scanf("%d", &op);
        fflush(stdin);
        switch(op){
            case 1: 
                cadastra(pos);
                pos++;    
            break;
            case 2:
                printa_tudo(pos);
            break;
            case 3: 
                printf("Entre com o dia, o mes e o ano, respectivamente:\n");
                scanf("%d%d%d", &dia, &mes, &ano);
                printa_nascidos_conforme_data(pos, dia, mes, ano);
            break;
            case 4: 
                printf("Entre com a massa:\t"); scanf("%f", &massa);
                printa_bebes_abaixo_massa(pos, massa);
            break;
            case 5: 
                printf("Entre com a massa:\t"); scanf("%f", &massa);
                printa_bebes_acima_massa(pos, massa);
            break;
            case 6: printf("\nsaindo...\n"); break;
            default: printf("Opcao invalida...\n");
        }
    }while(op != 6);
}

int main(){
    menu();
    system("pause");
    return 0;
}