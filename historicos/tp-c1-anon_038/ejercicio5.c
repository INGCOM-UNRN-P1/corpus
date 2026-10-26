

#include <stdio.h>
#include <stdlib.h>
 
 
 
 
 
int suma_lenta(int numero, int otro_numero)
{
	int i = 0;
	
	while (i < abs(otro_numero))
		{
		if (numero<0 && otro_numero<0)
			{
			numero = numero - 1;
			i = i + 1;
			}\
		else if (numero<0 || otro_numero<0)
			{
				if (numero<0)
				{
					numero = numero + 1;
					i = i + 1;
				}
				else
				{
					numero = numero - 1;
					i = i + 1;
				}
			}
		else 
		{
			numero = numero + 1;
			i = i + 1;
		}
		}
	
	return numero;
}

int main(int argc, char *argv[])
{
	int numero;
	int otro_numero;
	
	printf("Ingrese un numero para hacer la suma lenta \n");
	scanf("%d", &numero);
	
	printf("Ingrese otro numero para hacer la suma lenta \n");
	scanf("%d", &otro_numero);
	
	int resultado = suma_lenta (numero, otro_numero);
	
	printf("El resultado de la suma lenta es %d \n", resultado);
	
	
	
	return 0;
	
}