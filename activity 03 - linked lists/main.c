#include <stdio.h>
#include <string.h>
/*Implementar um programa que gerencia uma lista encadeada ordenada com alocação dinâmica.

Cada elemento da lista deve conter um número inteiro.

Os elementos devem ser inseridos em ordem crescente. Por exemplo, de for inserida a sequência 5, 3, 9, 4, ao imprimir o conteúdo da lista, deve aparecer 3, 4, 5, 9.

O programa deve oferecer ao usuário as operações:

- Inserir elemento na lista;

- Retirar elemento da lista;

- Buscar um elemento informado está na lista, retornando o endereço do elemento se ele existir na lista, ou NULL se não existir;

- Imprimir o conteúdo da lista;

- Contar o número de elementos da lista.*/

#define MaxItens 10
#define TamItem 20
typedef char tpLista[MaxItens][TamItem];





void criarLista () {

}

void inserirElemento (tpLista lista, char *item2) {

}


int main (){

    int op;
    do {
    printf ("\nEscolha uma das opções abaixo:\n");
    printf ("1) Inserir elemento na lista\n");
    printf ("2) Retirar elemento da lista\n");
    printf ("3) Buscar elemento na lista\n");
    printf ("4) Imprimir elementos da lista\n");
    printf ("5) Contar os elementos da lista\n");
    printf ("6) Sair do programa\n");
    printf ("\nEscolha: ");
    scanf ("%d", &op);

    switch (op) {

        case 1: 
            //inserirElemento();
        break;

        case 2: 
            //retirarElemento();
        break;

        case 3: 
            //buscarElemento();
        break;
    
        case 4: 
            //imprimirElementos();
        break;

        case 5: 
            //contarElementos();
        break;

        case 6: 
            printf ("Saindo do programa");
        break;

        default: 
            printf ("\nOpção inválida, escolha entre 1 e 6\n");
        break;
    }
    }

    while (op != 6);

}