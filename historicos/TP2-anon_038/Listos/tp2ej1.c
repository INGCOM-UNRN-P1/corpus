
#include <stdio.h>

int parte_entera(int numero)
{
	float temp, raiz = 0;
	raiz = numero / 2;
	temp = 0;
	
	while (raiz != temp)
		{
		temp = raiz;
		raiz = (numero/temp + temp) / 2;
		}
	return raiz;
}
 
 
int main(int argc, char *argv[])
{
	int numero = 0;
	
	printf("Ingrese un numero \n # ");
	scanf("%d", &numero);

	int resultado_parte_entera = parte_entera(numero);
	
	printf("La parte entera de la raiz de %d es %d \n", numero, resultado_parte_entera);
	
}

