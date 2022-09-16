#ifndef ARVORE_H_
#define ARVORE_H_

typedef struct arvore Arvore;

#include "alunos.h"

Arvore *criaArvVazia(void);

Arvore *criaArvore(Aluno *aluno, Arvore *e, Arvore *d);

Arvore *liberaArvore(Arvore *arvore);

int arvoreVazia(Arvore *arvore);

int contemNaArvore(Arvore *arvore, Aluno *aluno);

void imprimeArvore(Arvore *arvore);

int altura(Arvore *arvore);

int folhas(Arvore *arvore);

int ocorrencias(Arvore *arvore, Aluno *aluno);

#endif