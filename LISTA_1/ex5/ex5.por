programa
{
	inclua biblioteca Matematica --> m
	
	/*Elabore  um algoritmo e um programa em C que leia a medida dos três lados de um triângulo
	e determine se o triângulo é equilátero, isósceles ou escaleno, imprimindo o resultado na tela.*/

	/*
	| b - c | < a < b + c
	| a - c | < b < a + c
	| a - b | < c < a + b
	referencia = https://mundoeducacao.bol.uol.com.br/matematica/condicao-existencia-um-triangulo.html
	*/
	funcao logico triangulo_pode_existir(real a, real b, real c){
    		logico condicao_1 = (a > m.valor_absoluto(b - c)) e (a < b + c)
    		logico condicao_2 = (b > m.valor_absoluto(a - c)) e (b < a + c)
    		logico condicao_3 = (c > m.valor_absoluto(a - b)) e (c < a + b)
    		retorne condicao_1 e condicao_2 e condicao_3
	}
	
	funcao inicio()
	{
		real a, b, c
	     escreva("a: ") leia(a)
	     escreva("b: ") leia(b)
	     escreva("c: ") leia(c)
	     se(nao(triangulo_pode_existir(a,b,c)))
	         escreva("Esses valores nao podem formar um triangulo\n")
	     senao{
	         logico todos_iguais = (a == b e a == c e b == c)
	         logico todos_diferentes = (nao(a == b) e nao(a == c) e nao(b == c))
	         se(todos_iguais)
	             escreva("Esses valores formam um triangulo equilatero\n")
	         senao se(todos_diferentes)
	             escreva("Esses valores formam um triangulo escaleno\n")
	         senao
	             escreva("Esses valores formam um triangulo isosceles\n")
	    }
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1428; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */