/**
 * @file main.c
 * @brief Programa principal del Ejercicio 3.
 */

#include <limits.h>
#include <stdio.h>
#include "recorrido.h"

#define CAPACIDAD_MAXIMA 10
#define TAMANO_LINEA 64

static bool leer_entero(const char *mensaje, int minimo, int maximo,
                        int *valor);
static size_t leer_arreglo(int *arreglo, size_t capacidad);
static void imprimir_arreglo(const char *titulo, const int *arreglo,
                             size_t cantidad);

int main(void)
{
    printf("Ejercicio 3: Recorrido e inversión con punteros\n");

    int original[CAPACIDAD_MAXIMA] = {0};
    int copia[CAPACIDAD_MAXIMA] = {0};

    size_t cantidad = leer_arreglo(original, CAPACIDAD_MAXIMA);
    if (cantidad == 0)
    {
        printf("No se ingresaron datos.\n");
        return 0;
    }

    imprimir_arreglo("Original", original, cantidad);
    if (copiar_arreglo(copia, original, cantidad) == true)
    {
        imprimir_arreglo("Copia", copia, cantidad);
    }

    invertir_arreglo(copia, cantidad);
    imprimir_arreglo("Copia invertida", copia, cantidad);
    imprimir_arreglo("Original (sin cambios)", original, cantidad);

    return 0;
}

/**
 * Pide un número entero por consola hasta que se ingrese uno válido
 * dentro del rango [minimo, maximo].
 *
 * @param mensaje Texto que se muestra antes de cada lectura.
 * @param minimo  Menor valor aceptado.
 * @param maximo  Mayor valor aceptado.
 * @param valor   Parámetro de salida donde se guarda el número leído.
 *
 * @pre mensaje != NULL, valor != NULL y minimo <= maximo.
 *
 * @returns true si leyó un número válido; false si se terminó la entrada.
 */
static bool leer_entero(const char *mensaje, int minimo, int maximo,
                        int *valor)
{
    char linea[TAMANO_LINEA] = "";
    bool leido = false;
    bool hay_entrada = true;
    while (leido == false && hay_entrada == true)
    {
        printf("%s", mensaje);
        if (fgets(linea, TAMANO_LINEA, stdin) == NULL)
        {
            hay_entrada = false;
        }
        else
        {
            int numero = 0;
            bool es_numero = sscanf(linea, "%d", &numero) == 1;
            bool en_rango = numero >= minimo && numero <= maximo;
            if (es_numero == true && en_rango == true)
            {
                *valor = numero;
                leido = true;
            }
            else
            {
                printf("Valor inválido: ingrese un entero entre %d y %d.\n",
                       minimo, maximo);
            }
        }
    }
    return leido;
}

/**
 * Pide al usuario la cantidad de elementos y luego cada uno de ellos,
 * guardándolos en el arreglo con aritmética de punteros.
 *
 * @param arreglo   Arreglo donde se guardan los números.
 * @param capacidad Máxima cantidad de elementos que entran en el arreglo.
 *
 * @pre arreglo tiene al menos 'capacidad' elementos y
 *      0 < capacidad <= INT_MAX.
 *
 * @returns La cantidad de elementos cargados, o 0 si se terminó la entrada.
 */
static size_t leer_arreglo(int *arreglo, size_t capacidad)
{
    int cantidad = 0;
    bool hay_entrada = leer_entero("Cantidad de números: ", 1,
                                   (int)capacidad, &cantidad);

    int *fin = arreglo + cantidad;
    for (int *actual = arreglo; actual < fin && hay_entrada == true;
         actual++)
    {
        hay_entrada = leer_entero("Número: ", INT_MIN, INT_MAX, actual);
    }

    size_t cargados = 0;
    if (hay_entrada == true)
    {
        cargados = (size_t)cantidad;
    }
    return cargados;
}

/**
 * Muestra un arreglo de enteros por salida estándar.
 *
 * @param titulo   Texto que se imprime antes de los elementos.
 * @param arreglo  Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos a mostrar.
 *
 * @pre titulo != NULL y arreglo tiene al menos 'cantidad' elementos.
 */
static void imprimir_arreglo(const char *titulo, const int *arreglo,
                             size_t cantidad)
{
    printf("%s:", titulo);
    const int *fin = arreglo + cantidad;
    for (const int *actual = arreglo; actual < fin; actual++)
    {
        printf(" %d", *actual);
    }
    printf("\n");
}
