

#include <stdio.h>
#include <stdbool.h>

bool es_multiplo(int numero, int otro_numero);



int main()

{
    int numero;
    int otro_numero;
    int resultado;

    printf("Ingrese un numero -> ");
    scanf("%d", &numero);

    printf("Ingrese otro numero menor-> ");
    scanf("%d", &otro_numero);
    
    resultado = es_multiplo(numero, otro_numero);
    
    if (resultado)
    {
        printf("\n%d es multiplo de %d", otro_numero, numero);
    }
    else
    {
        printf("\n%d no es multiplo de %d", otro_numero, numero);
    }
    return 0;
}


bool es_multiplo(int numero, int otro_numero)
{
    
    while (numero>=otro_numero)
    {
        numero -= otro_numero;

    }
    if (numero == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}