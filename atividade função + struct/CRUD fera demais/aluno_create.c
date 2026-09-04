#include <stdio.h>
#include <string.h>

void inserir_aluno() {
    Alunos a;
    a.id = gerar_id();
    
    while (getchar() != '\n'); 
    printf("Nome do aluno: ");
    fgets(a.nome, sizeof(a.nome), stdin);    
    a.nome[strcspn(a.nome, "\n")] = '\0'; 
    
    printf("Matricula: ");
    scanf("%d", &a.matricula);
    printf("Faltas: ");
    scanf("%d", &a.falta);
    printf("Nota 1: ");
    scanf("%f", &a.p1);
    printf("Nota 2: ");
    scanf("%f", &a.p2);
    
    a.media = (a.p1 + a.p2) / 2.0;
    
    if (a.media >= 6.0 && a.falta <= 20) {
        strcpy(a.situacao, "Aprovado"); 
    } else {
        strcpy(a.situacao, "Reprovado");
    }

    FILE *arquivo = fopen("alunos.bin", "ab");
    if (arquivo != NULL) {
        fwrite(&a, sizeof(Alunos), 1, arquivo);
        fclose(arquivo);
        printf("\nAluno salvo! ID: %d\n", a.id);
    }
}
