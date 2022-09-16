#ifndef ALUNOS_H_
#define ALUNOS_H_

typedef struct aluno Aluno;

Aluno *preencheAluno(char *nome, int matricula, float n1, float n2, float n3);

char *retornaNome(Aluno *aluno);

void calculaMedia(Aluno *aluno);

void imprimeAluno(Aluno* aluno);

void destroiAluno(Aluno *aluno);

#endif