/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"
#include "punteros.h"



bool copiar_arreglo(const int *arreglo, int *destino, size_t cantidad){
    if (arreglo == NULL || destino == NULL){
        return false;
    }
    
    const int *ptr = arreglo;
    const int *fin_ptr = arreglo + cantidad;
    int temp = 0;
    while (ptr < fin_ptr){
        *destino = *ptr;
        ptr++;
        destino++;
    }
    return true;
}

bool invertir_arreglo (int *arreglo, size_t cantidad){
if (arreglo == NULL || cantidad == 0){
        return false;
    }
 //**hacer libreria de validar null */   
    int *ptr_inicio = arreglo;
    int *ptr_fin = arreglo + cantidad-1;
    
    while(ptr_inicio < ptr_fin){
        intercambiar(ptr_inicio, ptr_fin);
        ptr_fin--;
        ptr_inicio++;
    }
    return true;
}
