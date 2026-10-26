
#include <stdio.h>
#include <stdlib.h>

int signo(int numero)
{
    
    int variable;
    if (numero == 0)
    {
        variable = 0;
    }
    else if(numero + abs(numero) == 0)
    {
        variable = -1;
    }
    else if(numero - numero == 0)
    {
        variable = 1;
    }
    return variable;
}

int main()
{
    int llamada;
    int numero;
    printf("Ingrese un numero para indicar si es positivo negativo o cero: \n");
    scanf("%d", &numero);
    llamada = signo(numero);
    printf("El numero es %i", llamada);
    return 0;
}

