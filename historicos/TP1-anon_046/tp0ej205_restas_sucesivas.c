
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int divide_lento(int dividendo, int divisor){
    int cociente = 0;
    int signo = 1;

    if (dividendo < 0){
        signo *= -1;
	dividendo *= -1;
    }
    if (divisor < 0){
        signo *= -1;
	divisor *= -1;
    }

    while (dividendo >= divisor){
        cociente += 1;
	dividendo -= divisor;
    }

    return cociente * signo;
}

int resto_lento(int dividendo, int divisor){
    int signo = 1;

    if (dividendo < 0){
        signo *= -1;
	dividendo *= -1;
    }
    if (divisor < 0){
        
	divisor *= -1;
    }

    while (dividendo >= divisor){
	dividendo -= divisor;
    }

    return dividendo * signo;
}

int main(int argc, char *argv[])
{
    long int numero[2];
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese dos numeros enteros de a uno, el segundo debe ser distinto de 0\n");
    for (int i = 0; i < 2; i++){
        printf("\t%d: ", i + 1);
        if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
            printf("\n*** Error en ingreso de numero entero\n");
            return (-1);
        }
	if (parseLong(entrada, &numero[i], 10) || (i == 1 && numero[i] == 0)){
            printf("\n*** Debe ingresar un numero entero\n");
            return (-1);
        }
    }

    printf("Resultado de la division y resto lentos de %d / %d = %d, %d %% %d = %d\n",
            numero[0], numero[1],
	    divide_lento(numero[0], numero[1]),
            numero[0], numero[1],
	    resto_lento(numero[0], numero[1]));
    printf("Verificacion: resultado de la division y resto de %d / %d = %d, %d %% %d = %d\n",
            numero[0], numero[1],
	    numero[0] / numero[1],
            numero[0], numero[1],
	    numero[0] % numero[1]);

    return 0;
}
