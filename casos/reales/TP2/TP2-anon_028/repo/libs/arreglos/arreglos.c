/**
 * @file arreglos.c
 * @brief Esqueleto de implementación para la biblioteca libarreglos.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Las funciones provistas son esqueletos iniciales para ser completados
 * íntegramente por los estudiantes como parte de la entrega.
 */

#include "arreglos.h"
#include <stddef.h>
#include <stdbool.h>

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0){
        return 0;
    }
    long long suma = 0;
    for (size_t i = 0; i < cantidad; i++){
        suma += arreglo[i];
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad == 0){
        return -1;
    }
    for (size_t i = 0; i < cantidad; i++){
        if (arreglo[i] == buscado){
            return (int)i;
        }
        
    }
    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad <= 1){
        return;
    }
    size_t i = 0;
    size_t j = cantidad - 1;
    while (i < j){
        int temp = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = temp;
        i++;
        j--;
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL){
        return false;
    }
    if (cantidad <= 1){
        return true;
    }
    for (size_t i =0; i < cantidad - 1; i++){
        if (arreglo [i] > arreglo[i + 1]){
            return false;
        }
    }
    return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad == 0){
        return 0;
    }
    size_t contador = 0;
    for (size_t i = 0; i < cantidad; i++){
        if (arreglo[i] == buscado){
            contador++;
        }
    }
    return contador;
}


size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor){
    if (arreglo == NULL || cantidad == 0){
        return 0;
    }
    size_t nueva_cantidad = 0;
    for (size_t i = 0; i < cantidad; i++){
        if (arreglo[i] != valor){
            arreglo[nueva_cantidad] = arreglo[i];
            nueva_cantidad++;
        }
    }
    return nueva_cantidad;
}

size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad){
    if (destino == NULL || capacidad == 0){
        return 0;
    }
    size_t indice_arreglo_primero = 0;
    size_t indice_arreglo_segundo = 0;
    size_t indice_arreglo_destino = 0;

    if (primero != NULL && segundo != NULL){
        while (indice_arreglo_primero < cantidad_uno && indice_arreglo_segundo < cantidad_dos && indice_arreglo_destino < capacidad){
            if (primero[indice_arreglo_primero] <= segundo[indice_arreglo_segundo]){
                destino[indice_arreglo_destino] = primero[indice_arreglo_primero];
                indice_arreglo_primero++;
            } else {
                destino[indice_arreglo_destino] = segundo[indice_arreglo_segundo];
                indice_arreglo_segundo++;
            }
            indice_arreglo_destino++;
        }
    }
    
    if (primero != NULL){
        while (indice_arreglo_primero < cantidad_uno && indice_arreglo_destino < capacidad){
            destino[indice_arreglo_destino] = primero[indice_arreglo_primero];
            indice_arreglo_primero++;
            indice_arreglo_destino++;
        }
    }

    if (segundo != NULL){
        while (indice_arreglo_segundo < cantidad_dos && indice_arreglo_destino < capacidad){
            destino[indice_arreglo_destino] = segundo[indice_arreglo_segundo];
            indice_arreglo_segundo++;
            indice_arreglo_destino++;
        }
    }
    return indice_arreglo_destino;
}