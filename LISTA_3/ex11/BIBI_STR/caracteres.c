#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caracteres.h"

int conta_caracter(char s[],char c){
  int i, qtde=0;
  for(i=0;s[i]!='\0';i++)
  {
      if(s[i] == c) 
        qtde++;
  }
  return qtde;
}

void substitui_caracter(char s[],char c){
    int i;
  for(i=0;s[i]!='\0';i++)
  {
      if(s[i] == c)
       s[i] = '*';
  }
  printf("\nnovo ficou:%s",s);
}

int eh_vogal(char c){
  char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
  for(int i = 0; i < 5; i++){
    if(vogais[i] == c)
      return 1;
  }
  return 0;
}

int conta_vogais(char s[]){
  int qtd = 0;
  for(int i = 0; i < strlen(s); i++){
    if(eh_vogal(s[i]))
      qtd++;
  }
  return qtd;
}

void substitui_vogais_por_asterisco(char s[]){
  for(int i = 0; i < strlen(s); i++){
    if(eh_vogal(s[i]))
      s[i] = '*';
  } 
}

int conta_consoante(char s[]){
  int qtd = 0;
  for(int i = 0; i < strlen(s); i++){
      if(!eh_vogal(s[i]))
        qtd++;
    }
  return qtd;
}