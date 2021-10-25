/*Lara Tagarro Bernardes*/
#ifndef LISTALUNO_H_
#define LISTALUNO_H_

#include "alunos.h"

typedef struct listaAluno ListaAluno;

ListaAluno *inicializaLisAluno();

ListaAluno *insereAlunoList(ListaAluno *lista, Aluno *aluno);

ListaAluno *busca(ListaAluno *lista, char *nome);

ListaAluno *retiraAlunoList(ListaAluno *lista, char * nome);

void imprimeLista(ListaAluno *lista);

void destroiLista(ListaAluno *lista);

#endif