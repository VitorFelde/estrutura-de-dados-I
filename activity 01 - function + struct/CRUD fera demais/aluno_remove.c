#include <stdio.h>

void remover_aluno(int id_alvo) {
    FILE *original = fopen("alunos.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");
    //aqui criamos um arquivo temporario apenas para servir de peneira e remover apenas o bloco que queremos
    //se nao criarmos existe a chance do arquivo corromper
    
    Alunos a;
    int achou = 0;
    
    while (fread(&a, sizeof(Alunos), 1, original) == 1) {
        //se o aluno nao for igual ao id que queremos excluir ele é salvo no arquivo temporario
        //e dai no arquivo original fica livre apenas para o que iremos excluir
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
        printf("aluno removido\n");
    } else {
        remove("temp.bin");
        printf("aluno nao encontrado.\n");
    }
}
