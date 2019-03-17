typedef struct pessoa{
    char nome[20+1];
    int idade;
    float peso;
    float altura;
} PESSOA;

void cria_pessoa(PESSOA *p);
void envelhecer(int anos, PESSOA *p);
void engordar(float kg, PESSOA *p);
void emagrecer(float kg, PESSOA *p);
void crescer(PESSOA *p);
float Imc(float peso, float altura);
void relatorio(PESSOA *p);