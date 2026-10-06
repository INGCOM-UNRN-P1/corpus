#include <stdio.h>
#include "texto.h"
#include "cadenas.h"

int main(void)
{
    char mensaje[64];

    printf("=== Ejercicio 2: Demo de Cadenas Seguras ===\n");

    bool exito = unir_con_separador(
        mensaje,
        sizeof(mensaje),
        "Programacion 1",
        "UNRN 2026",
        " - "
    );

    if (exito)
    {
        printf("Cadena unida: %s\n", mensaje);
    }

    size_t conteo = cadena_a_mayusculas(
        mensaje,
        sizeof(mensaje)
    );

    printf(
        "En mayusculas: %s (modificados: %zu)\n",
        mensaje,
        conteo
    );

    printf(
        "Longitud segura: %zu\n",
        cadena_longitud(mensaje, sizeof(mensaje))
    );

    
    char limitado[10];

    bool resultado = unir_con_separador(
        limitado,
        sizeof(limitado),
        "TextoLargo",
        "MasTexto",
        "::"
    );

    printf(
        "Intento en buffer de 10 bytes: '%s' (exito: %s)\n",
        limitado,
        resultado ? "si" : "no (truncado)"
    );

    return 0;
}