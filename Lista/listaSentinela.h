/*Lara Tagarro Bernardes*/
#ifndef LISTALUNO_H_
#define LISTALUNO_H_

typedef struct listaAluno ListaAluno;
typedef struct celula Celula;

#include "alunos.h"

ListaAluno *inicializaLisAluno();

void insereAlunoList(ListaAluno *lista, Aluno *aluno);

void insereListaUlt(ListaAluno *lista, Aluno *aluno);

Aluno *retiraAlunoList(ListaAluno *lista, int posicao);

void imprimeLista(ListaAluno *lista);   

void destroiLista(ListaAluno *lista);

#endif
