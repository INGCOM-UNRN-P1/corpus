

#include <stdio.h>



int suma_numeros_primos(int n)
{
    int i;
    int numero = 0;
    int restos;
    int suma = 0;

    while(n > 0)
    {
        numero++;
        restos = 0;

        for(i = 1;i <= numero; i++)
        {
            if(numero % i == 0)
            {
                restos++;
            }
        }

        if(restos == 2)
        {
            suma = suma + numero;
            n = n - 1;
        }
    }

    return suma;
}

int main()
{
    int n;
    int resultado;

    printf("Ingrese cuantos numeros primos quiere sumar: ");
    scanf("%d", &n);

    resultado = suma_numeros_primos(n);
    printf("La suma es: %d", resultado);

    return 0;
}