

#include <stdio.h>



unsigned int valor_absoluto(int numero);
int signo(int numero);

/**
 * Calcula la suma de los dígitos de un número natural.
 *
 * @param numero El número del cual se calculará la suma de dígitos.
 * @return La suma de los dígitos del número.
 *
 * @pre El número debe ser un natural, los numeros negativos seran tratados como positivos.
 * @post El valor devuelto es la suma de los dígitos del número.
 */
unsigned int suma_digitos(int numero)
{
    int suma = 0;
    numero = valor_absoluto(numero);
    while (numero > 0)
    {
        suma = suma + (numero % 10);
        numero = numero / 10;
    }
    return suma;
}


int signo(int numero)
{
    int retorno;
    if (numero < 0)
    {
        retorno = -1;
    }
    else if (numero > 0)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}


unsigned int valor_absoluto(int numero)
{
    return signo(numero) * numero;
}

#define CASOS 6

int main()
{
    // Casos significativos
    int casos[CASOS][2] = {
        {0, 0 },
        {1, 1},
        {10, 1},
        {100, 1},
        {-1234, 10},
        {54321, 15}
    };

    for (int i = 0; i < CASOS; i++)
    {
        int numero = casos[i][0];
        int esperado = casos[i][1];

        int resultado = suma_digitos(numero);

        printf("El numero %d dio que la suma de sus digitos es %d ", numero, resultado);
        
        printf("y se esperaba %d, que fue ", esperado);
        if (resultado == esperado)
        {
            printf("correcto");
        }
        else
        {
            printf("incorrecto");
        }
        printf(" con %d\n", resultado);
    }
    return 0;
}
