

#include <stdio.h>

int compara(int numero, int otro_numero);



int main()

{
    int numero;
    int otro_numero;
    int resultado;

    printf("Ingrese el primer numero -> ");
    scanf("%d", &numero);

    printf("Ingrese el segundo numero -> ");
    scanf("%d", &otro_numero);
    
    printf("Resultado: ");

    resultado = compara(numero, otro_numero);
    
    printf("%d", resultado);

    return 0;
}


int compara(int numero, int otro_numero)
{
    if (numero > otro_numero)
    {
        return 1;
    }
    else if (numero < otro_numero)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}