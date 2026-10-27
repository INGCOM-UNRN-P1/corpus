
#define MAX_CADENA 100
#include <stdio.h>
#include <string.h>
char * linea(int numero);
int main(int argc, char *argv[])
{
	int numero = 0;
	while(1)
	{
		printf("Ingrese un numero: ");
		fflush(stdout);
		scanf("%d", &numero);
		if(numero > 0)
			break;
		else
		{
			printf("El numero no puede ser negativo ni 0");
		}
	}
	//char * mostrar = linea(numero);
	//printf("%s", mostrar);
	linea(numero);
}
char * linea(int numero)
{
    char linea_asteriscos[MAX_CADENA];
    for (int i = 0; i < numero; i++)
    {
        linea_asteriscos[i] = '*';
    }
	linea_asteriscos[numero] = '\0';
    char * retornar = linea_asteriscos;
	printf("%s", retornar);
    return 0;
}