#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*7.  Faca um programa que converta coordenadas polares para cartesianas:
•Crie e leia um ponto em coordenada polar, composto por raio (r) e argumento (a)em radianos.
•Crie outro ponto, agora em coordenada cartesiana, composto por x e y, sabendo que x=r∗cosa e y=r∗sina.
No programa principal, leia um ponto em coordenada polar e mostre as coordenadas do ponto gerado no plano cartesiano.*/

typedef struct coordenadaPolar {
    float raio;
    float argumento;
} CORD;

void converteParaCartesiana(float *r, float *arg){
    *r *= cos(*r);
    *arg *= sin(*arg);
}

int main(){
    CORD c;
    printf("Raio: "); scanf("%f", &c.raio);
    printf("Argumento: "); scanf("%f", &c.argumento);
    converteParaCartesiana(&c.raio, &c.argumento);
    printf("FORMA CARTESIANA: ( %.2f ; %.2f )\n", c.raio, c.argumento);
    system("pause");
    return 0;
}