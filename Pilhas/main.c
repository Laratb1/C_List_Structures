/*Lara Tagarro Bernardes*/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    PilhaDupla *pDupla;
    int *n1, *n2;

    pDupla = inicializaPilhaDupla();

    pushPilha1(pDupla, 1);
    pushPilha1(pDupla, 2);
    pushPilha1(pDupla, 3);
    pushPilha1(pDupla, 4);
    pushPilha1(pDupla, 5);
    pushPilha1(pDupla, 6);
    pushPilha1(pDupla, 7);
    pushPilha1(pDupla, 8);
    pushPilha1(pDupla, 9);
    pushPilha1(pDupla, 10);

    pushPilha2(pDupla, 11);
    pushPilha2(pDupla, 12);
    pushPilha2(pDupla, 13);
    pushPilha2(pDupla, 14);
    pushPilha2(pDupla, 15);
    pushPilha2(pDupla, 16);
    pushPilha2(pDupla, 17);
    pushPilha2(pDupla, 18);
    pushPilha2(pDupla, 19);
    pushPilha2(pDupla, 20);

    imprimePilha(pDupla);

    n1 = popPilha1(pDupla);
    n2 = popPilha2(pDupla);

    printf("\nValor retirado da pilha1: %d\n", *n1);
    printf("Valor retirado da pilha2: %d\n\n", *n2);

    imprimePilha(pDupla);

    destroiPilha(pDupla);

    return 0;
}