

#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int suma_lenta(int numero, int otro_numero)
// Precondiciones: Los valores de entrada tienen que ser de tipo entero
// Postcondiciones: Devolverá la suma entre los valores de entrada
{
    int suma = numero;
    if (otro_numero < 0)
    {
        for (int i = 0; i > otro_numero; i--)
        {
            suma--;
        }
    }
    else
    {
        for (int i = 0; i < otro_numero; i++)
        {
            suma++;
        }
    }
    return suma;
}

int main()
{
    int numero;
    int otro_numero;
    float numeroFloat;
    float otro_numeroFloat;
    int resultado;
    printf(ANSI_COLOR_CYAN "\nEjercicio 5: Suma lenta" ANSI_COLOR_RESET "\n");
    printf("Mediante el ingreso de dos números enteros, indicar la suma entre ellos\n\n");
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
        scanf("%f", &otro_numeroFloat);
        // Validación de número entero
        otro_numero = otro_numeroFloat;
        if (otro_numeroFloat - otro_numero)
        {
            printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero\n");
        }
        else
        {
            resultado = suma_lenta(numero, otro_numero);
            if (otro_numero >= 0)
            {
                printf("%d + %d = %d\n", numero, otro_numero, resultado);
            }
            else
            {
                printf("%d + (%d) = %d\n", numero, otro_numero, resultado);
            }
        }
    }
    return 0;
}