#include <stdio.h>
#include <string.h>

void atualizar_aluno(int id_alvo, int opcao_alteracao) {
    FILE *arquivo = fopen(ARQUIVO_ALUNOS, "r+b");
    if (arquivo == NULL) return;
    
    Alunos a;
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) {
        if (a.id == id_alvo) {
            if (opcao_alteracao == 1) { // Alterar apenas notas
                printf("Nova Nota 1: "); scanf("%f", &a.p1);
                printf("Nova Nota 2: "); scanf("%f", &a.p2);
            } else if (opcao_alteracao == 2) { // Alterar outros dados
                while (getchar() != '\n'); 
                printf("Novo Nome: ");
                fgets(a.nome, sizeof(a.nome), stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';
                printf("Nova Matricula: "); scanf("%d", &a.matricula);
                printf("Novas Faltas: "); scanf("%d", &a.falta);
            }
            
            // Recalcula média e situação independente do que foi alterado
            a.media = (a.p1 + a.p2) / 2.0;
            if (a.media >= 6.0 && a.falta <= 20) {
                strcpy(a.situacao, "Aprovado");
            } else {
                strcpy(a.situacao, "Reprovado");
            }
            
            // Volta o cursor 1 bloco para trás e salva
            fseek(arquivo, -sizeof(Alunos), SEEK_CUR);
            fwrite(&a, sizeof(Alunos), 1, arquivo);
            fclose(arquivo);
            printf("\nAluno atualizado com sucesso!\n");
            return;
        }
    }
    fclose(arquivo);
    printf("\nAluno com ID %d nao encontrado.\n", id_alvo);
}
