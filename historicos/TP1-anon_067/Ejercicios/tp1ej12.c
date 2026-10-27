
#include <stdio.h>

int mayorOMenor(float numero1, float numero2);

int main(int argc, char *argv[])
{
    float numero1, numero2;
    printf("Ingrese un numero: ");
    scanf("%f", &numero1);
    printf("Ingrese otro numero: ");
    scanf("%f", &numero2);

    switch(mayorOMenor(numero1, numero2))
    {
        case -1:
            printf("%.3f es menor a %.3f\n", numero1, numero2);
        break;
        case 0:
            printf("Los numeros eran iguales\n");
        break;
        case 1:
            printf("%.3f es mayor a %.3f\n", numero1, numero2);
        break;
    }
    return 1;
}

int mayorOMenor(float numero1, float numero2)
{
    if(numero1 < numero2)
        return -1;
    else if(numero1 == numero2)
        return 0;
    else
        return 1;
}
