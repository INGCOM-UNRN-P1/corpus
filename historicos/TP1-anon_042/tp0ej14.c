
#include <stdio.h>
int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);
int main(int argc, char *argv[])
{
    int dividendo;
    int divisor;
    int resto;
    int cociente;
    int resultado;
    int resultado_resto;
    int resultado_total;
    printf("Ingresar el dividendo: ");
    scanf("%d", &dividendo);
    printf("Ingresar el divisor: ");
    scanf("%d", &divisor);
    resultado = divide_lento(dividendo, divisor);
    resultado_resto = resto_lento(dividendo, divisor);
    resultado_total = printf("El cociente es: %d \nEl resto es: %d", resultado, resultado_resto);
    return  resultado_total;
	
}

int divide_lento(int dividendo, int divisor)
{
    int cociente= 0;

    while (dividendo >= divisor)
    {
        dividendo = dividendo - divisor;
        cociente ++;
    }
    return cociente;
}

int resto_lento(int dividendo, int divisor)
{   int cociente= 0;
    int resto;
    int guardar = dividendo;
        while (dividendo >= divisor)
        {
            dividendo = dividendo - divisor;
            cociente ++;
        }
    resto = guardar - (divisor * cociente);
    return resto;
}


