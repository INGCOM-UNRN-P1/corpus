
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int isqrt(int entero){
    int minimo, medio, maximo;
    
    if (entero < 2)
        return entero;

    minimo = 1;
    maximo = entero / 2;
    while (minimo <= maximo){
        medio = (maximo + minimo) / 2;
	if (entero < (medio * medio))
	    maximo = medio - 1;
	else
	    minimo = medio + 1;
    }

    return maximo;
}

int main(int argc, char *argv[])
{

    long int entero, temp;
    char entrada[MAX_DIGITOS + 1] = {"\0"};
    char *nombre[2] = {"n", "m"};

    for (int repeticion = 0; repeticion < 2; repeticion++){
        printf("Ingrese el valor %s: ", nombre[repeticion]);
        if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
            printf("\n*** Error en ingreso de numero entero\n");
            return (-1);
        }
        if (parseLong(entrada, &entero, 10) || entero < 0){
            printf("\n*** Debe ingresar un numero entero positivo\n");
            return (-1);
        }

        printf("La parte entera de la raiz cuadrada de %s (%ld) es %ld\n", 
	       nombre[repeticion], entero, isqrt(entero));
    }

    return 0;
}
