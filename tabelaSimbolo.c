#include <stdio.h>
#include <stdlib.h>

#include "tabelaSimbolo.h"

// Função para alocação de memoria de tamanha generico.
void *aloca(size_t tam) {

	void *memoria = malloc(tam);

	// Testa alocacao valida.
	if (memoria == NULL){
		printf("ERRO: Falha ao alocar memoria!\n");
		exit(1);
	}

	return memoria;
} // Fim aloca

// Inicializa tabela de simbolo vazia.
void fazTabelaSimboloVazia(TabelaSimbolo *ts) {

	ts->primeiro = aloca(sizeof(TSimbolo));
	ts->ultimo = ts->primeiro;
	ts->primeiro->ilc = 0;
	ts->primeiro->prox = NULL;

} // Fim fazTabelaSimboloVazia.

// Checa tabela vazia.
int testaVazia(TabelaSimbolo ts) {

	return (ts.primeiro == ts.ultimo);

} // Fim testaVazia.

// Adiciona simbolo no final da lista.
void adicionaSimbolo(TabelaSimbolo *ts, char *nome, int ilc) {

	ts->ultimo->prox = aloca(sizeof(TSimbolo));
	ts->ultimo = ts->ultimo->prox;
	ts->ultimo->nome = nome;
	ts->ultimo->ilc = ilc;
	ts->ultimo->prox = NULL;

} // Fim adicionaSimbolo.

// Imprime tabela de simbolo.
void imprimeTabela(TabelaSimbolo *ts) {

	pSimbolo aux;

	aux = ts->primeiro->prox;

	printf("Tabela de Simbolos!\n\n");
	printf("Label: ILC\n");
	while (aux != NULL) {

		printf("%s: %d \n",aux->nome, aux->ilc);

		aux = aux->prox;
	}
} // Fim imprimeTabela.