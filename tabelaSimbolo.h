// Universidade Federal de Minas Gerais
// Software Basico - Trabalho Pratico 2
// Montador
// Lucas Furtini Veado - 2013007609
// Edson Roteia Araujo Junior - 2014004174

// TAD para representação da tabela de simbolos. 

#ifndef TABELASIMBOLO_H_
#define TABELASIMBOLO_H_

// ------- ESTRUTURAS --------------------------

typedef struct Simbolo *pSimbolo;

// Tabela de simbolos.
typedef struct Simbolo {

	char nome[15];
	short ilc;

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
short buscaSimbolo(TabelaSimbolo *, char *nome);

// Atualiza o ilc das variaveis na tabela de simbolo para o endereço delas.
void atualizaVariaveis(TabelaSimbolo *, short counter);

// Libera tabela de simbolos da memoria.
void liberaTabela(TabelaSimbolo *);

// Imprime tabela de simbolo.
void imprimeTabela(TabelaSimbolo *);

#endif // TABELASIMBOLO_H_