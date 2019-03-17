#include <stdio.h>
#include <stdlib.h>

int encontra_maior(int arr[], int qtd){
    int maior = arr[0];
    for(int i = 1; i < qtd; i++){
        if(arr[i] > maior)
            maior = arr[i];
    }
    return maior;
}

int encontra_menor(int arr[], int qtd){
    int menor = arr[0];
    for(int i = 1; i < qtd; i++){
        if(arr[i] < menor)
            menor = arr[i];
    }
    return menor;
}

double calcula_media(int arr[], int qtd){
    double somatorio = 0.0;
    for(int i = 0; i < qtd; i++){
        somatorio += arr[i];
    }
    return (somatorio/qtd);
}

void alimenta_vetor(int arr[], int qtd){
    printf("Entre com %d valores:\n", qtd);
    for(int i = 0; i < qtd; i++){
        scanf("%d", &arr[i]);
    }
}

void printa_vetor(int arr[], int qtd){
    for(int i = 0; i < qtd; i++){
        printf("%d\n", arr[i]);
    }
}

int comparador(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void ordena_vetor(int arr[], int qtd){
    qsort(arr, qtd, sizeof(int), comparador);
}

int eh_par(int n){
    return (n % 2 == 0);
}

double descobre_mediana(int arr[], int qtd){
    ordena_vetor(arr, qtd);
    if(eh_par(qtd)){
        int a = qtd/2;
        int b = a + 1;
        return ((arr[a-1] + arr[b-1]) / 2.0);
    }
    int c = ((qtd - 1)/2)+1;
    return arr[c-1];
}

int descobre_moda(int arr[], int qtd){
    ordena_vetor(arr, qtd);
    int vezes_repitidas[qtd];
    for(int i = 0; i < qtd; i++){
        int temp = arr[i];
        int vezes = 0;
        for(int j = 0; j < qtd; j++){
            if(temp == arr[j])
                vezes++;
        }
        vezes_repitidas[i] = vezes;
    }

    int maior = encontra_maior(vezes_repitidas, qtd);
    if(maior == 1)
        return 0; //amodal
    for(int i = 0; i < qtd; i++){
        if(vezes_repitidas[i] == maior)
            return arr[i];
    }
}