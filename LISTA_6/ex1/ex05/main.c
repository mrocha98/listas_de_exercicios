#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*5. Faca um programa que receba do usuario um arquivo texto e um caracter. Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo.*/

int main(){
    FILE *f = fopen("arq.txt", "r");
    int total = 0;
    char c, recebido;
    printf("Qual caractere? "); scanf(" %c", &recebido); recebido = tolower(recebido);
    while(!feof(f)){
        c = fgetc(f);
        c = tolower(c);
        if(c == recebido) total++;
    }
    printf("TOTAL DE OCORRENCIAS: %d\n\n", total);
    fclose(f);
    system("pause");
    return 0;
}