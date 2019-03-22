#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caracteres.h"

int conta_caracter(char s[],char c)
{
  int i, qtde=0;
  for(i=0;s[i]!='\0';i++)
  {
      if(tolower(s[i])==tolower(c)) qtde++;
  }
  return qtde;
}

void substitui_caracter(char s[],char c)
{
    int i;
  for(i=0;s[i]!='\0';i++)
  {
      if(tolower(s[i])==tolower(c)) s[i]='*';
  }
  printf("\nnovo ficou:%s",s);
}

