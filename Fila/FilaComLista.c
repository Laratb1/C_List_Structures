/*Lara Tagarro Bernardes*/
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "listaAluno.h"
#include "alunos.h"

#define TAM 100

struct fila{
    ListaAluno *lista;
};

typedef struct fila Fila;
typedef struct celula Celula;

Fila *inicializaFila(void){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->lista = inicializaLisAluno();
    return fila;
}

void insereFila(Fila *fila, Aluno *aluno){
    insereListaUlt(fila->lista, aluno);
}

Aluno *retiraFila(Fila *fila){
    return retiraAlunoList(fila->lista, 0);
}

void imprimeFila(Fila *fila){
    imprimeLista(fila->lista);
}

void destroiFila(Fila *fila){
    destroiLista(fila->lista);
    free(fila);
}