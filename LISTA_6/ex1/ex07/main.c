#include <stdio.h>
#include <stdlib.h>

/*7.  Faca um programa que receba do usuario um arquivo texto. Crie outro arquivo texto contendo o texto do arquivo de entrada, 
mas com as vogais substituıdas por ‘*’.*/

int ehVogal(char c){
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 5; i++){
        if(c == vogais[i])
            return 1;
    }
    return 0;
}

int main(){
    FILE *fr = fopen("lido.txt", "r");
    FILE *fw = fopen("escrito.txt", "w");
    char c;
    rewind(fr);
    rewind(fw);
    while(!feof(fr)){
        c = fgetc(fr);
        if(ehVogal(c)) c = '*';
        fputc(c, fw);
    }
    fclose(fr);
    fclose(fw);
    system("pause");
    return 0;
}