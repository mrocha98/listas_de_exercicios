#include <stdio.h>
#include <stdlib.h>
#define TAM_NOME 30+1
#define TAM_END 100+1

/*2.  Implemente  um  programa  que  leia  o  nome,  a  idade  e  o  endereço  de  uma  pessoa  e
armazene os dados em uma estrutura.*/

typedef struct pessoa {
    char nome[TAM_NOME];
    int idade;
    char endereco[TAM_END];
} P;

int main(){
    P pes;
    printf("NOME: "); scanf("%[^\n]s", pes.nome);
    printf("IDADE: "); scanf("%d", &pes.idade);
    printf("ENDERECO: "); fflush(stdin); scanf("%[^\n]s", pes.endereco);

    printf("NOME: %s\n", pes.nome);
    printf("IDADE: %d\n", pes.idade);
    printf("ENDERECO: %s\n", pes.endereco);

    system("pause");
    return 0;
}
