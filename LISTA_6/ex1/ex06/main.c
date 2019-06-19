#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define a 97
#define z 122

/*6.  Faca um programa que receba do usuario um arquivo texto e mostre na tela quantas vezes cada letra do alfabeto aparece dentro do arquivo.*/

int main() {
  FILE *f;
  f = fopen("arq.txt", "r"); 
  char c;
  int k = 0, alfabeto[26];
  
  //looping percorrendo o alfabeto 
  //k seria a letra analisada
  for(int i = 0, j = a; i < 26; i++, j++){
    rewind(f);
    k = 0;
    //percorre o arquivo todo contando quantas vezes apareceu k
    while(!feof(f)){
      c = fgetc(f);
      c = tolower(c);
      if(c == j)
        k++;
    }
    alfabeto[i] = k;
  }

  //printa quantas vezes cada letra apareceu
  for(int i = 0, j = a; i < 26; i++, j++){
    printf("%c:\t%d\n", j, alfabeto[i]);
  }
  fclose(f);  
  return 0;
}