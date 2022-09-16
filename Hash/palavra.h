#ifndef PALAVRA_H_
#define PALAVRA_H_

typedef struct palavra Palavra;

Palavra *inicializaPalavra (char *string);

char *retornaConteudo(Palavra *palavra);

void atualizaOcorrencias(Palavra *palavra);

int retornaOcorrencias(Palavra *palavra);

Palavra *buscaPalavra(Palavra *palavra, char *string);

Palavra *inserePalavraNaLista(Palavra *lista, Palavra *palavra);

void imprimeLista(Palavra *palavra);

void liberaListaPalavra(Palavra *palavra);

#endif 