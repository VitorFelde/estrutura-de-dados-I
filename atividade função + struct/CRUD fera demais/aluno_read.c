#include <stdio.h>
#include <string.h>

void exibir_todos_alunos() {
    FILE *arquivo = fopen("alunos.bin", "rb");
    if (arquivo == NULL) return; //verificação de segurança
    
    Alunos a; //criacao da variavel para melhor controle
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) { 
        //lemos armazenamos um por vez na variael a enquanto a funcao
        //conseguir ler pelo menos um termo
        printf("ID: %d\nNome: %s\nMedia: %.2f\nSituação: %s\n", 
               a.id, a.nome, a.media, a.situacao);
    }
    fclose(arquivo);
}

void consultar_por_situacao(char situacao_busca[]) {
    FILE *arquivo = fopen("alunos.bin", "rb");
    if (arquivo == NULL) return;
    
    Alunos a;
    printf("\nalunos %sS\n", situacao_busca); //pegando os alunos da situação busca que sera digitada pelo usuario
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) {
        if (strcmp(a.situacao, situacao_busca) == 0) { //colocando na string situação os alunos de determinada situação
            printf("ID: %d\nNome: %s\nMedia: %.2f\n", a.id, a.nome, a.media);
        }
    }
    fclose(arquivo);
}
