
#include <stdio.h>

#define LARGO 5 //largo del array de multiplos

int main()
{
    int nro, i;
    int multiplos[LARGO] = {2, 3, 4, 5, 6}; //array de multiplos

    printf("Ingrese un numero entero mayor a 100\n");
    scanf("%d", &nro);

    while (nro <= 100)
    {
        printf("El numero ingresado es menor a 100, por favor ingrese un numero mayor a 100\n");
        scanf("%d", &nro);
    }

    for(i = 0; i < LARGO; i++)
    {
        if(nro % multiplos[i] == 0)
        {
            printf("Es multiplo de %d: SI\n", multiplos[i]);
        }
        else 
        {
            printf("Es multiplo de %d: NO\n", multiplos[i]);
        }
    }

    return 0;
}
