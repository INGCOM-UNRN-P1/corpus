

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nro;

    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &nro);

        if (nro < 100)
        {
            printf("El numero es mayor a 100. \n");
        }
        

    } while (nro < 100);
    
    return 0;

}