programa

{
	/*
	*Elabore  um algoritmo e um programa a em C que leia o tamanho do lado de um retângulo
	*e calcule o perímetro e área, imprimindo o resultado na tela
	*/
	
	funcao real calcula_perimetro(real l1, real l2){
		retorne (2 * l1 + 2 * l2)
	}

	funcao real calcula_area(real l1, real l2){
		retorne l1 * l2
	}
	
	funcao inicio()
	{
		real lado1, lado2, area, perimetro
    		escreva("LADO 1: ") leia(lado1)
    		escreva("LADO 2: ") leia(lado2)
    		area = calcula_area(lado1, lado2)
    		perimetro = calcula_perimetro(lado1, lado2)
    		escreva("PERIMETRO: ", perimetro, "\tAREA: ", area, "\n")
	}
}


/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 613; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */