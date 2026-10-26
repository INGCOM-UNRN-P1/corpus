

#include <stdio.h>

/**
 * La función duplica el valor de una variable dada.
 *  @param variable a duplicar.
 *  @pre int válido.
 */
void duplica(int* variable)
{
    *variable = *variable * 2;
}

int main()
{
    int variable;
    printf("Ingrese un número entero:\n");
    scanf("%d", &variable);

    duplica(&variable);
    printf("El número duplicado es %d.\n", variable);

    return 0;
}