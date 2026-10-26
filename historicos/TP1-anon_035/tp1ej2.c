/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int suma_lenta(int numero, int otronumero)
{
	int resultado, contador;
	resultado = numero;
	contador = 1;
	
	while(contador <= otronumero)
	
	{
		
		resultado = resultado + 1;
		
		contador++;
		
	}



	return resultado;
}



int main(int argc, char *argv[])
{
	
    int numero, otronumero, resultado;
	
    printf("Ingrese primer numero \n");
	
	scanf("%d" , &numero);
	
	printf("Ingrese segundo numero \n");
	
	scanf("%d" , &otronumero);
	
	resultado = suma_lenta( numero, otronumero);
	
	printf("El resultado es: %d", resultado);
	
    return 0;
}
