

#include <stdio.h>

int suma_recursiva(int valor1, int valor2);
int producto_recursivo(int factor1, int factor2);
int potencia_recursiva(int base, int exponente);

int main()
{
    int numero1 = 0;
    int numero2 = 0;
    //int base, exponente;

    printf("Ingrese el primer termino: ");
    scanf("%d", &numero1);
    printf("Ingrese el segundo termino: ");
    scanf("%d", &numero2);

    printf("La suma de %d y %d es: %d\n", numero1, numero2, suma_recursiva(numero1, numero2));
    printf("El producto de %d y %d es: %d\n", numero1, numero2, producto_recursivo(numero1, numero2));
    printf("La potencia de %d elevado a %d es: %d\n", numero1, numero2, potencia_recursiva(numero1, numero2));

    return 0;
}



int suma_recursiva(int valor1, int valor2)
{
    if(valor2 == 0)//caso base
        return valor1;
    else
        return 1 + suma_recursiva(valor1, valor2 - 1);
}



int producto_recursivo(int factor1, int factor2)
{
    if(factor2 == 0)//caso base
    {
        return 0;
    }    
    else if(factor2 > 0)
    {
        return factor1 + producto_recursivo(factor1, factor2 - 1);
    }
    else
    {
        return -producto_recursivo(factor1, -factor2);
    }
}


int potencia_recursiva(int base, int exponente)
{
    if(exponente == 0)//caso base
    {
        return 1;
    }
    else
    {
        return base * potencia_recursiva(base, exponente - 1);
    }
}

