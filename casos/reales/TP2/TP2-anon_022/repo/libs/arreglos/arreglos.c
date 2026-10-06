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

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    if(arreglo == NULL || cantidad == 0){
        return 0;
    }

    long long acumulador = 0;

    for(size_t i = 0; i < cantidad; i++){
        acumulador += arreglo[i];
    }

    return acumulador;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    if(arreglo == NULL){
        return -1;
    }

    for(size_t i = 0; i < cantidad; i++){
        if(arreglo[i] == buscado){
            return i;
        }
    }
    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    if(arreglo == 0 || cantidad <= 1){
        return;
    }
    else{
        for(size_t i = 0; i < cantidad / 2; i++){
            int temporal = arreglo[i];
            arreglo[i] = arreglo[cantidad - 1 - i];
            arreglo[cantidad - 1 - i] = temporal;
        }
    }

    return;
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    if(arreglo == NULL){
        return false;
    }
    
    if(cantidad <= 1){
        return true;
    }

    for(size_t i = 0; i < cantidad - 1; i++){
        if(arreglo[i] > arreglo[i + 1]){
            return false;
        }
    }

    return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    if(arreglo == NULL || cantidad == 0){
        return 0;
    }

    size_t contador = 0;

    for(size_t i = 0; i < cantidad; i++){
        if(arreglo[i] == buscado){
            contador++;
        }
    }
    
    return contador;
}


size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    if(arreglo == NULL){
        return 0;
    }

    size_t nueva_cantidad = 0;

    for(size_t i = 0; i < cantidad; i++){
        if(arreglo[i] != valor){
            arreglo[nueva_cantidad] = arreglo[i];
            nueva_cantidad++;
        }
    }

    return nueva_cantidad;
}

