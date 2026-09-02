#ifndef ALUNO_H
#define ALUNO_H

#define ARQUIVO_ALUNOS "alunos.bin"

typedef struct {
    int id;
    char nome[50];
    int matricula;
    int falta;
    float p1, p2, media;
    char situacao[10];
} Alunos;

#endif
