

#include <stdio.h>
#include "ejercicio.h"

int main()
{
    printf("Suma lenta\n");
    int valor_uno;
    int valor_dos;
    int resultado;
    printf("Ingrese el primer valor a sumar: ");
    scanf("%d", &valor_uno);
    printf("\nIngrese el primer valor a sumar: ");
    scanf("%d", &valor_dos);
    
    resultado = suma_lenta(valor_uno, valor_dos);
    printf("\nLa cuenta resultante es:\n");
    printf("%d+%d=%d\n", valor_uno, valor_dos, resultado);
    
   return 0;
}
