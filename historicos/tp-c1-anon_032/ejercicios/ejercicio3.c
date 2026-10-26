

#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int signo(double numero)
// Precondiciones: El valor de entrada tiene que ser de tipo double y puede tener una presición de hasta 2 decimales
// Postcondiciones: Devolverá un 0 si el número ingresado es 0, un 1 si es positivo o un -1 si es negativo
{
    if (numero == 0)
    {
        return 0;
    }
    else if (numero > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    double numero;
    int signoNumero;
    printf(ANSI_COLOR_CYAN "\nEjercicio 3: Números positivos y negativos" ANSI_COLOR_RESET "\n");
    printf("Mediante el ingreso de un número, indicar si el mismo es positivo, negativo o cero\n\n");
    printf("Introduzca un número: ");
    fflush(stdout);
    scanf("%lf", &numero);
    signoNumero = signo(numero);
    if (signoNumero == 0)
    {
        printf("%.2f es cero\n", numero);
    }
    else if (signoNumero == 1)
    {
        printf("%.2f es positivo\n", numero);
    }
    else
    {
        printf("%.2f es negativo\n", numero);
    }
    return 0;
}