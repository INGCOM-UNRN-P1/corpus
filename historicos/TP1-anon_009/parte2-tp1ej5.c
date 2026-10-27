
#include <stdio.h>
 
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);

int main(int argc, char *argv[])
{
    printf("%i\n", divide_lento(125, 5));
    printf("%i\n", resto_lento(12, 5));
}



int divide_lento(int dividendo, int divisor)//Resta el divisor al dividendo siempre y cuando el resto sea mayor que 0. Devuelve la cantidad de veces que lo hace.
{
    int cociente;
    while((dividendo - divisor) > 0 )
    {
        dividendo= dividendo - divisor;
        cociente = cociente + 1;
    }
    return cociente;
}

int resto_lento(int dividendo, int divisor)//Le resta el divisot al dividendo siempre y cuando el resto sea mayor que 0 y devuelve el resto.
{

    while((dividendo - divisor) > 0 )
    {
        dividendo = dividendo - divisor;
    }
    return dividendo;
}
