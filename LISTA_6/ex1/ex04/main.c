#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*4.  Faca um programa que receba do usuario um arquivo texto e mostre na tela quantas letras sao vogais e quantas sao consoantes.*/

int ehVogal(int c){
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 5; i++){
        if(c == vogais[i])
            return 1;
    }
    return 0;
}

int main(){
    FILE *f = fopen("arq.txt", "r");
    int totalVogais = 0, totalConsoantes = 0;
    int c;
    while(!feof(f)){
        c = fgetc(f);
        if(ehVogal(tolower(c))) totalVogais++;
        else if(isalpha(c)) totalConsoantes++;
    }
    printf("TOTAL DE VOGAIS: %d\n\n", totalVogais);
    printf("TOTAL DE CONSOANTES: %d\n\n", totalConsoantes);
    fclose(f);
    system("pause");
    return 0;
}