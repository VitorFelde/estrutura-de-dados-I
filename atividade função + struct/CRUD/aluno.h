#ifndef ALUNO_H
#define ALUNO_H

//esses dois comandos servem como segurança para evitar que algum dos outros arquivos abra esse aluno.h duas vezes

typedef struct {
    int id;
    char nome[50];
    int matricula;
    int falta;
    float p1, p2, media;
    char situacao[10];
} Alunos;

#endif
//fechando a verificação fera demais 
