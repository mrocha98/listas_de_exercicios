programa
{

/*Elabore um algoritmo e um programa em C que leia os coeficientes a e b de uma função
 de 1º grau e calcule x para y=0 ( y=ax+b), imprimindo o resultado na tela.*/
	
	funcao inicio()
	{
		real a, b, x
		escreva("Entre com os valores de a e b, respectivamente:\n")
		leia(a, b)
		x = -b/a
		escreva("x == ", x, "\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 341; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */