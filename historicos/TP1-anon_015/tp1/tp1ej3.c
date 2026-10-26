#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numero1, numero2, multiplicacion, division, resto;


    printf("dime el numero1: ");
    scanf("%d", &numero1);
    printf("dime el numero2: ");
    scanf("%d", &numero2);

    multiplicacion = numero1 * numero2;
    division = numero1 / numero2;
    resto = numero1 % numero2;

    printf("La multiplicacion es: %d \n", multiplicacion);
    printf("La division es: %d \n", division);
    printf("El resto es: %d \n", resto);



    return 0;
}