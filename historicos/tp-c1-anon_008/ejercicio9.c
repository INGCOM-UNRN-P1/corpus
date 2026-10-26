


#include <stdio.h>

int main(){
	int numero, otro_numero, aux;
	
	
	printf ("Escriba un numero: ");
	scanf ("%i", &numero);
	
	printf ("Escriba otro numero: ");
	scanf ("%i", &otro_numero);
	
	aux = numero;

	while(numero >= otro_numero)
	{
		numero = numero - otro_numero;
	}
	if(numero == 0 )
	{
	printf("El numero %i es multiplo de  %i \n", aux, otro_numero);	
	}		
	else
	{	
	printf("El numero %i no es multiplo de  %i \n", aux, otro_numero);	
	}
	
	return 0;
}
