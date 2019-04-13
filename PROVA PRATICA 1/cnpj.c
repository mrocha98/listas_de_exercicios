#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM_CNPJ 18
char matriz[20][TAM_CNPJ+1]; 
int indice = 0;

int calcula_primeiro_verificador(int digitos[]){
    int primeiro_verificador, somatorio = 0;
    int primeiro_quadro_multiplicador[] = {5,4,3,2,9,8,7,6,5,4,3,2};
    for(int i = 0; i < 12; i++){
        somatorio += (digitos[i] * primeiro_quadro_multiplicador[i]);
    }
    primeiro_verificador = somatorio % 11;
    (primeiro_verificador < 2)?(primeiro_verificador = 0):(primeiro_verificador = (11 - primeiro_verificador));
    return primeiro_verificador;
}

int calcula_segundo_verificador(int digitos[]){
    int primeiro_verificador = calcula_primeiro_verificador(digitos);
    int segundo_verificador, somatorio = 0;
    int segundo_quadro_multiplicador[] = {6,5,4,3,2,9,8,7,6,5,4,3,2};
    for(int i = 0; i < 12; i++){
        somatorio += digitos[i] * segundo_quadro_multiplicador[i];
    }
    somatorio += (segundo_quadro_multiplicador[12] * primeiro_verificador);
    segundo_verificador = somatorio % 11;
    (segundo_verificador < 2)?(segundo_verificador = 0):(segundo_verificador = (11 - segundo_verificador));
    return segundo_verificador;
}

void coloca_simbolos(int posicao){
    matriz[posicao][2] = '.';
    matriz[posicao][6] = '.';
    matriz[posicao][10] = '/';
    matriz[posicao][15] = '-';
}

void coloca_0001(int posicao){
    for(int i = 11; i <= 13; i++){
        matriz[posicao][i] = '0';
    }
    matriz[posicao][14] = '1';
}

void coloca_verificadores(int posicao, int primeiro, int segundo){
    matriz[posicao][16] = (primeiro + '0');
    matriz[posicao][17] = (segundo + '0');
}

void coloca_digitos(int posicao, int digitos[8]){
    matriz[posicao][0] = (digitos[0] + '0');
    matriz[posicao][1] = (digitos[1] + '0');
    matriz[posicao][3] = (digitos[2] + '0');
    matriz[posicao][4] = (digitos[3] + '0');
    matriz[posicao][5] = (digitos[4] + '0');
    matriz[posicao][7] = (digitos[5] + '0');
    matriz[posicao][8] = (digitos[6] + '0');
    matriz[posicao][9] = (digitos[7] + '0');
}

void monta_cnpj(int posicao, int digitos[], int primeiro, int segundo){
    coloca_verificadores(posicao, primeiro, segundo);
    coloca_0001(posicao);
    coloca_simbolos(posicao);
    coloca_digitos(posicao, digitos);
    matriz[posicao][TAM_CNPJ] = '\0';
    fflush(stdin);
}

void listar_cnpjs(int indice){
    for(int i = 0; i < indice; i++){
        printf("[%d]\t->\t%s\n", i+1, matriz[i]);
    }
}

void cnpjs_comecam_com_quatro(int indice){
    for(int i = 0; i < indice; i++){
        if(matriz[i][0] == '4')
            printf("[%d]\t->\t%s\n", i+1, matriz[i]);
    }
}

int cnpj_eh_valido(char cnpj[]){
    if(strlen(cnpj) != TAM_CNPJ)
        return 0;
    if(cnpj[2] != '.' || cnpj[6] != '.' || cnpj[10] != '/' || cnpj[11] != '0' || cnpj[12] != '0' || cnpj[13] != '0' || cnpj[14] != '1' || cnpj[15] != '-')
        return 0;
    int digitos[] = {(int) cnpj[0], (int) cnpj[1], (int) cnpj[3], (int) cnpj[4], (int) cnpj[5], (int) cnpj[7], (int) cnpj[8], (int) cnpj[9], 0, 0, 0, 1};
    int p = calcula_primeiro_verificador(digitos);
    int s = calcula_segundo_verificador(digitos);
    if(cnpj[16] != (p + '0') || cnpj[17] != (s + '0'))
        return 0;
    return 1;
}

void preenche_automaticamente(){
    int digi[12];
    while(1){
        for(int j = 0; j < 8; j++){digi[j] = (rand()%10);}
        for(int j = 8; j < 11; j++){digi[j] = 0;}
        digi[11] = 1;
        int p = calcula_primeiro_verificador(digi);
        int s = calcula_segundo_verificador(digi);
        monta_cnpj(indice, digi, p, s);        
        if(cnpj_eh_valido(matriz[indice])){
            indice++;
            break;
        }
    }
}

void preenche_4_automaticamente(){
    for(int i = 0; i < 4; i++){
        if(indice == 20){
            printf("\nNumero maximo de cnpjs cadastrados...\n");
            break;
        }
        srand(time(NULL) * i);
        preenche_automaticamente();
    }
    listar_cnpjs(indice);
}

void texto_menu(){
    printf("------\tMENU\t------\n");
    printf("1. Inserir CNPJ\n");
    printf("2. Preencher automaticamente 4 CNPJS\n");
    printf("3. Verificar se CNPJ eh valido\n");
    printf("4. Listar todos os CNPJS cadastrados que comecam com 4\n|\n-->");
}

void preenche(){
    if(indice == 20)
        printf("Nao foi possivel cadastrar pois ja existem 20 cnpjs.\n");
    else{
        printf("Entre com o CNPJ:\n");
        scanf("%s", matriz[indice]);
        printf("CNPJ %s cadastrado com sucesso na posicao %d", matriz[indice], indice+1);
        indice++;
    }
}

void checar_cnpj(){
    printf("Escolha um CNPJ...\n");
    listar_cnpjs(indice);
    int n;
    scanf("%d", &n);
    if(cnpj_eh_valido(matriz[n-1]))
        printf("Eh valido!\n");
    else
        printf("Nao eh valido!\n");
}

int main(){
    int op;
    char cont;
    do{
        texto_menu();
        scanf("%d", &op);
        if(op == 1)
            preenche();
        else if(op == 2)
            preenche_4_automaticamente();
        else if(op == 3)
            checar_cnpj();
        else if(op == 4)
            cnpjs_comecam_com_quatro(indice);
        else
            printf("Opcao invalida...\n");
        fflush(stdin);
        printf("\ncontinuar? [S/N]\t"); scanf(" %c", &cont);
    }while(cont == 'S' || cont == 's');
    printf("\n\nsaindo....\n\n");
    system("pause");
    return 0;
}