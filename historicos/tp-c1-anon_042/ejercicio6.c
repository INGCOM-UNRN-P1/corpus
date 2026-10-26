



#include <stdio.h>
#include <stdlib.h>

int division_lenta(int dividendo, int divisor){
    int cociente = 0;
    int signo_dividendo, signo_divisor;
    signo_dividendo = dividendo;
    signo_divisor = divisor;
    while(abs(dividendo) >= abs(divisor)){
        cociente = cociente + 1;
        dividendo = abs(dividendo) - abs(divisor);
    }
    if(signo_dividendo < 0 || signo_divisor < 0)
    {
        cociente = cociente *-1;
    }
	if(signo_dividendo < 0 && signo_divisor < 0)
    {
        cociente = cociente *-1;
    }
    return cociente;
}

int resto_lento(int dividendo, int divisor){
    int signo_dividendo, signo_divisor;
    signo_dividendo = dividendo;
    signo_divisor = divisor;
    while(abs(dividendo) >= abs(divisor)){
        dividendo = abs(dividendo) - abs(divisor);
    }
    if(signo_dividendo < 0 || signo_divisor < 0)
    {
        dividendo = dividendo *-1;
    }
	if(signo_dividendo < 0 && signo_divisor < 0)
    {
        dividendo = dividendo*-1;
    }
    return dividendo;
}

int main()
{
    int dividendo, divisor;
    int resultado;
    int resultador;
    printf("Ingrese el dividendo. \n");
    scanf("%d", &dividendo);
    printf("Ingrese el divisor. \n");
    scanf("%d", &divisor);

    resultado = division_lenta(dividendo, divisor);
    resultador = resto_lento(dividendo, divisor);
    printf("%d \n", resultado);
    printf("%d \n", resultador);

    return 0;
}