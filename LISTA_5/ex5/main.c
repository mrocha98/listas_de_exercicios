#include <stdio.h>
#include <stdlib.h>

/*5.  Considerando a estrutura
    struct Vetor{
    float x;
    float y;
    float z;
    };
para representar um vetor no R³, implemente um programa que calcule a soma de dois vetores.*/
//https://www.ebah.com.br/content/ABAAAgSjcAH/vetores-no-r3

typedef struct Vetor{
    float x;
    float y;
    float z;
} V;

void somaVetorial(V v1, V v2, V *v3){
    v3->x = v1.x + v2.x;
    v3->y = v1.y + v2.y;
    v3->z = v1.z + v2.z;
}

int main(){
    V v1, v2, v3;

    printf("X1: "); scanf("%f", &v1.x);
    printf("Y1: "); scanf("%f", &v1.y);
    printf("Z1: "); scanf("%f", &v1.z);

    printf("\nX2: "); scanf("%f", &v2.x);
    printf("Y2: "); scanf("%f", &v2.y);
    printf("Z2: "); scanf("%f", &v2.z);

    somaVetorial(v1, v2, &v3);
    printf("\nX3: %.2f\n", v3.x);
    printf("Y3: %.2f\n", v3.y);
    printf("Z3: %.2f\n", v3.z);

    system("pause");
    return 0;
}