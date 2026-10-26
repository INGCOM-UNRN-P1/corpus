/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * Hanchut -- anon_034
 *************************/
 
#include <stdio.h>

#define CADENA_CORTA -1
#define MAX_CADENA 100


int largo_cadena(char *cadena, int capacidad_cadena)
{
    capacidad_cadena = 0;

    if (cadena[capacidad_cadena] != 0)
    {
        while (cadena[capacidad_cadena] != 0)
        {
            capacidad_cadena++;
        }
    }
    else 
    {
        return CADENA_CORTA;
    }

    return capacidad_cadena;
}

char * busqueda(char * cadena, int largo, char * busqueda)
{
	int i, j;
	int coinciden;
	int largo_busqueda = largo_cadena(busqueda, MAX_CADENA);
		
	for (i = 0; i < largo; i++)
	{
		coinciden = 1;
		
		for (j = 0; j < largo_busqueda; j++)
		{
			if (cadena[i + j] != busqueda[j])
			{
				coinciden = 0;
				break;
			}
		}
		if (coinciden == 1)
		{
			return &cadena[i];
		}
	}

	return NULL; // por si no se encontro la palabra buscada.
}

int main()
{
    char cadena[MAX_CADENA] = "Hola MundMundo!";
    char palabra[MAX_CADENA] = "Mundo";
    char * resultado;

	printf("\nCadena ingresada: %s\n", cadena);
	printf("\nPalabra buscada: %s\n", palabra);

    resultado = busqueda(cadena, MAX_CADENA, palabra);

    printf("\nRESULTADO: %s\n", resultado);

  return 0;
}