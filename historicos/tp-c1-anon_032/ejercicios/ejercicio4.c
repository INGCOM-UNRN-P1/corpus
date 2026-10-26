

#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int compara(double numero, double otro_numero)
// Precondiciones: Los valores de entrada tienen que ser de tipo double y puede tener una presición de hasta 2 decimales
// Postcondiciones: Devolverá un 1 si el 1er número ingresado es mayor al 2do número ingresado,
//                  un -1 si el 1er número ingresado es menor al 2do número ingresado o
//                  un 0 si el 1er número ingresado es igual al 2do número ingresado
{
    if (numero - otro_numero > 0)
    {
        return 1;
    }
    else if (numero - otro_numero < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    double numero;
    double otro_numero;
    int comparacionNumeros;
    printf(ANSI_COLOR_CYAN "\nEjercicio 4: Comparación de números" ANSI_COLOR_RESET "\n");
    printf("Mediante el ingreso de dos números, indicar cúal es el mayor/menor o si son iguales\n\n");
    printf("Introduzca el 1er número: ");
    fflush(stdout);
    scanf("%lf", &numero);
    printf("Introduzca el 2do número: ");
    fflush(stdout);
    scanf("%lf", &otro_numero);
    comparacionNumeros = compara(numero, otro_numero);
    if (comparacionNumeros == 1)
    {
        printf("%.2f es mayor que %.2f\n", numero, otro_numero);
    }
    else if (comparacionNumeros == -1)
    {
        printf("%.2f es menor que %.2f\n", numero, otro_numero);
    }
    else
    {
        printf("%.2f y %.2f son iguales\n", numero, otro_numero);
    }
    return 0;
}