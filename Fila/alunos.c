/*Nome: Lara Tagaro Bernardes*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* nome;
    int matricula;
    float n1;
    float n2;
    float n3;
    float media;
}Aluno;

Aluno *preencheAluno(char *nome, int matricula, float n1, float n2, float n3){
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->nome = strdup(nome);
    aluno->matricula = matricula;
    aluno->n1 = n1;
    aluno->n2 = n2;
    aluno->n3 = n3;
    aluno->media = 0;
    return aluno;
}

void calculaMedia(Aluno *aluno){
    float media = (aluno->n1 + aluno->n2 + aluno->n3) / 3;
    aluno->media = media; 
}

char *retornaNome(Aluno *aluno){
    return aluno->nome;
}

void imprimeAluno(Aluno* aluno){
    printf("%s\n", aluno->nome);
}

void destroiAluno(Aluno *aluno){
    free(aluno->nome);
    free(aluno);
}