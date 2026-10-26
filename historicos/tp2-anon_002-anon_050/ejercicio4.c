

#include <stdio.h>


int grandote_triple(int numero1, int numero2, int numero3)
{
    int max = numero1;
    if (numero2 > max)
    {
        max = numero2;
    }
    if (numero3 > max)
    {
        max = numero3;
    }
    return max;
}

int main()
{
    int num1;
    int num2;
    int num3;
    printf("Escriba el primer número a comprobar: \n");
    scanf("%u", &num1);

    printf("Escriba el segundo número a comprobar: \n");
    scanf("%u", &num2);

    printf("Escriba el tercer número a comprobar: \n");
    scanf("%u", &num1);

    printf("El mayor número es %d.\n", grandote_triple(num1, num2, num3));

    return 0;
}
