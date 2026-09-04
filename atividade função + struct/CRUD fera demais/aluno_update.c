#include <stdio.h>
#include <string.h>

void atualizar_aluno(int id_alvo, int opcao) {
    FILE *arquivo = fopen("alunos.bin", "r+b"); 
    if (arquivo == NULL) return;
    
    Alunos a;
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) {
        if (a.id == id_alvo) {
            if (opcao == 1) { 
                printf("Nova Nota 1: "); scanf("%f", &a.p1);
                printf("Nova Nota 2: "); scanf("%f", &a.p2);
            } else if (opcao == 2) { 
                while (getchar() != '\n'); 
                printf("Novo Nome: ");
                fgets(a.nome, sizeof(a.nome), stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';
                printf("Nova Matricula: "); scanf("%d", &a.matricula);
                printf("Novas Faltas: "); scanf("%d", &a.falta);
            }
            
            a.media = (a.p1 + a.p2) / 2.0;
            if (a.media >= 6.0 && a.falta <= 20) {
                strcpy(a.situacao, "Aprovado");
            } else {
                strcpy(a.situacao, "Reprovado");
            }
            
            fseek(arquivo, -sizeof(Alunos), SEEK_CUR); // Volta o cursor
            fwrite(&a, sizeof(Alunos), 1, arquivo); // Sobrescreve
            fclose(arquivo);
            printf("Atualizado!\n");
            return;
        }
    }
    fclose(arquivo);
    printf("Nao encontrado.\n");
}
