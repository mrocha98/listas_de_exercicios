#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/*4- Usando o programa do WiFi apresentado em aula, melhore-o de forma que ele leia três roteadores e 
calcule se algum deles permite que seu sinal seja captado por um dispositivo na posição (x,y)
http://fatecsjc-prd.azurewebsites.net/moodle/pluginfile.php/6131/mod_resource/content/4/Wifi.c*/

/*Programa sobre WiFi
1 - ler atributos
2 - calcular area de abrangencia
3 - verificar se dipositivo capta sinal*/

// definicao de estrutura que virou tipo WF
typedef struct wifi{
    char cor[20];
	float xo;
    float yo;
    float raio;
}WF;
//variavel eq do tipo WF
WF eq;
WF tabW[3];

// funcao para leitura
void ler_equi(){
	printf("\nDigite cor do equipamento:\n");
    scanf("%s", eq.cor); fflush(stdin);
    printf("\nDigite o raio de equipamento:\n");
    scanf("%f",&eq.raio);
    printf("\nDigite a posição no eixo x:\n");
    scanf("%f",&eq.xo);
    printf("\nDigite a posição no eixo y:\n");
    scanf("%f",&eq.yo);
}


void ler_varios(){
	for(int i=0;i<3;i++){	
		printf("\nDigite cor do equipamento:\n");
        scanf("%s", tabW[i].cor); fflush(stdin);
    	printf("\nDigite o raio de equipamento:\n");
    	scanf("%f",&tabW[i].raio);
    	printf("\nDigite a posição no eixo x:\n");
    	scanf("%f",&tabW[i].xo);
    	printf("\nDigite a posição no eixo y:\n");
    	scanf("%f",&tabW[i].yo);	
	}	
}
// função que calcula a área de abrangência
float calcular_area_Wifi(){
   return(3.14*pow(eq.raio, 2));
}

//função para captar sinal
int capta_sinal(float x1, float y1){
    float b,c,a;
    b=eq.xo-x1;
    c=eq.yo-y1;
    a=sqrt((b*b)+(c*c));
    printf("\na=%.2f,b=%.2f,c=%.2f",a,b,c);
    if (a<=eq.raio)return 1;
    else return 0;
}
// função principal com menu
int main(){
    int op;
    float h,v;
    setlocale(LC_ALL,"Portuguese");
    do{
        printf("\n1-ler atributos\n2-area\n3-capta?\n4-ler tres roteadores\n5-sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:ler_equi();
                break;
            case 2:printf("\nArea: %.2f",calcular_area_Wifi());
                break;
            case 3:printf("\nDigite a posição do dispositivo(x,y)\n");
                scanf("%f,%f",&h,&v);
                if(capta_sinal(h,v)) printf("\nDentro da area\n");
                else                    printf("\nFora da area\n");
                break;
            case 4:ler_varios();
                break;
            case 5:printf("Saindo..\n");
                break;
            default: printf("\nOp invalida\n");
        }
    }while(op!=5);
    system("pause");
    return 0;
}