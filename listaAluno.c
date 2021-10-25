/*Lara Tagarro Bernardes*/

#ifndef ALUNO_H_
#define ALUNO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAluno.h"
#include "alunos.h"

typedef struct listaAluno ListaAluno;

struct listaAluno{
    Aluno *aluno;
    ListaAluno *prox;
    ListaAluno *ant;
};

ListaAluno *inicializaLisAluno(){
    return NULL;
}

ListaAluno *insereAlunoList(ListaAluno *lista, Aluno *aluno){
    ListaAluno *novoAluno = (ListaAluno*) malloc(sizeof(ListaAluno));
    novoAluno->aluno = aluno;
    novoAluno->ant = NULL;
    novoAluno->prox = lista;
    if(lista != NULL){
        lista->ant = novoAluno;
    }
    return novoAluno;
}

ListaAluno *busca(ListaAluno *lista, char *nome){
    ListaAluno *p;
    for(p = lista; p != NULL; p = p->prox){
        if(strcmp(retornaNome(p->aluno), nome) == 0){
            return p;
        }
    }
    return NULL;
}

ListaAluno *retiraAlunoList(ListaAluno *lista, char * nome){
    ListaAluno *p = busca(lista, nome);
    if(p == NULL){
        return NULL;
    }
    if(p->ant != NULL){
        p->ant->prox = p->prox;
    }
    else{
        lista = p->prox;
        lista->ant = NULL;
    }

    if(p->prox != NULL){
        p->prox->ant = p->ant;
    }
    else{
        p->ant->prox = NULL;
    }
    free(p);

    return lista;
}

void imprimeLista(ListaAluno *lista){
    ListaAluno *p;
    for(p = lista; p != NULL; p = p->prox){
        imprimeAluno(p->aluno);
    }
}

void destroiLista(ListaAluno *lista){
    ListaAluno *p = lista;
    ListaAluno *t;

    while (p != NULL){
        t = p->prox;
        destroiAluno(p->aluno);
        free(p);
        p = t;
    } 
}
#endif