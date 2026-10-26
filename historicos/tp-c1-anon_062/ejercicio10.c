


#include <stdio.h>

int Factorial(int numero)
{
    int acumula = 1;
    int i = 1;

    while (i <= numero)
    {
    acumula = acumula * i;
    i++;
    }

    return acumula;
}


// ----------------- MAIN ---------------
int main (int argc, char *argv[])
{
   int numero = 0;
   int calculando = 0;

   printf("ingresa un numero para calcular el factorial \n");
   scanf("%d", &numero);

   calculando = Factorial(numero);
   printf("el FACTORIAL ES %d ", calculando);
   return 0;
}
