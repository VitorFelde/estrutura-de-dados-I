/*Exercícios de Registros e Manipulação de Arquivos.

1. Implemente um programa para tratar e armazenar as notas dos alunos de uma turma de uma disciplina.

- A turma pode ter até 40 alunos.

- Para cada aluno, é preciso armazenar:

a) Nome (até 40 caracteres)

b) Matrícula (inteiro)

c) Notas:

- Prova 1 (real)

- Prova 2 (real)

- Média (real, calculada pelo programa)

d) Faltas (inteiro)

e) Situação (aprovado (se média >=6 e faltas <= 20) ou reprovado (se média < 6 ou faltas > 20))

O programa deve oferecer as seguintes opções ao usuário:

1. Inserir alunos. Função que lê os dados do aluno (nome, matrícula, notas e faltas), calcula a média e a situação, e mantém armazenados no vetor da turma.

2. Exibir alunos. Função que imprime na tela os dados de todos os alunos da turma.

3. Salvar dados. Função que grava em arquivo os dados dos alunos.

4. Carrega dados. Função que lê o arquivo de dados dos alunos e armazena em memória, na estrutura de alunos.

5. Sair do programa.


Postar arquivo com o código fonte em C.*/

#include <stdio.h>

	typedef struct {

	char nome[50];
	int falta, matricula;
	char situacao[10];
	float p1, p2, media;

}Alunos;


void cadastrar(Alunos lista_turma[], int numerodealunos) {
    for (int i = 0; i < numerodealunos; i++) {
        while (getchar() != '\n'); //limpezinha de buffer lendária
        
        printf ("Digite o nome do funcionário: ");
        fgets(inserir[i].nome, sizeof(inserir[i].nome), stdin);    
        inserir[i].nome[strcspn(inserir[i].nome, "\n")] = '\0';
        printf ("Digite o número de matricula: ");
        scanf ("%d", &inserir[i].matricula);
        printf ("Digite a quantidade de faltas: ");
        scanf ("%f", &inserir[i].falta);
        printf ("Digite a primeira nota: ");
        scanf ("%d", &inserir[i].p1);
        printf ("Digite a segundo nota: ");
        scanf ("%d", &inserir[i].p2);
        while (getchar() != '\n');
	

int main (){
	
	}
