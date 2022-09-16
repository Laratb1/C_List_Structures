/*Lara Tagarro Bernardes*/
#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"
#include "arvoreBin.h"

int main(){
    Aluno *aluno1, *aluno2, *aluno3, *aluno4, *aluno5, *aluno6;

    aluno1 = preencheAluno("Maria", 123, 5.4, 8, 7.9);
    aluno2 = preencheAluno("Joao", 456, 5.8, 8.5, 9);
    aluno3 = preencheAluno("Laura", 789, 7.8, 8, 9);
    aluno4 = preencheAluno("Pedro", 101, 3.5, 6.9, 10);
    aluno5 = preencheAluno("Lucas", 101, 3.5, 6.9, 10);

    Arvore *a = criaArvVazia();

    a = criaArvore(aluno1, 
                criaArvore(aluno2, 
                criaArvVazia(),
                criaArvore(aluno3, criaArvVazia(),
                criaArvVazia())
                ),
                criaArvore(aluno4,
                criaArvore(aluno2, criaArvVazia(),
                    criaArvVazia()),
                criaArvore(aluno5, criaArvVazia(), criaArvVazia())
            )
    );

    printf("Imprimindo a arvore...\n");
    imprimeArvore(a);

    printf("\n\nQuantas vezes aparece o aluno 2? %d\n", ocorrencias(a, aluno2));

    printf("Qual a altura da arvore? %d\n", altura(a));

    printf("Quantas folhas tem a arvore? %d\n", folhas(a));

    destroiAluno(aluno1);
    destroiAluno(aluno2);
    destroiAluno(aluno3);
    destroiAluno(aluno4);
    destroiAluno(aluno5);
    liberaArvore(a);
}