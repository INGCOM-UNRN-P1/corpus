/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>

int fibonacci(int numero);
 
int main(int argc, char *argv[])
{
    int entrada;

    printf("Ingrese un número mayor a 10.\n\t");
    scanf("%d", &entrada);

    if (entrada <= 10)
    {
        printf("El número tiene que ser mayor a 10!");
        entrada = 0;
        return 0;
    }

    fibonacci(entrada); 

}

int fibonacci(int numero)
{

    int num_uno = 0;
    int num_dos = 1;
    int intercambio = 0;

    printf("Los numeros de la sucesion de fibonacci menor a %d son:", numero);

    while(intercambio < numero)
    {
        intercambio = num_uno + num_dos;
        num_dos = num_uno;
        num_uno = intercambio;

        if(intercambio < numero)
        {
            printf("%d, ", num_dos);
        }
        else
        {
            printf("%d", num_dos);
        }


    }

}