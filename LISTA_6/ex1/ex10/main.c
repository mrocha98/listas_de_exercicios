#include <stdio.h>
#include <stdlib.h>

/*10.  Faca um programa que receba o nome de um arquivo de entrada e outro de saıda.  O arquivo de entrada contem em cada linha 
o nome de uma cidade (ocupando 40 caracteres) e o seu numero de habitantes. O programa devera ler o arquivo de entrada e gerar 
um arquivo de saıda onde aparece o nome da cidade mais populosa seguida pelo seu numero de habitantes. */

//exercicio nao finalizado...

int contaLinhas(FILE *f){
    char c;
    int linhas = 0;
    rewind(f);
    while(!feof(f)){
        c = fgetc(f);
        if(c == '\n')
            linhas++;
    }
    return linhas;
}

int main(){
    char arqEntrada[50+1], arqSaida[50+1];
    FILE *fr, *fw;

    printf("Entre com o nome do arquivo de entrada: "); setbuf(stdin, NULL); scanf("%s", arqEntrada);
    fr = fopen(arqEntrada, "r");
    if(fr == NULL){
        printf("Arquivo invalido...\n"); system("pause"); exit(1);
    }
    printf("Entre com o nome do arquivo de saida: "); setbuf(stdin, NULL); scanf("%s", arqSaida);
    fw = fopen(arqSaida, "w");

    int qtdLinhas = contaLinhas(fr);
    char cidade[40+1], maiorCidade[40+1];
    int populacao;
    for(int i = 0, maior = 0; i < qtdLinhas; i++){
        fscanf(fr, "%s %d", cidade, &populacao);
        printf("%s %d\n", cidade, populacao);
    }

    system("pause");
    return 0;
}