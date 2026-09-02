#include <stdio.h>
#include <time.h>
#include <string.h>

int gerar_id() { 
    return (int)time(NULL); 
}

void gera_arquivo_alunos() {
    FILE *arquivo = fopen(ARQUIVO_ALUNOS, "rb");
    if (arquivo != NULL) {
        fclose(arquivo);
        return; 
    }
    
    printf(">> Criando novo arquivo de alunos...\n");
    arquivo = fopen(ARQUIVO_ALUNOS, "wb");
    
    if (arquivo == NULL) {
        printf("Erro fatal: Sem permissao de acesso.\n");
        return;
    }

    Alunos a1 = {gerar_id(), "Joao Silva", 1234, 10, 7.0, 8.0, 7.5, "Aprovado"};
    Alunos a2 = {gerar_id() + 1, "Maria Souza", 5678, 25, 5.0, 4.0, 4.5, "Reprovado"};

    fwrite(&a1, sizeof(Alunos), 1, arquivo);
    fwrite(&a2, sizeof(Alunos), 1, arquivo);

    fclose(arquivo);
    printf(">> Arquivo salvo com alunos de exemplo!\n\n");
}
