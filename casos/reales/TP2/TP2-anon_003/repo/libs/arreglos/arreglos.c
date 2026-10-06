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
    
    long long suma_arreglo = 0;
    if(arreglo == NULL || cantidad == 0){
        return 0;
    }
    else{
        for (size_t i = 0; i < cantidad; i++ ){
            suma_arreglo = suma_arreglo + arreglo[i];
            
        }
        return suma_arreglo;
    }
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    if (cantidad == 0 || arreglo == NULL){
        return -1;
    }else {
        for( size_t  i=0; i < cantidad; i++ ){
            if(arreglo [i] == buscado){
                return i;
            }
        }
    }
    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
   
    if(arreglo == NULL || cantidad <=1){
        return;
    } else{
        int aux = 0;
        size_t inicio = 0;
        size_t fin = cantidad -1;
        while(inicio<fin){
            aux = arreglo[inicio];
            arreglo [inicio] = arreglo[fin];
            arreglo [fin] = aux;
            inicio++;
            fin--;
        }
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    
    if(arreglo == NULL){
        return false;
    } 
    if (cantidad<=1){
        return true;
    }
    for (size_t i = 0; i< cantidad -1 ; i++){
        if (arreglo[i]> arreglo[i+1])
        {
            return false;
        }
            
    }
    
return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
   size_t buscado_encontrado = 0;
   if (arreglo == NULL|| cantidad ==0)
   {
    return 0;
   }
   for (size_t i =0; i < cantidad ; i++){
        if(arreglo[i] == buscado){
            buscado_encontrado++;
        }
   }
    return buscado_encontrado;
}
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor){
    if (cantidad == 0 || arreglo == NULL){
        return 0;
    }
    size_t posicion_valor = 0;
    for( size_t  i=0; i < cantidad; i++ ){
        if (arreglo[i] != valor){
            arreglo [posicion_valor] = arreglo [i];
            posicion_valor++;
            }

        }
    
    return posicion_valor;
}



