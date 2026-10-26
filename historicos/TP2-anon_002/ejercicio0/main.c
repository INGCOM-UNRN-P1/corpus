

#include <stdio.h>
#include "ejercicio.h"

int main()
{
    printf("Ejercicio 1\n");
    int valor_uno;
    int valor_dos;
    int resultado;
    
    valor_uno = 10;
    valor_dos = 5;
    
    resultado = suma_lenta(valor_uno, valor_dos);
    printf("%d+%d=%d\n", valor_uno, valor_dos, resultado);
    
    valor_uno = -10;
    valor_dos = -5;
    
    resultado = suma_lenta(valor_uno, valor_dos);
    printf("%d+%d=%d\n", valor_uno, valor_dos, resultado);
    
    
    valor_uno = 10;
    valor_dos = -10;
    
    resultado = suma_lenta(valor_uno, valor_dos);
    printf("%d+%d=%d\n", valor_uno, valor_dos, resultado);
    
    valor_uno = -10;
    valor_dos = 5;
    
    resultado = suma_lenta(valor_uno, valor_dos);
    printf("%d+%d=%d\n", valor_uno, valor_dos, resultado);
    return 0;
}
