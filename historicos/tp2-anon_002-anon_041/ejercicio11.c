

#include <stdio.h>



int numero_perfecto(int numero)
{
    int suma = 0;
    int resultado;
    int i;
    
    for(i = 1;i < numero; i++)
    {
        if(numero % i == 0)
        {
            suma = suma + i;
        }
    }

    if(suma == numero)
    {
        resultado = 1;
    }
    else
    {
        resultado = 0;
    }


    return resultado;
}


int main()
{
    int numero;
    int resultado;

    printf("Ingrese un numero entero positivo para saber si es perfecto: ");
    scanf("%d", &numero);

    resultado = numero_perfecto(numero);

    if(resultado == 1)
    {
        printf("Es un numero perfecto.");
    }
    else
    {
        printf("No es un numero perfecto.");
    }

    return 0;
}