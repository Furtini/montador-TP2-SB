// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 2
// Montador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "tradutor.h"
#include "tabelaSimbolo.h"

// TAD para funções da saida simples do montador.

static int counter;

// Função para execução do montador simples.
void primeiraPassagem(FILE *entrada,  TabelaSimbolo *tabela) {

	counter = 0;

	char *buffer = NULL;
	char *token;
	
	size_t tam = 0;

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

		}
		if (strcmp(token, "MOV") == 0) {
			counter += 3;
		}
		if (strcmp(token, "ADD") == 0) {
			counter += 3;
		}
		if (strcmp(token, "SUB") == 0) {
			counter += 3;
		}
		if (strcmp(token, "MUL") == 0) {
			counter += 2;
		}
		if (strcmp(token, "DIV") == 0) {
			counter += 2;
		}
		if (strcmp(token, "AND") == 0) {
			counter += 3;
		}
		if (strcmp(token, "NOT") == 0) {
			counter += 2;
		}
		if (strcmp(token, "OR") == 0) {
			counter += 3;
		}
		if (strcmp(token, "CMP") == 0) {
			counter += 3;
		}
		if (strcmp(token, "JMP") == 0) {
			counter += 2;
		}
		if (strcmp(token, "JZ") == 0) {
			counter += 2;
		}
		if (strcmp(token, "JS") == 0) {
			counter += 2;
		}
		if (strcmp(token, "CALL") == 0) {
			counter += 2;
		}
		if (strcmp(token, "RET") == 0) {
			counter += 1;
		}
		if (strcmp(token, "PUSH") == 0) {
			counter += 2;
		}
		if (strcmp(token, "POP") == 0) {
			counter += 2;
		}
		if (strcmp(token, "DUMP") == 0) {
			counter += 1;
		}
		if (strcmp(token, "READ") == 0) {
			counter += 2;
		}
		if (strcmp(token, "WRITE") == 0) {
			counter += 2;
		}
		if (strcmp(token, "HLT") == 0) {
			counter += 1;
		}
	}

	atualizaVariaveis(tabela, counter);
}

