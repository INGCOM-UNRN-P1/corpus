#include "operaciones.h"
#include "arreglos.h"

double calcular_promedio(const int arreglo[], size_t cantidad)
{
    double promedio_es = 0.0;

    if ((arreglo !=  NULL) && (cantidad > 0))
    {
        long long suma_total = arreglo_sumar(arreglo, cantidad); 
        promedio_es = suma_total / cantidad;
    }
    return promedio_es;
}

bool contiene_valor(const int arreglo[], size_t cantidad, int valor)
{
    bool valor_encontrado = true;
    if((arreglo != NULL) && (cantidad > 0))
    {
        int respuesta_buscar = arreglo_buscar(arreglo, cantidad, valor);
        if(respuesta_buscar == -1)
        {
            valor_encontrado = false;
        }
    }
    else
    {
        valor_encontrado = false;
    }
    return valor_encontrado;
}
