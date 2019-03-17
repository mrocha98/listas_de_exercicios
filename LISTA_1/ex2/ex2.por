programa
{

	/*Elabore um algoritmo e um programa em C que resolva o  Problema B
	"Um pra você, um pra mim", de Lúcio Nunes de Lira (Fatec São Paulo),
	da Maratona de Programação InterFatec's 2018.*/
	
	inteiro amigo_saldo = 0, seu_saldo = 0, valor_nota

	funcao logico eh_par(inteiro n){
     	retorne (n % 2 == 0)
	}
	
	funcao vazio loop_amigo_comeca(inteiro qtd){
     	para(inteiro i = 1; i <= qtd; i++){
        		escreva("Valor da nota: ") leia(valor_nota)
        	se(eh_par(i))
            seu_saldo += valor_nota
          senao
            amigo_saldo += valor_nota
     	}
	}

	funcao vazio loop_voce_comeca(inteiro qtd){
     	para(inteiro i = 1; i <= qtd; i++){
        		escreva("Valor da nota: ") leia(valor_nota)
        	se(eh_par(i))
            amigo_saldo += valor_nota
          senao
            seu_saldo += valor_nota
     	}
	}
		
	funcao inicio()
	{
		caracter primeiro
		inteiro qtd_notas
		escreva("Quem começa? [V/A]\t") leia(primeiro)
		escreva("Quantas notas? ") leia(qtd_notas)

		logico voce_comeca = (primeiro == 'V')
		se(voce_comeca){loop_voce_comeca(qtd_notas)}
		senao{loop_amigo_comeca(qtd_notas)}
		escreva("VOCE: ", seu_saldo, " AMIGO: ", amigo_saldo)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 446; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */