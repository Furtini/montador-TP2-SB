// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 2
// Montador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include <stdio.h>
#include <stdlib.h>

#include "tabelaSimbolo.h"
#include "tradutor.h"

int main(int argc, char const *argv[]) {
	
	FILE *entrada = NULL;
	FILE *saida = NULL;

	// Cria tabela de simbolos vazia.
	TabelaSimbolo *tabela = aloca(sizeof(TabelaSimbolo));
	fazTabelaSimboloVazia(tabela);

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

		primeiraPassagem(entrada, tabela);
		rewind(entrada);
		segundaPassagem(entrada, saida, tabela);
	}

	// Arquivo de entrada + tipo de saida.	
	if (argc == 3){
	
		// Abre arquivo de escrita como nome dado.
		saida = fopen("exec.sa", "wb");

		primeiraPassagem(entrada, tabela);
		rewind(entrada);
		segundaPassagem(entrada, saida, tabela);
		if (strcmp(argv[2], "-v") == 0) {
			imprimeTabela(tabela);
		}
	}

	// Arquivo de entrada + tipo de saida + arquivo de saida.
	if (argc == 4){
		
		// Abre arquivo de escrita como nome dado.
		saida = fopen(argv[3], "wb");

		primeiraPassagem(entrada, tabela);
		rewind(entrada);
		segundaPassagem(entrada, saida, tabela);
		if (strcmp(argv[2], "-v") == 0) {
			imprimeTabela(tabela);
		}
	}
	// Arquivo de entrada + tipo de saida + arquivo de saida + tipo de saida.
	if (argc == 5){
		
		// Abre arquivo de escrita como nome dado.
		saida = fopen(argv[3], "wb");

		primeiraPassagem(entrada, tabela);
		rewind(entrada);
		segundaPassagem(entrada, saida, tabela);
		if (strcmp(argv[4], "-v") == 0) {
			imprimeTabela(tabela);
		}
	}

	// Libera estruturas e fecha arquivos.
	liberaTabela(tabela);
	free(tabela);
	fclose(entrada);
	fclose(saida);
	return 0;
}