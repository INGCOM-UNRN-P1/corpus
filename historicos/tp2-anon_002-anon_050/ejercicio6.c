

#include <stdio.h>
#include <stdbool.h>


bool prima_lejana(int numero)
{
    if (numero <= 1)
    {
        return false;
    }
    else
    {
        for (int i = 2; i * i <= numero; i++)
        {
            return (numero % i != 0);
        }
    }
}


int alabama(int numero)
{
    int suma = 0;

    for (int i = 2; i <= numero; i++ )
    {
        if (prima_lejana(i))
        {
            suma = suma + i;
        }
    }
    return suma;
}

int main()
{
    int num;
    
    printf("Ingrese el número máximo para operar la suma de primos: \n");
    scanf("%d", &num);

    printf("La suma de los primos entre 2 y %d es: %d\n", num, alabama(num));
    return 0;
}
