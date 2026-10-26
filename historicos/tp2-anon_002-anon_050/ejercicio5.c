

#include <stdio.h>


int zip_me_this(int numero1, int numero2, int numero3)
{
    int min = numero1;
    if (numero2 < min)
    {
        min = numero2;
    }
    if (numero3 < min)
    {
        min = numero3;
    }
    return min;
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

    printf("El menor número es %d.\n", zip_me_this(num1, num2, num3));

    return 0;
}
