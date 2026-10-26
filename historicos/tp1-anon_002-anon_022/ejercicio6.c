

#include <stdio.h>


int division_lenta(int dividendo, int divisor)
{
    int resto = 0;
    if (dividendo<0)
    {
        dividendo = dividendo*(-1);
    }
    if (divisor<dividendo)
    {
        divisor = divisor *(-1);
    }
    while (dividendo >= divisor)
    {
        dividendo = dividendo - divisor;
        resto = dividendo;
    }
    return resto;
}

int cociente_lento(int dividendo, int divisor)
{
    int cociente = 0;
    if (dividendo<0)
    {
        dividendo = dividendo*(-1);
    }
    if (divisor < dividendo)
    {
        divisor = divisor*(-1);
    }
    while (dividendo>=divisor)
    {
        dividendo = dividendo - divisor;
        cociente = cociente + 1;
    }
    return cociente;
}


int main()
{
   int dividendo;
   int divisor;
   int resto;
   int cociente;
   printf("Ingrese el dividendo: \n");
   scanf("%d", &dividendo);
   printf("Ingrese el divisor: \n");
   scanf("%d",&divisor);
   resto = division_lenta(dividendo,divisor);
   cociente = cociente_lento(dividendo, divisor);
   printf("Resto: %d\n",resto);
   printf("Cociente: %d\n",cociente);
   return 0;
}