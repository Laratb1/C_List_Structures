#ifndef HASH_H_
#define HASH_H_

typedef struct hash Hash;

Hash *inicializaHash(int tamanho);

Palavra *acessaPalavra(Hash *tabela, char *palavra);

void imprimeHash(Hash *tabela);

void liberaHash(Hash *tabela);

#endif