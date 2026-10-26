

#include <stdio.h>
#include <stdbool.h>

bool es_primo(int numero);



int main()

{
    int numero;
    bool resultado;

    printf("Ingrese un numero -> ");
    scanf("%d", &numero);
    
    resultado = es_primo(numero);
    
    if (resultado)
    {
        printf("\nEl numero es primo");
    }
    else
    {
        printf("\nEl numero no es primo");
    }
    return 0;
}


bool es_primo(int numero)
{
    int aux = 2;
    int resto;

    while (aux < numero)
    {
        resto = numero;
        while (resto>=aux)
        {
            resto = resto - aux;
            if (resto==0)
            {
                return false;
            }
        }
    
        aux++;
    }
    return true;
}

