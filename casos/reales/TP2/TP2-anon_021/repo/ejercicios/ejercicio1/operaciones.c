#include "operaciones.h"
#include "arreglos.h"

double calcular_promedio(const int arreglo[], size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return 0.0;
    }
    long long suma = arreglo_sumar(arreglo, cantidad);
    return (double)suma / (double)cantidad;
}

bool contiene_valor(const int arreglo[], size_t cantidad, int valor)
{
    return arreglo_buscar(arreglo, cantidad, valor) != -1;
}
