/**
 * @file recorrido.c
 * @brief Implementación de recorrido, copia e inversión con aritmética de punteros.
 */

#include "recorrido.h"

bool copiar_arreglo(const int *origen, int *destino, size_t cantidad)
{
    bool verificacion = true;
    if (origen == NULL || destino == NULL )
    {
        verificacion = false;
    }
    else
    {
        verificacion = true;
        const int *ptr_origen = NULL;//puntero auxiliar que apuntara al inicio d emi origen
        ptr_origen = origen;
        int *ptr_destino = NULL;//puntero auxiliar apuntando a inicio de destino
        ptr_destino = destino;
        const int *limite = NULL;
        limite = origen + cantidad;

        while (ptr_origen < limite)
        {
            *ptr_destino = *ptr_origen;

            ptr_origen = ptr_origen + 1;
            ptr_destino = ptr_destino + 1;
        }
    }
    return verificacion;
}
bool invertir_arreglo(int *arreglo, size_t cantidad)
{
    bool resultado= true;
    if (arreglo == NULL)
    {
        resultado = false;
    }
    else
    {
        if (cantidad <= 1)
        {
            resultado = true;//si arreglo vacio o de un elemeno ya esta invertido se podria decir
        }
        else
        {
            int *inicio = NULL; //puntero desde izquierda apunta al primer elemento del arreglo
            inicio = arreglo;
            int *fin = NULL;
            fin = arreglo + cantidad -1;

            while (inicio < fin)
            {
                intercambiar(inicio, fin);//paso direccion de los dos extremos
                inicio = inicio +1; //muevo puntero izquierdo hacia derecha
                fin = fin -1 ; //muevo puntero derecho a izq
            }
        }
        
    }
    return resultado;
}