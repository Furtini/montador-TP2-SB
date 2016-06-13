#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "saidaSimples.h"
#include "tabelaSimbolo.h"

// TAD para funções da saida simples do montador.

// Cria tabela de simbolos vazia GLOBAL.
TabelaSimbolo *tabela;


// Função para execução do montador simples.
void primeiraPassagem(FILE *entrada) {

	int counter = 0;
	int opcode = 0;

	char *buffer = NULL;
	char *token;
	
	size_t tam = 0;


	int i; 
	tabela = aloca(sizeof(TabelaSimbolo));
	fazTabelaSimboloVazia(tabela);

	// Leitura do arquivo de entrada.
	while(getline(&buffer, &tam, entrada) != -1) {

		// Quebrando buffer em palavras.
		token = strtok(buffer, " :");
		// Se primeiro nome for label
		if (token[0] == '_') {

			for (i=0; i < 15; i++) {
				if (token[i] == '\0') {
					printf("Achei fim: %d \n",i );
					break;
				}
			}
			// Adiciona na lista junto com o contador.
			adicionaSimbolo(tabela, token, counter);

			token = strtok(NULL, " ");	
		} 
		// Checa qual instrução.
		if (strcmp(token, "DW") == 0) {
			printf("%s\n",token);

		}
		if (strcmp(token, "MOV") == 0) {
			//printf("%s\n",token);
			opcode = 1;
			counter += 6;
		}
		if (strcmp(token, "ADD") == 0) {
			//printf("%s\n",token);
			opcode = 2;
			counter += 6;
		}
		if (strcmp(token, "SUB") == 0) {
			//printf("%s\n",token);
			opcode = 3;
			counter += 6;
		}
		if (strcmp(token, "MUL") == 0) {
			//printf("%s\n",token);
			opcode = 4;
			counter += 4;
		}
		if (strcmp(token, "DIV") == 0) {
			//printf("%s\n",token);
			opcode = 4;
			counter += 4;
		}
		if (strcmp(token, "AND") == 0) {
			//printf("%s\n",token);
			opcode = 6;
			counter += 6;
		}
		if (strcmp(token, "NOT") == 0) {
			//printf("%s\n",token);
			opcode = 7;
			counter += 4;
		}
		if (strcmp(token, "OR") == 0) {
			//printf("%s\n",token);
			opcode = 8;
			counter += 6;
		}
		if (strcmp(token, "CMP") == 0) {
			//printf("%s\n",token);
			opcode = 9;
			counter += 6;
		}
		if (strcmp(token, "JMP") == 0) {
			//printf("%s\n",token);
			opcode = 10;
			counter += 4;
		}
		if (strcmp(token, "JZ") == 0) {
			//printf("%s\n",token);
			opcode = 11;
			counter += 4;
		}
		if (strcmp(token, "JS") == 0) {
			//printf("%s\n",token);
			opcode = 12;
			counter += 4;
		}
		if (strcmp(token, "CALL") == 0) {
			//printf("%s\n",token);
			opcode = 13;
			counter += 4;
		}
		if (strcmp(token, "RET") == 0) {
			//printf("%s\n",token);
			opcode = 14;
			counter += 2;
		}
		if (strcmp(token, "PUSH") == 0) {
			//printf("%s\n",token);
			opcode = 15;
			counter += 4;
		}
		if (strcmp(token, "POP") == 0) {
			//printf("%s\n",token);
			opcode = 16;
			counter += 4;
		}
		if (strcmp(token, "DUMP") == 0) {
			//printf("%s\n",token);
			opcode = 17;
			counter += 2;
		}
		if (strcmp(token, "READ") == 0) {
			//printf("%s\n",token);
			opcode = 18;
			counter += 4;
		}
		if (strcmp(token, "WRITE") == 0) {
			//printf("%s\n",token);
			opcode = 19;
			counter += 4;
		}
		if (strcmp(token, "HLT") == 0) {
			//printf("%s\n",token);
			opcode = 20;
			counter += 2;
		}
	}
	printf("-------------------------------\n");
	imprimeTabela(tabela);
	printf("-------------------------------\n");
}

