
#include <stdio.h>

#define CADENA_CORTA -1
#define MAX_CADENA 100
#define ERROR_CADENA 0

int largo_cadena(char *cadena, int capacidad_cadena) // Funciona
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



int copiadora(char* origen, char* destino, int capacidad_destino)
{
    return 0;
}

int limpiadora(char* origen, char* destino, int capacidad_destino)
{
    char caracteres[] = "0123456789abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ"; // 59 caracteres
	int i, j;
	int y = 0;
	int borrar_caracter = 1;
	
	// i recorre la cadena, j recorre los caracteres, y recorre destino.
	
	for (i = 0; i <= MAX_CADENA; i++)
	{
		borrar_caracter = 1;
		
		for (j = 0; j <= 59; j++)
		{
			if (origen[i] != caracteres[j])
			{
				borrar_caracter = 0;
			}
			
			if (borrar_caracter)
			{
				if (y < capacidad_destino)
				{
					destino[y] = origen[i];
					printf("%c", destino[y]);
				}
				y++;
			}
		}
	}
	
    return 0;
}

int inversor(char* origen, char* destino, int capacidad_destino)
{
    int i, j = 0;
    int longitud_origen = largo_cadena(origen, MAX_CADENA);

    for (i = longitud_origen; i >= 0; i--)
    {	
		destino[j] = origen[i];
		j++;
		//printf("%c", destino[j]);
    };

    return 0;
}

int compara(char * primera, char * segunda) // Funciona
{
    int i;

    do 
    {
        for (i = 0; i < MAX_CADENA; i++)
        {
            if (primera[i] > segunda[i])
            {
                return 1;
            }
            else if (primera[i] < segunda[i])
            {
                return -1;
            }
        }
    }
    while (primera[i] != segunda[i]);

    return 0;
}

int es_palindromo(char* cadena, int largo) // Funciona
{
    int igualdad = 1;
    int oracion = 1;
    int i;
    largo = largo_cadena(cadena, MAX_CADENA);
    
    for (i = largo - 1; i >= 0; i--)
    {
        if (cadena[i] == cadena[oracion])
        {
            igualdad += 1;
            oracion += 1;
        }
    }
    if (largo_cadena(cadena, MAX_CADENA) == igualdad)
    {
        return 1;
    }
    else
    {
        return -1;
    }

    return 0;
}

int main()
{
    char * cadena = "anteojo";
    char * segunda_cadena = "antojo";
    char * no_alfa = "abc_____";
    char variable_destino[MAX_CADENA];
	char variable_destino_dos[MAX_CADENA];

    printf("\nBienvenido a mi codigo!\n");
    printf("\nCadena de caracteres ingresada: %s\n", cadena);
    printf("\nSegunda cadena de caracteres ingresada: %s\n", segunda_cadena);

    inversor(cadena, variable_destino_dos, MAX_CADENA);
    limpiadora(no_alfa, variable_destino, largo_cadena(no_alfa, MAX_CADENA));

    printf("\n---------- 1 = True // -1 = False // 0 = Igualdad ----------\n");
    printf("\nPalindromo: %d\n", es_palindromo(cadena, largo_cadena(cadena, MAX_CADENA)));
    printf("\nInversion: %s\n", variable_destino_dos);
    printf("\nComparacion: %d\n", compara(cadena, segunda_cadena));
    printf("\nLimpiadora: %s\n", variable_destino);

    return 0;
}