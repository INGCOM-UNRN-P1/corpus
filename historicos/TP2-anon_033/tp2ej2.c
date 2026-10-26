/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_033 de GitHub
*************************/
#include <stdio.h>

unsigned long long int producto(int numeroN, int numeroM);
unsigned long long int potencia(int numeroN, int numeroM);

int main ()
{
    int numeroN, numeroM, resultadoPro, resultadoPot;
    printf("Ingrese un numero: ");
    scanf("%d" ,&numeroN);
    printf ("Ingrese otro numero: ");
    scanf("%d" ,&numeroM);

    resultadoPro=producto(numeroN, numeroM);
    resultadoPot=potencia(numeroN, numeroM);
    printf ("El resultado del producto es: %d " ,resultadoPro);
    printf ("\nEl resultado de la potencia es: %d " ,resultadoPot);
    return 0;
}

unsigned long long int producto(int numeroN, int numeroM)
{
    int resultado1, cont;
    cont=0;
    while (cont<numeroM)
    {
        resultado1 = resultado1 + numeroN;
        cont++;
    }
    return resultado1;
}
unsigned long long int potencia(int numeroN, int numeroM)
{
    int resultado2=numeroN, cont = 1;
    while (cont<numeroM)
    {
        resultado2 = resultado2*numeroN;
        cont++;
    }
    return resultado2;
}