// Faz a segunda passagem no arquivo de entrada.
void segundaPassagem(FILE *entrada, FILE *saida,  TabelaSimbolo *tabela) {

	unsigned int temp;
	
	int8_t opcode, codigo; // Devem ser 1 byte cada.
	
	unsigned short ipInicial = 0;
	unsigned short op1, op2; 	   // Devem ser 2 byte cada.
	unsigned short aux1, aux2;

	char *buffer = NULL;
	char *token;

	size_t tam = 0;

	// Escreve inicio do IP.
	fwrite(&ipInicial, 2, 1, saida);

	// TODO:  buscar variavel na tabela de simbolo e atualizar seu endereço.


	// Leitura do arquivo de entrada.
	while(getline(&buffer, &tam, entrada) != -1) {
		
		// Quebrando buffer em palavras.
		token = strtok(buffer, " :\n\r");
		// Se primeiro nome for label
		if (token[0] == '_') {
			// Pula o label.
			token = strtok(NULL, " \n\r");	
		} 
		// Checa qual instrução.
		if (strcmp(token, "DW") == 0) {
			// Pula o label.
			token = strtok(NULL, " \n\r");
		}
		if (strcmp(token, "MOV") == 0) {
			opcode = 1;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando 1	 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				aux1 = buscaSimbolo(tabela, token);
			}
			
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op2 == 11) {
				aux2 = buscaSimbolo(tabela, token);
			}
			
			codigo = codigoDoisOperandos(op1, op2);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
				op2 = temp;
			}

			// Atualiza nome da variavel pelo endereço.
			if (op1 == 11) {
				op1 = aux1;
			}
			if (op2 == 11) {
				op2 = aux2;
			}

			// Escreve operandos na saida.
			fwrite(&op1, 2, 1, saida);
			fwrite(&op2, 2, 1, saida);
		}
		if (strcmp(token, "ADD") == 0) {
			opcode = 2;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Dois Operandos
			// Lendo operando 1	 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				aux1 = buscaSimbolo(tabela, token);
			}
			
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op2 == 11) {
				aux2 = buscaSimbolo(tabela, token);
			}
			
			codigo = codigoDoisOperandos(op1, op2);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
				op2 = temp;
			}

			// Atualiza nome da variavel pelo endereço.
			if (op1 == 11) {
				op1 = aux1;
			}
			if (op2 == 11) {
				op2 = aux2;
			}

			// Escreve operandos na saida.
			fwrite(&op1, 2, 1, saida);
			fwrite(&op2, 2, 1, saida);
		}
		if (strcmp(token, "SUB") == 0) {
			opcode = 3;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Dois Operandos
			// Lendo operando 1	 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				aux1 = buscaSimbolo(tabela, token);
			}
			
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op2 == 11) {
				aux2 = buscaSimbolo(tabela, token);
			}
			
			codigo = codigoDoisOperandos(op1, op2);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
				op2 = temp;
			}

			// Atualiza nome da variavel pelo endereço.
			if (op1 == 11) {
				op1 = aux1;
			}
			if (op2 == 11) {
				op2 = aux2;
			}

			// Escreve operandos na saida.
			fwrite(&op1, 2, 1, saida);
			fwrite(&op2, 2, 1, saida);
		}
		if (strcmp(token, "MUL") == 0) {
			opcode = 4;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "DIV") == 0) {
			opcode = 5;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "AND") == 0) {
			opcode = 6;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Dois Operandos
			// Lendo operando 1	 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				aux1 = buscaSimbolo(tabela, token);
			}
			
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op2 == 11) {
				aux2 = buscaSimbolo(tabela, token);
			}
			
			codigo = codigoDoisOperandos(op1, op2);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
				op2 = temp;
			}

			// Atualiza nome da variavel pelo endereço.
			if (op1 == 11) {
				op1 = aux1;
			}
			if (op2 == 11) {
				op2 = aux2;
			}

			// Escreve operandos na saida.
			fwrite(&op1, 2, 1, saida);
			fwrite(&op2, 2, 1, saida);
		}
		if (strcmp(token, "NOT") == 0) {
			// Um operando.
			printf("%s\n",token);
			opcode = 7;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "OR") == 0) {
			opcode = 8;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Dois Operandos
			// Lendo operando 1	 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				aux1 = buscaSimbolo(tabela, token);
			}
			
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op2 == 11) {
				aux2 = buscaSimbolo(tabela, token);
			}
			
			codigo = codigoDoisOperandos(op1, op2);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
				op2 = temp;
			}

			// Atualiza nome da variavel pelo endereço.
			if (op1 == 11) {
				op1 = aux1;
			}
			if (op2 == 11) {
				op2 = aux2;
			}

			// Escreve operandos na saida.
			fwrite(&op1, 2, 1, saida);
			fwrite(&op2, 2, 1, saida);
		}
		if (strcmp(token, "CMP") == 0) {
			opcode = 9;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Dois Operandos
			// Lendo operando 1	 da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				aux1 = buscaSimbolo(tabela, token);
			}
			
			// Lendo operando 2 da instrução.
			token = strtok(NULL, " ,\r\n");
			op2 = checaOperando(token);
			// Busca endereço do op1 caso seja simbolo.
			if (op2 == 11) {
				aux2 = buscaSimbolo(tabela, token);
			}
			
			codigo = codigoDoisOperandos(op1, op2);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Muda op2 para hexa caso imediato.
			if (op2 == 10) {
				sscanf(token, "%x", &temp);
				op2 = temp;
			}

			// Atualiza nome da variavel pelo endereço.
			if (op1 == 11) {
				op1 = aux1;
			}
			if (op2 == 11) {
				op2 = aux2;
			}

			// Escreve operandos na saida.
			fwrite(&op1, 2, 1, saida);
			fwrite(&op2, 2, 1, saida);
		}
		if (strcmp(token, "JMP") == 0) {
			opcode = 10;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			op1 = buscaSimbolo(tabela, token);
			
			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "JZ") == 0) {
			opcode = 11;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			op1 = buscaSimbolo(tabela, token);	

			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "JS") == 0) {
			opcode = 12;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			op1 = buscaSimbolo(tabela, token);
			
			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "CALL") == 0) {
			opcode = 13;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			op1 = buscaSimbolo(tabela, token);
			
			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "RET") == 0) {
			opcode = 14;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			codigo = 0;
			// Escreve opcode da instrução.
			fwrite(&codigo, 1, 1, saida);
		}
		if (strcmp(token, "PUSH") == 0) {
			opcode = 15;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "POP") == 0) {
			opcode = 16;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "DUMP") == 0) {
			opcode = 17;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			codigo = 0;
			// Escreve opcode da instrução.
			fwrite(&codigo, 1, 1, saida);
		}
		if (strcmp(token, "READ") == 0) {
			opcode = 18;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "WRITE") == 0) {
			opcode = 19;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			// Lendo operando da instrução.
			token = strtok(NULL, " ,\r\n");
			op1 = checaOperando(token);

			codigo = codigoUmOperando(op1);
			// Escreve codigo no arquivo.
			fwrite(&codigo, 1, 1, saida);

			// Busca endereço do op1 caso seja simbolo.
			if (op1 == 11) {
				op1 = buscaSimbolo(tabela, token);
			}

			// Escreve operando no arquivo.
			fwrite(&op1, 2, 1, saida);
		}
		if (strcmp(token, "HLT") == 0) {
			opcode = 20;
			// Escreve opcode da instrução.
			fwrite(&opcode, 1, 1, saida);

			codigo = 0;
			// Escreve opcode da instrução.
			fwrite(&codigo, 1, 1, saida);
		}
	}
}

// Verifica qual operando possui cada instrução e retorna o codigo do
static short checaOperando(char *op) {

	if(strcmp(op, "AL") == 0) {
		return 0;
	} else 
	if(strcmp(op, "AH") == 0) {
		return 1;
	} else
	if(strcmp(op, "AX") == 0) {
		return 2;
	} else
	if(strcmp(op, "BH") == 0) {
		return 3;
	} else
	if(strcmp(op, "BL") == 0) {
		return 4;
	} else
	if(strcmp(op, "BX") == 0) {
		return 5;
	} else
	if(strcmp(op, "CL") == 0) {
		return 6;
	} else
	if(strcmp(op, "CH") == 0) {
		return 7;
	} else
	if(strcmp(op, "CX") == 0) {
		return 8;
	} else
	// Label
	if(op[0] == '_') {
		return 9;
	} else
	// Imediato!
	if(op[0] == '0' && op[1] == 'x') {
		return 10;
	} else {
		// Nome de uma variavel
		return 11;
	}
}

// Retorna qual o codigo quando isntrução usa 1 operando.
static short codigoUmOperando(unsigned short op1) {

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
static short codigoDoisOperandos(unsigned short op1, unsigned short op2) {
	
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
	// Se forem 9 é um label (tipo2 = 1);
	// Se forem 10 é um imediato (tipo2 = 2).
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
		return 3;
	}
	// Memoria e registrador.
	if (tipo1 == 1 && tipo2 == 0) {
		return 4;
	}
	//Registrador e registrador.
	if (tipo1 == 0 && tipo2 == 0) {
		return 5;
	}
	//Memoria e imediato.
	if (tipo1 == 1 && tipo2 == 2) {
		return 6;
	}
	// Registrador e imediato.
	if (tipo1 == 0 && tipo2 == 2) {
		return 7;
	}
}