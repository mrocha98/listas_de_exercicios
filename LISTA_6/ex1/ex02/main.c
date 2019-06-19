#include <stdio.h>
#include <stdlib.h>

/*2.  Faca um programa que receba do usuario um arquivo texto e mostre na tela quantas linhas esse arquivo possui.*/

int main(){
    FILE *f = fopen("arq.txt", "r");
    int n = 0; char c;
    while(!feof(f)){
        c = fgetc(f);
        if(c == '\n')
            n++;
    }
    printf("TOTAL DE LINHAS: %d\n\n", n);
    fclose(f);
    system("pause");
    return 0;
}