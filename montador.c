#include <stdio.h>
#include <stdlib.h>

#include "saidaSimples.h"

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
		printf("Simples SEM modo e SEM arquivo saida.\n");
		printf("%s\n",argv[1]);

		// Abre arquivo de escrita como nome dado.
		saida = fopen("exec.sa", "wb");

		execSimples(entrada, saida);
	}

	// Arquivo de entrada + tipo de saida.	
	if (argc == 3){
		printf("Simples COM modo e SEM arquivo saida.\n");
		printf("%s\n",argv[2]);

		// Abre arquivo de escrita como nome dado.
		saida = fopen("exec.sa", "wb");

		execSimples(entrada, saida);
	}

	// Arquivo de entrada + tipo de saida + arquivo de saida.
	if (argc == 4){
		printf("Simples COM modo e COM arquivo saida.\n");
		printf("%s\n",argv[3]);

		// Abre arquivo de escrita como nome dado.
		saida = fopen(argv[3], "wb");

		execSimples(entrada, saida);
	}
	// Arquivo de entrada + tipo de saida + arquivo de saida + tipo de saida.
	if (argc == 5){
		printf("Simples COM modo e COM arquivo saida.\n");
		printf("%s\n",argv[4]);
		
		// Abre arquivo de escrita como nome dado.
		saida = fopen(argv[3], "wb");

		execSimples(entrada, saida);
	}
	


	fclose(entrada);
	fclose(saida);
	return 0;
}