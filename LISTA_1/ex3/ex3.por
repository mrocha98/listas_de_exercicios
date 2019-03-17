programa
{
	inclua biblioteca Matematica --> m
	/*Elabore um algoritmo e um programa em C que leia a medida dos três lados de um triângulo
	e calcule o perímetro e área, imprimindo o resultado na tela. */

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

	funcao real calcula_perimetro(real a, real b, real c){
		retorne a + b + c
	}

	/*
	*utilizei a formula de heron, pois ela se aplica em qualquer tipo de triangulo
	*referencia: https://www.todamateria.com.br/area-do-triangulo/
	*/
	funcao real calcula_area(real a, real b, real c){
    		real p = calcula_perimetro(a, b, c)/2.0
    		real p_menos_a = p - a
    		real p_menos_b = p - b
    		real p_menos_c = p - c
    		real s = m.raiz(p * p_menos_a * p_menos_b * p_menos_c, 2)
    		retorne s
	}
	
	funcao inicio()
	{
		real a, b, c
	     escreva("a: ") leia(a)
	     escreva("b: ") leia(b)
	     escreva("c: ") leia(c)
	     se(triangulo_pode_existir(a,b,c))
	         escreva("PERIMETRO: ",calcula_perimetro(a,b,c),"\tAREA: ",calcula_area(a,b,c))
	     senao
	         escreva("Nao é possivel formar um triangulo com esses valores...\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1558; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */