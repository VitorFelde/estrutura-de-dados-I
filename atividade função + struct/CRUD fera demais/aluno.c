#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"
#include "aluno_init.c"
#include "aluno_create.c"
#include "aluno_read.c"
#include "aluno_find.c"
#include "aluno_update.c"
#include "aluno_remove.c"

int main() {
    int opcao = -1, id;
    char nome[50];
    Alunos resultado;

    gera_arquivo_alunos(); 

    while (opcao != 0) {
        printf("\n--- MENU ---\n");
        printf("1. Inserir aluno\n2. Listar todos\n3. Buscar por ID\n");
        printf("4. Buscar por Nome\n5. Alterar Notas\n6. Alterar Dados\n");
        printf("7. Ver Aprovados\n8. Ver Reprovados\n9. Remover\n0. Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserir_aluno(); break;
            case 2: exibir_todos_alunos(); break;
            case 3:
                printf("ID: "); scanf("%d", &id);
                if (buscar_aluno(id, NULL, &resultado)) 
                    printf("Encontrado: %s - Media: %.2f\n", resultado.nome, resultado.media);
                else 
                    printf("Nao encontrado.\n");
                break;
            case 4:
                while (getchar() != '\n'); 
                printf("Nome: "); fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                if (buscar_aluno(-1, nome, &resultado)) 
                    printf("Encontrado: %s - Media: %.2f\n", resultado.nome, resultado.media);
                else 
                    printf("Nao encontrado.\n");
                break;
            case 5:
                printf("ID para alterar notas: "); scanf("%d", &id);
                atualizar_aluno(id, 1);
                break;
            case 6:
                printf("ID para alterar dados: "); scanf("%d", &id);
                atualizar_aluno(id, 2);
                break;
            case 7: consultar_por_situacao("Aprovado"); break;
            case 8: consultar_por_situacao("Reprovado"); break;
            case 9:
                printf("ID para remover: "); scanf("%d", &id);
                remover_aluno(id);
                break;
        }
    }
    return 0;
}
