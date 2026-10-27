 


#include <stdio.h>

#define MAX_LEN 50
#define MAX_STRINGS 4
#define MAX_CARACTERES 7


int largo_cadena(char *cadena, int capacidad_cadena)
{
        int len;
        int i = 0;

        for (len = 0; len < capacidad_cadena; i++)
        {
            if (cadena[i] == '\0')
            {
                break;
            }
            else
            {
                len++;
            }
        }
        return len;
}

void division_cadena(char *cadena, int capacidad_cadena, char *array[MAX_STRINGS])
{
	char *caracter;

	int booleano = 0;
	int pos_array = 0;

	for (int i = 0; i < capacidad_cadena; i++)
	{
		if (cadena[i] != '_')
		{
			if (booleano == 0)
			{
				caracter = &cadena[i];
				array[pos_array] = caracter;
				booleano = 1;
				pos_array++;
			}
		}
		else
		{
			booleano = 0;
		}
	}
}

int main(int argc, char* argv[])
{
	char *lista[MAX_STRINGS];
	char *puntero;

	int largo;

	if (argc > 2)
	{
		printf("Solo se debe ingresar un string!\n");
	}
	else if (argc == 1)
	{
		printf("Se debe ingresar el texto!\n");
	}
	else
	{
		largo = largo_cadena(argv[1], MAX_LEN);
		division_cadena(argv[1], largo, lista);
	}

	for (int i = 0; i < MAX_STRINGS; i++)
	{
		puntero = lista[i];
		for (int x = 0; x < MAX_CARACTERES; x++)
		{
			if (*puntero != '_')
			{
				printf("%c", *puntero);
				puntero++;
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}

    return 0;
}

