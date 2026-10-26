#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "cajero.h"
#include "consola.h"

static void mostrar_desglose(int monto)
{
    const int denominaciones[] = {
        BILLETE_20000,
        BILLETE_10000,
        BILLETE_5000,
        BILLETE_2000,
        BILLETE_1000,
        BILLETE_500,
        BILLETE_200,
        BILLETE_100
    };
    const size_t total_denominaciones = sizeof(denominaciones)
                                      / sizeof(denominaciones[0]);
    size_t i = 0;
    int remanente = monto;

    printf("\nDesglose para $%d:\n", monto);
    for (i = 0; i < total_denominaciones; ++i)
    {
        int cant = calcular_cantidad_billetes(remanente, denominaciones[i]);
        remanente = calcular_resto_monto(remanente, denominaciones[i]);
        printf("  Billetes de $%5d: %d\n", denominaciones[i], cant);
    }
    printf("\n");
}

static void procesar_retiro(void)
{
    int monto = leer_entero("Ingrese el monto a retirar ($): ");

    if (es_monto_valido(monto))
    {
        mostrar_desglose(monto);
    }
    else
    {
        printf("Monto inválido. Debe ser mayor a 0 y múltiplo de %d.\n",
               DENOMINACION_MINIMA);
    }
}

int main(void)
{
    bool continuar = false;

    do
    {
        procesar_retiro();
        continuar = leer_logico("¿Desea realizar otra operación? (s/n): ");
    } while (continuar);

    return 0;
}
