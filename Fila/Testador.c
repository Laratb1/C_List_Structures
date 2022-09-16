/*Lara Tagarro Bernardes*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#include "Fila.h"

int main(){
    Aluno *aluno1, *aluno2, *aluno3, *aluno4, *aluno5, *alunoRetirado;
    Fila *fila;
    char *nome1 = "Maria";
    char *nome2 = "Joao";
    char *nome3 = "Laura";
    char *nome4 = "Pedro";
    char *nome5 = "Jasmim";
    
    aluno1 = preencheAluno(nome1, 123, 5.4, 8, 7.9);
    aluno2 = preencheAluno(nome2, 456, 5.8, 8.5, 9);
    aluno3 = preencheAluno(nome3, 789, 7.8, 8, 9);
    aluno4 = preencheAluno(nome4, 101, 3.5, 6.9, 10); 
    aluno5 = preencheAluno(nome5, 202, 5.6, 10, 9.0);
    
    fila = inicializaFila();
    
    insereFila(fila, aluno1);
    insereFila(fila, aluno2);
    insereFila(fila, aluno3);
    insereFila(fila, aluno4);
    
    printf("Fila completa:\n");
    imprimeFila(fila);

    printf("\nRetira primeiro da fila:\n");
    alunoRetirado = retiraFila(fila);
    imprimeFila(fila);

    printf("\nInsere no aluno na ultima posicao da fila:\n");
    insereFila(fila, aluno5);
    imprimeFila(fila);

    destroiFila(fila);

    return 0;
}