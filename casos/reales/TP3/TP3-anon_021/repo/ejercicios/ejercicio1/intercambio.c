/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"


void ordenar_par(int *menor, int *mayor)
{
    if (menor != NULL && mayor != NULL)
    {
        if (*menor > *mayor)
        {
            intercambiar(menor,mayor);
        }
        
    }
    
}

void ordenar_tria(int *a, int *b, int *c)
{
    if (a != NULL && b != NULL && c != NULL)
    {
        ordenar_par(a,b);   //me conviene ir haciendo primero entre a y b
        ordenar_par(b,c);
        ordenar_par(a,b);   //vuelvo a ordenarlos por las dudas, garantizando que a vuelva a ser <= que b
    }
    
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    bool verificacion = false;
    if (arreglo == NULL || resultado == NULL)
    {
        verificacion = false;
    }
    else
    {
        verificacion = true;
        long long suma_total = 0; //variable que me va a servir de acumulador
        const int *actual = NULL;   //puntero de lectura al inicio de arreglo
        actual = arreglo;
        const int *limite = NULL;//puntero que va sumando de acuerdo a desplzamiento
        limite = arreglo + cantidad;
        while (actual<limite)
        {
            suma_total = suma_total + *actual;//sumo valor al acumulador
            actual = actual +1;//avanzo a isguiente celda de memoria
        }
        *resultado = suma_total;
    }
    
    return verificacion;
}
