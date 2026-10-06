/**
 * @file main.c
 * @brief Programa principal del Ejercicio 2.
 */

#include <stdio.h>
#include "estadistica.h"

int main(void)
{
    printf("Ejercicio 2: Estadísticas con punteros\n");
    int minimo = 0;
    int maximo = 0;
    int datos[] = {15, -3, 42, 8, 0, 99, -12, 24, 72};
    size_t cantidad = sizeof(datos) / sizeof(datos[0]);
    double promedio = 0.0;
    printf("---prueba obtener_min_max---\n");
    if(obtener_min_max(datos,cantidad,&minimo,&maximo))
    {
        printf("minimo hallado: %d \n", minimo);
        printf("maximo hallado: %d \n", maximo);
    }
    else
    {
        printf("-Error al calcular el minimo o el maximo\n");
    }

    printf("---Prueba Estadsitica---\n");
    if(calcular_estadisticas(datos, cantidad, &minimo, &maximo, &promedio));
    {
        printf("minimo: %d \n", minimo);
        printf("maximo: %d \n", maximo);
        printf("promedio: %f \n", promedio);
    }


    
    return 0;
}
