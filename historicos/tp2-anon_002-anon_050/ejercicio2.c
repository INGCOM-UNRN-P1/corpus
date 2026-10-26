

#include <stdio.h>


int sumar_digitos(unsigned int numero)
{
    int suma = 0;
    while (numero != 0)
    {
        suma = suma + (numero % 10);
        numero = numero / 10;
    }
    return suma;
}

int main()
{
    unsigned int num;
    printf("Escriba el número a operar: \n");
    scanf("%u", &num);

    printf("La suma de dígitos es: %u", sumar_digitos(num));

    return 0;
}
