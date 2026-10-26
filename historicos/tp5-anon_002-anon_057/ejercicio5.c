#include <stdio.h>


typedef struct
{
    int cociente;
    int resto;
} division_t;

/**
Esta funcion indica el signo del numero
@param numero a ser evaluado
@returns -1 si el signo de numero es negativo
          0 si el signo de numero es cero y
          1 si el signo de numero es positivo.
Precondiciones de la funcion, un numero entero
Postcondiciones de la funcion, un numero entero entre -1 y 1.
*/
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

/**
 * Calcula el cociente entre el dividendo y el divisor utilizando
 * el método de restas sucesivas.
 *
 * @param dividendo El número que se dividirá.
 * @param divisor El número por el cual se dividirá el dividendo.
 * @return El cociente y el resto de la división en la estructura.
 *
 * Precondiciones Ambos `dividendo` y `divisor` deben ser números enteros
 * válidos. Precondiciones El divisor no puede ser cero. Postcondiciones El
 * resultado sera identico al calculado con los operadores tradicionales.
 */
division_t division_lenta(int dividendo, int divisor)
{
    int cociente = 0;
    division_t retorno = {.cociente = 0, .resto = 0};
    int signo_dividendo = signo(dividendo);
    int signo_divisor = signo(divisor);
    if (divisor == 0)
    {
        printf("Error: Divisor no puede ser cero.\n");
    }
    else
    {
        dividendo = dividendo * signo_dividendo;
        divisor = divisor * signo_divisor;

        while (dividendo >= divisor)
        {
            dividendo -= divisor;
            cociente++;
        }
        retorno.cociente = cociente * signo_dividendo * signo_divisor;
        retorno.resto = dividendo * signo_dividendo;
    }
    return retorno;
}

int main()
{
    int valor_uno;
    int valor_dos;

    valor_uno = 10;
    valor_dos = 3;

    division_t resultado = division_lenta(valor_uno, valor_dos);

    printf("Dividendo: %d\n", valor_uno);
    printf("Divisor: %d\n", valor_dos);
    printf("Cociente: %d\n", resultado.cociente);
    printf("Resto: %d\n", resultado.resto);

    return 0;
}