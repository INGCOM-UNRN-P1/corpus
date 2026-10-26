

#include <stdio.h>

typedef struct {
    int cociente;
    int resto;
}division_t;

division_t division_lenta(int dividendo, int divisor){
    division_t resultado;
    int resto_div= 0;
    int cociente_div = 0;
    while (dividendo>=divisor){
        dividendo = dividendo - divisor;
        cociente_div = cociente_div +1;
    }
    resultado.resto = dividendo;
    resultado.cociente = cociente_div;
    return resultado;
    
}


int main()
{
   division_t numero,resultado;
   int dividendo;
   int divisor;
   printf("Ingrese el dividendo: ");
   scanf("%i", &dividendo);
   printf("Ingrese el divisor: ");
   scanf("%i", &divisor);
   resultado= division_lenta(dividendo, divisor);
   printf("Resto: %i\nCociente: %i",resultado.resto, resultado.cociente );
   return 0;
}