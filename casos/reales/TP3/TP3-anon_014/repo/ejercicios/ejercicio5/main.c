/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

#define CAPACIDAD_TEXTO 32

static bool leer_linea(const char *mensaje, char *buffer, size_t capacidad);

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");

    char primero[CAPACIDAD_TEXTO] = "";
    char segundo[CAPACIDAD_TEXTO] = "";
    bool hay_datos = leer_linea("Primer texto: ", primero, CAPACIDAD_TEXTO);
    if (hay_datos == true)
    {
        hay_datos = leer_linea("Segundo texto: ", segundo, CAPACIDAD_TEXTO);
    }
    if (hay_datos == false)
    {
        printf("No se ingresaron datos.\n");
        return 0;
    }

    char destino[CAPACIDAD_TEXTO] = "";
    if (copiar_con_punteros(destino, CAPACIDAD_TEXTO, primero) == true)
    {
        printf("Copia: \"%s\" (longitud %zu)\n", destino,
               longitud_con_punteros(destino, CAPACIDAD_TEXTO));
    }

    bool entro = concatenar_con_punteros(destino, CAPACIDAD_TEXTO, segundo);
    printf("Concatenada: \"%s\" (longitud %zu)\n", destino,
           longitud_con_punteros(destino, CAPACIDAD_TEXTO));
    if (entro == false)
    {
        printf("El resultado se truncó a %d bytes.\n", CAPACIDAD_TEXTO);
    }

    return 0;
}

/**
 * Lee una línea de texto por consola con fgets y le quita el salto de
 * línea final.
 *
 * @param mensaje   Texto que se muestra antes de la lectura.
 * @param buffer    Buffer donde se guarda el texto leído.
 * @param capacidad Tamaño total del buffer, incluido el '\0'.
 *
 * @pre mensaje != NULL, buffer tiene al menos 'capacidad' bytes y
 *      capacidad > 1.
 *
 * @returns true si leyó una línea; false si se terminó la entrada.
 *
 * @post Si retorna true, buffer queda terminado en '\0' y sin '\n'.
 */
static bool leer_linea(const char *mensaje, char *buffer, size_t capacidad)
{
    printf("%s", mensaje);
    bool leida = fgets(buffer, (int)capacidad, stdin) != NULL;
    if (leida == true)
    {
        char *actual = buffer;
        while (*actual != '\0' && *actual != '\n')
        {
            actual++;
        }
        if (*actual == '\n')
        {
            *actual = '\0';
        }
        else
        {
            // La línea no entró completa: se descarta el resto para que no
            // aparezca en la próxima lectura.
            int caracter = getchar();
            while (caracter != '\n' && caracter != EOF)
            {
                caracter = getchar();
            }
        }
    }
    return leida;
}
