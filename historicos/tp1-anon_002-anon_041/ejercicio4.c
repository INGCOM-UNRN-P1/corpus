

#include <stdio.h>


int compara(int numero, int otro_numero)
{
    if (numero < otro_numero)
    {
        return -1;
    }
    else if(numero > otro_numero)
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
    int numero;
    int otro_numero;
    int resultado;

    printf("Ingrese dos numeros enteros para compararlos entre si.\n");
    printf("Primer numero: ");
    scanf("%d", &numero);
    printf("Segundo numero: ");
    scanf("%d", &otro_numero);

    resultado = compara(numero, otro_numero);

    if(resultado > 0)
    {
        printf("El primer numero ingresado es mayor que el segundo");
    }
    else if(resultado < 0)
    {
        printf("El primer numero ingresado es menor que el segundo");
    }
    else
    {
        printf("Los numeros son iguales");
    }

    return 0;
}
