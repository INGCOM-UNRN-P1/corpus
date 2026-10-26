/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_043 de GitHub
*************************/

#include <stdio.h>
#include <conio.h>

int divide_lento(int dividendo, int divisor)
{
   if (dividendo > 0 && divisor > 0)
   {
       int cociente = 0;
       int resto = dividendo;

       while (resto >= divisor)
       {
           resto = resto - divisor;
           cociente++;
       }

       return cociente;
       
   }
   
}

int resto_lento(int dividendo, int divisor)
{
    if (dividendo > 0 && divisor > 0)
    {
        int cociente = 0;
        int resto = dividendo;

        while (resto >= divisor)
        {
            resto = resto - divisor;
            cociente++;
        }

        return resto;
       
    }
}

int main(int argc, char const *argv[])
{
    int dividendo, divisor, cociente, resto;

    printf("Introduzca dividendo (entero): ");
    do
    {
        scanf("%d", &dividendo);

        if (dividendo < 0)
        {
            printf("El numero debe ser positivo. Intente de nuevo.");
        }

    } while (dividendo < 0);
    
    printf("Introduzca divisor (entero): ");
    do
    {
        scanf("%d", &divisor);

        if (divisor < 0)
        {
            printf("El numero debe ser positivo. Intente de nuevo.");
        }
        
    } while (divisor < 0);
    

    
    cociente = divide_lento(dividendo, divisor);
    resto = resto_lento(dividendo, divisor);

    printf("Cociente: %d \n", cociente);
    printf("Resto: %d", resto);

    return 0;

}
