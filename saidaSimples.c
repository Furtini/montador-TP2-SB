#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "saidaSimples.h"
#include "tabelaSimbolo.h"


// TAD para funções da saida simples do montador.

// Função para execução do montador simples.
void passagemUm(FILE *entrada) {

	int counter = 0;

	char *buffer = NULL;
	char *token;

	size_t tam = 0;
	ssize_t read;

	// Cria tabela de simbolos vazia.
	TabelaSimbolo *tabela = aloca(sizeof(TabelaSimbolo));
	fazTabelaSimboloVazia(tabela);

	// Leitura do arquivo de entrada.
	while((read = getline(&buffer, &tam, entrada)) != -1) {
		//printf("%s",buffer);

		// Quebrando buffer em palavras.
		token = strtok(buffer, " :");
		// Se primeiro nome for label
		if (token[0] == '_') {
			printf("Label: %s\n",token);
			
		// Se não for label é instrução.
		} else {
			printf("%s\n",token);
				
		}


		

		counter++;
	}
	printf("\n");

}
