#include <stdio.h>


/**
 * Duplica el valor de un numero ingresado
 * @param numero Puntero al numero entero a duplicar.
 * @pre numero es un puntero valido a un entero.
 * @post El valor apuntado por numero se duplica.
 */
void duplicar(int * numero)
{
    *numero = *numero * 2;
}

int main ()
{
    int numero;
    printf("Ingrese el numero a multiplicar: ");
    scanf("%d", &numero);
    duplicar(&numero);
    printf("Despues de multiplicar por 2: %d", numero);
    return 0;
}