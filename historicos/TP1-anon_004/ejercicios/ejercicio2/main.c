#include <stdbool.h>
#include <stdio.h>

#include "consola.h"
#include "estadistica.h"

static void mostrar_estadisticas(float acumulador, float promedio,
                                float minimo, float maximo)
{
    printf("Suma: %.2f\n", (double)acumulador);
    printf("Promedio: %.2f\n", (double)promedio);
    printf("Mínimo: %.2f\n", (double)minimo);
    printf("Máximo: %.2f\n", (double)maximo);
}

int main(void)
{
    bool continuar = false;
    do
    {
        int cantidad = 0;
        while (cantidad <= 0)
        {
            cantidad = leer_entero("Ingrese la cantidad de números a procesar: ");
            if (cantidad <= 0)
            {
                printf("La cantidad debe ser mayor a cero.\n");
            }
        }

        float acumulador_suma = 0.0f;
        float valor_minimo = 0.0f;
        float valor_maximo = 0.0f;

        for (int indice = 0; indice < cantidad; indice++)
        {
            float valor = leer_flotante("Ingrese un número: ");
            if (indice == 0)
            {
                acumulador_suma = valor;
                valor_minimo = valor;
                valor_maximo = valor;
            }
            else
            {
                acumulador_suma += valor;
                valor_minimo = actualizar_minimo(valor_minimo, valor);
                valor_maximo = actualizar_maximo(valor_maximo, valor);
            }
        }

        float promedio = calcular_promedio(acumulador_suma, cantidad);
        mostrar_estadisticas(acumulador_suma, promedio, valor_minimo, valor_maximo);

        continuar = leer_logico(
            "¿Desea procesar otra serie de números? (s/n): "
        );
    } while (continuar);

    return 0;
}
