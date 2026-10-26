

#include <stdio.h>



unsigned int valor_absoluto(int numero);
int signo(int numero);



int cuenta_digitos(int numero)
{
    int contador = 0;
    numero = valor_absoluto(numero);
    while (numero > 0)
    {
        numero = numero / 10;
        contador++;
    }
    return contador;
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
    int casos[CASOS][2] = 
    {
        {0, 0 },
        {1, 1},
        {10, 2},
        {100, 3},
        {-1234, 4},
        {54321, 5}
    };

    for (int i = 0; i < CASOS; i++)
    {
        int numero = casos[i][0];
        int esperado = casos[i][1];

        int resultado = cuenta_digitos(numero);

        printf("El numero %d dio que tiene %d ", numero, resultado);
        
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
