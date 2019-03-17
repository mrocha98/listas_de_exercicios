#include <stdio.h>
#include <stdlib.h>

/*C) Elabore um programa em C que leia cinco dist�ncias entre cidades e imprima a dist�ncia total a ser percorrida.*/
void ex_c(){
    float somatorio = 0.0;
    float distancia;
    for(int i = 2; i <= 5; i++){
        printf("Cidade %d a %d:\t", i-1, i);
        scanf("%f", &distancia);
        somatorio += distancia;
    }printf("TOTAL: %.2f\n", somatorio);
}
/*D)  Elabore um programa em C que leia uma dist�ncia a ser percorrida em Km, o pre�o do litro do combust�vel,
o consumo, os gastos com manuten��o do ve�culo e com ped�gio. Em seguida, dever� ser impresso o gasto por km rodado.*/
void ex_d(){
    float km, preco_litro, consumo, gastos, pedagio;
    printf("KM: "); scanf("%f", &km);
    printf("PRECO DO LITRO: R$"); scanf("%f", &preco_litro);
    printf("CONSUMO: [KM/L]  "); scanf("%f", &consumo);
    printf("GASTOS: R$"); scanf("%f", &gastos);
    printf("PEDAGIO: "); scanf("%f", &pedagio);
    float total = (preco_litro * km)/consumo;
    total += gastos + pedagio;
    printf("No total serao gastos R$%.2f\n", total);
}

/*E) Considerando a Tabela 6 do artigo,  elabore um programa em C que calcule e imprima o percentual
de redu��o do Km rodado, ap�s a leitura do km rodado sem e com a aplica��o do algoritmo descrito no artigo.*/
void ex_e(){
    float km_antes, km_depois, percentual, diferenca;
    printf("KMs antes: ");  scanf("%f", &km_antes);
    printf("KMs depois: "); scanf("%f", &km_depois);
    diferenca = km_antes - km_depois;
    percentual = (diferenca * 100) / km_antes;
    printf("Percentual de reducao: %.3f\n", percentual);
}

int main()
{
    printf("\nEX C:\n\n");
    ex_c();
    printf("\nEX D:\n\n");
    ex_d();
    printf("\nEX E:\n\n");
    ex_e();
    system("pause");
    return 0;
}
