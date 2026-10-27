
#include <stdio.h>

int suma_lenta(int numero, int otro_numero)
{
    volatile int i;
    for(i = 0; i < otro_numero; i++)
    {
        numero++;
    }
    return numero;
}

int main()
{
    volatile int numero_a, numero_b, resultado;
    
    printf("Ingrese un numero:");
    scanf("%d", &numero_a);
    printf("Ingrese otro numero:");
    scanf("%d", &numero_b);
    resultado = suma_lenta(numero_a, numero_b);
    printf("%d + %d = %d\n", numero_a, numero_b, resultado);
    
    return 0;
}
