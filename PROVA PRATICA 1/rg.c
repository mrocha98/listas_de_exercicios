#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM_RG 12
char matriz[20][TAM_RG+1]; 
int indice = 0;

char calcula_verificador(int digitos[]){
    char verificador;
    int somatorio = 0;
    int quadro_multiplicador[] = {2,3,4,5,6,7,8,9};
    for(int i = 0; i < 8; i++){
        somatorio += (digitos[i] * quadro_multiplicador[i]);
    }
    int resto = somatorio % 11;
    resto = 11 - resto;
    verificador = resto + '0';
    if(verificador == 10)
        verificador = 'X';
    else if(verificador == 11)
        verificador = '0';
    return verificador;
}

void coloca_simbolos(int posicao){
    matriz[posicao][2] = '.';
    matriz[posicao][6] = '.';
    matriz[posicao][10] = '-';
}


void coloca_verificador(int posicao, char verificador){
    matriz[posicao][11] = verificador;
}

void coloca_digitos(int posicao, int digitos[]){
    matriz[posicao][0] = (digitos[0] + '0');
    matriz[posicao][1] = (digitos[1] + '0');
    matriz[posicao][3] = (digitos[2] + '0');
    matriz[posicao][4] = (digitos[3] + '0');
    matriz[posicao][5] = (digitos[4] + '0');
    matriz[posicao][7] = (digitos[5] + '0');
    matriz[posicao][8] = (digitos[6] + '0');
    matriz[posicao][9] = (digitos[7] + '0');
}

void monta_rg(int posicao, char verificador, int digitos[]){
    coloca_verificador(posicao, verificador);
    coloca_simbolos(posicao);
    coloca_digitos(posicao, digitos);
    matriz[posicao][TAM_RG] = '\0';
    fflush(stdin);
}

void listar_rgs(int indice){
    for(int i = 0; i < indice; i++){
        printf("[%d]\t->\t%s\n", i+1, matriz[i]);
    }
}

void rgs_comecam_com_digito(int indice, char digito){
    for(int i = 0; i < indice; i++){
        if(matriz[i][0] == digito)
            printf("[%d]\t->\t%s\n", i+1, matriz[i]);
    }
}

int rg_eh_valido(char rg[]){
    if(strlen(rg) != TAM_RG){
        //printf("ERRO DE TAMANHO\n");
        return 0;
    }
    if(rg[2] != '.' || rg[6] != '.' || rg[10] != '-'){
        //printf("ERRO DE POSICIONAMENTO SIMBOLICO\n");
        return 0;
    }
    int digitos[] = {(int) rg[0], (int) rg[1], (int) rg[3], (int) rg[4], (int) rg[5], (int) rg[7], (int) rg[8], (int) rg[9]};
    int v = calcula_verificador(digitos);
    if(rg[11] != (v)){
        //printf("ERRO DE VERIFICADOR (%c) != (%c)\n", rg[11], v);
        return 0;
    }
    return 1;
}

void preenche_automaticamente(){
    int digi[8];
    while(1){
        for(int j = 0; j < 8; j++){digi[j] = (rand()%10);}
        int v = calcula_verificador(digi);
        monta_rg(indice, v, digi);        
        if(rg_eh_valido(matriz[indice])){
            indice++;
            break;
        }
    }
}

void preenche_3_automaticamente(){
    for(int i = 1; i <= 3; i++){
        if(indice == 20){
            printf("\nNumero maximo de rgs cadastrados...\n");
            break;
        }
        srand(time(NULL) * i + TAM_RG);
        preenche_automaticamente();
    }
    listar_rgs(indice);
}

void texto_menu(){
    printf("------\tMENU\t------\n");
    printf("1. Inserir RG\n");
    printf("2. Preencher automaticamente 3 RGS\n");
    printf("3. Verificar se RG eh valido\n");
    printf("4. Listar todos os RGS cadastrados que comecam com digito\n|\n-->");
}

void preenche(){
    if(indice == 20)
        printf("Nao foi possivel cadastrar pois ja existem 20 rgs.\n");
    else{
        printf("Entre com o RG:\n");
        scanf("%s", matriz[indice]);
        printf("RG %s cadastrado com sucesso na posicao %d", matriz[indice], indice+1);
        indice++;
    }
}

void checar_rg(){
    printf("Escolha um RG...\n");
    listar_rgs(indice);
    int n;
    scanf("%d", &n);
    if(rg_eh_valido(matriz[n-1]))
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
            preenche_3_automaticamente();
        else if(op == 3)
            checar_rg();
        else if(op == 4){
            char digito; printf("Digito:\n|\n-->"); scanf(" %c", &digito);
            fflush(stdin);
            rgs_comecam_com_digito(indice, digito);
        }
        else
            printf("Opcao invalida...\n");
        fflush(stdin);
        printf("\ncontinuar? [S/N]\n|\n-->"); scanf(" %c", &cont);
    }while(cont == 'S' || cont == 's');
    printf("\n\nsaindo....\n\n");
    system("pause");
    return 0;
}