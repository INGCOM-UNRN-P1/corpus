/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_042 de GitHub
*************************/
#include <stdio.h>

long long int fibonacci(long int numero);
int main(int argc, char *argv[])
{
    int numero;
    int resultado;
    printf("Ingresar un numero entero mayor a 10: ");
    scanf("%d", &numero);
    resultado = fibonacci(numero);
    return resultado;
}

long long int fibonacci(long int numero)
{
	
    int cont;
    int a = 0;
    int b = 1;
    unsigned long long int c;
    printf("0,1,");
    for(cont = 0; cont < numero; cont++)
    {
	
        c = a + b;
        if (c < numero)
        {
            printf("%llu,", c);
        }
        a = b;
        b = c;
		
    }
    return 0;
}


