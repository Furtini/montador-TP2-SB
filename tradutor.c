#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tradutor.h"
#include "tabelaSimbolo.h"

// TAD para funções da saida simples do montador.

// Cria tabela de simbolos vazia GLOBAL.
TabelaSimbolo *tabela;

// Função para execução do montador simples.
void primeiraPassagem(FILE *entrada) {

	int counter = 0;

	char *buffer = NULL;
	char *token;
	
	size_t tam = 0;

	tabela = aloca(sizeof(TabelaSimbolo));
	fazTabelaSimboloVazia(tabela);

	// Leitura do arquivo de entrada.
	while(getline(&buffer, &tam, entrada) != -1) {

		// Quebrando buffer em palavras.
		token = strtok(buffer, " :\r");
		// Se primeiro nome for label
		if (token[0] == '_') {

			// Adiciona na lista junto com o contador.
			adicionaSimbolo(tabela, token, counter);

			token = strtok(NULL, " \r");	
		} 
		// Checa qual instrução.
		if (strcmp(token, "DW") == 0) {
			printf("%s\n",token);

			// Busca variavel e adiciona na tabela de simbolo.
			token = strtok(NULL, " \r\n");	
			adicionaSimbolo(tabela, token, counter);

			// Tamanho 4: 2 bytes nome, 2 bytes variavel.
			counter += 4;
		}
		if (strcmp(token, "MOV") == 0) {
			counter += 6;
		}
		if (strcmp(token, "ADD") == 0) {
			counter += 6;
		}
		if (strcmp(token, "SUB") == 0) {
			counter += 6;
		}
		if (strcmp(token, "MUL") == 0) {
			counter += 4;
		}
		if (strcmp(token, "DIV") == 0) {
			counter += 4;
		}
		if (strcmp(token, "AND") == 0) {
			counter += 6;
		}
		if (strcmp(token, "NOT") == 0) {
			counter += 4;
		}
		if (strcmp(token, "OR") == 0) {
			counter += 6;
		}
		if (strcmp(token, "CMP") == 0) {
			counter += 6;
		}
		if (strcmp(token, "JMP") == 0) {
			counter += 4;
		}
		if (strcmp(token, "JZ") == 0) {
			counter += 4;
		}
		if (strcmp(token, "JS") == 0) {
			counter += 4;
		}
		if (strcmp(token, "CALL") == 0) {
			counter += 4;
		}
		if (strcmp(token, "RET") == 0) {
			counter += 2;
		}
		if (strcmp(token, "PUSH") == 0) {
			counter += 4;
		}
		if (strcmp(token, "POP") == 0) {
			counter += 4;
		}
		if (strcmp(token, "DUMP") == 0) {
			counter += 2;
		}
		if (strcmp(token, "READ") == 0) {
			counter += 4;
		}
		if (strcmp(token, "WRITE") == 0) {
			counter += 4;
		}
		if (strcmp(token, "HLT") == 0) {
			counter += 2;
		}
	}
	printf("-------------------------------\n");
	printf("Contador: %d\n",counter );
	imprimeTabela(tabela);
	printf("-------------------------------\n");
}

// Faz a segunda passagem no arquivo de entrada.
void segundaPassagem(FILE *entrada, FILE *saida) {

	unsigned int temp;
	
	unsigned short opcode, codigo; // Devem ser 1 byte cada.
	unsigned short op1, op2; 	   // Devem ser 1 byte cada.

	char *buffer = NULL;
	char *token;

	size_t tam = 0;

	// Leitura do arquivo de entrada.
	while(getline(&buffer, &tam, entrada) != -1) {
		
		// Quebrando buffer em palavras.
		token = strtok(buffer, " :\n\r");
		// Se primeiro nome for label
		if (token[0] == '_') {
			
			printf("Label: %s ->",token);
			// Pula o label.
			token = strtok(NULL, " \n\r");	
		} 
		// Checa qual instrução.
		if (strcmp(token, "DW") == 0) {
			printf("%s\n",token);

			// Pula o label.
			token = strtok(NULL, " \n\r");
		}
		if (strcmp(token, "MOV") == 0) {
			printf("%s\n",token);
			opcode = 1;
			// Dois Operandos
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);

			codigo = codigoDoisOperandos(op1, op2);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
			}
			op2 = temp;

			printf("Operando 1: %d \n", op1);
			printf("Operando 2: %d \n", op2);
		}
		if (strcmp(token, "ADD") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 2;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);

			codigo = codigoDoisOperandos(op1, op2);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
			}
			op2 = temp;

			printf("Operando 1: %d \n", op1);
			printf("Operando 2: %d \n", op2);

		}
		if (strcmp(token, "SUB") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 3;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);

			codigo = codigoDoisOperandos(op1, op2);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
			}
			op2 = temp;

			printf("Operando 1: %d \n", op1);
			printf("Operando 2: %d \n", op2);

		}
		if (strcmp(token, "MUL") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			printf("Operando 1: %d \n", op1);

			 codigo = codigoUmOperando(op1);

		}
		if (strcmp(token, "DIV") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 4;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "AND") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 6;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);

			codigo = codigoDoisOperandos(op1, op2);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
			}
			op2 = temp;

			printf("Operando 1: %d \n", op1);
			printf("Operando 2: %d \n", op2);

		}
		if (strcmp(token, "NOT") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 7;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "OR") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 8;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);

			codigo = codigoDoisOperandos(op1, op2);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
			}
			op2 = temp;

			printf("Operando 1: %d \n", op1);
			printf("Operando 2: %d \n", op2);

		}
		if (strcmp(token, "CMP") == 0) {
			// Dois operandos.
			printf("%s\n",token);
			opcode = 9;
			// Lendo operando 1 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);

			codigo = codigoDoisOperandos(op1, op2);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
			}
			op2 = temp;

			printf("Operando 1: %d \n", op1);
			printf("Operando 2: %d \n", op2);

		}
		if (strcmp(token, "JMP") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 10;
			// Lendo operando da instrução.
			token = strtok(NULL, " \r\n");
			op1 = checaOperando(token);
			// Busca ILC do label.
			if (op1 == 9) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Operando sempre memoria.
			codigo = 2;

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "JZ") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 11;
			// Lendo operando da instrução.
			token = strtok(NULL, " ;\r\n");
			op1 = checaOperando(token);
			// Busca ILC do label.
			if (op1 == 9) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Operando sempre memoria.
			codigo = 2;

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "JS") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 12;
			// Lendo operando da instrução.
			token = strtok(NULL, " ;\r\n");
			op1 = checaOperando(token);
			// Busca ILC do label.
			if (op1 == 9) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Operando sempre memoria.
			codigo = 2;

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "CALL") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 13;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			// Operando sempre memoria.
			codigo = 2;

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "RET") == 0) {
			// Nenhum operando.
			printf("%s\n",token);
			opcode = 14;

		}
		if (strcmp(token, "PUSH") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 15;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			// Confere qual o operando.
			op1 = checaOperando(token);

			// Retorna codigo do operando.
			codigo = codigoUmOperando(op1);

			// Significa op1 imediato.
			if (op1 == 10) {
				// Converte string de hexa para int.
				sscanf(token, "%x", &temp);
			}
			op1 = temp;

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "POP") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 16;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "DUMP") == 0) {
			// Nenhum operando.
			printf("%s\n",token);
			opcode = 17;

		}
		if (strcmp(token, "READ") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 18;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "WRITE") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 19;
			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);

			printf("Operando 1: %d \n", op1);

		}
		if (strcmp(token, "HLT") == 0) {
			// Nenhum operando.
			printf("%s\n",token);
			opcode = 20;

		}
	}
}

