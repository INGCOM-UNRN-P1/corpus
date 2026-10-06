

#include "arreglos.h"

long long arreglo_sumar(const int arreglo[], size_t cantidad)
{
    if(arreglo == NULL || cantidad == 0)
    {
        return 0LL;
    }
    long long suma = 0;
    for(size_t i = 0; i < cantidad; i++)
    {
        suma += arreglo[i];
    }
    return suma;
}

int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return -1;
    }
    for(size_t i = 0;i < cantidad;i++)
    {
        if(arreglo[i] == buscado)
        {
            return (int)i;
        }
    }
    return -1;
}

void arreglo_invertir(int arreglo[], size_t cantidad)
{
    if(arreglo == NULL || cantidad <= 1)
    {
        return;
    }
    size_t inicio = 0;
    size_t fin = cantidad - 1;
    while(inicio < fin)
    {
        int auxilar = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = auxilar;
        inicio++;
        fin--;
    }
}

bool arreglo_ordenado(const int arreglo[], size_t cantidad)
{
    if(arreglo == NULL)
    {
        return false;
    }
    if(cantidad <= 1)
    {
        return true;
    }
    for(size_t i = 0;i < cantidad - 1;i++)
    {
        if(arreglo[i] > arreglo[i + 1])
        {
            return false;

        }
    }    
    return true;
}

size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado)
{
    size_t contador = 0;
    if(arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    for(size_t i = 0;i < cantidad; i++)
    {
        if(arreglo[i] == buscado)
        {
            contador++;
        }
    }
    return contador;
}

size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor)
{
    if(arreglo == NULL || cantidad == 0)
    {
        return 0;
    }
    size_t escritura = 0;
    for(size_t lectura = 0;lectura < cantidad; lectura++)
    {
        if(arreglo[lectura] != valor)
        {
            arreglo[escritura] = arreglo[lectura];
            escritura++;
        }
    }
    return escritura;
}



