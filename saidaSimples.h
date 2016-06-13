// TAD para funções da saida simples do montador.

// Faz a primeira passagem no arquivo de entrada.
void primeiraPassagem(FILE *entrada);

// Faz a segunda passagem no arquivo de entrada.
void segundaPassagem(FILE *entrada, FILE *saida);

// Verifica qual operando possui cada instrução e retorna o codigo do eprando
static int checaOperando(char *op);