#include <stdio.h>
#include <string.h>

void inserir_aluno() {
    Alunos a; //criamos a variavel para controle mais facil dos dados
    a.id = gerar_id(); 
    //essa função gerar id é criada no init, e depois na main chamamos tudo e dai funciona fera demais
    
    while (getchar() != '\n'); //limpeza de buffer lendaria
    printf("Nome do aluno: ");
    fgets(a.nome, sizeof(a.nome), stdin);    
    a.nome[strcspn(a.nome, "\n")] = '\0'; //limpando o buffer debaixo agora
    
    printf("Matricula: ");
    scanf("%d", &a.matricula);
    printf("Faltas: ");
    scanf("%d", &a.falta);
    printf("Nota 1: ");
    scanf("%f", &a.p1);
    printf("Nota 2: ");
    scanf("%f", &a.p2);
    
    a.media = (a.p1 + a.p2) / 2;
    
    if (a.media >= 6.0 && a.falta <= 20) {
        strcpy(a.situacao, "Aprovado"); //passando o valor pra string com o strcpy
    } else {
        strcpy(a.situacao, "Reprovado");
    }

    FILE *arquivo = fopen("alunos.bin", "ab"); //abrindo um arquivo com esse nome
    //usamos ab para que o programa nao exclua os antigos alunos do cadastro e coloque
    //os novos na ultima posicao do nosso vetor de struct Alunos
    if (arquivo != NULL) {
        fwrite(&a, sizeof(Alunos), 1, arquivo);
        fclose(arquivo);
        printf("\nAluno salvo - ID: %d\n", a.id); 
        //aqui printamos o id para que o usuario possa buscar pelo mesmo dps
    }
}
