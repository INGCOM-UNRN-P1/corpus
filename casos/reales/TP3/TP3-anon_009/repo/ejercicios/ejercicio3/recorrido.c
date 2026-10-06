

#include "recorrido.h"


void copiar_arreglo(int *arreglo, size_t cantidad, int *destino)
{
    if(arreglo == NULL || destino == NULL || cantidad == 0)
    {
        return;
    }
    const int *fin_arreglo = arreglo + cantidad;
    while(arreglo < fin_arreglo)
    {
        *destino = *arreglo;
        arreglo++;
        destino++;
    }
}

void invertir_arreglo(int *arreglo, size_t cantidad)
{
    if(arreglo == NULL || cantidad <= 1)
    {
        return;
    }
    int *inicio = arreglo;
    int *fin = arreglo + (cantidad - 1);
    while(inicio < fin)
    {
        intercambiar(inicio, fin);
        inicio++;
        fin--;
    }
}