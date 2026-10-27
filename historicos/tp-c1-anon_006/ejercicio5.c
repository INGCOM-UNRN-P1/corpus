




#include <stdio.h>

int SumaLenta(int numero, int otro_numero);
 
int main () 
{
	int numero_uno;
	int numero_dos;
	int resultado;
   
	printf("\n");
	printf("Ingrese dos numeros enteros para ser sumados: \n");
	scanf("%d", &numero_uno);
	scanf("%d",&numero_dos);
		
	resultado = SumaLenta(numero_uno, numero_dos);
	printf("\nEl resultado de la suma lenta de %d y %d es %d.", numero_uno, numero_dos, resultado);
	printf("\n");
	
}

int SumaLenta(int numero, int otro_numero)
{
	int cantidad_sumas = otro_numero;
	
	if(otro_numero < 0)
	{
		cantidad_sumas *= -1;
	}
	
	for(int i = 0; i < cantidad_sumas; i++)
	{
		if (otro_numero >= 0)
		{
			numero += 1;
		}
		else
		{
			numero -= 1;
		}
	}
	return numero;
}