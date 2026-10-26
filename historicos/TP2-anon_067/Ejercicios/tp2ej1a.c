/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, resultado = 0;

    do{
        printf("Ingrese un numero natural:\t");
        scanf("%d", &n);
    }while(n <= 0);


    while(resultado*resultado <= n)//pruebo numero a numero que el cuadrado del resultado sea menor al numero ingresado
        resultado++;// si es menor, aumento en 1 al resultado

    resultado--;// reduzco el resultado en 1, ya que el chequeo anterior supera en esa cantidad al resultado esperado

    printf("La parte entera de la raiz cuadrada de %d es: %d\n", n, resultado);
    return 1;
}
