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
    printf("BATATA (T): %d\n", busca_indice("BATATA", 'T', 3));
    system("pause");
    return 0;
}