/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/
#include <stdio.h>

int sumaLenta(int numero1, int numero2);

int main(int argc, char *argv[])
{
    int numero1, numero2, resultado;
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero1);
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero2);

    resultado = sumaLenta(numero1, numero2);

    printf("El resultado de la suma %d+%d es: %d\n", numero1, numero2, resultado);
    return 1;
}

int sumaLenta(int numero1, int numero2)
{
    for(int i = 0; i < numero2; i++)
        numero1++;
    return numero1;
}
