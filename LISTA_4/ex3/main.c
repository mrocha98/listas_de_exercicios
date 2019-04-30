#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*3- Observe as instruções desse truque de Ilusionismo.
Peça que a pessoa siga estas instruções

Anotar mês de nascimento (Exemplo de Fevereiro): 2 
Duplicá-lo: 4 
Adicionar 5: 9 
Multiplicar por 50: 450 
Adicionar idade do amigo (Exemplo 40): 490 
Subtrair 365: 125
Neste ponto, pergunte à pessoa para dizer o valor total, o que, neste caso, é de 125. 
Na sua cabeça, de forma rápida e secretamente adicionar 115. 
Neste exemplo, você vai acabar com 240. 
Em seguida, proclame: "Você nasceu em fevereiro e tem 40 anos de idade. "   

Elabore um programa, usando Linguagem de Programação C, que simule o truque de ilusionismo descrito acima. 
O programa dará as instruções ao usuário e lerá via teclado apenas o valor_total, apresentando, em seguida, 
o mês de nascimento e a idade da pessoa.*/

int idade, valor_total;
char mes[10+1];

void instrucoes(){
    printf("Anotar mes de nascimento.\n");
    printf("Duplica-lo.\n");
    printf("Adicionar 5.\n");
    printf("Multiplicar por 50.\n");
    printf("Adicionar idade.\n");
    printf("Subtrair 365");
    printf("\nInsira o resultado:\t");
}

void pega_mes(int n){
    switch(n){
        case 1: strcpy(mes, "Janeiro"); return;
        case 2: strcpy(mes, "Fevereiro"); return;
        case 3: strcpy(mes, "Marco"); return;
        case 4: strcpy(mes, "Abril"); return;
        case 5: strcpy(mes, "Maio"); return;
        case 6: strcpy(mes, "Junho"); return;
        case 7: strcpy(mes, "Julho"); return;
        case 8: strcpy(mes, "Agosto"); return;
        case 9: strcpy(mes, "Setembro"); return;
        case 10:strcpy(mes, "Outubro"); return;
        case 11:strcpy(mes, "Novembro"); return;
        case 12:strcpy(mes, "Dezembro"); return;
    }
}

void calcula(int total){
    total += 115;
    idade = total % 100;
    int i = total / 100;
    //printf("\n\nIDADE: %d\tI: %d\n\n", idade, i);
    pega_mes(i);
}

int main(){
    instrucoes();
    scanf("%d", &valor_total);
    calcula(valor_total);
    printf("Voce nasceu em %s e tem %d anos de idade!\n", mes, idade);
    system("pause");
    return 0;
}