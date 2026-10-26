

#include <stdio.h>
#include "ejercicio.h"
#include <stdbool.h>



void test_suma_lenta(char mensaje[], 
                    int valor_uno, 
                    int valor_dos, 
                    int esperado)
{

    int resultado = suma_lenta(valor_uno, valor_dos);
    printf("%s: ", mensaje);
    if(resultado == esperado)
    {
        printf("OK\t");
    }
    else
    {
        printf("FAIL:\t");
    }
    
    printf("(%d)+(%d)=(%d) == (%d)\n", valor_uno, valor_dos, resultado, esperado);
}

int main()
{
    printf("INICIO TEST suma_lenta\n");
    test_suma_lenta("positivo positivo", 10, 10, 20);
    test_suma_lenta("positivo negativo", 10, -10, 0);
    test_suma_lenta("negativo positivo", -10, 10, 0);
    test_suma_lenta("negativo negativo", -10, -10, -20);
    test_suma_lenta("mas pruebas", 50, -10, 40);
    printf("FIN TEST suma_lenta\n");
    return 0;
}
