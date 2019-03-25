#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*27. Faca um programa que, dada uma string, diga se ela ́e um palındromo ou nao.  
Lembrando que um palındromo ́e uma palavra que tenha a propriedade de poder ser lida tanto da direita para a esquerda
como da esquerda para a direita. Exemplo: ovo; arara; Socorram-me, subi no onibus em Marrocos; Anotaram a data da maratona*/

int eh_palindromo(char str[]){
    for(int i = 0, j = 0; i < strlen(str); i++, j++) { //retira os espaços da string
        if (str[j] == ' ')
            j++;
        str[i] = str[j];
    }
    for(int i = strlen(str)-1, j = 0; i >= 0; i--, j++){
        if(isspace(str[i]) || !isalpha(str[i]) || isspace(str[j]) || !isalpha(str[j]))
            continue;
        else if(tolower(str[i]) != tolower(str[j]))
            return 0;
    }
    return 1;
}

int main(){
    char str[50+1];
    printf("Entre com uma string:\t"); scanf("%[^\n]s", str);
    printf("\n%s : %d\n", str, eh_palindromo(str));
    system("pause");
    return 0;
}