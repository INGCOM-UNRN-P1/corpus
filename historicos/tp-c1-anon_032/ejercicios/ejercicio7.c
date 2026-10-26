

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int es_primo(int numero)
// Precondiciones: El valor de entrada debe ser un entero
// Postcondiciones: Devolverá un 1 si el número ingresado es solo divisible por 1 y por si mismo, de caso contrario,
//                  devolverá un 0 si el número ingresado tiene más de 2 divisores
{
    int contadorDivisores = 0;
    for (int i = 1; i <= numero; i++)
    {
        if (numero % i == 0)
        {
            contadorDivisores++;
        }
    }
    if (contadorDivisores == 2)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main()
{
    int numero;
    int esPrimo;
    printf(ANSI_COLOR_CYAN "\nEjercicio 7: Números primos" ANSI_COLOR_RESET "\n");
    printf("Mediante el ingreso de un número, indicar si pertenece al grupo de los números primos\n\n");
    printf("Introduzca un número: ");
    fflush(stdout);
    scanf("%d", &numero);
    esPrimo = es_primo(numero);
    if (esPrimo == TRUE)
    {
        printf("El número %d es primo? %s\n", numero, ANSI_COLOR_GREEN "Verdadero");
    }
    else
    {
        printf("El número %d es primo? %s\n", numero, ANSI_COLOR_RED "Falso");
    }
    return 0;
}