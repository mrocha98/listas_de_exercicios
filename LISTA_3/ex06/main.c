#include <stdio.h>
#include <stdlib.h>

/*6)Utilizando matrizes, implemente um programa em C que resolva o  Problema G, "Jogo de TV", de 
Lúcio Nunes de Lira (Fatec São Paulo), da Maratona de Programação InterFatec's 2018.*/

int linha_diferente = 0, coluna_diferente = 0;

int **aloca_matriz(int linhas, int colunas) {
   int **v;
   if ((linhas < 1) || (colunas < 1)) return NULL;
   v = (int **)calloc(linhas, sizeof(int));
   if (v == NULL) {
      printf("\nFatal Error!\n");
      exit(1);
   }
   for(int x = 0 ; x < linhas ; x++) {
      v[x] = (int *)calloc(colunas, sizeof(int));
      if (v[x] == NULL) {
         printf("\nFatal Error!\n");
         exit(1);
      }
   }
   return v;
}

int **libera_matriz(int linhas, int colunas, int **mat) {
   if ((linhas < 1) || (colunas < 1)) {
      printf("\nFatal Error!\n");
      exit(1);
   }
   if(mat == NULL) return NULL;
   for(int x = 0 ; x < linhas ; x++) free(mat[x]);
   free(mat);
   return NULL;   
}

int main(){
    int linhas, colunas;
    int **matriz;
    printf("Entre com a quantidade de linhas(minimo 1) e colunas(minimo 3), respectivamente:\n");
    do{scanf("%d%d", &linhas, &colunas);}while(colunas < 3 || linhas < 1);
    matriz = aloca_matriz(linhas, colunas);
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf(" %c", &matriz[i][j]);
            fflush(stdin);
        }
        fflush(stdin);
    }
    if(matriz[0][0] != matriz[0][1] && matriz[0][0] != matriz[0][2]){
        linha_diferente = 0;
        coluna_diferente = 0;
    }else if(matriz[0][1] != matriz[0][0] && matriz[0][1] != matriz[0][2]){
        linha_diferente = 0;
        coluna_diferente = 1;
    }
    else{
        char padrao = matriz[0][0];
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                if(matriz[i][j] != padrao){
                    linha_diferente = i;
                    coluna_diferente = j;
                    i = linhas;
                    break;
                }
            }
        }
    }
    libera_matriz(linhas, colunas, matriz);
    printf("LINHA %d COLUNA %d\n", linha_diferente+1, coluna_diferente+1);
    system("pause");
    return 0;
}