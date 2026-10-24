#include <stdio.h>

/*Faça um programa que implemente uma fila com alocação dinâmica, para armazenar números inteiros.

O usuário deve poder incluir quantos elementos desejar na fila.

As opções permitidas para o usuário são:

1 - Inserir um elemento no final da fila

2 - Retirar um elemento do início da fila

3 - Imprimir o conteúdo da fila.

Deve ser postado o código fonte em C, compilável e funcionando, sem o uso de bibliotecas específicas de Windows.*/

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

Fila inserirFila(Fila f, int e) {

    
    



}