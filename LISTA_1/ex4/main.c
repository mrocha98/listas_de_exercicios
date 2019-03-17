#include <stdio.h>
#include <stdlib.h>

/*Elabore um algoritmo e um programa em C que resolva o  Problema C, " A Horta do Juquinha",
de: Antonio Cesar de Barros Munari (Fatec Sorocaba), da Maratona de Programação InterFatec's 2018.
*/

int main()
{
    int qtd_sementes, qtd_necessarias, covas = 0;
    for(int i = 0; i < 3; i++){
        printf("Entre com a quantidade de sementes do saquinho e\na quantidade necessaria para uma cova, respectivamente: ");
        scanf("%d", &qtd_sementes);
        scanf("%d", &qtd_necessarias);
        while(1){
            if(qtd_sementes < qtd_necessarias)
                break;
            qtd_sementes -= qtd_necessarias;
            covas++;
        }
    }

    printf("COVAS: %d", covas);
    return 0;
}
