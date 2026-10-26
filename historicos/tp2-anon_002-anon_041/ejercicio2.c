

#include <stdio.h>



int suma_digitos(int numero)
{
    int digito;
    int suma;

    while(numero > 0)
    {
        digito = numero % 10;
        numero = numero / 10;
        suma = suma + digito;
    }

    return suma;
}

int main()
{
    int numero;
    int resultado;

    printf("Ingrese un numero entero positivo para saber la suma de sus digitos:\n");
    scanf("%d", &numero);

    if(numero < 0)
    {
        printf("No ingreso un numero entero positivo");
        return 0;
    }

    resultado = suma_digitos(numero);
    printf("El resultado es: %d", resultado);

    return 0;
}