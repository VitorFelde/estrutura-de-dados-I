#include <stdio.h>

/*Faça um programa que implemente uma fila com alocação dinâmica, para armazenar números inteiros.

O usuário deve poder incluir quantos elementos desejar na fila.

As opções permitidas para o usuário são:

1 - Inserir um elemento no final da fila

2 - Retirar um elemento do início da fila

3 - Imprimir o conteúdo da fila.

Deve ser postado o código fonte em C, compilável e funcionando, sem o uso de bibliotecas específicas de Windows.*/

#define TRUE 1
#define FALSE 0



struct elemento {
    int dado;
    struct elemento *prox; 
};

typedef struct elemento *ApElemento;

typedef struct {
    ApElemento ini;
    ApElemento fim;
} Fila;

Fila criarFila(){
    Fila f;

    f.ini = NULL;
    f.fim = NULL;

    return (f); //returning f because we will use f value to have a referente of the ini and fim
}

int filaVazia(Fila f) {
    if (f.ini == NULL)
        return (TRUE);
    else
        return (FALSE);
}

Fila inserirFila(Fila f, int e) {

    ApElemento novo;

        novo = malloc(sizeof(struct elemento)); //storing in memory space for our new element

        novo -> dado = e; //pointing to dado, and atributting its value as the new inserted element

        novo -> prox = NULL; //now the next value is null

        if (filaVazia(f) == 1) {
            f.ini = novo;
            f.fim = novo;
        }
        
        else {
            f.fim->prox = novo;
            f.fim = novo;
        }
        return (f);
    
}