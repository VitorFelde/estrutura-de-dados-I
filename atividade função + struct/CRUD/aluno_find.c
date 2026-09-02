#include <stdio.h>
#include <string.h>

// Retorna 1 se achou, 0 se não achou
int buscar_aluno(int id_busca, const char* nome_busca, Alunos *resultado) {
    FILE *arquivo = fopen(ARQUIVO_ALUNOS, "rb");
    if (arquivo == NULL) return 0;
    
    Alunos a;
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) {
        // Verifica se o ID bate (quando id_busca != -1) ou se o Nome bate
        if ((id_busca != -1 && a.id == id_busca) || 
            (nome_busca != NULL && strcmp(a.nome, nome_busca) == 0)) {
            *resultado = a; // Copia os dados para a variável ponteiro
            fclose(arquivo);
            return 1;
        }
    }
    fclose(arquivo);
    return 0; 
}
