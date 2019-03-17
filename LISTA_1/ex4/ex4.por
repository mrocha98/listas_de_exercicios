programa
{
	/*Elabore um algoritmo e um programa em C que resolva o  Problema C, " A Horta do Juquinha",
	de: Antonio Cesar de Barros Munari (Fatec Sorocaba), da Maratona de Programação InterFatec's 2018.*/
	
	funcao inicio()
	{
		inteiro qtd_sementes, qtd_necessarias
		inteiro covas = 0
    		para(inteiro i = 0; i < 3; i++){
        		escreva("Entre com a quantidade de sementes do saquinho e\na quantidade necessaria para uma cova, respectivamente:\n")
        		leia(qtd_sementes, qtd_necessarias)
        		enquanto(verdadeiro){
            		se(qtd_sementes < qtd_necessarias)
                		pare
            		qtd_sementes -= qtd_necessarias
            		covas++
        		}
    		}
		escreva("COVAS: ", covas)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 537; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */