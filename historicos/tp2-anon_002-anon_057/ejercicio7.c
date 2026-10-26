

#include <stdio.h>



int signo(long long int numero);
unsigned long long int potencia_lenta(unsigned long long int base, int exponente);
long long int multiplicacion_lenta(long long int num1, long long int num2);
unsigned long long int valor_absoluto(long long int numero);

/**
 * Calcula la potencia de un número elevado a una potencia dada.
 *
 * @param base La base de la potencia.
 * @param exponente El exponente al que se elevará la base.
 * @return El resultado de la operación base elevada a la exponente.
 *
 * @pre El exponente debe ser un número entero no negativo.
 * @post El valor devuelto es el resultado de base elevada a la exponente.
 *       o 0 cuando el exponente sea negativo.
 */
unsigned long long int potencia_lenta(unsigned long long int base, int exponente) 
{
    unsigned long long int resultado = 1;
    int i = 0;
    if (exponente < 0) 
    {
        printf("Error: El exponente debe ser un número entero no negativo.\n");
        resultado = 0;
    }
    else if (exponente == 0) 
    {
        resultado = 1;
    }

    while (i < exponente)
    {
        resultado = multiplicacion_lenta(resultado, base);
        i++;
    }
    return resultado;
}


/**
 * Calcula la multiplicación de dos números enteros utilizando sumas y restas.
 *
 * @param izquierdo El primer número entero.
 * @param derecho El segundo número entero.
 * @return El resultado de la multiplicación de izquierdo por derecho.
 *
 * @pre Se esperan dos numeros.
 * @post El valor devuelto es el resultado de la multiplicación de izquierdo por derecho.
 */
long long int multiplicacion_lenta(long long int izquierdo, long long int derecho) 
{
    int resultado = 0;
    int multiplicador = valor_absoluto(izquierdo);
    int multiplicando = valor_absoluto(derecho);
    int i = 0;

    if (izquierdo == 0 || derecho == 0) 
    {
         resultado = 0;
    }
    else
    {

        while (i < multiplicando) 
        {
            resultado = resultado + multiplicador;
            i++;
        }

        if ((izquierdo < 0 && derecho > 0) || (izquierdo > 0 && derecho < 0)) 
        {
            resultado = -resultado;
        }
    }
    return resultado;
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


int main()
{
    unsigned long long int base;
    int exponente;

    printf("Ingrese la base: ");
    scanf("%llu", &base);

    printf("Ingrese el exponente (no negativo): ");
    scanf("%d", &exponente);

    unsigned long long int resultado = potencia_lenta(base, exponente);

    printf("El resultado de %llu elevado a la %d es: %llu\n", base, exponente, resultado);

    return 0;
}

