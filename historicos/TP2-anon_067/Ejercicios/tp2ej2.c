/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/

#include <stdio.h>

int multiplicacion(int numeroUno, int numeroDos);
int potenciacion(int base, int potencia);

int main(int argc, char *argv[])
{
    int n, m, producto, potencia;

    do{
        printf("Ingrese un numero natural:\t");
        scanf("%d", &n);
    }while(n <= 0);
    do{
        printf("Ingrese un numero natural:\t");
        scanf("%d", &m);
    }while(m <= 0);

    producto = multiplicacion(n, m);
    potencia = potenciacion(n, m);

    printf("%d*%d = %d\n", n, m, producto);
    printf("%d^%d = %d\n", n, m, potencia);

    return 1;
}

int multiplicacion(int numeroUno, int numeroDos)
{
    int resultado;

    resultado = numeroUno * numeroDos;

    return resultado;
}
int potenciacion(int base, int potencia)
{
    int resultado = base;

    for(int i = 1; i<potencia; i++)
        resultado = multiplicacion(resultado, base);

    return resultado;
}
