

#include <stdio.h>
int signo(int numero)
{
    if (numero > 0)
    {
        return 1;
    }
    else if (numero < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}

int main()
{
    int valor;
    int resultado;
    printf("Ingrese el número a comparar: ");
    scanf("%d", &valor);
    resultado = signo(valor);
    
    if (resultado == 1)
    {
        printf("Positivo.\n");
    }
    else if (resultado == -1)
    {
        printf("Negativo.\n");
    }
    else
    {
        printf("Cero.\n");
    }
    return 0;
}