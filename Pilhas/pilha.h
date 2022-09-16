/*Lara Tagarro Bernardes*/
#ifndef PILHA_H_
#define PILHA_H_

typedef struct pilha Pilha;
typedef struct pilhaDupla PilhaDupla;

PilhaDupla *inicializaPilhaDupla(void);

void pushPilha1(PilhaDupla *pDupla, int num);

void pushPilha2(PilhaDupla *pDupla, int num);

int *popPilha1(PilhaDupla *pDupla);

int *popPilha2(PilhaDupla *pDupla);

void imprimePilha(PilhaDupla *pDupla);

void destroiPilha(PilhaDupla *pDupla);



#endif