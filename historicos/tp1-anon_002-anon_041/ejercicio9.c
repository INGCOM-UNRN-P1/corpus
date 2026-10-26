

#include <stdio.h>


int es_multiplo(int numero, int multiplo)
{
    int i;
    int suma = multiplo;

    if(numero == 0 || multiplo == 0)
    {
        return 0;
    }
    else if(numero < 0 && multiplo < 0)
    {
        for(i = multiplo;i > numero;i++)
        {
            multiplo = multiplo + suma;
            if(multiplo == numero)
            {
                return 1;
            }
        }
    }

    for(i = multiplo;i < numero;i++)
    {
        multiplo = multiplo + suma;
        if(multiplo == numero)
        {
            return 1;
        }
    }
    
    return 0;
}

int main()
{
    int numero;
    int multiplo;
    int resultado;

    printf("Averiguar si un numero entero es multiplo de otro a traves de sumas y restas.\n");
    printf("Ingrese el numero: ");
    scanf("%d", &numero);
    printf("Ingrese el multiplo: ");
    scanf("%d", &multiplo);

    resultado = es_multiplo(numero, multiplo);

    if(resultado == 1)
    {
        printf("Si es multiplo");
    }
    else
    {
        printf("No es multiplo");
    }

    return 0;
}
