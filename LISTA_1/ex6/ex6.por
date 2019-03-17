programa
{

/*Elabore  um algoritmo e um programa em C que leia a medida dos três lados de um triângulo
e determine se o triângulo é acutângulo, obtusângulo ou retângulo, imprimindo o resultado na tela.
*/
	
	inclua biblioteca Matematica --> m

	//aproveitando codigo do ex 3 xD
	funcao logico triangulo_pode_existir(real a, real b, real c){
		logico cond1 = (a > m.valor_absoluto(b - c)) e (a < b + c)
		logico cond2 = (b > m.valor_absoluto(a - c)) e (b < a + c)
		logico cond3 = (c > m.valor_absoluto(a - b)) e (c < a + b)
		retorne cond1 e cond2 e cond3
	}

	funcao real descobre_maior(real a, real b, real c){
		real maior = a
		se(b > maior)
			maior = b
		se(c > maior)
			maior = c
		retorne maior
	}
	
	funcao real descobre_menor(real a, real b, real c){
		real menor = a
		se(b < menor)
			menor = b
		se(c < menor)
			menor = c
		retorne menor
	}

	funcao real descobre_meio(real a, real b, real c){
		real maior = descobre_maior(a, b, c)
		real menor = descobre_menor(a, b, c)
		se(nao(a == maior) e nao(a == menor))
			retorne a	
		se(nao(b == maior) e nao(b == menor))
			retorne b	
		retorne c
	}
	
	funcao inicio()
	{
		real a, b, c
		escreva("Entre com os valores de a, b e c, respectivamente:\n")
		leia(a, b, c)
		logico todos_iguais = (a == b e a == c e b == c)
		se(nao(triangulo_pode_existir(a, b, c)))
			escreva("Esses valores nao podem formar um triangulo\n")
		senao se(todos_iguais)
			escreva("Esses valores formam um triangulo acutangulo\n")
		senao{
			real maior = descobre_maior(a, b, c)
			real meio = descobre_meio(a, b, c)
			real menor = descobre_menor(a, b, c)

			real quad_maior = m.potencia(maior, 2.0)
			real quad_meio = m.potencia(meio, 2.0)
			real quad_menor = m.potencia(menor, 2.0)

			logico eh_retangulo = (quad_maior == quad_meio + quad_menor)
			logico eh_obtusangulo = (quad_maior > quad_meio + quad_menor)

			se(eh_retangulo)
				escreva("Esses valores formam um triangulo retangulo\n")
			senao se(eh_obtusangulo)
				escreva("Esses valores formam um triangulo obtusangulo\n")
			senao
				escreva("Esses valores formam um triangulo acutangulo\n")
		}
		
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 205; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */