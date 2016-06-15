// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 2
// Montador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

#include "tabelaSimbolo.h"
// TAD para funções do tradutor do montador.

// Faz a primeira passagem no arquivo de entrada.
void primeiraPassagem(FILE *entrada, TabelaSimbolo *);

// Faz a segunda passagem no arquivo de entrada.
void segundaPassagem(FILE *entrada, FILE *saida,  TabelaSimbolo *);

// Verifica qual operando possui cada instrução e retorna o codigo do operando
static short checaOperando(char *op);

// Retorna qual o codigo quando isntrução usa 1 operando.
static short codigoUmOperando(unsigned short op1);

// Retorna qual o codigo quando instrução usa 2 operandos.
static short codigoDoisOperandos(unsigned short op1, unsigned short op2);
