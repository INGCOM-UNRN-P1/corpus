#include "operaciones.h"
#include "arreglos.h"

double calcular_promedio(const int arreglo[], size_t cantidad)
{
    double promedio = 0.0;

    if (arreglo == NULL || cantidad == 0)
    {
        long long suma = arreglo_sumar(arreglo, cantidad);
        promedio = (double)suma / (double)cantidad;
    }

    return promedio;
}

bool contiene_valor(const int arreglo[], size_t cantidad, int valor)
{
    bool pertenece = false; 
    
    if (arreglo != NULL && cantidad > 0)
    { 
        pertenece = (arreglo_buscar(arreglo, cantidad, valor) != -1);
    } 
    
    return pertenece; 
}