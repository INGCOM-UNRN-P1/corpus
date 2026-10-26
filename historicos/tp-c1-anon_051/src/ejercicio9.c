
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int es_multiplo(int numero, int multiplo)
{
    int resultado;
    while (abs(numero) <= abs(multiplo))
    {
        multiplo = abs(multiplo) - abs(numero);
    }
    if (multiplo == 0)
    {
        resultado = TRUE;
    }
    else
    {
        resultado = FALSE;
    }
    return resultado;
}
int main()
{
   int numero, multiplo, guardar;
   printf("Ingrese un numero: \n");
   scanf("%d", &numero);
   printf("Ahora ingrese otro para ver si es multiplo: \n");
   scanf("%d", &multiplo);
   guardar = es_multiplo(numero, multiplo);
   printf("El resultado es %d" , guardar);
   return 0;
}
