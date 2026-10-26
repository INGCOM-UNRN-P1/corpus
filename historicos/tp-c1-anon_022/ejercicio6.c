

#include <stdio.h>

int division_lenta(int dividendo, int divisor){
    int resto = 0;
    while (dividendo>=divisor){
        dividendo = dividendo - divisor;
        resto = dividendo;
    }
    return resto;
}

int cociente_lento( int dividendo, int divisor){
    int cociente = 0;
    while (dividendo>=divisor){
        dividendo = dividendo-divisor;
        cociente = cociente + 1;
    }
    return cociente;
}

int main()
{
   int dividendo, divisor, resultado_division, resultado_cociente;
   printf("Ingrese el dividendo: \n");
   scanf("%d", &dividendo);
   printf("Ingrese el divisor: \n");
   scanf("%d", &divisor);
   resultado_cociente = cociente_lento(dividendo, divisor);
   resultado_division = division_lenta(dividendo, divisor);
   printf("El cociente es: %d\n",resultado_cociente);
   printf("El resto es: %d\n", resultado_division);
   return 0;

}