#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_NOME 50+1
#define DESCONTO 0.1

/*22.Ler o nome e o valor de uma determinada mercadoria de uma loja.
Sabendo que odesconto para pagamento`a vista ́e de 10% sobre o valor total,  calcular o valor a serpago`a vista.
Escrever o nome da mercadoria, o valor total, o valor do desconto e o valora ser pago`a vista*/

typedef struct PRODUTO{
    char nome[TAMANHO_NOME];
    float valor_bruto;
} PROD;

float calcula_desconto(float valor){
    return valor - valor * DESCONTO;
}

void cadastra_produto(PROD *P){
    char aux[TAMANHO_NOME];
    printf("---------------------- CADASTRO -------------------------\n");
    printf("NOME:\t");
    memset(P->nome, '\0', sizeof(P->nome));
    scanf("%s", aux);
    strcpy(P->nome, aux);
    free(P->nome);
    printf("VALOR:\tR$"); scanf("%f", &P->valor_bruto);
    printf("CADASTRO EFETUADO....\n%s\tR$%.2f\n\n", P->nome, P->valor_bruto);
}

int main()
{
    PROD P;
    cadastra_produto(&P);
    printf("PORCENTAGEM DO DESCONTO: %.2f\nVALOR A VISTA: %.2f\n\n", DESCONTO*100, calcula_desconto(*&P.valor_bruto));
    system("pause");
    return 0;
}



