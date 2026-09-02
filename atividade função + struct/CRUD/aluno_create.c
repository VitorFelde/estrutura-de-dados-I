#include <stdio.h>
#include <string.h>

void inserir_aluno() {
    Alunos a;
    a.id = gerar_id();
    
    while (getchar() != '\n'); // limpando buffer antes
    printf("Digite o nome do aluno: ");
    fgets(a.nome, sizeof(a.nome), stdin);    
    a.nome[strcspn(a.nome, "\n")] = '\0'; // limpando o buffer depois
    
    printf("Digite o numero de matricula: ");
    scanf("%d", &a.matricula);
    printf("Digite a quantidade de faltas: ");
    scanf("%d", &a.falta);
    printf("Digite a primeira nota: ");
    scanf("%f", &a.p1);
    printf("Digite a segunda nota: ");
    scanf("%f", &a.p2);
    
    a.media = (a.p1 + a.p2) / 2;
    
    if (a.media >= 6.0 && a.falta <= 20) {
        strcpy(a.situacao, "Aprovado"); 
    } else {
        strcpy(a.situacao, "Reprovado");
    }

    FILE *arquivo = fopen(ARQUIVO_ALUNOS, "ab");
    if (arquivo != NULL) {
        fwrite(&a, sizeof(Alunos), 1, arquivo);
        fclose(arquivo);
        printf("\nAluno salvo id = %d\n", a.id); //para melhor visualização do usuario fera demais
    }
}
