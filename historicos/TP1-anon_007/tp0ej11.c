
//Leí que decía numeros naturales cuando ya lo había hecho.
#include <stdio.h>
int suma_lenta(int numero, int otro_numero);
int main(int argc, char *argv[])
{
	int numero;
	int otro_numero;
	int resultado;
	printf("Ingrese un numero: ");
	fflush(stdout);
	scanf("%d", &numero);
	printf("Ingrese otro numero: ");
	fflush(stdout);
	scanf("%d", &otro_numero);
	resultado = suma_lenta(numero, otro_numero);
	printf("El resultado de la suma lenta es: %d", resultado);
}
int suma_lenta(int numero, int otro_numero)
{
	int resultado = 0;
	int i = 0;
	int mayor = 0;
	int menor = 0;
	int es_negativo = 0;
	if (numero > 0 && otro_numero > 0)
	{
		menor = numero * (-1);
		mayor = otro_numero;
	}
	else
	{
		if (numero > 0 && otro_numero < 0)
		{
			if (numero > otro_numero * (-1))
			{
				menor = otro_numero * (-1);
				mayor = numero;
			}
			else
			{
				mayor = otro_numero * (-1);
				menor = numero;
				es_negativo = 1;
			}
		}
		else
		{
			if (numero < 0 && otro_numero < 0)
			{
				mayor = otro_numero * (-1);
				menor = numero;
				es_negativo = 1;
			}
			else
			{
				if (numero * (-1) > otro_numero)
				{
					mayor = numero * (-1);
					menor = otro_numero;
					es_negativo = 1;
				}
				else
				{
					menor = numero * (-1);
					mayor = otro_numero;	
				}
			}
		}
	}
	for (menor; menor < mayor; menor++)
	{
		i++;
	}
	resultado = i;
	if (es_negativo == 1)
	{
		resultado = resultado * (-1);
	}
	return resultado;
}