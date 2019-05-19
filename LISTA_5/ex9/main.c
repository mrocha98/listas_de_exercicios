#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*9. Faca um programa que faca operacoes simples de numeros complexos:
•Crie e leia dois numeros complexos z e w, compostos por parte real e parte imaginaria.
•Apresente a soma,  subtracao e produto entre z e w,  nessa ordem,  bem como o modulo de ambos.*/

typedef struct complexo {
    float real;
    float imaginario;
} COMPLEXO;

COMPLEXO somaComplexa(COMPLEXO n1, COMPLEXO n2){
    COMPLEXO n3;
    n3.real = n1.real + n2.real;
    n3.imaginario = n1.imaginario + n2.imaginario;
    return n3;
}

COMPLEXO subtracaoComplexa(COMPLEXO n1, COMPLEXO n2){
    COMPLEXO n3;
    n3.real = n1.real - n2.real;
    n3.imaginario = n1.imaginario - n2.imaginario;
    return n3;
}

COMPLEXO produtoComplexo(COMPLEXO n1, COMPLEXO n2){
    COMPLEXO n3;
    n3.real =  n1.real*n2.real - n1.imaginario*n2.imaginario; //ac - bd
    n3.imaginario = n1.real*n2.imaginario + n1.imaginario*n2.real;//i(ad+bc)
    return n3;
}

float modulo(COMPLEXO n){
    return sqrtf(pow(n.imaginario, 2) + pow(n.real, 2));    
}

int main(){
    COMPLEXO w, z, m;
    printf("W real: "); scanf("%f", &w.real);
    printf("W imaginario: "); scanf("%f", &w.imaginario);
    printf("Z real: "); scanf("%f", &z.real);
    printf("Z imaginario: "); scanf("%f", &z.imaginario);
    m = somaComplexa(w, z);
    printf("SOMA: %.1f + i(%.1f)\n", m.real, m.imaginario);
    m = subtracaoComplexa(w, z);
    printf("SUBTRACAO: %.1f + i(%.1f)\n", m.real, m.imaginario);
    m = produtoComplexo(w, z);
    printf("PRODUTO: %.1f + i(%.1f)\n", m.real, m.imaginario);
    printf("MODULO W: %.2f\n", modulo(w));
    printf("MODULO Z: %.2f\n", modulo(z));
    system("pause");
    return 0;
}