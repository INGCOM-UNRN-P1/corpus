
#include <stdio.h>
#include <stdlib.h>
int division_lenta(int dividendo, int divisor)
{
    
    int cociente = 0;
    int resultado;
    resultado = dividendo;
    while(abs(resultado) >= abs(divisor)){
        cociente = cociente + 1;
        resultado = abs(resultado) - abs(divisor);
    }
    if(dividendo < 0 || divisor < 0)
    {
        if(dividendo < 0 && divisor < 0)
        {
            cociente = cociente *-1;
        }
        cociente = cociente *-1;
    }
    return cociente;
}
int resto_lento(int dividendo, int divisor){
    int resto;
    int resultado;
    resultado = dividendo;
    while(abs(resultado) >= abs(divisor)){
        resultado = abs(resultado) - abs(divisor);
    }
    if(dividendo < 0 || divisor < 0)
    {
        if(dividendo < 0 && divisor < 0)
        {
            resultado = resultado *-1;
        }
        resultado = resultado *-1;
    }
    return resultado;
}
int main()
{
    int dividendo;
    int divisor;
    int guardar; 
    int guardar1;
    
    printf("Ingresar un dividendo \n");
    scanf("%d", &dividendo);
    
    printf("Ingresar un divisor \n");
    scanf("%d", &divisor);
    
    guardar = division_lenta(dividendo, divisor);
    guardar1 = resto_lento(dividendo, divisor);
    printf("El cociente es: %d \n", guardar);
    printf("El resto es: %d \n", guardar1);
    return 0;
}

