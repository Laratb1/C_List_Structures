#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"
#include "hash.h"

struct hash{
    Palavra **vetor;
    int tamanho;
};

static int hash(char *string, int tamanho){
    int total = 0;
    for(int i = 0; string[i] != '\0'; i++)
        total += string[i];
    return total % tamanho;
}

Hash *inicializaHash(int tamanho){
    Hash *hash = (Hash*) malloc(sizeof(Hash));
    hash->tamanho = tamanho;
    hash->vetor = (Palavra**) malloc(tamanho * sizeof(Palavra*));
    for(int i = 0; i < tamanho; i++)
        hash->vetor[i] = NULL;
    return hash;
}

Palavra *acessaPalavra(Hash *tabela, char *palavra){
    Palavra *p;

    int i = hash(palavra, tabela->tamanho);
    p = buscaPalavra(tabela->vetor[i], palavra);

    if(p)
        return p;

    p = inicializaPalavra(palavra);
    tabela->vetor[i] = inserePalavraNaLista(tabela->vetor[i], p);

    return p;

}

void imprimeHash(Hash *tabela){
    for(int i = 0; i < tabela->tamanho; i++){
        printf("Posicao %d: \n", i);
        imprimeLista(tabela->vetor[i]);
    }
}

void liberaHash(Hash *tabela){
    for(int i = 0; i < tabela->tamanho; i++)
        liberaListaPalavra(tabela->vetor[i]);
    free(tabela->vetor);
    free(tabela);
}