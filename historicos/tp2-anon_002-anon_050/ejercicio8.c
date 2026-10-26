

#include <stdio.h>
#include <stdbool.h>


bool el_defectuoso(int numero)
{
    int suma = 0;
    for (int i = 1; i <= numero / 2; i++)
    {
        if (numero % i == 0)
        {
            suma = suma + i;
        }
    }
    return suma < numero;
}

int main()
{
    int num;

    printf("Ingrese el número a comprobar: \n");
    scanf("%d", &num);

    if (el_defectuoso(num))
    {
        printf("%d es un número deficiente.\n", num);
    }
    else
    {
        printf("%d no es un número deficiente.\n", num);
    }
    return 0;
}
