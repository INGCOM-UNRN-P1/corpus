

int es_multiplo(int numero, int multiplo);

#include <stdio.h>

int main()
{
    int numero = 12;
    int multiplo = 3;

    int esMultiplo = es_multiplo(numero, multiplo);   

    if (esMultiplo == 1) 
    {
        printf("Es multiplo\n");
    } 
    else 
    {
        printf("No es multiplo\n");
    }
    return 0;
}

int es_multiplo(int numero, int multiplo)
{
    int resolucion = 0;
    int suma = numero;
    int resta = multiplo;

    while(suma < multiplo)
    {
        suma = suma + numero;
    }
    while(resta > 0)
    {
        resta = resta - numero;
    }
    if(suma == multiplo && resta == 0)
    {
        resolucion = 1;
    }
    else
    {
        resolucion;
    }
    return resolucion;
}
//pre: recibe 2 numeros enteros
//pos: retorna si es multiplo o no


