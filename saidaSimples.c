#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "saidaSimples.h"
#include "tabelaSimbolo.h"

// TAD para funções da saida simples do montador.

// Função para execução do montador simples.
void passagemUm(FILE *entrada) {

	int counter = 0;
	int opcode = 0;

	char *buffer = NULL;
	char *token;
	char label[15];

	size_t tam = 0;

	// Cria tabela de simbolos vazia.
	TabelaSimbolo *tabela = aloca(sizeof(TabelaSimbolo));
	fazTabelaSimboloVazia(tabela);

	// Leitura do arquivo de entrada.
	while(getline(&buffer, &tam, entrada) != -1) {
		//printf("%s",buffer);

		// Quebrando buffer em palavras.
		token = strtok(buffer, " :");
		// Se primeiro nome for label
		if (token[0] == '_') {
			strcpy(label, token);
			printf("Label: %s, ILC: %d \n",label, counter);
			// Adiciona na lista junto com o contador.
			adicionaSimbolo(tabela, label, counter);

			token = strtok(NULL, " ,");
			printf("Instrução: %s\n",token );
			// Checa qual instrução.
			if (strcmp(token, "MOV") == 0) {
				printf("%s\n",token);
				opcode = 1;
				counter += 6;
			}
			if (strcmp(token, "ADD") == 0) {
				printf("%s\n",token);
				opcode = 2;
				counter += 6;
			}
			if (strcmp(token, "SUB") == 0) {
				printf("%s\n",token);
				opcode = 3;
				counter += 6;
			}
			if (strcmp(token, "MUL") == 0) {
				printf("%s\n",token);
				opcode = 4;
				counter += 4;
			}
			if (strcmp(token, "DIV") == 0) {
				printf("%s\n",token);
				opcode = 4;
				counter += 4;
			}
			if (strcmp(token, "AND") == 0) {
				printf("%s\n",token);
				opcode = 6;
				counter += 6;
			}
			if (strcmp(token, "NOT") == 0) {
				printf("%s\n",token);
				opcode = 7;
				counter += 4;
			}
			if (strcmp(token, "OR") == 0) {
				printf("%s\n",token);
				opcode = 8;
				counter += 6;
			}
			if (strcmp(token, "CMP") == 0) {
				printf("%s\n",token);
				opcode = 9;
				counter += 6;
			}
			if (strcmp(token, "JMP") == 0) {
				printf("%s\n",token);
				opcode = 10;
				counter += 4;
			}
			if (strcmp(token, "JZ") == 0) {
				printf("%s\n",token);
				opcode = 11;
				counter += 4;
			}
			if (strcmp(token, "JS") == 0) {
				printf("%s\n",token);
				opcode = 12;
				counter += 4;
			}
			if (strcmp(token, "CALL") == 0) {
				printf("%s\n",token);
				opcode = 13;
				counter += 4;
			}
			if (strcmp(token, "RET") == 0) {
				printf("%s\n",token);
				opcode = 14;
				counter += 2;
			}
			if (strcmp(token, "PUSH") == 0) {
				printf("%s\n",token);
				opcode = 15;
				counter += 4;
			}
			if (strcmp(token, "POP") == 0) {
				printf("%s\n",token);
				opcode = 16;
				counter += 4;
			}
			if (strcmp(token, "DUMP") == 0) {
				printf("%s\n",token);
				opcode = 17;
				counter += 2;
			}
			if (strcmp(token, "READ") == 0) {
				printf("%s\n",token);
				opcode = 18;
				counter += 4;
			}
			if (strcmp(token, "WRITE") == 0) {
				printf("%s\n",token);
				opcode = 19;
				counter += 4;
			}
			if (strcmp(token, "HLT") == 0) {
				printf("%s\n",token);
				opcode = 20;
				counter += 2;
			}
			
		// Se não for label é instrução.
		} else {
			//printf("%s\n",token);

			// Checa qual instrução.
			if (strcmp(token, "MOV") == 0) {
				printf("%s\n",token);
				opcode = 1;
				counter += 6;
			}
			if (strcmp(token, "ADD") == 0) {
				printf("%s\n",token);
				opcode = 2;
				counter += 6;
			}
			if (strcmp(token, "SUB") == 0) {
				printf("%s\n",token);
				opcode = 3;
				counter += 6;
			}
			if (strcmp(token, "MUL") == 0) {
				printf("%s\n",token);
				opcode = 4;
				counter += 4;
			}
			if (strcmp(token, "DIV") == 0) {
				printf("%s\n",token);
				opcode = 4;
				counter += 4;
			}
			if (strcmp(token, "AND") == 0) {
				printf("%s\n",token);
				opcode = 6;
				counter += 6;
			}
			if (strcmp(token, "NOT") == 0) {
				printf("%s\n",token);
				opcode = 7;
				counter += 4;
			}
			if (strcmp(token, "OR") == 0) {
				printf("%s\n",token);
				opcode = 8;
				counter += 6;
			}
			if (strcmp(token, "CMP") == 0) {
				printf("%s\n",token);
				opcode = 9;
				counter += 6;
			}
			if (strcmp(token, "JMP") == 0) {
				printf("%s\n",token);
				opcode = 10;
				counter += 4;
			}
			if (strcmp(token, "JZ") == 0) {
				printf("%s\n",token);
				opcode = 11;
				counter += 4;
			}
			if (strcmp(token, "JS") == 0) {
				printf("%s\n",token);
				opcode = 12;
				counter += 4;
			}
			if (strcmp(token, "CALL") == 0) {
				printf("%s\n",token);
				opcode = 13;
				counter += 4;
			}
			if (strcmp(token, "RET") == 0) {
				printf("%s\n",token);
				opcode = 14;
				counter += 2;
			}
			if (strcmp(token, "PUSH") == 0) {
				printf("%s\n",token);
				opcode = 15;
				counter += 4;
			}
			if (strcmp(token, "POP") == 0) {
				printf("%s\n",token);
				opcode = 16;
				counter += 4;
			}
			if (strcmp(token, "DUMP") == 0) {
				printf("%s\n",token);
				opcode = 17;
				counter += 2;
			}
			if (strcmp(token, "READ") == 0) {
				printf("%s\n",token);
				opcode = 18;
				counter += 4;
			}
			if (strcmp(token, "WRITE") == 0) {
				printf("%s\n",token);
				opcode = 19;
				counter += 4;
			}
			if (strcmp(token, "HLT") == 0) {
				printf("%s\n",token);
				opcode = 20;
				counter += 2;
			}
		}
	}
	printf("\n");
	printf("-------------------------------\n");
	imprimeTabela(tabela);
}
