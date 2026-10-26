/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>

typedef struct division{
    int dividendo;
    int divisor;
    int resto;
    int cociente;
} division_t;

division_t divide(division_t division_lenta);




int main()
{
    division_t division_lenta;
    division_t respuesta;

    
    printf("ingrese el dividendo: ");
    scanf("%d",&division_lenta.dividendo);
    
    printf("ingrese el divisor: ");
    scanf("%d",&division_lenta.divisor);
    
    respuesta = divide(division_lenta);
    
    printf("El cociente es: %d \n",respuesta.cociente);
    printf("El resto es: %d \n",respuesta.resto);

}



division_t divide(division_t division_lenta)
{
    
    if (division_lenta.divisor == 0)
    {
        return division_lenta;
    }
    else    
    {
        while (division_lenta.dividendo >= division_lenta.divisor)
        {
		division_lenta.dividendo = division_lenta.dividendo - division_lenta.divisor;
		division_lenta.cociente = division_lenta.cociente + 1;
        }
        division_lenta.resto = division_lenta.dividendo;
        return division_lenta;
    }

}