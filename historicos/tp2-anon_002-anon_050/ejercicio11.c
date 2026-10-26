

#include <stdio.h>
#include <stdbool.h>


bool le_perfecto(int numero)
{
    int suma = 0;
    for (int i = 1; i <= numero / 2; i++)
    {
        if (numero % i == 0)
        {
            suma = suma + i;
        }
    }
    return suma == numero;
}

int main()
{
    int num;

    printf("Ingrese el valor a comprobar: \n");
    scanf("%d", &num);

    if (le_perfecto(num))
    {
        printf("%d es un número perfecto.\n", num);
    }
    else
    {
        printf("%d no es un número perfecto.\n", num);
    }

    return 0;
}
