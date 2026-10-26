

#include <stdio.h>




int suma_lenta(int numero, int otro_numero)
{
    if (otro_numero > 0)
    {
        while (otro_numero)
        {
            otro_numero = otro_numero - 1;
            numero = numero + 1;
        }
    }
    else if (otro_numero < 0)
    {
        while (otro_numero)
        {
            otro_numero = otro_numero + 1;
            numero = numero - 1;
        }
    }
//    else
//    {
// no hay mucho que hacer cuando el otro_numero es cero
//    }
    return numero;
}

int main()
{
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
