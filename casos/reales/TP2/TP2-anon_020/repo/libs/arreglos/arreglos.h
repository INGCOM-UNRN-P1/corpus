/**
 * @file arreglos.h
 * @brief Biblioteca de manipulación y procesamiento de arreglos de enteros (int).
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * - Nombres de variables y parámetros descriptivos, de hasta dos palabras,
 *   sin abreviaturas y con un máximo de 12 caracteres.
 * - Todo arreglo viene acompañado por su cantidad de elementos válidos (size_t cantidad).
 * - Arreglos de solo lectura (const int arreglo[]) para funciones que no modifican datos.
 * - Arreglos mutables (int arreglo[]) para funciones que modifican contenido in-place.
 */

#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * =========================================================================
 * Ejercicio 1: Sumatoria de Elementos
 * =========================================================================
 * @brief Calcula la suma algebraica de los elementos de un arreglo de enteros.
 *
 * @param arreglo Puntero al primer elemento del arreglo de enteros. Puede
 *                ser NULL para indicar ausencia de datos.
 * @param cantidad Número de elementos válidos en el arreglo. Debe ser el
 *                 número máximo a leer desde "arreglo".
 *
 * @pre Si "arreglo" no es NULL, entonces "arreglo" debe apuntar a un bloque
 *      válido de al menos "cantidad" elementos. "cantidad" describe la
 *      cantidad de elementos lógicos a procesar. No hay efectos si
 *      "cantidad" == 0.
 * @post No modifica el arreglo de entrada.
 *
 * @return La suma algebraica de los elementos como "long long". Retorna 0 si
 *         "arreglo" == NULL o "cantidad" == 0.
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);

/**
 * =========================================================================
 * Ejercicio 2: Búsqueda Lineal
 * =========================================================================
 * @brief Busca la primera ocurrencia de un valor entero en un arreglo.
 *
 * @param arreglo Puntero al arreglo donde se realiza la búsqueda. Puede ser
 *                NULL para indicar ausencia de datos.
 * @param cantidad Cantidad de elementos válidos en "arreglo".
 * @param buscado Valor entero a localizar en el arreglo.
 *
 * @pre Si "arreglo" != NULL, entonces "arreglo" debe apuntar a al menos
 *      "cantidad" elementos.
 * @post No modifica el arreglo.
 *
 * @return Índice (base 0) de la primera aparición de "buscado". Retorna -1 si
 *         "arreglo" == NULL, "cantidad" == 0 o si el valor no está presente.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);

/**
 * =========================================================================
 * Ejercicio 3: Inversión In-Place
 * =========================================================================
 * @brief Invierte el orden de los elementos de un arreglo en su misma memoria.
 *
 * @param arreglo Arreglo de enteros a invertir. Si es NULL no se realiza
 *                ninguna operación.
 * @param cantidad Cantidad de elementos válidos en "arreglo".
 *
 * @pre Si "arreglo" != NULL, apunta a al menos "cantidad" elementos.
 * @post El arreglo queda con sus elementos en orden inverso respecto al
 *       inicial (se intercambian "arreglo[i]" y "arreglo[cantidad - 1 - i]").
 *       Si "cantidad" <= 1 no se modifica nada.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);

/**
 * =========================================================================
 * Ejercicio 4: Verificación de Orden Ascendente
 * =========================================================================
 * @brief Comprueba si los elementos del arreglo están ordenados en forma
 *        ascendente no estricta (<=) por parejas contiguas.
 *
 * @param arreglo Arreglo a verificar. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en "arreglo".
 *
 * @pre Si "arreglo" != NULL, apunta a al menos "cantidad" elementos.
 * @post No modifica el arreglo.
 *
 * @return "true" si el arreglo está ordenado ascendentemente o si
 *         "cantidad" <= 1. Retorna "false" si "arreglo" == NULL o se detecta
 *         algún par contiguo fuera de orden.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);

/**
 * =========================================================================
 * Ejercicio 5: Conteo de Ocurrencias
 * =========================================================================
 * @brief Cuenta cuántas veces aparece un valor entero dentro del arreglo.
 *
 * @param arreglo Arreglo donde se realiza el conteo. Puede ser NULL.
 * @param cantidad Cantidad de elementos válidos en "arreglo".
 * @param buscado Valor entero a contabilizar.
 *
 * @pre Si "arreglo" != NULL, apunta a al menos "cantidad" elementos.
 * @post No modifica el arreglo.
 *
 * @return Número de ocurrencias de "buscado" dentro del arreglo. Retorna 0 si
 *         "arreglo" == NULL o "cantidad" == 0.
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);

/**
 * =========================================================================
 * Ejercicio 6: Compactación In-Place
 * =========================================================================
 * @brief Elimina todas las apariciones de "valor" dentro de "arreglo",
 *        compactando los elementos restantes hacia el inicio y preservando su
 *        orden relativo. La operación se realiza in-place sin asignar memoria
 *        dinámica.
 *
 * @param arreglo Arreglo que será modificado in-place. Si es NULL no hace
 *                nada.
 * @param cantidad Cantidad de elementos válidos en "arreglo".
 * @param valor Entero a eliminar del arreglo.
 *
 * @pre Si "arreglo" != NULL, apunta a al menos "cantidad" elementos.
 * @post Los "cantidad" primeros elementos del arreglo pueden haber sido
 *       reordenados para compactarlos; la función devuelve la nueva cantidad
 *       lógica de elementos válidos. No se modifica la memoria más allá de los
 *       "cantidad" elementos originales.
 *
 * @return Nueva cantidad de elementos válidos después de eliminar "valor".
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);
/**
 * =========================================================================
 * Ejercicio 7: Fusión Ordenada
 * =========================================================================
 * @brief Fusiona dos arreglos ordenados ascendentemente "primero" y "segundo"
 *        en el arreglo "destino", manteniendo el orden ascendente sin
 *        sobrepasar la "capacidad" del destino.
 *
 * @param primero Arreglo ordenado ascendentemente; puede ser NULL si
 *                "cantidad_uno" == 0.
 * @param cantidad_uno Número de elementos válidos en "primero".
 * @param segundo Arreglo ordenado ascendentemente; puede ser NULL si
 *                "cantidad_dos" == 0.
 * @param cantidad_dos Número de elementos válidos en "segundo".
 * @param destino Búfer donde se escribirá la fusión. No debe ser NULL si
 *                el resultado requiere escribir al menos un elemento.
 * @param capacidad    Capacidad máxima (en elementos) del arreglo "destino".
 *
 * @pre Si "primero" != NULL debe apuntar a al menos "cantidad_uno" elementos.
 *      Si "segundo" != NULL debe apuntar a al menos "cantidad_dos" elementos.
 *      Si "capacidad" > 0 y se esperan elementos de salida, "destino" debe
 *      ser un búfer válido.
 * @post Se escriben en "destino" hasta "capacidad" elementos de la fusión
 *       mantenida ordenada. Si la suma de elementos supera "capacidad", solo
 *       se copian los primeros "capacidad" elementos del resultado ordenado.
 *
 * @return Cantidad de elementos escritos en "destino".
 */
size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad);
#endif 