// Verifica qual operando possui cada instrução e retorna o codigo do
static short checaOperando(char *op) {

	if(strcmp(op, "AL") == 0) {
		printf("Operando[0]: %s \n",op);
		return 0;
	} else 
	if(strcmp(op, "AH") == 0) {
		printf("Operando[1]: %s \n",op);
		return 1;
	} else
	if(strcmp(op, "AX") == 0) {
		printf("Operando[2]: %s \n",op);
		return 2;
	} else
	if(strcmp(op, "BH") == 0) {
		printf("Operando[3]: %s \n",op);
		return 3;
	} else
	if(strcmp(op, "BL") == 0) {
		printf("Operando[4]: %s \n",op);
		return 4;
	} else
	if(strcmp(op, "BX") == 0) {
		printf("Operando[5]: %s \n",op);
		return 5;
	} else
	if(strcmp(op, "CL") == 0) {
		printf("Operando[6]: %s \n",op);
		return 6;
	} else
	if(strcmp(op, "CH") == 0) {
		printf("Operando[7]: %s \n",op);
		return 7;
	} else
	if(strcmp(op, "CX") == 0) {
		printf("Operando[8]: %s \n",op);
		return 8;
	} else
	if(op[0] == '_') {
		printf("Operando label: %s \n",op);
		return 9;
	} else
	if(op[0] == '0' && op[1] == 'x') {
		printf("Operando imediato: %s \n",op);
		return 10;
	} else {
		printf("Variavel declarada: %s \n",op);
		return 11;
	}

	//printf("ERRO: operando invalido!\n");
	//return -1;
}

// Retorna qual o codigo quando isntrução usa 1 operando.
static short codigoUmOperando(short op1) {

	switch (op1) {
		// Regs
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			return 1;
			break;
		// Memoria.
		case 9:
			return 2;
			break;
		// Imediato.
		case 10:
			return 8;
			break;
		default:
			printf("ERRO: codigo operando errado!\n");
			break;
	}
}

// Retorna qual o codigo quando instrução usa 2 operandos.
static short codigoDoisOperandos(short op1, short op2) {
	
	short  tipo1, tipo2;

	// Se operando 1 entre 0-8 é um registrador (tipo1 = 0).
	// Se forem 9 é um label (tipo1 = 1);
	// Se forem 10 é um imediato (tipo1 = 2).
	switch (op1) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			tipo1 = 0;
			break;
		case 9:
			tipo1 = 1;
			break;
		case 10:
			tipo1 = 2;
			break;
		default:
			printf("ERRO: codigo operando errado!\n");
			break;
	}
	// Se operando 2 entre 0-8 é um registrador (tipo2 = 0).
	// Se forem 9 é um label (tipo2 = 0);
	// Se forem 10 é um imediato (tipo2 = 0).
	switch (op2) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			tipo2 = 0;
			break;
		case 9:
			tipo2 = 1;
			break;
		case 10:
			tipo2 = 2;
			break;
		default:
			printf("ERRO: codigo operando errado!\n");
			break;
	}

	// Encontra o codigo do par de operandos.
	
	// Registrador e memoria
	if (tipo1 == 0 && tipo2 == 1) {
		printf("Registrador e memoria!\n");
		return 3;
	}
	// Memoria e registrador.
	if (tipo1 == 1 && tipo2 == 0) {
		printf("Memoria e registrador!\n");
		return 4;
	}
	//Registrador e registrador.
	if (tipo1 == 0 && tipo2 == 0) {
		printf("Registrador e registrador!\n");
		return 5;
	}
	//Memoria e imediato.
	if (tipo1 == 1 && tipo2 == 2) {
		printf("Memoria e imediato!\n");
		return 6;
	}
	// Registrador e imediato.
	if (tipo1 == 0 && tipo2 == 2) {
		printf("Registrador e imediato!\n");
		return 7;
	}
}