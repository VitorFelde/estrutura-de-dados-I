#include <stdio.h>
#include <stdlib.h> //so we can put malloc and free

/*Implementar um programa que gerencia uma lista encadeada ordenada com alocação dinâmica.
Cada elemento da lista deve conter um número inteiro. 
Os elementos devem ser inseridos em ordem crescente. 
Por exemplo, de for inserida a sequência 5, 3, 9, 4, ao imprimir o conteúdo da lista, 
deve aparecer 3, 4, 5, 9. O programa deve oferecer ao usuário as operações: 
Inserir elemento na lista; -
Retirar elemento da lista; - 
Buscar um elemento informado está na lista, retornando o endereço do elemento se ele existir na lista,
ou NULL se não existir; -
Imprimir o conteúdo da lista; - 
Contar o número de elementos da lista.*/

struct elemento {
    int dado;
    struct elemento *prox; //points to the next node in the list
};

typedef struct elemento *Lista; //Lista is a pointer to a node so we can access the list through its first node

Lista criarLista() { //the list starts empty because it doesnt have a first node yet
    return NULL;
}

Lista inserirElemento(Lista l, int e) { //l is the first node and e is the number we want to insert
    Lista p, ant, novo;

    //sizeof gets the size of one node and malloc reserves that much memory
    novo = malloc(sizeof(struct elemento));

    if (novo == NULL) { //if memory allocation fails we cant use the new node
        printf("Erro ao alocar memoria\n");
        return l;
    }

    novo->dado = e; //-> lets us access a field through a pointer
    //this is the same as (*novo).dado

    p = l; //p moves through the list to find where e belongs
    ant = p; //ant keeps track of the previous node

    //keep moving while the current number is smaller than e
    while ((p != NULL) && (p->dado < e)) {
        ant = p; //save the current node before moving forward
        p = p->prox; //move to the next node
    }

    if (p != ant) {
        //p moved forward so the new node goes after ant
        ant->prox = novo;
    } else {
        //p didnt move so the new node belongs at the beginning
        //this happens if the list is empty or e is the smallest number
        l = novo;
    }

    //the new node points to the node that comes after it
    //if p is NULL then the new node becomes the last one
    novo->prox = p;

    return l;
}

Lista retirarElemento(Lista l, int e) { //l is the list and e is the number we want to remove
    Lista p, ant;

    p = l; //p searches for the node we want to remove
    ant = NULL; //there is no previous node at the start

    while ((p != NULL) && (p->dado != e)) {
        ant = p; //save the current node before moving forward
        p = p->prox;
    }

    if (p != NULL) { //p is valid so we found the number
        if (ant == NULL) {
            //the first node is being removed so the next node becomes first
            l = p->prox;
        } else {
            //skip p by connecting the previous node to the next one
            ant->prox = p->prox;
        }

        free(p); //release the memory used by the removed node
    }

    return l; //the first node may have changed
}

Lista buscarElemento(Lista l, int e) { //search for e and return the node if it exists
    Lista p;

    p = l; //start at the first node

    while ((p != NULL) && (p->dado != e)) {
        p = p->prox; //keep moving until we find e or reach the end
    }

    //p holds the node address if we found e
    //otherwise p is NULL
    return p;
}

void imprimirElementos(Lista l) {
    Lista p;

    p = l; //use p to move through the list without changing l

    if (p == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Elementos da lista: ");

    while (p != NULL) {
        printf("%d ", p->dado);
        p = p->prox; //move to the next node
    }

    printf("\n");
}

int contarElementos(Lista l) {
    Lista p;
    int cont;

    p = l;
    cont = 0; //we havent visited any nodes yet

    while (p != NULL) {
        cont++; //count the current node
        p = p->prox; //move forward so we dont count the same node twice
    }

    return cont;
}

int main(void) {
    Lista lista;
    Lista resultado;
    int op, e;

    lista = criarLista(); //start with an empty list

    do {
        printf("\nEscolha uma das opcoes abaixo:\n");
        printf("1) Inserir elemento na lista\n");
        printf("2) Retirar elemento da lista\n");
        printf("3) Buscar elemento na lista\n");
        printf("4) Imprimir elementos da lista\n");
        printf("5) Contar os elementos da lista\n");
        printf("6) Sair do programa\n");
        printf("\nEscolha: ");

        if (scanf("%d", &op) != 1) {
            printf("Entrada invalida.\n");
            break;
        }

        switch (op) {
            case 1:
                printf("Digite o numero que deseja inserir: ");
                if (scanf("%d", &e) != 1) {
                    printf("Entrada invalida.\n");
                    return 1;
                }

                //save the returned list because the first node might change
                lista = inserirElemento(lista, e);
                printf("Elemento inserido.\n");
                break;

            case 2:
                printf("Digite o numero que deseja retirar: ");
                if (scanf("%d", &e) != 1) {
                    printf("Entrada invalida.\n");
                    return 1;
                }

                //check if the number exists before trying to remove it
                resultado = buscarElemento(lista, e);

                if (resultado != NULL) {
                    lista = retirarElemento(lista, e);
                    printf("Elemento retirado.\n");
                } else {
                    printf("Elemento nao encontrado.\n");
                }
                break;

            case 3:
                printf("Digite o numero que deseja buscar: ");
                if (scanf("%d", &e) != 1) {
                    printf("Entrada invalida.\n");
                    return 1;
                }

                resultado = buscarElemento(lista, e);

                if (resultado != NULL) {
                    //%p prints a memory address and resultado holds the node address
                    printf("Elemento encontrado no endereco: %p\n",
                           (void *)resultado);
                } else {
                    printf("Elemento nao encontrado. Endereco: NULL\n");
                }
                break;

            case 4:
                imprimirElementos(lista);
                break;

            case 5:
                printf("Quantidade de elementos: %d\n",
                       contarElementos(lista));
                break;

            case 6:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Escolha entre 1 e 6.\n");
                break;
        }

    } while (op != 6); //keep showing the menu until the user chooses 6

    return 0;
}
