

#include <stdio.h>
#include <string.h>

#define MAX_CADENA 32
#define MAX_LINEAS 32
#define CADENA_CORTA -1

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

int dividirLinea(char * cadena, int capacidad_cadena, char resultado[MAX_LINEAS][MAX_CADENA], int cant_cadenas, int cantidad_filas, int * posiciones)
{
    int i, j;
    int fila = 1;
    int caracter = 0;

    if (cant_cadenas <= 1)
    {
        for (i = 0; i <= capacidad_cadena + 1; i++)
        {
            resultado[0][i] = cadena[i];
        }
    }
    else 
    {
        for (i = 0;i < posiciones[0] && i < capacidad_cadena + 1; i++)
        {
            resultado[0][i] = cadena[i];
            caracter++;
        }

        resultado[0][caracter] = '\0';
        caracter = 0;

        for (i = 0; i < cantidad_filas - 1; i++)
        {
            for (j = posiciones[i] + 1; j < posiciones[i + 1] && j <= posiciones[i] + capacidad_cadena + 1; j++)
            {
                resultado[fila][caracter] = cadena[j];
                caracter++;
            }

            resultado[fila][caracter] = '\0';
            fila++;
            caracter = 0;
        }
    }

    return 0;
}

int busca_cadenas(char * cadena, int capacidad_cadena, int * posiciones)
{
    int espacio = 0;
    int i;

    for (i = 0; i < capacidad_cadena; i++)
    {
        if (cadena[i] == '\n')
        {
            posiciones[espacio] = i;
            espacio++;
        }
    }

    return espacio;
}

int main()
{
    int cantidad_espacios;
    char cadena[MAX_CADENA] = "Hola mundo!";
    int posiciones[MAX_CADENA];
    int i;

    cantidad_espacios = busca_cadenas(cadena, MAX_CADENA, posiciones);

    char resultado[cantidad_espacios][MAX_CADENA];

    dividirLinea(cadena, MAX_CADENA, resultado, cantidad_espacios, MAX_LINEAS, posiciones);

    for (i = 0; i < cantidad_espacios; i++)
    {
        printf("%s\n", resultado[i]);
    }

    return 0;
}