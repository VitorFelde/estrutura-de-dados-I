#ifndef ALUNO_H
#define ALUNO_H
/*isso é uma verificação para segurança para que esse aluno.h não
possa ser incluido 2 vezes sem querer em um dos outros arquivos*/
typedef struct {
    int id;
    char nome[50];
    int matricula;
    int falta;
    float p1, p2, media;
    char situacao[10];
} Alunos;

#endif //fim da verificação fera demais 
