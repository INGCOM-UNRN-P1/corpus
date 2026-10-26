/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>

int ingreso_entero_restringido(int numero);

 
int main(int argc, char *argv[])
{
    printf("Ingrese un número mayor a 100.");
    ingreso_entero_restringido(100);
}

int ingreso_entero_restringido(int valor_min)
{
    int entrada;
    scanf("%d", &entrada);

    if (entrada > 100)
    {
        printf("El número es mayor a 100.");
        return entrada;
    }
    else if (entrada == 100)
    {
        printf("El número es igual a 100.\n");
        ingreso_entero_restringido(100);
    }
    else
    {
        printf("El número es menor a 100.\n");
        ingreso_entero_restringido(100);
    }

}