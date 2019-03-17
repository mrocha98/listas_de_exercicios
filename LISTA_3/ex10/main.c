#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*10) Faça um programa que receba uma frase e imprima-a de maneira invertida, trocando as letras A, se existir, por *.*/

void inverte_e_substitui_a_por_estrela(char s[]){
    printf("\n");
    for(int i = strlen(s); i >= 0; i--){
        if(s[i] == 'A' || s[i] == 'a')
            printf("*");
        else
            printf("%c", s[i]);
    }
    printf("\n\n");
}

int main(){
    char str[25+1];
    scanf("%s", str);
    inverte_e_substitui_a_por_estrela(str);
    system("pause");
    return 0;
}
