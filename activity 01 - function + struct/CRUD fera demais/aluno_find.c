#include <stdio.h>
#include <string.h>

int buscar_aluno(int idBusca, char nomeBusca[], Alunos *resultado) { 
    FILE *arquivo = fopen("alunos.bin", "rb");
    if (arquivo == NULL) return 0; //verificação igual dos slides
    
    Alunos a; //mais uma vez criando para melhor controle
    while (fread(&a, sizeof(Alunos), 1, arquivo) == 1) { 
        //sizeof ve o tamanho que os alunos ocupam na memoria em bytes
        if (a.id == idBusca || (nomeBusca != NULL && strcmp(a.nome, nomeBusca) == 0)) { 
            //fazendo comparaçõe de string para ver se o nome digitado for igual a algum que existe
            *resultado = a;
            //como precisamos retornar se achou ou nao + dados dos alunos, precisamos usar ponteiro para que
            //essa variavel em c consiga fazer isso fera demais
            fclose(arquivo);
            return 1;
        }
    }
    fclose(arquivo);
    return 0; 
}
