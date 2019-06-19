#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Faca um programa que leia o conteudo de um arquivo e crie um arquivo com o mesmo conteudo, mas com todas as letras 
minusculas convertidas para maiusculas. Os nomes dos arquivos serao fornecidos,  via teclado,  pelo usuario. */

int main(){
    char nomeArq[50+1];
    FILE *fw = fopen("criado.txt", "w");
    FILE *fr;
    printf("Entre com o nome do arquivo (incluindo .txt no final):\t");
    setbuf(stdin, NULL);    scanf("%s", nomeArq);
    fr = fopen(nomeArq, "r");
    if(fr == NULL){
        printf("Erro, arquivo invalido!\n");
        system("pause");
        exit(1);
    }
    char c;
    rewind(fw);
    rewind(fr);
    while(!feof(fr)){
        c = fgetc(fr);
        if(isalpha(c)) c = toupper(c);
        fputc(c, fw);
    }
    printf("Arquivo devidamente copiado\n");
    system("pause");
    return 0;
}