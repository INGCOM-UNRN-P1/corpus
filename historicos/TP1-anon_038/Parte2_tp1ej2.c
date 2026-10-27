
#include <stdio.h>
 
int suma_lenta(int numero, int otro_numero)
{
	int i = 0;
	
	while (i != otro_numero)
		{
		numero++;
		otro_numero--;
		printf("%d \n", numero);
		}
	
	return numero;
}

int main(int argc, char *argv[])
{
	int numero;
	int otro_numero;
	
	printf("Ingrese un numero NATURAL para hacer la suma lenta \n");
	scanf("%d", &numero);
	
	printf("Ingrese otro numero NATURAL para hacer la suma lenta \n");
	scanf("%d", &otro_numero);
	
	int resultado = suma_lenta (numero, otro_numero);
	
	printf("\n El resultado de la suma lenta es %d \n", resultado);
	
	
	
	return 0;
	
}
