/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero = 0; //declaro la variable entera para ingresar el numeros

    //Mientras que el numero sea menor a 100, sigue pidiendo el ingreso
    do
    {
        printf("Ingrese un numero entero mayor a 100: ");
        scanf("%d", &numero);
    }
    while(numero < 100);

    //compruebo e imprimo si el numero ingresado es multiplo o no
    for(int i = 2; i < 7; i++)
    {
        if((numero % i) == 0)
            printf("Es multiplo de %d: SI\n", i);
        else
            printf("Es multiplo de %d: NO\n", i);
    }
    return 1;
}
