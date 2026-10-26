

#include <stdio.h>

int suma_lenta(int numero, int otro_numero);

int main()
{	
	int numero, otro_numero, suma;
	suma = 0;

	printf("Digite 2 numeros enteros para sumarlos\n");
	printf("Numero: ");
	scanf("%d", &numero);
	printf("Siguiente numero: ");
    scanf("%d", &otro_numero);
    suma = suma_lenta(numero, otro_numero);
	printf("La suma lenta es: %d\n", suma);
	
	return 0;
}


int suma_lenta(int numero, int otro_numero)
{
	int i;
	if(otro_numero > 0)
    {
        for(i = 0; i < otro_numero; i ++)
	    {
		    numero = numero + 1;
	    }
    }
	
    else
    {
        otro_numero = otro_numero * -1;
        for(i = 0; i < otro_numero; i ++)
	    {
		    numero = numero - 1;   
        }
    }

	return numero;
}


