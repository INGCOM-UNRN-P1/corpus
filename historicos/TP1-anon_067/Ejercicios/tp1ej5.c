
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero1, numero2;

    printf("Ingrese el primer numero:\t");
    scanf("%d", &numero1);
    printf("Ingrese el segundo numero:\t");
    scanf("%d", &numero2);

    printf("Primer numero: %d\nSegundo numero: %d\n", numero1, numero2);
    if (numero1 > numero2)//en caso de que el segundo numero sea menor que el primero
        for(int i = numero2; i <= numero1; i++)
            printf("%d\n", i);
    else
        for(int i = numero1; i <= numero2; i++)
            printf("%d\n", i);    return 1;
}
