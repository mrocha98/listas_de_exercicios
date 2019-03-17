typedef struct String{
    char S1[20+1];
    char S2[20+1];
} STR;

void ler_s1(STR *string);
void ler_s2(STR *string);
void imprime_tamanho_S1(STR *string);
int compara(STR *string);
void concatena(STR *string);
void inverte(STR *string);
int conta_caracter(STR *string, char c);
void substitui_primeira_ocorrencia(STR *string, char c1, char c2);