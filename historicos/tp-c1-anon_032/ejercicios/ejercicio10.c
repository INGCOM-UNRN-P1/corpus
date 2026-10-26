

#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int factorial(int numero)
// Precondiciones: El valor de entrada debe ser de tipo entero mayor o igual a 0
// Postcondiciones: Devolverá el factorial del número ingresado
{
    int factorial;
    if (numero == 0)
    {
        return 1;
    }
    else
    {
        factorial = numero;
        for (int i = 1; i < numero; i++)
        {
            factorial = factorial * i;
        }
        return factorial;
    }
}

int main()
{
    int numero;
    float numeroFloat;
    int resultado;
    printf(ANSI_COLOR_CYAN "\nEjercicio 10: Factorial" ANSI_COLOR_RESET "\n");
    printf("Mediante el ingreso de un número entero positivo, indicar si su factorial\n\n");
    printf("Introduzca un número: ");
    fflush(stdout);
    scanf("%f", &numeroFloat);
    // Validación de número entero
    numero = numeroFloat;
    if (numeroFloat - numero && numero < 0)
    {
        printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero positivo\n");
    }
    else if (numeroFloat - numero)
    {
        printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero\n");
    }
    else
    {
        // Validación mayor o igual a 0
        if (numero >= 0)
        {
            resultado = factorial(numero);
            printf("!%d = %d\n", numero, resultado);
        }
        else
        {
            printf(ANSI_COLOR_RED "Error! Debes ingresar un número positivo\n");
        }
    }
    return 0;
}