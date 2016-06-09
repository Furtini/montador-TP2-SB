#include <stdio.h>
#include <stdlib.h>

#include "saidaSimples.h"


// TAD para funções da saida simples do montador.


// Função para execução do montador simples.
void execSimples(FILE *entrada, FILE *saida) {

	printf("Chamou executa simples OK!\n\n");
	
	char *buffer = NULL;

	size_t tam = 0;
	ssize_t read;

	while((read = getline(&buffer, &tam, entrada)) != -1) {
		printf("%s",buffer);
	}
	printf("\n");

}