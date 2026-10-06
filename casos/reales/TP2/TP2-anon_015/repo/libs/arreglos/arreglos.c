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
    long long sumatoria = 0;
    if (arreglo == NULL || cantidad == 0){
        return 0;
    }
    else{
        for(size_t i = 0; i < cantidad; i++){
            sumatoria = sumatoria + arreglo[i];
        }
    } 
    return sumatoria;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad == 0){
        return -1;
    }
    else{
        for(size_t i = 0; i < cantidad; i++){
            if(arreglo[i] == buscado){
                return i;
            }
        }
    }
    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    int temporal = 0;
    if (arreglo == NULL || cantidad <= 1){

    }
    else{
        for(size_t i = 0; i < cantidad / 2; i++){
            temporal = arreglo[i];
            arreglo[i] = arreglo[cantidad - 1 - i];
            arreglo[cantidad - 1 - i] = temporal;
            
        }
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
    else{
        for(size_t i = 0; i < cantidad - 1; i++){
            if (arreglo[i] > arreglo[i + 1]){
                return false;
            }
        }
    }
    return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t contador = 0;
    if (arreglo == NULL || cantidad == 0){
        return 0;
    }
    else{
        for (size_t i = 0; i < cantidad; i++){
           if (arreglo[i] == buscado){
            contador = contador + 1;
           } 
        }
    }
    return contador;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int buscado){
    size_t nuevo_indice = 0;
    if(arreglo == NULL || cantidad == 0){
        return 0;
    }
    else{
        for (size_t indice_base = 0; indice_base < cantidad; indice_base++){
            if (arreglo[indice_base] != buscado){
                arreglo[nuevo_indice] = arreglo[indice_base];
                nuevo_indice++; 
            }
        }
    }
    return nuevo_indice; 

}

size_t arreglo_fusionar(const int primer[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad){
    size_t j = 0;
    size_t k = 0;
    int fallo_primer = (primer == NULL || cantidad_uno == 0);
    int fallo_segundo = (segundo == NULL || cantidad_dos == 0);

    if (fallo_primer && fallo_segundo){
            return 0;
        }

    else{
        if(cantidad_uno >= cantidad_dos){
            for(size_t i = 0; i < cantidad_uno; i++){
                if (primer[i] < segundo[j]){
                    destino[k] = primer[i];
                    k++;
                    destino[k] = segundo[j];
                    j++;
                    k++;
                }
                else{
                    destino[k] = segundo[j];
                    k++;
                    destino[k] = primer[j];
                    j++;
                    k++;
                }
            }
        }
        else{
            for(size_t i = 0; i < cantidad_dos; i++){
                if (primer[i] < segundo[j]){
                    destino[k] = primer[i];
                    k++;
                    destino[k] = segundo[j];
                    j++;
                    k++;
                }
                else{
                    destino[k] = segundo[j];
                    k++;
                    destino[k] = primer[j];
                    j++;
                    k++;
                }
            }
        }
    }
    return k;

}