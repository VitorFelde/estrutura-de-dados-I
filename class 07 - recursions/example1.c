#include <stdio.h>

long fib (int n) {
	
	if (n <= 2) 
	return 1;
	else
	return (fib(n-1) + fib(n-2));
	
}
	
int main (){
	int numero;
	int termo;
	
	printf ("\nCalcula o n-esimo termo da sequencia\n");
	printf ("Entre com o valor de n: ");
	scanf ("%d", &numero);
	termo=fib(numero);
	printf ("\n\n%d", termo);
	
	
}
