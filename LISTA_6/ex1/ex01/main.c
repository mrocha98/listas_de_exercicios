#include <stdio.h>
#include <stdlib.h>


/*1.  Escreva um programa que:
(a)  Crie/abra um arquivo texto de nome “arq.txt”
(b)  Permita que o usuario grave diversos caracteres nesse arquivo, ate que o usuario entre com o caractere ‘0’
(c)  Feche o arquivo. Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os caracteres armazenados.*/

int main(){
    FILE *f;
    f = fopen("arq.txt", "a+");
    char c;
    while(1){
        scanf(" %c", &c);
        setbuf(stdin, NULL);
        if(c == '0')
            break;
        fputc(c, f);
    }
    rewind(f);
    while(!feof(f)){
        printf("%c", fgetc(f));
    }
    printf("\nFIM ARQUIVO\n\n");
    fclose(f);
    system("pause");
    return 0;
}
