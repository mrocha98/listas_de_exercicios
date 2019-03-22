#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caracteres.h"

int main()
{
    char s[3][7];
    char letra;
    int i;
    printf("\Digite nomes:\n");
    for(i=0;i<3;i++)
    {
        gets(s[i]);
    }
    printf("qual letra?");
    letra=getche();
    printf("\n%d",conta_caracter(s[0],letra));
    substitui_caracter(s[1],letra);
    return 0;
}
