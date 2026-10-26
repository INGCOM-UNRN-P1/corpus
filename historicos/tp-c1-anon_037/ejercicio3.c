

#include <stdio.h>

int sabersigno(int numero);



int main()

{
    int numero;
    int resultado;

    printf("Ingrese un numero -> ");
    scanf("%d", &numero);
    
    printf("El numero ingresado es ");

    resultado = sabersigno(numero);
    
    if (resultado == 1)
    {
        printf("positivo");
    }
    else if (resultado == -1)
    {
        printf("negativo");
    }
    else
    {
        printf("cero");
    }

    return 0;
}


int sabersigno(int numero)
{
    if (numero > 0)
    {
        return 1;
    }
    else if (numero < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}