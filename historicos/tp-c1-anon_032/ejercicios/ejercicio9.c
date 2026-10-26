

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int es_multiplo(int numero, int multiplo)
// Precondiciones: Los valores de entrada tienen que ser de tipo entero
// Postcondiciones: Devolverá un 1 si la división "multiplo"/"numero" da resto 0, de caso contrario,
//                  devolverá un 0 si la división da un resto distinto de 0
{
    int resto = multiplo;
    if (numero == 0)
    {
        return TRUE;
    }
    else
    {
        resto = multiplo;
        if (multiplo > 0 && numero > 0)
        {
            while (resto >= numero)
            {
                resto = resto - numero;
            }
        }
        else if (multiplo < 0 && numero > 0)
        {
            while (resto <= numero * -1)
            {
                resto = resto + numero;
            }
        }
        else if (multiplo > 0 && numero < 0)
        {
            while (resto >= numero * -1)
            {
                resto = resto + numero;
            }
        }
        else if (multiplo < 0 && numero < 0)
        {
            while (resto <= numero)
            {
                resto = resto - numero;
            }
        }
        if (resto == 0)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}

int main()
{
    int numero;
    int multiplo;
    float numeroFloat;
    float multiploFloat;
    printf(ANSI_COLOR_CYAN "\nEjercicio 9: Multiplos de" ANSI_COLOR_RESET "\n");
    printf("Mediante el ingreso de dos números enteros, indicar si el 1ro es un múltiplo del 2do\n\n");
    printf("1ro: Ingresar un número entero cualquiera\n2do: Ingresar el número entero que desea averiguar si es multiplo del 1er número\n\n");
    printf("Introduzca el 1er número: ");
    fflush(stdout);
    scanf("%f", &numeroFloat);
    // Validación de número entero
    numero = numeroFloat;
    if (numeroFloat - numero)
    {
        printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero\n");
    }
    else
    {
        printf("Introduzca el 2do número: ");
        fflush(stdout);
        scanf("%f", &multiploFloat);
        multiplo = multiploFloat;
        if (multiploFloat - multiplo)
        {
            printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero\n");
        }
        else
        {
            if (es_multiplo(numero, multiplo) == TRUE)
            {
                printf("El número %d es multiplo de %d? %s\n", multiplo, numero, ANSI_COLOR_GREEN "Verdadero");
            }
            else
            {
                printf("El número %d es multiplo de %d? %s\n", multiplo, numero, ANSI_COLOR_RED "Falso");
            }
        }
    }
    return 0;
}