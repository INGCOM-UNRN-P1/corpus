/**
 * @file busqueda.c
 * @brief Implementación de búsqueda lineal con retorno de puntero y resta de punteros.
 */

 /**
 *@brief buscar_primero busca la primera aparicion de un valor en un arreglo y devuelve
 *          su posicion
 * @param arreglo no debe ser null
 * @param cantidad no debe ser 0
 * @param valor_buscado int a buscar
 *
 *@pre arreglo no debe ser null, y canrtidad debe ser mayor a 0
 *@post si encuentra el valor devolvera su espacio en memoria
  *      Si no lo encuentra o los datos son invalidos,devolvera NULL
*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

#include "busqueda.h"

const int *buscar_primero(const int *arreglo, size_t cantidad, int valor_buscado){
    if (arreglo == NULL || cantidad == 0){
        return NULL;
    }
    const int *ptr = arreglo;
    const int *fin_ptr = arreglo + cantidad;
    int temp = 0;
    bool encontrado = false;
    while (ptr < fin_ptr && encontrado == false ){
        if (*ptr == valor_buscado){
            encontrado = true;
            return ptr;
        }
        ptr++;
    }
    return NULL;
}

long distancia_punteros(const int *inicio, const int *elemento){
    if (inicio == NULL || elemento == NULL || elemento < inicio) {
        return -1;
    }
    long distancia = elemento - inicio;
    return distancia;

}