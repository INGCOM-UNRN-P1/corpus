
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1 //codigo de error
#define MAXIMO 10
#define CAPACIDAD_MAX 20

int largo_seguro(char *str, int capacidad);

int main()
{
	char cadena[CAPACIDAD_MAX];
	int retorno = 0;
	int capacidad = MAXIMO;
	
	
	printf("Ingrese una cadena de caracteres: ");
	fgets(cadena, MAXIMO, stdin);

	retorno = largo_seguro(cadena, capacidad);
	
	printf("El largo de la cadena es: %d\n",retorno);
}




int largo_seguro(char *str, int capacidad)
{
	int contador = 0;
	
	while ((contador < capacidad) && (*str != '\0'))
	{
		contador++;
		str = str + 1;
		printf("Cadena: %s\n",str);
	
	}
	
	if (contador == CAPACIDAD_MAX)
	{
		contador = CADENA_SIN_TERMINADOR;
	}
	
	return contador;
	
	
}