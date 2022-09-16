#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

struct palavra{
    char *string;
    int n;
    Palavra *prox;
};

Palavra *inicializaPalavra (char *string){
    Palavra *palavra = (Palavra*) malloc(sizeof(Palavra));
    palavra->string = strdup(string);
    palavra->n = 0;
    palavra->prox = NULL;
    return palavra;
}

char *retornaConteudo(Palavra *palavra){
    return palavra->string;
}

void atualizaOcorrencias(Palavra *palavra){
    palavra->n++;
}

int retornaOcorrencias(Palavra *palavra){
    return palavra->n;
}

Palavra *buscaPalavra(Palavra *palavra, char *string){
    Palavra *p;
    for(p = palavra; p != NULL; p = p->prox){
        if(strcmp(string, p->string) == 0)
            return p;
    }
    return NULL;
}

Palavra *inserePalavraNaLista(Palavra *lista, Palavra *palavra){
    palavra->prox = lista;
    return palavra;
}


void imprimeLista(Palavra *palavra){
    Palavra *p;
    for(p = palavra; p != NULL; p = p->prox){
        printf("\nPalavra: %s\nOcorrencias: %d\n\n", p->string, p->n);
    }
}

void liberaListaPalavra(Palavra *palavra){
    Palavra *p = palavra;
    Palavra *t;
    while(p != NULL){
        t = p->prox;
        free(p->string);
        free(p);
        p = t;
    }
}