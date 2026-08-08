#include <stdio.h>


typedef struct {

    float salario;
    char nome [100];
    long id;
    char nascimento [10];

} Funcionario;

void imprimeDadosFuncionarios (Funcionario func) {
    printf ("\nNome: %s\nSalario: %.2f\n", func.nome, func.salario); //criamos a função aqui
    printf ("Data de nascimento: %s", func.nascimento);
}
    int main () {
    
			Funcionario vitor = { //atribuimos os valores para ela aqui
    
				2152.62,
				"Vitor",
				119,
				"24/05/2008"
    
			};
			
			Funcionario ana = {
				
				6500.00,
				"Ana",
				118,
				"18/07/1987"
				
			}
			
			Funcionario ivo = {
			
				8000.90,
				"Ivo",
				117,
				"24/10/1980"
				
			}

        imprimeDadosFuncionarios (vitor); //aqui fazemos a função e colocamos o nosso funcionario como parametro, assim extraíremos as infos
		vitor.salario += 200;
		imprimeDadosFuncionarios (vitor);
		
		Funcionario funcionarios [3];
		funcionarios [0] = vitor;
		funcionarios [1] = ana;
		funcionarios [2] = ivo;
		
	return 0;
			   }
    
