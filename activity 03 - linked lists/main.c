
#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int dado;
    struct elemento *prox;
};

typedef struct elemento *Lista;

Lista criarLista(void) {
    return NULL;
}

Lista inserirElemento(Lista l, int e) {
    Lista p, ant, novo;

    novo = malloc(sizeof(struct elemento));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return l;
    }

    novo->dado = e;

    p = l;
    ant = p;

    while ((p != NULL) && (p->dado < e)) {
        ant = p;
        p = p->prox;
    }

    if (p != ant) {
        ant->prox = novo;
    } else {
        l = novo;
    }

    novo->prox = p;

    return l;
}

Lista retirarElemento(Lista l, int e) {
    Lista p, ant;

    p = l;
    ant = NULL;

    while ((p != NULL) && (p->dado != e)) {
        ant = p;
        p = p->prox;
    }

    if (p != NULL) {
        if (ant == NULL) {
            l = p->prox;
        } else {
            ant->prox = p->prox;
        }

        free(p);
    }

    return l;
}

Lista buscarElemento(Lista l, int e) {
    Lista p;

    p = l;

    while ((p != NULL) && (p->dado != e)) {
        p = p->prox;
    }

    return p;
}

void imprimirElementos(Lista l) {
    Lista p;

    p = l;

    if (p == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Elementos da lista: ");

    while (p != NULL) {
        printf("%d ", p->dado);
        p = p->prox;
    }

    printf("\n");
}

int contarElementos(Lista l) {
    Lista p;
    int cont;

    p = l;
    cont = 0;

    while (p != NULL) {
        cont++;
        p = p->prox;
    }

    return cont;
}

int main(void) {
    Lista lista;
    Lista resultado;
    int op, e;

    lista = criarLista();

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

                lista = inserirElemento(lista, e);
                printf("Elemento inserido.\n");
                break;

            case 2:
                printf("Digite o numero que deseja retirar: ");
                if (scanf("%d", &e) != 1) {
                    printf("Entrada invalida.\n");
                    return 1;
                }

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

    } while (op != 6);

    return 0;
}
