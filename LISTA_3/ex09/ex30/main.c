#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*30.  Leia duas cadeias de caracteres A e B. Determine quantas vezes a cadeia A ocorre na cadeia B.*/

int chegou_no_fim(int n, int len){
    return (n == len);
}

int chars_iguais(char c1, char c2){
    return (c1 == c2);
}

int conta_a_em_b(char a[], char b[]){
    int total = 0;
    /*
     *  Optei por não fazer um "index_a++" no fim do for, pois ela é uma variável que
     *  só somará, caso a comparação de caracteres seja verdadeira, e quando não for,
     *  sempre voltará ao primeiro caracter (a[0])
     */
    for(int index_a = 0, index_b = 0; index_b <= strlen(b); index_b++){
        /*
         *  Caso a cadeia a inteira tenha sido encontrada em b, soma-se 1 no total
         *  e index_a retorna para o primeiro caracter (a[0])
         */
        if(chegou_no_fim(index_a, strlen(a))){
            index_a = 0;
            total++;
        }
        /*
         *  Necessário que pare o looping antes da ultima verificação de caracteres, 
         *  pois se continuasse, seria feita uma comparação entre valores "lixo".
         *  Mudar o "<=" do FOR para "<" faz com que o último total++ não seja contabilizado.
         */
        if(index_b == strlen(b))
            break;
        if(chars_iguais(a[index_a], b[index_b]))
            index_a++;
        else
            index_a = 0;
    }
    return total;
}

int main(){
    char a[50+1], b[50+1];
    printf("INSIRA A E B:\n");
    scanf("%s\n%s", a, b);
    if(strlen(a) < strlen(b))
        printf("A EM B: %d\n\n", conta_a_em_b(a, b));
    else
        printf("B EM A: %d\n\n", conta_a_em_b(b, a));    
    system("pause");
    return 0;
}