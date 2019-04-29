#include <stdio.h>
#include <stdlib.h>

/*2- O mágico descobre, com a força do seu pensamento, duas cartas escolhidas aleatoriamente pelo espectador.

MATERIAL NECESSÁRIO
Um baralho retirando-se do maço as cartas dez, valete, dama e rei de todos os naipes.

SEGREDO
a- Peça para o espectador escolher uma carta qualquer e memorizá-la.
b- Peça para ele multiplicar por dois o valor da carta, mentalmente.
c- Somar cinco e depois multiplicar por cinco.
d- Peça para memorizar o resultado da conta.
e- Agora, peça para escolher outra carta e somar o valor dela com o primeiro valor
memorizado, ou seja, o resultado da conta.
f- Peça para ele falar o valor total. Desse valor, subtraia 25, com resultado de dois algarismos você descobrirá 
o valor das duas cartas pensadas. (Ex: se o valor total foi 76, menos 25, é igual a 51, a primeira carta escolhida 
foi o número 5, e a segunda carta escolhida foi o número 1, ou seja, o ás.)

Elabore um programa, usando Linguagem de Programação C, que simule o truque de ilusionismo descrito acima. O programa 
dará as instruções ao usuário e lerá via teclado apenas o valor_total, apresentando, em seguida, os dois números 
escolhidos pelo usuário.*/

int c1, c2;

void instrucoes(){
    printf("Escolha uma carta entre 1 e 9 e memorize seu valor.\n");
    printf("Multiplique mentalmente por dois.\n");
    printf("Some 5 e em seguida multiplique por 5.\n");
    printf("Memorize o resultado da conta.\n");
    printf("Escolha outra carta e some com o resultado memorizado.\n");
    printf("Insira o resultado:\t");
}

void calcula_cartas(int total){
    total -= 25;
    c1 = total / 10;
    c2 = total % 10;
}

int main(){
    int valor_total;
    instrucoes();
    scanf("%d", &valor_total);
    calcula_cartas(valor_total);
    printf("As cartas escolhidas foram %d e %d!\n", c1, c2);
    system("pause");
    return 0;
}