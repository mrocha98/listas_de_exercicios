#include <stdio.h>
#include <stdlib.h>

/*Elabore um algoritmo e um programa em C que resolva o  Problema B
"Um pra você, um pra mim", de Lúcio Nunes de Lira (Fatec São Paulo),
da Maratona de Programação InterFatec's 2018.*/

int amigo_saldo = 0, seu_saldo = 0, valor_nota;

int eh_par(int n){
    return (n % 2 == 0);
}

void loop_amigo_comeca(qtd){
    for(int i = 1; i <= qtd; i++){
        printf("Valor da nota %d: ", i); scanf("%d", &valor_nota);
        if(eh_par(i))
            seu_saldo += valor_nota;
        else
            amigo_saldo += valor_nota;
    }
}

void loop_voce_comeca(qtd){
    for(int i = 1; i <= qtd; i++){
        printf("Valor da nota %d: ", i); scanf("%d", &valor_nota);
        if(eh_par(i))
            amigo_saldo += valor_nota;
        else
            seu_saldo += valor_nota;
    }
}

int main(){
    char primeiro;
    int qtd_notas;
    printf("Quem comeca? [V/A]\n"); scanf(" %c", &primeiro);
    printf("Quantas notas? "); scanf("%d", &qtd_notas);

    int voce_comeca = (primeiro == 'V');

    if(voce_comeca){
        loop_voce_comeca(qtd_notas);
    }else{
        loop_amigo_comeca(qtd_notas);
    }
    printf("VOCE: %d\tAMIGO: %d\n", seu_saldo, amigo_saldo);
}
