#include <stdio.h>
#include <stdlib.h>

/*6)Utilizando matrizes, implemente um programa em C que resolva o  Problema G, "Jogo de TV", de 
Lúcio Nunes de Lira (Fatec São Paulo), da Maratona de Programação InterFatec's 2018.*/

void teste(char **m, int row, int col){
    for(int i = 0; i < row; i++){
        printf("[\t");
        for(int j = 0; j < col; j++){
            printf(" %d ", m[i][j]);
        }
        printf("\t]\n");
    }
}

int main(){
    int m[5][6];
    teste(m, 5, 6);
    system("pause");
    return 0;
}