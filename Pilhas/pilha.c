/*Lara Tagarro Bernardes*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define TAM 100

typedef struct pilha{
    int topo;
    int base;
}Pilha;

 typedef struct pilhaDupla{      
    int *item[TAM];
    Pilha pilha1; 
    Pilha pilha2;
}PilhaDupla;

PilhaDupla *inicializaPilhaDupla(void){
    PilhaDupla *pDupla = (PilhaDupla*) malloc(sizeof(PilhaDupla));
    for(int i = 0; i < TAM; i++){
        pDupla->item[i] = (int*) malloc(sizeof(int));
        *(pDupla->item[i]) = 0;
    }
    pDupla->pilha1.base = 0;
    pDupla->pilha1.topo = 1;
    pDupla->pilha2.base = TAM;
    pDupla->pilha2.topo = TAM - 1;

    return pDupla;
}

void pushPilha1(PilhaDupla *pDupla, int num){
    if(!pDupla || pDupla->pilha2.base > TAM){
        printf("Pilha cheia");
        return;
    }

    *(pDupla->item[pDupla->pilha1.topo]) = num;

    if(pDupla->pilha1.topo == pDupla->pilha2.topo){
        printf("Pilha cheia");
        return;
    }
    pDupla->pilha1.topo++;
}

void pushPilha2(PilhaDupla *pDupla, int num){
    if(!pDupla || pDupla->pilha2.base > TAM){
        printf("Pilha cheia");
        return;
    }

    *(pDupla->item[pDupla->pilha2.topo]) = num;

    if(pDupla->pilha1.topo == pDupla->pilha2.topo){
        printf("Pilha cheia");
        return;
    }
    pDupla->pilha2.topo--;
}

int *popPilha1(PilhaDupla *pDupla){
    if(!pDupla){
        printf("Pilha vazia!");
        return NULL;
    }
    int *n = pDupla->item[pDupla->pilha1.topo - 1];
    pDupla->pilha1.topo--;

    return n;
}

int *popPilha2(PilhaDupla *pDupla){
    if(!pDupla){
        printf("Pilha vazia!");
        return NULL;
    }
    int *n = pDupla->item[pDupla->pilha2.topo + 1];
    pDupla->pilha2.topo++;

    return n;
}

void imprimePilha(PilhaDupla *pDupla){
    if(!pDupla){
        printf("Pilha vazia!");
        return;
    }
    printf("Imprime pilha 1: \n");
    for(int i = pDupla->pilha1.topo - 1; i > 0; i--){
        printf("%d\n", *(pDupla->item[i]));
    }
    printf("Imprime pilha 2: \n");
    for(int i = pDupla->pilha2.topo + 1; i <= TAM - 1; i++){
        printf("%d\n", *(pDupla->item[i]));
    }
}

void destroiPilha(PilhaDupla *pDupla){
    if(!pDupla){
        printf("Pilha vazia!");
        return;
    }
    for(int i = 0; i < TAM; i++){
        free(pDupla->item[i]);
    }
    free(pDupla);
}