programa
{
/*ax² + bx + c = 0*/
	
	inclua biblioteca Matematica --> m

	funcao real calcula_delta(real a, real b, real c){
		real delta = m.potencia(b, 2.0) - 4 * a * c
		se(delta < 0)
			retorne -1.0
		retorne delta
	}

	funcao real calcula_x1(real a, real b, real c){
		real delta = calcula_delta(a, b, c)
		retorne (-b + m.raiz(delta, 2.0))/(2 * a)
	}

	funcao real calcula_x2(real a, real b, real c){
		real delta = calcula_delta(a, b, c)
		retorne (-b - m.raiz(delta, 2.0))/(2 * a)
	}
	
	funcao inicio()
	{
		real a, b, c
		escreva("Entre com a, b e c, respectivamente:\n") leia(a, b, c)
		logico todos_nulos = (a == 0 e b == 0 e c == 0)
		logico delta_negativo = (calcula_delta(a, b, c) < 0)
		se(todos_nulos)
			escreva("Valores nulos...\n")
		senao se(delta_negativo)
			escreva("Delta negativo! As raizes nao pertencem aos nums reais!\n")
		senao{
			escreva("X1: ", calcula_x1(a, b, c), "\n")
			escreva("X2: ", calcula_x2(a, b, c), "\n")
		}
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 356; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */