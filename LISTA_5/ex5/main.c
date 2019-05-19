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

float soma2Valores(float n1, float n2){
    return (n1 + n2 + 0.0);
}

int main(){
    V v1, v2, v3;
    float x1, x2, y1, y2, z1, z2;

    printf("X1: "); scanf("%d", &x1);
    printf("Y1: "); scanf("%d", &y1);
    printf("Z1: "); scanf("%d", &z1);

    printf("\nX2: "); scanf("%d", &x2);
    printf("Y2: "); scanf("%d", &y2);
    printf("Z2: "); scanf("%d", &z2);

    printf("X1: %d\n", x1);
    printf("Y1: %d\n", y1);
    printf("Z1: %d\n", z1);

    v1.x = x1; v1.y = y1; v1.z = z1;
    v2.x = x2; v2.y = y2; v2.z = z2;

    v3.x = v1.x + v2.x;
    v3.y = soma2Valores(v1.y, v2.y);
    v3.z = soma2Valores(v1.z, v2.z);

    printf("NOVO VETOR:\n");
    printf("\tX: %d\n", v3.x);
    printf("\tY: %d\n", v3.y);
    printf("\tZ: %d\n", v3.z);

    system("pause");
    return 0;
}