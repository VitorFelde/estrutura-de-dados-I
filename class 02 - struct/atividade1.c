#include <stdio.h>

/*Atividade de Registros (entrega no papel)
- Modelar a entidade (struct) que representa o cliente(correntista)
    - saldo
    - id, chave
    - ...
Imprimir antes da transferência o saldo
Cenário: Jose faz um pix para Maria no valor de R$ 300,00.
- Saldo de josé é de R$ 800
- Saldo de maria é de R$ 1000,00 
- Qual será o saldo final de ambos?
Imprimir: saldo final de José e Maria após a transferência*/

typedef struct {

	char nome [50];
    float saldo;
    char chave [20];
    int id;
    } Cliente;

void imprimeSaldo (Cliente func) {
    printf ("\nNome: %s\nSaldo: %.2f\n", func.nome, func.saldo); 

}

void transferencia (Cliente *origem, Cliente *destino, float valor) {
	
	destino->saldo += valor;
	origem->saldo -= valor;
	

	
	}
    int main () {
    
			Cliente jose = { 
    
				"jose",
				800,
				"jose@gmail.com",
				022
    
			};
			
			Cliente maria = {
				
				"maria",
				1000,
				"maria@gmail.com",
				001
						
			};
		

		printf ("Antes da transferencia");

		imprimeSaldo (maria);
		imprimeSaldo (jose);
	
		printf ("\nDepois da transferencia");
	
		transferencia(&jose, &maria, 300);
        imprimeSaldo (maria);
		imprimeSaldo (jose);

		
		
	return 0;
			   }
    
