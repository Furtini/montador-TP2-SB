// TAD para funções da saida simples do montador.

// Faz a primeira passagem no arquivo de entrada.
void primeiraPassagem(FILE *entrada);

// Faz a segunda passagem no arquivo de entrada.
void segundaPassagem(FILE *entrada, FILE *saida);

// Verifica qual operando possui cada instrução e retorna o codigo do operando
static short checaOperando(char *op);

// Retorna qual o codigo quando isntrução usa 1 operando.
static short codigoUmOperando(short op1);

// Retorna qual o codigo quando instrução usa 2 operandos.
static short codigoDoisOperandos(short op1, short op2);
