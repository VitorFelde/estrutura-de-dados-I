#include <stdio.h>
#include <string.h>

void exibir_todos_alunos() {
    FILE *arquivo = fopen("alunos.bin", "rb");
    if (arquivo == NULL) return;
    
    Alunos a;
    printf("\n--- ALUNOS ---\n");
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) {
        printf("ID: %d | Nome: %s | Media: %.2f | Situação: %s\n", 
               a.id, a.nome, a.media, a.situacao);
    }
    fclose(arquivo);
}

void consultar_por_situacao(char situacao_busca[]) {
    FILE *arquivo = fopen("alunos.bin", "rb");
    if (arquivo == NULL) return;
    
    Alunos a;
    printf("\n--- ALUNOS %sS ---\n", situacao_busca);
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) {
        if (strcmp(a.situacao, situacao_busca) == 0) {
            printf("ID: %d | Nome: %s | Media: %.2f\n", a.id, a.nome, a.media);
        }
    }
    fclose(arquivo);
}
