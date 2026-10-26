#include <stdbool.h>
#include <stdio.h>

#include "consola.h"
#include "conversor.h"

#define OPCION_CELSIUS_A_FAHRENHEIT 1
#define OPCION_FAHRENHEIT_A_CELSIUS 2

int main(void)
{
    bool continuar = false;

    do
    {
        int opcion;
        float temperatura;

        opcion = leer_entero_entre(
            "Elija opción:\n1. Celsius a Fahrenheit\n"
            "2. Fahrenheit a Celsius\nOpción: ",
            OPCION_CELSIUS_A_FAHRENHEIT,
            OPCION_FAHRENHEIT_A_CELSIUS
        );
        temperatura = leer_flotante("Ingrese la temperatura a convertir: ");

        if (opcion == OPCION_CELSIUS_A_FAHRENHEIT)
        {
            float res = celsius_a_fahrenheit(temperatura);
            printf("%.2f °C equivalen a %.2f °F\n", (double)temperatura, (double)res);
        }
        else
        {
            float res = fahrenheit_a_celsius(temperatura);
            printf("%.2f °F equivalen a %.2f °C\n", (double)temperatura, (double)res);
        }

        continuar = leer_logico("¿Desea realizar otra conversión? (s/n): ");
    } while (continuar);

    return 0;
}
