#ifndef PRODUTO_H //se nao tiver definido esse nome
#define PRODUTO_H //defina-o

#define ARQUIVO_ESTOQUE "estoque.bin"

typedef struct {
	int id, quantidade;
	char nome[50];
	float valor;	
} Produto;

#endif
