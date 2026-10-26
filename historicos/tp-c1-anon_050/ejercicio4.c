

#include <stdio.h>
//Pre: dos numeros enteros con signo, numero y otronumero
//Post: resultado es -1, 0, o 1
int compara(int numero, int otronumero)
{
    if (numero < otronumero)
        return -1;
    else if (otronumero < numero)
        return 1;
    else
        return 0;
}

int main()
{
    int valor_a, valor_b;
    printf("Ingrese el primer número: ");
    scanf("%d", &valor_a);
    printf("Ingrese el segundo número: ");
    scanf("%d", &valor_b);

    printf("El resultado es: %d\n", compara(valor_a, valor_b));
    return 0;
}