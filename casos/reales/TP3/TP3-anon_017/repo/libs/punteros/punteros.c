

#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{
    (void)primer;
    (void)segundo;
    
    if((primer != NULL) && (segundo != NULL) && (primer != segundo))
    {
        int auxiliar = *primer;
        *primer = *segundo;
        *segundo = auxiliar;
    }
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    (void)arreglo;
    (void)cantidad;
    (void)minimo;
    (void)maximo;
    
    bool manejo_errores = true;
    if((arreglo == NULL) || (cantidad == 0) || (minimo == NULL) || (maximo == NULL))
    {
        manejo_errores = false;
    }
    else
    {
        *minimo = *arreglo;
        *maximo = *arreglo;

        for(size_t i = 0; i < cantidad; i++)
        {
            if(*arreglo < *minimo)
            {
                *minimo = *arreglo;
            }
            else if(*arreglo > *maximo)
            {
                *maximo = *arreglo;
            }
            arreglo = arreglo + 1;
        }
    }
    return manejo_errores;
}
