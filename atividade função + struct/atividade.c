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


void inserirdados(Alunos lista_turma[], int numerodealunos) {
    for (int i = 0; i < numerodealunos; i++) {
        while (getchar() != '\n'); //limpando buffer antes
        
        printf ("Digite o nome do aluno: ");
        fgets(lista_turma[i].nome, sizeof(lista_turma[i].nome), stdin);    
        lista_turma[i].nome[strcspn(lista_turma[i].nome, "\n")] = '\0'; //limpando o buffer depois
        printf ("Digite o número de matricula: ");
        scanf ("%d", &lista_turma[i].matricula);
        printf ("Digite a quantidade de faltas: ");
        scanf ("%d", &lista_turma[i].falta);
        printf ("Digite a primeira nota: ");
        scanf ("%f", &lista_turma[i].p1);
        printf ("Digite a segundo nota: ");
        scanf ("%f", &lista_turma[i].p2);
        
        
        //calculo da media, pegando as notas
        lista_turma[i].media = (lista_turma[i].p1 + lista_turma[i].p2) / 2.0;
        
        if (lista_turma[i].media >= 6.0 && lista_turma[i].falta <= 20) {
            strcpy(lista_turma[i].situacao, "Aprovado"); 
            //o strcpy passa para a situação se o aluno foi aprovado ou nao dependendo da sua media e faltas
        } else {
            strcpy(lista_turma[i].situacao, "Reprovado");
        }
        
    }	
}

void exibirdados(Alunos lista_turma[], int numerodealunos) {
    
    for (int i = 0; i < numerodealunos; i++) {
    
        printf ("\nNome do aluno do cadastro %d: %s ", i + 1, lista_turma[i].nome);
        printf ("\nMatricula do aluno %d: %d", i + 1, lista_turma[i].matricula);
        printf ("\nQuantidade de faltas do aluno %d: %d", i + 1, lista_turma[i].falta);
        printf ("\nPrimeira nota do aluno %d: %.2f", i + 1, lista_turma[i].p1);
        printf ("\nSegunda nota do aluno %d: %.2f", i + 1, lista_turma[i].p2);
        printf ("\nMédia das notas do aluno %d: %.2f", i + 1, lista_turma[i].media);
        printf ("\nSituação do aluno %d: %s\n", i + 1, lista_turma[i].situacao);
        
    }
    
    
}

void salvardados(Alunos lista_turma[], int numerodealunos) {
    //abre em binario e escreve em binario
    FILE *arquivo = fopen("alunos.bin", "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n"); //mensagem de segurança/verificação
        return;//tive de pesquisar, se nao usarmos, mesmo que nao consiga salvar, o programa vai tentar rodar o menu de novo e vai bugar
    }


    fwrite(lista_turma, sizeof(Alunos), numerodealunos, arquivo);
    //o sizeof pega o tamanho de bytes de cada aluno, assim sabendo onde cada um encerra
    //pega a quantidade de alunos da lista turma, e salva no arquivo, que criamos la em cima
    //pega a quantidade pelo sizeof da struct que chamamos de Alunos la em cima

    fclose(arquivo); //fechando o arquivo após salvar os alunos nele
    printf("\nDados salvos com sucesso!\n\n"); //printf de confirmação apenas
}

void carregardados(Alunos lista_turma[], int *numerodealunos){ //ativando variavel ponteiro
    
    FILE *arquivo = fopen("alunos.bin", "rb"); //vai abrir o arquivo que salvamos, e vai no modo read binary
    if (arquivo != NULL) { //verificaçãozinha para dar certo
      
      *numerodealunos = fread(lista_turma, sizeof(Alunos), 40, arquivo);//utilizando o ponteiro para 
      //puxar na função depois, usamos o 40 pois sera o limite de alunos que poderemos pegar
      //ao inves de colocar algo dentro do arquivo, estamos carregando com as infos
      //dele atraves do fread, que esta lendo o fwrite que fizemos la na função salvardados
      fclose(arquivo);
    }
 
    else {
        printf ("Não existem alunos salvos na memória");
    }   
}

int main ()
{
    int n = 0;
    int opcao;
    Alunos turma[40];
    //passaremos turma inteiro como parametro, portanto ira sem os colchetes
    

    do {
        printf ("\nDigite a opção desejada: \n");
        printf ("1. Inserir alunos\n");
        printf ("2. Exibir alunos\n");
        printf ("3. Salvar dados\n");
        printf ("4. Carregar dados\n");
        printf ("5. Sair do programa\n\n"); //demorei pra chegar no resultado bonitinho
        scanf ("%d", &opcao);
        
        switch (opcao) {
            
            case 1:
                printf ("Digite o número de alunos que deseja cadastrar: ");
                scanf ("%d", &n);
                if (n > 40) {
                    printf("Limite maximo de 40 alunos!\n");//usuario nao pode cadastrar mais de 40
                    n = 0;
                } else {
                    inserirdados(turma, n);
                }
                break;
            
            case 2:
                if (n == 0) { //caso nao tenha nenhum aluno cadastrado
                    printf("Nao ha alunos cadastrados ou carregados na memoria.\n");
                } else {
                    exibirdados(turma, n);
                }
                break;
                    
            case 3:
                if (n == 0) {//se nao tiver aluno nao tem o que salvar
                    printf("Nao ha dados para salvar.\n");
                } else {
                    salvardados(turma, n);
                }
                break;
                  
            case 4:
                // Passamos o '&n' para que o fread atualize o valor de 'n' no main
                carregardados(turma, &n); 
                break;
            
            case 5:
                printf ("Saindo do programa\n");
                break;
            
            default: 
                printf ("Opcao invalida, selecione uma das possiveis\n");
                break;
        }
        
    } while (opcao != 5); 
    //enquanto for diferente da opção saida
    return 0;
}
