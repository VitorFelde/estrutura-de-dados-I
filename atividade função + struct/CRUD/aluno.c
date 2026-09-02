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
    int opcao = -1; 
    int id_aluno, tipo_alt;
    char nome_busca[50];
    Alunos aluno_resultado;

    gera_arquivo_alunos(); // Inicializa se nao existir

    while (opcao != 0) {
        printf(" 1. Inserir aluno\n");
        printf(" 2. Exibir todos os alunos\n");
        printf(" 3. Buscar aluno por ID\n");
        printf(" 4. Buscar aluno por Nome\n");
        printf(" 5. Alterar Notas do aluno\n");
        printf(" 6. Alterar Dados do aluno\n");
        printf(" 7. Consultar Aprovados\n");
        printf(" 8. Consultar Reprovados\n");
        printf(" 9. Remover aluno\n");
        printf(" 0. Sair\n");
        printf("Escolha uma: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_aluno();
                break;
            case 2:
                exibir_todos_alunos();
                break;
            case 3:
                printf("Digite o ID do aluno: ");
                scanf("%d", &id_aluno);
                if (buscar_aluno(id_aluno, NULL, &aluno_resultado)) {
                    printf("\nAluno Encontrado: %s | Matricula: %d | Media: %.2f | Situacao: %s\n", 
                           aluno_resultado.nome, aluno_resultado.matricula, aluno_resultado.media, aluno_resultado.situacao);
                } else {
                    printf("\nAluno nao encontrado.\n");
                }
                break;
            case 4:
                while (getchar() != '\n'); 
                printf("Digite o nome exato do aluno: ");
                fgets(nome_busca, sizeof(nome_busca), stdin);
                nome_busca[strcspn(nome_busca, "\n")] = '\0';
                
                if (buscar_aluno(-1, nome_busca, &aluno_resultado)) { // Passamos -1 pro ID e o Nome preenchido
                    printf("\nAluno Encontrado: ID: %d | Media: %.2f | Situacao: %s\n", 
                           aluno_resultado.id, aluno_resultado.media, aluno_resultado.situacao);
                } else {
                    printf("\nAluno nao encontrado.\n");
                }
                break;
            case 5:
                printf("Digite o ID do aluno para alterar NOTAS: ");
                scanf("%d", &id_aluno);
                atualizar_aluno(id_aluno, 1);
                break;
            case 6:
                printf("Digite o ID do aluno para alterar DADOS: ");
                scanf("%d", &id_aluno);
                atualizar_aluno(id_aluno, 2);
                break;
            case 7:
                consultar_por_situacao("Aprovado");
                break;
            case 8:
                consultar_por_situacao("Reprovado");
                break;
            case 9:
                printf("Digite o ID do aluno para remover: ");
                scanf("%d", &id_aluno);
                remover_aluno(id_aluno);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
    return 0;
}
