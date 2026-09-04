#include <stdio.h>
#include <string.h>

int buscar_aluno(int id_busca, char nome_busca[], Alunos *resultado) {
    FILE *arquivo = fopen("alunos.bin", "rb");
    if (arquivo == NULL) return 0;
    
    Alunos a;
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) {
        if (a.id == id_busca || (nome_busca != NULL && strcmp(a.nome, nome_busca) == 0)) {
            *resultado = a;
            fclose(arquivo);
            return 1;
        }
    }
    fclose(arquivo);
    return 0; 
}
