
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0
int es_primo(int numero)
{
    
    int i = 1;
    int contador = 0;
    int variable_return;
    while(i <= abs(numero))
    {
        if (abs(numero) % i == 0)
        {
            contador = contador + 1;
        }
        i = i + 1;
    }
    if (contador == 2)
    {
        variable_return = TRUE;
    }
    else
    {
        variable_return = FALSE;
    }
    return variable_return;
}
int main()
{  
   int numero;
   bool guardarvariable;
   printf("Ingrese un numero para verificar si es o no primo: \n");
   scanf("%d", &numero);
   guardarvariable = es_primo(numero);
   printf("El resultado es: %i", guardarvariable);
   return 0;
}
