#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*4) Um veículo tem um certo consumo de combustível (medidos em km / litro) e uma certa quantidade de combustível no tanque.
O consumo é especificado em uma constante e o nível de combustível inicial é 0. 
Implemente um programa contenha as seguintes funções:
    a) void andar( ) que simula o ato de dirigir o veículo por uma certa distância, 
    reduzindo o nível de combustível no tanque de gasolina;
    
    b) float obterGasolina( ), que retorna o nível atual de combustível;
    
    c) adicionarGasolina(float litros), para abastecer o tanque.

O programa deve apresentar um menu de opções que permita ao usuário escolher a opção desejada.
*/

double nivel_combustivel = 0, consumo;

/*optei por utilizar 100m em vez 1km pois o resultado sai mais preciso
 *o ideal seria 1m, mas isso gastaria processamento em troca de valores desprezíveis depois da virgula 
 */
double qtdNecessariaParaAndar100m(){
    return (0.1/consumo);
}

int podeAndar100m(){
    int tem_combustivel_suficiente = nivel_combustivel >= qtdNecessariaParaAndar100m();
    return tem_combustivel_suficiente;
}

void andar(){
    double distancia;
    double kms_rodados = 0.0;
    printf("Quantos km? "); scanf("%lf", &distancia);
    while(podeAndar100m() && kms_rodados <= distancia){
        kms_rodados += 0.1;
        nivel_combustivel -= qtdNecessariaParaAndar100m();
    }
    printf("KMs RODADOS: %.2f\n\n\n", kms_rodados);
}

double obterGasolina(){
    return nivel_combustivel;
}

void adicionarGasolina(){
    double litros;
    printf("Quantos litros? "); scanf("%lf", &litros);
    nivel_combustivel += abs(litros);
    printf("%.2fL adicionados\n\n", litros);
}


void mensagem(){
    printf("-------------------------------------------------\n");
    printf("| Escolha uma opcao: \n");
    printf("| 1. Andar\n");
    printf("| 2. Checar nivel atual de combustivel\n");
    printf("| 3. Abastecer\n");
    printf("|\n|\n|>");
}

void menu(){
    printf("Quantos km/litro seu carro faz? "); scanf("%lf", &consumo);
    int op;
    char continuar;
    do{
        mensagem();
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                andar();
                break;
            case 2:
                printf("O tanque possui %.2fL\n\n\n", obterGasolina());
                break;
            case 3:
                adicionarGasolina();
                break;
            default:
                printf("Opcao invalida...\n\n\n");
                break;
        }
        printf("Continuar? [S/N]"); scanf(" %c", &continuar);
    } while(continuar == 'S' || continuar == 's');
}

int main(){
    menu();
    printf("\nsaindo.....\n\n");
    system("pause");
    return 0;
}