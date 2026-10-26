

#include <stdio.h>

int suma_lenta(int numero, int otro_numero);



int main()

{
    int numero;
    int otro_numero;
    int resultado;

    printf("Ingrese un numero -> ");
    scanf("%d", &numero);

    printf("Ingrese otro numero -> ");
    scanf("%d", &otro_numero);
    
    printf("La suma de ambos es: ");

    resultado = suma_lenta(numero, otro_numero);
    
    printf("%d", resultado);

    return 0;
}


int suma_lenta(int numero, int otro_numero)
{
    int aux;

    if (numero>0)
    {
        aux = numero;

        while (aux>0)
        {
        otro_numero = otro_numero +1;
        aux = aux -1;
        }

        return otro_numero;
    }

    else if (otro_numero>0)
    {
        aux = otro_numero;

        while (aux>0)
        {
        numero = numero +1;
        aux = aux -1;
        }

        return numero;
    }

    else
    {
        aux = otro_numero;

        while (aux<0)
        {
        numero = numero -1;
        aux = aux +1;
        }

        return numero;
    }
}