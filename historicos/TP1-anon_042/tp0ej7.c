
#include <stdio.h>
int factorial(int numero);
int factorial_reload(int numero);
int main(int argc, char *argv[])
{
    int numero;
    int resultado;
    printf("Ingresar un numero: ");
    scanf("%d", &numero);
    resultado = factorial_reload(numero);
    return resultado;
}

int factorial(int numero)
{
    int total = 1;
    int i;
    for(i=1;i <= numero;i++)
    {
        total = total * i;
    }
    printf("El factorial de %d es: %d \n", numero, total);
    return 0;
}

int factorial_reload(int numero)
{
    int c = 0;
    int reload = 1;
    for(c= 0; c <= numero; c++)
    {
        reload = factorial(c);
    }
	return 0;
}
