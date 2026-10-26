/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_043 de GitHub
*************************/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    int multiplo = 0;

    printf("Ingrese un numero mayor a 100: \n");
    do
    {
        
        scanf("%d", &a);
    
    } while (a < 0);

    for (int i = 2; i <= 6; i++)
    {

        multiplo = a%i;
        
        if (multiplo == 0)
        {
            printf("Es multiplo de %d: SI \n", i);
        }
        else
        {
            printf("Es multiplo de %d: NO \n", i);
        }
        
        
    }

    return 0;
}