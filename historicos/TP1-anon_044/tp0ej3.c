/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_044
*************************/
#include <stdio.h>

int main()
{
    int numero_a, numero_b;
    
    printf("Ingrese el primer numero entero:\n");
    scanf("%d", &numero_a);
    printf("Primer numero: A = %d\n\n", numero_a);
    printf("Ingrese el segundo numero entero:\n");
    scanf("%d", &numero_b);
    printf("Segundo Numero: B = %d\n\n", numero_b);


    printf("Operador de multiplicacion: A*B = %d\n", numero_a * numero_b);
    printf("Operador de division: A/B = %d\n", numero_a / numero_b);
    printf("Operador de resto: A%B = %d\n\n", numero_a % numero_b);

    return 0;
}
