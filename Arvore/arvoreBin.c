#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreBin.h"

typedef struct arvore{
    Aluno *aluno;
    struct arvore *esq;
    struct arvore *dir;    
}Arvore;

Arvore *criaArvVazia(void){
    return NULL;
}

Arvore *criaArvore(Aluno *aluno, Arvore *e, Arvore *d){
    Arvore *arv = (Arvore*) malloc(sizeof(Arvore));
    arv->aluno = aluno;
    arv->esq = e;
    arv->dir = d;
    return arv;
}

Arvore *liberaArvore(Arvore *arvore){
    if(!arvoreVazia(arvore)){
        liberaArvore(arvore->esq);
        liberaArvore(arvore->dir);
        free(arvore);
    }
    return NULL;
}

int arvoreVazia(Arvore *arvore){
    return arvore == NULL;
}

int contemNaArvore(Arvore *arvore, Aluno *aluno){
    char *nome1 = retornaNome(aluno);
    
    if(arvoreVazia(arvore))
        return 0;
    else{
        return !(strcmp(retornaNome(arvore->aluno), nome1)) || contemNaArvore(arvore->esq, aluno) || contemNaArvore(arvore->dir, aluno);
    }
}

void imprimeArvore(Arvore *arvore){
    if(!arvoreVazia(arvore)){
        printf("%s ", retornaNome(arvore->aluno));
        imprimeArvore(arvore->esq);
        imprimeArvore(arvore->dir);
    }
}

static int max(int a, int b){
    return (a > b) ? a : b;
}

int altura(Arvore *arvore){
    if(arvoreVazia(arvore)){
        return -1;
    }
    else{
        return 1 + max(altura(arvore->esq), altura(arvore->dir));
    }
}

int folhas(Arvore *arvore){
    if(!arvoreVazia(arvore)){
        if(arvore->esq == NULL && arvore->dir == NULL){
            return folhas(arvore->esq) + folhas(arvore->dir) + 1;
        }
        else{
            return folhas(arvore->esq) + folhas(arvore->dir);
        }
    }
    else{
        return 0;
    }
}

int ocorrencias(Arvore *arvore, Aluno *aluno){
    char *nome1 = retornaNome(aluno);
    if(arvoreVazia(arvore)){
        return 0;
    }
    else{
        if(!(strcmp(retornaNome(arvore->aluno), nome1))){
            return ocorrencias(arvore->esq, aluno) + ocorrencias(arvore->dir, aluno) + 1;
        }
        else{
            return ocorrencias(arvore->esq, aluno) + ocorrencias(arvore->dir, aluno);
        }
    }
}