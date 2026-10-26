

#include <stdio.h>

int division_lenta(int dividendo, int divisor);

int cociente_lento(int dividendo, int divisor);

int main()
{
    int dividendo = 24;
    int divisor = 6;

    int resultado_division = division_lenta(dividendo, divisor);
    int resultado_cociente = cociente_lento(dividendo, divisor);
    printf("\nResto %d \nCociente %d", resultado_division, resultado_cociente);

    return 0;
}

int division_lenta(int dividendo, int divisor)
{
    int resto;
    resto = dividendo;
    printf("Division lenta: %d\n", dividendo);
    while (resto >= divisor)//en cada vuelta se le restara el divisor 
    {
        resto = resto - divisor;
        printf("%d\n", resto);
    }
    return resto;    
}
//pre: recibe 2 enteros positivos
//pos: retorna el resto de la division

int cociente_lento(int dividendo, int divisor)
{
    int cociente;
    printf("Cociente: %d\n", divisor);
    while(dividendo >= divisor)//en cada vuelta el cociente contara cuantas veces se le resto el divisor al divideno
    {
        dividendo = dividendo - divisor;
        cociente = cociente + 1;
        printf("%d\n", cociente);
    }
    return cociente;
}
//pre:recibe 2 enteros positivos con divisor mayor a 0
//pos:retorna el cociente de la division



