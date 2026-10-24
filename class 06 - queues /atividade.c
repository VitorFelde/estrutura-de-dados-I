#include <stdio.h>
#include <stdlib.h>

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

Fila retirarFila(Fila f, int *e) {

    ApElemento ap;

    if (! filaVazia(f)) {
        *e=f.ini->dado; //basically we're passing the value of the dado at beggining to the pointer e
        ap = f.ini;

        f.ini = f.ini->prox;
        free(ap);

        if (filaVazia(f)) {
            f.fim = NULL;
        }
    }
    else {
        *e = -1;
        printf ("\nFila vazia\n");
    }
    return (f);
}

void mostrarFila(Fila f){ //void because it doesnt return, it just prints

    ApElemento ap;
    
    ap = f.ini;
    
    while (ap != NULL) {
        printf ("%d - ", ap->dado); //showing the data store on ap
        ap = ap->prox; //thats like incrementing 
    }
    printf ("\n");
}

int main (){
    
    Fila fila1 = criarFila();
    int novo;
    
    int op;
    
    do {
    printf ("\nDigite a opção que deseja: \n");
    printf ("1) Inserir elemento na fila\n");
    printf ("2) Remover elemento da fila\n");
    printf ("3) Mostrar fila\n");
    printf ("4) Sair do programa\n");
    printf ("\nEscolha: ");
    scanf ("%d", &op);
    
        switch (op) {
            
            case 1:
                printf ("\nDigite o numero a ser inserido: ");
                scanf ("%d", &novo);
                fila1 = inserirFila(fila1, novo);
            break;
            
            case 2:
            if (filaVazia(fila1) == 0){
                printf ("\nPrimeiro elemento removido\n");
                fila1 = retirarFila(fila1, &novo);
            } else {
                printf ("\nFila vazia\n");
            }
            break;
            
            case 3:
                if (filaVazia(fila1) == 0){
                mostrarFila(fila1);
            } else {
                printf ("\nFila vazia\n");
            }
            break;
            
            case 4:
                printf ("Saindo do programa");
            break;
        }
    } while (op != 4);
}
