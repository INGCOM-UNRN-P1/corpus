
//declaro funcion
int suma_rango(int n, int m);

#include <stdio.h>

int main()
{
    int m = 4;
    int n = 1;
//asigno la funcion a una variable
    int rango = suma_rango(n, m);

    printf("La suma entre %d y %d es: %d", n, m, rango);

    return 0;
}

int suma_rango(int n, int m)
{
    int i = 0;    
    int suma = 0;

    for (i = n; i < m; i++)//en cada vuelta se realiza la suma entre n q es i y suma
    {
        suma = suma + i;        
    }
    return suma;
}
//pre: recibe 2 numero enteros y n debe ser menor que n
//pos: devuelve la suma de los enteros en el rango


