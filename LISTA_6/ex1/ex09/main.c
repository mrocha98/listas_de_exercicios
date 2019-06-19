#include <stdio.h>
#include <stdlib.h>

/*9.  Faca um programa que receba dois arquivos do usuario, e crie um terceiro arquivo com o conteudo dos dois primeiros juntos 
(o conteudo do primeiro seguido do conteudo do segundo).*/

int main(){
    FILE *f1, *f2, *fw;
    fw = fopen("juncao.txt", "w");
    f1 = fopen("arq1.txt", "r");
    f2 = fopen("arq2.txt", "r");

    rewind(fw);
    rewind(f1);
    rewind(f2);

    char c;
    while(!feof(f1)){
        c = fgetc(f1);
        fputc(c, fw);
    }
    while(!feof(f2)){
        c = fgetc(f2);
        fputc(c, fw);
    }

    printf("Fim da juncao de arquivos...\n");
    system("pause");
    return 0;
}