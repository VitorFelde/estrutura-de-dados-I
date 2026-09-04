#include <stdio.h>
#include <time.h>
//incluindo biblioteca do horario 

int gerar_id() { //aqui esta a funcao que puxamos no create
    return (int)time(NULL);  
    //aqui pegamos o tempo, transformamos em int para poder gerar o id fera demais 
}

void gera_arquivo_alunos() {
    FILE *arquivo = fopen("alunos.bin", "rb");
    if (arquivo != NULL) {//verificação fera demais 
        fclose(arquivo);
        return; // Se abriu, o arquivo já existe. Não faz nada.
    }
    
    arquivo = fopen("alunos.bin", "wb");
    if (arquivo == NULL) return;


    //verificar isso
    Alunos a1 = {gerar_id(), "Joao", 111, 10, 7.0, 8.0, 7.5, "Aprovado"};
    Alunos a2 = {gerar_id() + 1, "Maria", 222, 25, 5.0, 4.0, 4.5, "Reprovado"};

    fwrite(&a1, sizeof(Alunos), 1, arquivo);
    fwrite(&a2, sizeof(Alunos), 1, arquivo);

    fclose(arquivo);
}
