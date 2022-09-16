/*Lara Tagarro Bernardes*/
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "alunos.h"

#define TAM 100

struct fila{
    int ini;
    int n;
    Aluno *alunos[TAM];
};

Fila *inicializaFila(void){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->ini = 0;
    fila->n = 0;
    return fila;
}

void insereFila(Fila *fila, Aluno *aluno){
    int i;

    if(fila == NULL){
        printf("Fila nao existe\n");
        return;
    }
    if(fila->n >= TAM){
        printf("Fila cheia\n");
        return;
    }

    i = (fila->ini + fila->n % TAM);
    fila->alunos[i] = aluno;
    fila->n++;
}

Aluno *retiraFila(Fila *fila){
    Aluno *aluno;
    
    if(fila == NULL){
        printf("Fila nao existe\n");
        exit (1);
    }
    if(fila->n == 0){
        printf("Fila cheia\n");
        exit (1);
    }
    aluno = fila->alunos[fila->ini];
    fila->ini = (fila->ini + 1) % TAM;
    fila->n--;
    return aluno;
}

void imprimeFila(Fila *fila){
    int i, j;

    if(fila == NULL){
        printf("Fila nao existe\n");
        exit (1);
    }

    for(i = 0; i < fila->n; i++){
        j = (fila->ini + i) % TAM;
        imprimeAluno(fila->alunos[j]);
    }
}

void destroiFila(Fila *fila){
    if(fila == NULL){
        printf("Fila nao existe\n");
        exit (1);
    }
    for(int i = 0; i <= fila->n; i++){
        destroiAluno(fila->alunos[i]);
    }
    free(fila);
}