// Faz a segunda passagem no arquivo de entrada.
void segundaPassagem(FILE *entrada, FILE *saida) {

	int counter = 0;
	int opcode = 0;
	int codigo = 0;
	int op1, op2;

	char *buffer = NULL;
	char *token;
	int i;
	size_t tam = 0;

	// Leitura do arquivo de entrada.
	while(getline(&buffer, &tam, entrada) != -1) {
		
		// Quebrando buffer em palavras.
		token = strtok(buffer, " :\n");
		// Se primeiro nome for label
		if (token[0] == '_') {
			
			printf("Label: %s, ILC: %d \n",token, counter);

			token = strtok(NULL, " \n");	
		} 
		// Checa qual instrução.
		if (strcmp(token, "DW") == 0) {
			printf("%s\n",token);

		}
		if (strcmp(token, "MOV") == 0) {
			// Dois Operandos
			printf("%s\n",token);
			opcode = 1;
			counter += 6;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\n");
			op2 = checaOperando(token);

		}
		if (strcmp(token, "ADD") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 2;
			counter += 6;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\n");
			op2 = checaOperando(token);

		}
		if (strcmp(token, "SUB") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 3;
			counter += 6;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\n");
			op2 = checaOperando(token);

		}
		if (strcmp(token, "MUL") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 4;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);

		}
		if (strcmp(token, "DIV") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 4;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);

		}
		if (strcmp(token, "AND") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 6;
			counter += 6;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\n");
			op2 = checaOperando(token);

		}
		if (strcmp(token, "NOT") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 7;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);

		}
		if (strcmp(token, "OR") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 8;
			counter += 6;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\n");
			op2 = checaOperando(token);

		}
		if (strcmp(token, "CMP") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 9;
			counter += 6;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\n");
			op2 = checaOperando(token);

		}
		if (strcmp(token, "JMP") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 10;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " \n");
			op1 = checaOperando(token);
			printf("TESTE\n");
			printf("%d \n", '\n');
			for (i=0; i < 15; i++) {
				printf("Caracteres[%d]: %c \n",i, token[i] );
				if (token[i] == '\0') {
					printf("Achei fim: %d \n",i );
					break;
				}
			}
			// Busca ILC do label.
			if (op1 == 9) {
				buscaSimbolo(tabela, token);
			}

		}
		if (strcmp(token, "JZ") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 11;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ;\n");
			op1 = checaOperando(token);
			// Busca ILC do label.
			if (op1 == 9) {
				buscaSimbolo(tabela, token);
			}

		}
		if (strcmp(token, "JS") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 12;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ;\n");
			op1 = checaOperando(token);
			// Busca ILC do label.
			if (op1 == 9) {
				buscaSimbolo(tabela, token);
			}

		}
		if (strcmp(token, "CALL") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 13;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);

		}
		if (strcmp(token, "RET") == 0) {
			// Nenhum operando.
			printf("%s\n",token);
			opcode = 14;
			counter += 2;

		}
		if (strcmp(token, "PUSH") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 15;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);

		}
		if (strcmp(token, "POP") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 16;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);

		}
		if (strcmp(token, "DUMP") == 0) {
			// Nenhum operando.
			printf("%s\n",token);
			opcode = 17;
			counter += 2;

		}
		if (strcmp(token, "READ") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 18;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);

		}
		if (strcmp(token, "WRITE") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 19;
			counter += 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\n");
			op1 = checaOperando(token);

		}
		if (strcmp(token, "HLT") == 0) {
			// Nenhum operando.
			printf("%s\n",token);
			opcode = 20;
			counter += 2;

		}
	}
}

// Verifica qual operando possui cada instrução e retorna o codigo do
static int checaOperando(char *op) {

	if(strcmp(op, "AL") == 0) {
		printf("Operando[0]: %s \n",op);
		return 0;
	}
	if(strcmp(op, "AH") == 0) {
		printf("Operando[1]: %s \n",op);
		return 1;
	}
	if(strcmp(op, "AX") == 0) {
		printf("Operando[2]: %s \n",op);
		return 2;
	}
	if(strcmp(op, "BH") == 0) {
		printf("Operando[3]: %s \n",op);
		return 3;
	}
	if(strcmp(op, "BL") == 0) {
		printf("Operando[4]: %s \n",op);
		return 4;
	}
	if(strcmp(op, "BX") == 0) {
		printf("Operando[5]: %s \n",op);
		return 5;
	}
	if(strcmp(op, "CL") == 0) {
		printf("Operando[6]: %s \n",op);
		return 6;
	}
	if(strcmp(op, "CH") == 0) {
		printf("Operando[7]: %s \n",op);
		return 7;
	}
	if(strcmp(op, "CX") == 0) {
		printf("Operando[8]: %s \n",op);
		return 8;
	}
	if(op[0] == '_') {
		printf("Operando label: %s \n",op);
		return 9;
	}
	if(op[0] == '0' && op[1] == 'x') {
		printf("Operando imediato: %s \n",op);
		return 10;
	}

	printf("ERRO: operando invalido!\n");
	return -1;
}