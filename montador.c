// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 2
// Montador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include <stdio.h>
#include <stdlib.h>

#include "tradutor.h"

// arg[1] -> arquivo entrada 			: saida = exec.sa
// arg[2] -> saida simples ou verbose	: saida = exec.sa (opcional)
// arq[3] -> nome do arquivo de saida	: saida = argv[3] (opcional)
int main(int argc, char const *argv[]) {
	
	FILE *entrada = NULL;
	FILE *saida = NULL;

	// Abre o arquivo de entrada para leitura.
	entrada = fopen(argv[1], "r");
	if (entrada == NULL){
		printf("ERRO ao abrir arquivo.\n");
		exit(1);	
	}


	// Apenas arquivo de entrada passado.
	if (argc == 2){
		
		// Abre arquivo de escrita como nome dado.
		saida = fopen("exec.sa", "wb");

		primeiraPassagem(entrada);
		rewind(entrada);
		segundaPassagem(entrada, saida);
	}

	// Arquivo de entrada + tipo de saida.	
	if (argc == 3){
	
		// Abre arquivo de escrita como nome dado.
		saida = fopen("exec.sa", "wb");

		primeiraPassagem(entrada);
		rewind(entrada);
		segundaPassagem(entrada, saida);
	}

	// Arquivo de entrada + tipo de saida + arquivo de saida.
	if (argc == 4){
		
		// Abre arquivo de escrita como nome dado.
		saida = fopen(argv[3], "wb");

		primeiraPassagem(entrada);
		rewind(entrada);
		segundaPassagem(entrada, saida);
	}
	// Arquivo de entrada + tipo de saida + arquivo de saida + tipo de saida.
	if (argc == 5){
		
		// Abre arquivo de escrita como nome dado.
		saida = fopen(argv[3], "wb");

		primeiraPassagem(entrada);
		rewind(entrada);
		segundaPassagem(entrada, saida);
	}
	


	fclose(entrada);
	fclose(saida);
	return 0;
}