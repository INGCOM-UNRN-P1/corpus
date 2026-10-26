

#include <stdio.h>

int es_multiplo(int numero, int multiplo)
{
    int suma = 0;
    while (suma < numero)
    {
        suma = suma + multiplo;
    }
    return (suma == numero);
}

int main()
{
    int num1;
    int num2;

    printf("Ingrese el primer número: \n");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: \n");
    scanf("%d", &num2);

    if (es_multiplo(num1, num2))
    {
        printf("%d es un múltiple de %d.\n", num1, num2);
    }
    else
    {
        printf("%d no es múltipo de %d.\n", num1, num2);
    }
   
    return 0;
}