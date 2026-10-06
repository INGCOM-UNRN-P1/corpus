#include <stdbool.h>
#include <stdio.h>

#include "consola.h"
#include "fecha.h"

int main(void)
{
    bool continuar = false;

    do
    {
        int anio = leer_entero("Ingrese año (ej: 2026): ");
        int mes = leer_entero_entre("Ingrese mes (1-12): ", 1, 12);
        int dia = leer_entero_entre("Ingrese día (1-31): ", 1, 31);

        if (es_fecha_valida(dia, mes, anio))
        {
            printf("La fecha %02d/%02d/%d es válida.\n", dia, mes, anio);
        }
        else
        {
            printf("La fecha %02d/%02d/%d NO es válida.\n", dia, mes, anio);
        }

        if (es_bisiesto(anio))
        {
            printf("El año %d es bisiesto.\n", anio);
        }
        else
        {
            printf("El año %d no es bisiesto.\n", anio);
        }

        continuar = leer_logico("¿Desea validar otra fecha? (s/n): ");
    } while (continuar);

    return 0;
}
