#include <stdio.h>

void remover_aluno(int id_alvo) {
    FILE *original = fopen(ARQUIVO_ALUNOS, "rb");
    FILE *temp = fopen("temp.bin", "wb");
    if (original == NULL || temp == NULL) return;
    
    Alunos a;
    int encontrou = 0;
    
    while (fread(&a, sizeof(Alunos), 1, original) == 1) {
        if (a.id != id_alvo) {
            fwrite(&a, sizeof(Alunos), 1, temp); // Copia os que não serão deletados
        } else {
            encontrou = 1; // Ignora o aluno que queremos remover
        }
    }
    
    fclose(original);
    fclose(temp);
    
    if (encontrou) {
        remove(ARQUIVO_ALUNOS); 
        rename("temp.bin", ARQUIVO_ALUNOS); 
        printf("\nAluno removido com sucesso!\n");
    } else {
        remove("temp.bin");
        printf("\nAluno nao encontrado para remocao.\n");
    }
}
