#include <stdio.h> 
#include <string.h>
#include <ctype.h>

/*Faça um programa que  implementa uma lista com vetores de strings, conforme o exemplo visto em sala, com as seguintes operações:

1. Inserir elemento 
2. Retirar Elemento
3. Criar Lista
4. Contar elementos da lista
5. Exibir o conteúdo da lista

A interface com o usuário deve ser feita pelo programa principal, passando os parâmetros para as funções que implementam as operações sobre a lista.
Enviar o arquivo fonte em C, funcionando.*/


#define MaxItens 10
#define TamItem 20
typedef char tpLista[MaxItens][TamItem];

void inserirElemento (tpLista lista, char *item2){
	int i;
	for(i = 0; i < MaxItens && strlen(lista[i]) > 0; i++);
	if (i < MaxItens) {
	    strcpy(lista[i], item2);
	}
	else {
	    printf("Lista cheia, não pode inserir");
	}
}

void retirarElemento(tpLista lista, char *item2){
    
    int i;
    
    //se o item lista[i] for diferente ao que o usuario digitou (item2), 
    //cresce o contador e continua buscando o elemento que o usuario digitou
    for(i = 0; i < MaxItens && strlen(lista[i]) > 0 && (strcmp(lista[i], item2) != 0); i++);
    if (i < MaxItens && (strcmp(lista[i], item2) == 0)) {
        printf("\nItem (%s) foi encontrado e será removido\n", item2);
        if (i < (MaxItens - 1)) { //verifica se não é o ultimo item da lista
            for (; i < (MaxItens-1) && strlen(lista[i]) > 0; i++) 
            //nao tem inicialização do i, pq o i é a exata posição que foi apagada
            //loop continua enquanto não estourar o limite do vetor e enquanto houver elementos válidos na frente para puxar
            strcpy(lista[i], lista[i+1]); //essa linha copiamos a linha da frente e puxamos para a de tras
    }
   
        lista[MaxItens-1][0] = '\0'; //atribui o valor vazio ao ultimo elemento, para que possa ter uma nova insercao
    }
    else {
        printf("\nItem (%s) não foi encontrado, verifique se digitou corretamente", item2);
    }
}

void criaLista(tpLista listatop){ //aqui estamos criando a lista vazia para poder estar iniciando wessa lista
    int i;
    for (i = 0; i < MaxItens; i++) { //enquanto for menor que o tamanho maximo que criamos
        listatop[i][0] = '\0'; //criamos o numero de itens possiveis, e com 
    }
}

void contarElementos(tpLista contador){
    int i, j = 0;
    for (i = 0; i < MaxItens && strlen(contador[i]) > 0; i++) {
        j++;
    }

    printf ("A lista tem: %d itens \n", j);
}

void exibirLista(tpLista exibir){
    int i; 	
    for (i = 0; i < MaxItens && strlen(exibir[i])>0; i++) {
        printf ("%s\n", exibir[i]);
    }
}

int main() {
	tpLista listaTop;
    
    criaLista(listaTop);
	
	int op = 1;
	
	do {
		printf ("\nEscolha uma das opções abaixo: \n");
		printf ("1 - Inserir elemento\n");
		printf ("2 - Retirar elemento\n");
		printf ("3 - Contar elementos da lista\n");
		printf ("4 - Exibir lista\n");
		printf ("5 - Sair do programa\n");
		printf ("\nEscolha: ");
		scanf ("%d", &op);

	
    	switch (op) {
    		
    	case 1: 
    	    char novoItem[TamItem]; //criando uma string para que o usuario possa digitar o item que quer add
                
                int k;
                
                printf("Digite o elemento que deseja inserir: ");
                scanf("%s", novoItem);
                
                if (strlen(novoItem) > 20) {
					printf ("\nVoce nao pode inserir um item com mais de 20 caracteres\n");
				}
				
				else { //professor, tentei criar uma função la em cima pra poder fazer isso, mas fui incapaz 
					//de fazer isso, e não queria usar IA pra manter o codigo fera                
					for(k = 0; novoItem[k] != '\0'; k++) {
						novoItem[k] = toupper(novoItem[k]);	
					}
					
					inserirElemento(listaTop, novoItem);
			}
    	break;	
    	
    	case 2: 
    	    char itemRemove[TamItem];
    	    int t;
    	        	    
    	    printf ("Digite o elemento que deseja remover: ");
    	    scanf ("%s", itemRemove);
    	
			for(t = 0; itemRemove[t] != '\0'; t++) {
				itemRemove[t] = toupper(itemRemove[t]);	
			}

    		retirarElemento(listaTop, itemRemove);
    	break;	
    	
    	case 3: 
    		contarElementos(listaTop);
    	break;	
    	
    	case 4: 
    		exibirLista(listaTop); //passando a lista que criamos para que a função saiba onde tem que procurar o que exibir
    	break;	
    	
    	case 5: 
    		printf ("Saindo do programa");
    	break;
    	
    	default: 
			printf ("\nDigite uma das opções válidas\n");
		break;
	    }
	}
	while (op != 5);

	return 0;
}
