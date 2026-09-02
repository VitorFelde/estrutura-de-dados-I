#include <stdio.h>
#include <string.h>

void exibir_todos_alunos() {
    FILE *arquivo = fopen(ARQUIVO_ALUNOS, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    
    Alunos a;
    printf("\n--- LISTA DE ALUNOS ---\n");
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) {
        printf("ID: %-10d | Nome: %-20s | Notas: %.2f, %.2f | Media: %.2f | Situação: %s\n", 
               a.id, a.nome, a.p1, a.p2, a.media, a.situacao);
    }
    fclose(arquivo);
}

void consultar_por_situacao(const char* status_busca) {
    FILE *arquivo = fopen(ARQUIVO_ALUNOS, "rb");
    if (arquivo == NULL) return;
    
    Alunos a;
    printf("\n--- ALUNOS %sS ---\n", status_busca);
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) {
        if (strcmp(a.situacao, status_busca) == 0) {
            printf("ID: %-10d | Nome: %-20s | Media: %.2f | Faltas: %d\n", 
                   a.id, a.nome, a.media, a.falta);
        }
    }
    fclose(arquivo);
}
