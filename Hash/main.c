#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"
#include "hash.h"

#define QUANTPALAVRAS 50
#define TAMTABELA 100

int main(int argc, char **argv){
    char *s;
    int i = 0;
    char string[10000];
    Palavra *p;
   
    if(argc != 2){
        printf("Erro!\n");
        return 0;
    }
    FILE *fp = fopen(argv[1], "rt");
    
    if(fp == NULL){
        printf("Erro no arquivo!\n");
        return 0;
    }

    Hash *tabela = inicializaHash(TAMTABELA);

    while(!feof(fp)){
        fscanf(fp, "%s", string);
        if(feof(fp))
            break;
        p = acessaPalavra(tabela, string);
        atualizaOcorrencias(p);
    }

    imprimeHash(tabela);

    //ultima palavra do arquivo 
    printf("Quantas vezes aparece a palavra teste: %d\n", retornaOcorrencias(p));

    liberaHash(tabela);
    fclose(fp);

    return 0;
}