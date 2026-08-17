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
#include <string.h>

	typedef struct {

	char nome[50];
	int falta, matricula;
	char situacao[10];
	float p1, p2, media;

}Alunos;


void inserir(Alunos lista_turma[], int numerodealunos) {
    for (int i = 0; i < numerodealunos; i++) {
        while (getchar() != '\n'); //limpezinha de buffer lendária
        
        printf ("Digite o nome do aluno: ");
        fgets(lista_turma[i].nome, sizeof(lista_turma[i].nome), stdin);    
       lista_turma[i].nome[strcspn(lista_turma[i].nome, "\n")] = '\0';
        printf ("Digite o número de matricula: ");
        scanf ("%d", &lista_turma[i].matricula);
        printf ("Digite a quantidade de faltas: ");
        scanf ("%d", &lista_turma[i].falta);
        printf ("Digite a primeira nota: ");
        scanf ("%f", &lista_turma[i].p1);
        printf ("Digite a segundo nota: ");
        scanf ("%f", &lista_turma[i].p2);
        while (getchar() != '\n');
        
    }	
}

void exibir(Alunos lista_turma[], int numerodealunos) {
    
    for (int i = 0; i < numerodealunos; i++) {
    
        printf ("\nNome do aluno do cadastro %d: %s ", i, lista_turma[i].nome);
        printf ("\nMatricula do aluno %d: %d", i, lista_turma[i].matricula);
        printf ("\nQuantidade de faltas do aluno %d: %d", i, lista_turma[i].falta);
        printf ("\nPrimeira nota do aluno %d: %f", i, lista_turma[i].p1);
        printf ("\nSegunda nota do aluno %d: %f", i, lista_turma[i].p2);
    }
    
}

void salvar (Alunos lista_turma[], int numerodealunos){
    
    FILE *arquivo = fopen("turma.txt", "w");
    
    if (arquivo == NULL) { //verificação de segurança, está no slide, se o arquivo for null, nao podera salvar infos
        printf("Erro ao criar o arquivo!\n");
        return;
    }
    
    for (int i = 0; i < numerodealunos; i++) {
        
        // Aqui dentro você usa o fprintf apontando para a variável 'arquivo'
        fprintf(arquivo, "%s\n", lista_turma[i].nome);
        fprintf(arquivo, "%d\n", lista_turma[i].matricula);
        fprintf(arquivo, "%d\n", lista_turma[i].falta);
        fprintf(arquivo, "%.2f\n", lista_turma[i].p1);
        fprintf(arquivo, "%.2f\n", lista_turma[i].p2);
        fprintf(arquivo, "%.2f\n", lista_turma[i].media);
        fprintf(arquivo, "%s\n", lista_turma[i].situacao);
        //aqui salvamos os valores dentro da variavel arquivo que criamos anteriormente
    }
    
    fclose(arquivo); //fechando o arquivo após ter as informações salvas
    
    printf("Todos os alunos foram salvos com sucesso!\n"); //mensagemzinha de confirmação de cadastro
    
}

void carregar (Alunos lista_turma[], int numerodealunos){
    
}

int main ()
{
	return 0;
	}
