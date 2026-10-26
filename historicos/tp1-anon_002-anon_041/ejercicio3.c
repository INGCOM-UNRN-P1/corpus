

#include <stdio.h>


int signo(int numero)
{
    if(numero < 0)
    {
        return -1;
    }
    else if(numero > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int numero_ingresado;
    int resultado;

    printf("Ingrese un numero entero para saber si es positivo, negativo o igual a 0: \n");
    scanf("%d", &numero_ingresado);

    resultado = signo(numero_ingresado);

    if(resultado > 0)
    {
        printf("El numero ingresado es positivo");
    }
    else if(resultado < 0)
    {
        printf("El numero ingresado es negativo");
    }
    else
    {
        printf("El numero ingresado es igual a cero");
    }

    return 0;
}
