/*Lara Tagarro Bernardes*/
#ifndef FILA_H_
#define FILA_H_

#include "listaAluno.h"
#include "alunos.h"

typedef struct fila Fila;

Fila *inicializaFila(void);

void insereFila(Fila *fila, Aluno *aluno);

void insereListaUlt(ListaAluno *lista, Aluno *aluno);

Aluno *retiraFila(Fila *fila);

void imprimeFila(Fila *fila);

void destroiFila(Fila *fila);

#endif