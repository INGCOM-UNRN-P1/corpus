
#include <stdio.h>

int es_primo(int numero);
 
int main(int argc, char *argv[])
{
    int numero;
    int result;

    printf("Ingrese un número: \n\t");
    scanf("%d", &numero);

    result = es_primo(numero);

    if(result == 1)
    {
        printf("Es primo!");
    }
    else
    {
        printf("No es primo!");
    }   
}

int es_primo(int numero)
{
    if(numero <= 0 || numero == 2)
    {
        return 0;
    }
    if(numero == 1)
    {
        return 1;
    }
    for(int i = 2; i < numero; i++)
    {
        if(numero % i == 0)
        {
            return 0;
        }
    }
    return 1;
}