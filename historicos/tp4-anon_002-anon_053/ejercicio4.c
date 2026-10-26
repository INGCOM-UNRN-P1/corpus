

#include <stdio.h>

#define ERROR -1 

void obtenerCocienteYResto(int dividendo, int divisor, int *cociente, int *resto);

int main() 
{
    int numero1;
    int numero2;
    int resultadoCociente;
    int resultadoResto;

    printf("Ingrese el dividendo: ");
    scanf("%d", &numero1);

    printf("Ingrese el divisor: ");
    scanf("%d", &numero2);
    
    //Llamar a la funcion
    obtenerCocienteYResto(numero1, numero2, &resultadoCociente, &resultadoResto);

    printf("Cociente: %d\n", resultadoCociente);
    printf("Resto: %d\n", resultadoResto);

    return 0;
}


void obtenerCocienteYResto(int dividendo, int divisor, int *cociente, int *resto) 
{
    int error = 0;
    if (divisor == 0) 
    {
        error = ERROR;
    }

    *cociente = dividendo / divisor;//obtiene el cociente mediante la division
    *resto = dividendo % divisor;//obtiene el resto aplicando modulo
}
