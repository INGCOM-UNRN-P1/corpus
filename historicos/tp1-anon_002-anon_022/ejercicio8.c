

#include <stdio.h>

int suma_rango(int n, int m)
{
    int suma=0;
    int numero;
    for (numero = n; numero < m; numero++)
    {
        suma = suma + numero;        
    }
    return suma;
}

int main()
{
    int inferior;
    int superior;
    int evaluar;
    printf("Ingrese el numero de la cota inferior: ");
    scanf("%d",&inferior);
    printf("Ingrese el numero de la cota superior: ");
    scanf("%d",&superior);
    evaluar = suma_rango(inferior,superior);
    printf("La suma es: %d\n",evaluar);
    return 0;
}