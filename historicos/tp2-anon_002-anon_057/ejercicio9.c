

#include <stdio.h>

unsigned long long int fibonacci(int n);
unsigned long long int suma_digitos(long long int numero);
int signo(long long int numero);
unsigned long long int valor_absoluto(long long int numero);
unsigned long long int suma_digitos_fibonacci(int n);



/**
 * Calcula el N-ésimo término de la serie de Fibonacci.
 *
 * @param termino es el número de la serie de Fibonacci que se calculara.
 * @return El N-ésimo término de la serie de Fibonacci.
            termino = 0 -> 0
            termino = 1 -> 1
            si termino es negativo, se retornara 0.
 */
unsigned long long int fibonacci(int termino) 
{

    unsigned long long int uno = 0;
    unsigned long long int dos = 1;
    unsigned long long int resultado = 0;
    int i = 2;
    
    if (termino <= 0)
    {
        resultado = 0;
    }
    else if (termino == 1)
    {
        resultado = 1;
    }

    while ( i <= termino ) 
    {
        resultado = uno + dos;
        uno = dos;
        dos = resultado;
        i++;
    }

    return resultado;
}

/**
 * Calcula la suma de los dígitos de un número natural.
 *
 * @param numero El número del cual se calculará la suma de dígitos.
 * @return La suma de los dígitos del número.
 *
 * @pre El número debe ser un natural, los numeros negativos seran tratados como positivos.
 * @post El valor devuelto es la suma de los dígitos del número.
 */
unsigned long long int suma_digitos(long long int numero)
{
    long long int suma = 0;
    numero = valor_absoluto(numero);
    while (numero > 0)
    {
        suma = suma + (numero % 10);
        numero = numero / 10;
    }
    return suma;
}


int signo(long long int numero)
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


unsigned long long int valor_absoluto(long long int numero)
{
    return signo(numero) * numero;
}

/**
 * Calcula la suma de los dígitos de los términos en una serie de Fibonacci
 * hasta el N-ésimo término.
 *
 * @param n El número de términos de Fibonacci a considerar.
 * @return La suma de los dígitos de los términos en la serie de Fibonacci.
 */
unsigned long long int suma_digitos_fibonacci(int n) 
{
    
    unsigned long long int termino = 0;
    unsigned long long int suma_digitos_total = 0;
    int i = 1;
    if (n > 0)
    {
        while ( i <= n ) 
        {
            termino = fibonacci(i);
            suma_digitos_total = suma_digitos_total + suma_digitos(termino);
            i++;
        }
    }
    return suma_digitos_total;
}

int main() 
{
    int n;

    printf("Ingrese el valor de n (número de términos de Fibonacci): ");
    scanf("%d", &n);

    unsigned long long int resultado = suma_digitos_fibonacci(n);

    printf("La suma de los dígitos de los %d primeros términos de Fibonacci es: %llu\n", n, resultado);

    return 0;
}

