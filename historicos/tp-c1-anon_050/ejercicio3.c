

#include <stdio.h>
// Pre: número entero numero
// Post: resultado 0, 1, o 2
int signo(int numero)
{
    int i = 0;
    if (numero > 0)
    {
        i++; //there, a sum
        return 1;
    }
    else if (numero < 0)
    {
        i--; //there, a rest
        return 2;
    }
    else
    {
        return 0;
    }

}

int main()
{
    int valor;
    int i = 0;
    printf("Ingrese el número a comparar: ");
    scanf("%d", &valor);

    if (signo(valor) == 1)
    {
        printf("Positivo.\n");
    }
    else if (signo(valor) == 2)
    {
        printf("Negativo.\n");
    }
    else
    {
        printf("Cero.\n");
    }
    return 0;
}