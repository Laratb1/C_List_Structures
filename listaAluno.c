/*Lara Tagarro Bernardes*/
#ifndef ALUNO_H_
#define ALUNO_H_

#include "alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAluno.h"

typedef struct celula Celula;

struct celula{
    Aluno *aluno;
    Celula *prox;
};

struct listaAluno{
    Celula *prim;
    Celula *ult;
};

typedef struct listaAluno ListaAluno;

ListaAluno *inicializaLisAluno(){
    ListaAluno* lista = (ListaAluno*) malloc(sizeof(ListaAluno));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void insereAlunoList(ListaAluno *lista, Aluno *aluno){
    Celula *novoAluno = (Celula*) malloc(sizeof(Celula));
    novoAluno->aluno = aluno;
    novoAluno->prox = lista->prim;
    lista->prim = novoAluno;
    if(lista->ult == NULL){
        lista->ult = novoAluno;
    }
}

void insereListaUlt(ListaAluno *lista, Aluno *aluno){
    Celula *novo = (Celula*) malloc(sizeof(Celula));
    novo->aluno = aluno;
    novo->prox = NULL;

    if(lista->ult == NULL){
        lista->prim = lista->ult = novo;
        return;
    }

    lista->ult->prox = novo;
    lista->ult = novo;
}

Aluno *retiraAlunoList(ListaAluno *lista, int posicao){
    Celula *ant = NULL;
    Celula *p = lista->prim;
    Aluno *aluno;
    
    for(int i = 0; i < posicao; i++){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        exit (1);
    }
    if(lista->prim == p && lista->ult == p){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    else if(lista->prim == p){
        lista->prim = p->prox;
    }
    else if(lista->ult == p){
        lista->ult = ant;
        lista->ult->prox = NULL;
    }
    else{
        ant->prox = p->prox;
    }
    aluno = p->aluno;
    destroiAluno(p->aluno);
    free(p);
    
    return aluno;
}

void imprimeLista(ListaAluno *lista){
    Celula* p;
    for(p = lista->prim; p != NULL; p = p->prox){
        imprimeAluno(p->aluno);
    }
}

void destroiLista(ListaAluno *lista){
    Celula* p = lista->prim;
    Celula* t;

    while(p != NULL){
        t = p->prox;
        destroiAluno(p->aluno);
        free(p);
        p = t;
    }
    free(lista); 
}
#endif