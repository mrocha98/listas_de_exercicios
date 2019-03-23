#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*24.  Escreva  um  programa  que  recebe  do  usúario  uma  string  S,  um  caractere  C,  
e  uma posicao I e devolve o ́ındice da primeira posicao da string onde foi encontrado o caractere C. 
A procura deve comecar a partir da posicao I.*/

int busca_indice(char s[], char c, int i){
    for(int k = i; k < strlen(s); k++){
        if(s[k] == c)
            return k;
    }
    return -1;
}

int main(){
    char str[30+1], c;
    int i;
    printf("Entre com uma frase, um caractere e um indice, respectivamente:\n");
    scanf("%[^\n]s", str);
    fflush(stdin);
    scanf(" %c", &c);
    fflush(stdin);
    scanf("%d", &i);
    printf("Primeira posicao apartir do indice %d: %d\n", i, busca_indice(str, c, i));
    system("pause");
    return 0;
}