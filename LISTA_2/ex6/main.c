#include <stdio.h>
#include <stdlib.h>

/*6) Faça um programa, descritor de uma bomba de combustível, que contenha as seguintes características
a) variáveis -> char tipoCombustivel, float valorLitro, float quantidadeCombustivel

b) funções ->

b1. void abastecerPorValor(float valor) – dado o valor a ser abastecido, mostra a quantidade
de litros de combustível que foi colocada no veículo;

b2. void abastecerPorLitro(float litros) – dada a quantidade em litros de combustível, mostra 
o valor a ser pago pelo cliente.

b3. void alterarValor( loat valor) – altera o valor do litro do combustível.

b4. void alterarCombustivel(char c) – altera o tipo do combustível.

b5. void alterarQuantidadeCombustivel( ) – altera a quantidade de combustível restante na bomba.

OBS: Sempre que acontecer um abastecimento é necessário atualizar a quantidade de combustível total na bomba.
A função main fornecerá um menu para que o usuário escolha a opção desejada.*/

char tipoCombustivel;
float valorLitro, quantidadeCombustivel, abastecido, valor, litros;

void alterarValor(float valor){
    valorLitro = valor;
}

void alterarCombustivel(char c){
    tipoCombustivel = c;
}

void alterarQuantidadeCombustivel(float l){
    quantidadeCombustivel -= l;
}

void abastecerPorValor(float valor){
    abastecido = valor / valorLitro;
    if(abastecido > quantidadeCombustivel)
        printf("Nao ha combustivel suficiente na bomba...\n");
    else{
        printf("Abastecido: %.2fL\n",abastecido);
        alterarQuantidadeCombustivel(abastecido);
    }
}

void abastecerPorLitro(float litro){
    abastecido = valorLitro * litro;
    if(abastecido > quantidadeCombustivel)
        printf("Nao ha combustivel suficiente na bomba...\n");
    else{
        printf("Abastecido: R$%.2f\n",abastecido);
        alterarQuantidadeCombustivel(abastecido);
    }
}

void msg(){
    printf("\n---------------------------------------------------------------\n");
    printf("|\t1. Abastecer por valor\n");
    printf("|\t2. Abastecer por litro\n");
    printf("|\t3. Alterar valor do litro\n");
    printf("|\t4. Alterar o tipo do combustivel\n");
    printf("|\t5. Alterar a quantidade de litros na bomba\n");
    printf("|\n|>\t");
}

int main(){
    char continuar, comb; 
    int op; 
    printf("Informe a quantidade inicial de litros na bomba: "); scanf("%f", &litros);
    quantidadeCombustivel = litros;
    do{
        msg();
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                scanf("%f", &valor);
                abastecerPorValor(valor);
                break;
            case 2:
                scanf("%f", &litros);
                abastecerPorLitro(litros);
                break;
            case 3:
                scanf("%f", &valor);
                alterarValor(valor);
                break;
            case 4:
                scanf(" %c", &comb);
                alterarCombustivel(comb);
                break;
            case 5:
                scanf("%f", &litros);
                quantidadeCombustivel = litros;
                break;
            default:
                printf("opcao invalida....\n\n");
                break;
        }
        printf("Continuar? [S/N]\t"); scanf(" %c", &continuar);
    } while(continuar == 'S' || continuar == 's');
    
    printf("\nsaindo.....\n");
    system("pause");
    return 0;
}