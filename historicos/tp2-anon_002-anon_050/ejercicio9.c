

#include <stdio.h>


int suma_de_digitos(int numero)
{
    int suma = 0;
    while (numero != 0)
    {
        suma = suma + numero % 10;
        numero = numero / 10;;
    }
    return suma;
}


int suma_fibonacci(int numero)
{
    int num1 = 0;
    int num2 = 1;
    int num3;
    int suma = 0;
    for (int i = 0; i < numero; i++)
    {
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
        suma = suma + suma_de_digitos(num3);
    }
    return suma;
}

int main()
{
    int num;

    printf("Ingrese el número a comprobar: \n");
    scanf("%d", &num);

    printf("La suma de dígitos de los primeros %d términos de la serie de Fibonacci es: %d\n", 
    num, suma_fibonacci(num));
    return 0;
}
