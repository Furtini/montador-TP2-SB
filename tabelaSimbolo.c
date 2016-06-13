#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	strcpy(ts->ultimo->nome, nome);
	ts->ultimo->ilc = ilc;
	ts->ultimo->prox = NULL;

} // Fim adicionaSimbolo.


// Busca por simbolo na tabela e retorna seu ILC.
int buscaSimbolo(TabelaSimbolo *ts, char *nome) {

	pSimbolo aux;

	aux = ts->primeiro->prox;
	while (aux != NULL) {

		if (strcmp(nome, aux->nome) == 0) {
			
			printf("ILC achado -> %d \n",aux->ilc);
			return aux->ilc;
		} else {
			aux = aux->prox;
		}
	}
	// Caso não encontre simbolo retorno -1
	printf("ERRO: simbolo nao encontrado!\n");
	return -1;
}

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