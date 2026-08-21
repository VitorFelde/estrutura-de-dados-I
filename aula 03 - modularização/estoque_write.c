#include <stdio.h>
#include "produto.h"
#include <time.h>
// Função utilitária para gerar ID automático
int gerar_id() {
    // time(NULL) retorna os segundos desde 1970 (timestamp).
    // cast para converter o formato time_t par int.
    return (int) time(NULL);
}

int salvar_produto(const Produto *produto, const char *filename) {
    FILE *arquivo = fopen(filename, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }
    fwrite(produto, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
    printf ("arquivo salvo\n");
    return 0;
}

int main (){
	int id = gerar_id();
	Produto p = {1001, "Saco de cimento", 38, 10};
	salvar_produto(&p, ARQUIVO_ESTOQUE);
    //solicitar os dados do produto
}
