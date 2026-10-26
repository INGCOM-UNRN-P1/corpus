#include <stdio.h>



/**
 * Calcula el cociente y el resto de la division de dos enteros 
 * @param dividendo El numero que se va a dividir.
 * @param divisor El numero por el cual se va a dividir.
 * @param cociente Puntero al entero donde se almacenara el cociente.
 * @param resto Puntero al entero donde se almacenara el resto.
 * @pre divisor no es igual a cero y cociente y resto son punteros validos a enteros.
 * @post El cociente y el resto de la division se almacenan en cociente y resto, respectivamente.
 */ 
void cociente_resto (int dividendo, int divisor, double * cociente, double *resto)
{
    *cociente = 0;
    *resto = dividendo;
    while (*resto >= divisor)
    {
        *resto = *resto - divisor;
        (*cociente)++;
    }
}



int main ()
{
    int dividendo;
    int divisor;
    double cociente;
    double resto;
    printf("Ingrese el dividendo: ");
    scanf("%d", &dividendo);
    printf("Ingrese el divisor: ");
    scanf("%d", &divisor);
    cociente_resto(dividendo,divisor,&cociente,&resto);
    if (divisor !=0)
    {
        printf("Cociente: %lf\n",cociente);
        printf("Resto: %lf\n", resto);
    }
    else
    {
        printf("Divisor no valido\n");
    }
    return 0;
}