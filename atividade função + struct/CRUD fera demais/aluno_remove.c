#include <stdio.h>

void remover_aluno(int id_alvo) {
    FILE *original = fopen("alunos.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");
    
    Alunos a;
    int achou = 0;
    
    while (fread(&a, sizeof(Alunos), 1, original) == 1) {
        if (a.id != id_alvo) {
            fwrite(&a, sizeof(Alunos), 1, temp);
        } else {
            achou = 1; 
        }
    }
    
    fclose(original);
    fclose(temp);
    
    if (achou) {
        remove("alunos.bin"); 
        rename("temp.bin", "alunos.bin"); 
        printf("Removido com sucesso!\n");
    } else {
        remove("temp.bin");
        printf("Aluno nao encontrado.\n");
    }
}
