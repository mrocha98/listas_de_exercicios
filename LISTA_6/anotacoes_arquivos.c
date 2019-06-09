#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Modos de abertura de arquivos:
 *  r   -   Leitura. Arquivo deve existir.
 *  w   -   Escrita. Cria arquivo se não houver. Apaga o anterior se ele existir.
 *  a   -   Escrita. Os dados serão adicionados no fim do arquivo ('append').
 *  rb  -   Leitura binário. Arquivo deve existir.
 *  wb  -   Escrita binário. Cria arquivo se não houver. Apaga o anterior se ele existir.
 *  ab  -   Escrita binário. Os dados serão adicionados no fim do arquivo ('append').
 *  r+  -   Leitura/Escrita. O arquivo deve existir e pode ser modificado.
 *  w+  -   Leitura/Escrita. Cria o arquivo se não houver. Apaga o anterior se ele existir.
 *  a+  -   Leitura/Escrita. Os dados serão adicionados no fim do arquivo ('append').
 *  r+b -   Leitura/Escrita binário. O arquivo deve existir e pode ser modificado.
 *  w+b -   Leitura/Escrita binário. Cria arquivo se não houver. Apaga o anterior se ele existir.
 *  a+b -   Leitura/Escrita binário. Os dados serão adicionados no fim do arquivo ('append').
*/

/*  Posicionamento dentro do arquivo
 *  int fseek(FILE *fp, long numbytes, int origem);
 *     -    fp          =   ponteiro para o arquivo
 *     -    numbytes    =   total de bytes a ser pulado a partir da origem (aceita números negativos, que são usados quando se quer voltar no arquivo)
 *     -    origem      =   a partir de onde os numbytes serão contados
 *  Retorna 0 em caso de sucesso
 *  Constantes p/ origem:
 *      -   SEEK_SET    =   Início do arquivo
 *      -   SEEK_CUR    =   Ponto atual do arquivo
 *      -   SEEK_END    =   Fim do arquivo
 * 
 *  void rewind(FILE *fp);
 *  Simplesmente volta para o início do arquivo.
*/

/*  Escrever um cractere em um arquivo
 *  int fputc(char c, FILE *fp);
 *  retorna:
 *      -   Em caso de erro: EOF
 *      -   Em caso de sucesso: o próprio caractere
 *  exemplo de aplicação:   */
void exemploFputc(){
    FILE *f;
    f = fopen("arquivo.txt", "w");
    char texto[15+1] = "Batata frita";
    for(int i = 0; i < strlen(texto); i++) fputc(texto[i], f);
    fclose(f);
}

/*  Para ler um caractere de um arquivo
 *  int fgetc(FILE *fp);
 *  retorna:
 *      -   Em caso de erro: EOF
 *      -   Em caso de sucesso: o próprio caractere lido do arquivo
 *  exemplo de aplicação:   */
void exemploFgetc(){
    FILE *f;
    f = fopen("arquivo.txt", "r"); 
    char c = fgetc(f);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(f);
    }
    printf("\n\n");
}   

//Quando estiver trabalhando com arquivos binários, utilizar feof(FILE *fp); em vez de EOF

/*  Para escrever uma string em um arquivo
 *  int fputs(char *std, FILE *fp);
 *  retorna:
 *      -   Em caso de erro: EOF
 *      -   Em caso de suceeso: um valor diferente de 0
 *  exemplo de aplicação:   */
void exemploFputs(){
    FILE *f;
    f = fopen("arquivo.txt", "w");
    fputs("Hello World\n");
    fclose(f);
}

/*  Para ler uma string de um arquivo
 *  char* fgets(char std, int tamanho, FILE *fp);
 *  retorna:
 *      -   Em caso de erro: NULL
 *      -   Em caso de sucesso: um ponteiro para o primeiro caractere de str
 *  exemplo de aplicação:    */
void exemploFgets(){
    FILE *arq;
    arq = fopen("arquivo.txt", "r");
    char str[20];
    fgets(str, 20, arq);
    fclose(arq);
}

/*  Para escrever um bloco de bytes em um arquivo
 *  int fwrite(void *buffer, int bytes, int count, FILE *fp);
 *  Parâmetros:
 *      -   buffer: ponteiro genérico para os dados
 *      -   bytes:  tamanho, em bytes, de cada unidade de dado a ser gravada
 *      -   count:  total de unidades de dados que devem ser gravadas
 *      -   fp:     ponteiro para o arquivo
 *  Retorno:
 *      -   Total de unidades de dados gravadas com sucesso.
 *  exemplo de aplicação:   */ 
void exemplofWrite(){
    FILE *arq;
    arq = fopen("dados.txt", "wb");
    char str[20] = "Hello world!\n";
    float x = 5;
    int v[5] = {1, 2, 3, 4, 5};
    typedef struct cadastro {char nome[30], endereco[30]; int idade} CAD;
    CAD c = {"Fulano", "Rua dos Bobos", 42};
    fwrite(str, sizeof(char), 20, arq);
    fwrite(&x, sizeof(float), 1, arq);
    fwrite(v, sizeof(int), 5, arq);
    fwrite(&c, sizeof(CAD), 1, arq);
    fclose(arq);
}

/*  Para ler um bloco de bytes em um arquivo
 *  int fread(void *buffer, int bytes, int count, FILE *fp);
 *  Parâmetros:
 *      -   buffer: ponteiro genérico para os dados
 *      -   bytes:  tamanho, em bytes, de cada unidade de dado a ser lida
 *      -   count:  total de unidades de dados que devem ser lidas
 *      -   fp:     ponteiro para o arquivo
 *  Retorno:
 *      -   Total de unidades de dados lidas com sucesso.
 *  exemplo de aplicação:   */ 
void exemplofWrite(){
    FILE *arq;
    arq = fopen("dados.txt", "rb");
    char str[20];
    float x;
    int v[5];
    typedef struct cadastro {char nome[30], endereco[30]; int idade} CAD;
    CAD c;
    fread(str, sizeof(char), 20, arq);
    fwrite(&x, sizeof(float), 1, arq);
    fwrite(v, sizeof(int), 5, arq);
    fwrite(&c, sizeof(CAD), 1, arq);
    //se c fosse um array de structs, não precisaria colocar o & na frente, e o count seria o tamanho do array
    fclose(arq);
}

/*  Para escrever uma lista formatada de variáveis em um arquivo
 *  fprintf(FILE *f, "tipos de saída", variáveis);
 *  exemplo de aplicação:   */
void exemploFprintf(){
    FILE *f;
    f = fopen("arquivo.txt", "w");
    char nome[20] = "Faustop";
    int idade = 25;
    float salario = 8567.95;
    fprintf(f, "NOME: %s\nIDADE: %d\nSALARIO: %.2f", nome, idade, salario);
    fclose(f);
}

/*  Para ler uma lista formatada de variáveis em um arquivo
 *  fscanf(FILE *f, "tipos de entrada", variaveis);
 *  exemplo de aplicação:   */
void exemploFscanf(){
    FILE *f = fopen("arquivo.txt", "r");
    char textos[3][20], nome[20];
    int idade;
    float salario;
    fscanf(f, "%s %s", textos[0], nome);
    fscanf(f, "%s %d", textos[1], &idade);
    fscanf(f, "%s %f", textos[2], &salario);
    fclose(f);
}

int main(){
    system("pause");
    return 0;
}