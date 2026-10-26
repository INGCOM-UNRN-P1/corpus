/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/

#include <stdio.h>

int raizCuadrada(int numero);

int main(int argc, char *argv[])
{
    int n, m, resultadoN, resultadoM;

    do{
        printf("Ingrese un numero natural:\t");
        scanf("%d", &n);
    }while(n <= 0);
    do{
        printf("Ingrese un numero natural:\t");
        scanf("%d", &m);
    }while(m <= 0);

    resultadoN = raizCuadrada(n);
    resultadoM = raizCuadrada(m);

    printf("La parte entera de la raiz cuadrada de %d es: %d\n", n, resultadoN);
    printf("La parte entera de la raiz cuadrada de %d es: %d\n", m, resultadoM);

    return 1;
}

int raizCuadrada(int numero)
{
    int resultado = 0;
    while(resultado*resultado <= numero)//pruebo numero a numero que el cuadrado del resultado sea menor al numero ingresado
        resultado++;// si es menor, aumento en 1 al resultado

    resultado--;// reduzco el resultado en 1, ya que el chequeo anterior supera en esa cantidad al resultado esperado

    return resultado;
}
