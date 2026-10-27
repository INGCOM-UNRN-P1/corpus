

#include <stdio.h>
#include <math.h>

int es_primo(int numero)
{

    if (numero <= 1){
        return 0;
    }

    for (int i = 2; i <= sqrt(numero); i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
        
    }

    return 1;

}

int main(int argc, char const *argv[])
{
    int numero = 0, result = 0;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numero);

    result = es_primo(numero);

    if (result == 0)
    {
        printf("El numero no es primo: %d", result);
    }else{
        printf("El numero es primo: %d", result);
    }

    return 0;

}
