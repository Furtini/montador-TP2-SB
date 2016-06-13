// TAD para representação da tabela de simbolos. 

#ifndef TABELASIMBOLO_H_
#define TABELASIMBOLO_H_

// ------- ESTRUTURAS --------------------------

typedef struct Simbolo *pSimbolo;

// Tabela de simbolos.
typedef struct Simbolo {

	char nome[15];
	int ilc;

	pSimbolo prox;

} TSimbolo;

typedef struct listaSimbolo {
	
	pSimbolo primeiro, ultimo;

} TabelaSimbolo;


// -------- FUNCOES --------------------------------
// Função para alocação de memoria de tamanha generico.
void *aloca(size_t tam);

// Inicializa tabela de simbolo vazia.
void fazTabelaSimboloVazia(TabelaSimbolo *);

// Checa tabela vazia.
int testaVazia(TabelaSimbolo ts);

// Adiciona simbolo no final da lista.
void adicionaSimbolo(TabelaSimbolo *, char *nome, int ilc);

// Busca por simbolo na tabela e retorna seu ILC.
int buscaSimbolo(TabelaSimbolo *, char *nome);

// Imprime tabela de simbolo.
void imprimeTabela(TabelaSimbolo *);

#endif // TABELASIMBOLO_H_