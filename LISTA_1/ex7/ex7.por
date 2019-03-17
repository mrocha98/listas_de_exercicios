programa
{
	inclua biblioteca Matematica --> m

/*Elabore  um algoritmo e um programa em C que leia peso
e altura de uma pessoa e calcule o IMC, imprimindo o resultado na tela. */
	
	//referência: http://www.calculoimc.com.br/como-calcular/
	funcao real calcula_imc(real peso, real altura){
    		retorne peso/m.potencia(altura, 2.0)
	}
	
	funcao inicio()
	{
		real peso, altura
		escreva("PESO [KG]: ") leia(peso)
		escreva("ALTURA [M]: ") leia(altura)
		escreva("IMC: ", calcula_imc(peso, altura))
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 511; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */