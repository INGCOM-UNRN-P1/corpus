



#include <stdio.h>
#include <stdlib.h>
typedef struct division{ 
    int cociente;
    int resto;
} division_t;

void mostrar(division_t resultado_c) 
{
	
	printf("Cociente: %d\nResto: %d\n",resultado_c.cociente, resultado_c.resto);
}

division_t division_lenta(int dividendo, int divisor){ 
	
	division_t resultado_c;
    int signo_dividendo;
	int signo_divisor;
    resultado_c.cociente = 0;
    signo_dividendo = dividendo;
    signo_divisor = divisor;
    while(abs(dividendo) >= abs(divisor)){
        resultado_c.cociente = resultado_c.cociente + 1;
		resultado_c.resto = abs(dividendo) - abs(divisor);
        dividendo = abs(dividendo) - abs(divisor);
    }
    if(signo_dividendo < 0 || signo_divisor < 0)
    {
        resultado_c.cociente = resultado_c.cociente *-1;
		resultado_c.resto = resultado_c.resto *-1;
    }
	if(signo_dividendo < 0 && signo_divisor < 0)
    {
        resultado_c.cociente = resultado_c.cociente *-1;
        resultado_c.resto = resultado_c.resto*-1;
    }
	return resultado_c;
}

int main()
{
    int dividendo, divisor;
	division_t resultado_nuevo;
    printf("Ingrese el dividendo. \n");
    scanf("%d", &dividendo);
    printf("Ingrese el divisor. \n");
    scanf("%d", &divisor);
	
	resultado_nuevo= division_lenta(dividendo, divisor);
	mostrar(resultado_nuevo);
    return 0;
}