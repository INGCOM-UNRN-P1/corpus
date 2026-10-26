

#include <stdio.h>

// Pre: Enteros num1 y num2
// Post: cadena True o False
int es_multiplo(int numero1, int numero2)
{
    if (numero1 % numero2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int num1, num2;
    printf("Ingrese el primer número: \n");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: \n");
    scanf("%d", &num2);

    if (es_multiplo(num1, num2) == 0)
    {
        printf("True");
    } 
    else
    {
        printf("False");
    }
    return 0;
}