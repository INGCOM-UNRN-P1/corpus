/*************************
Ingenieria en Computacion - UNRN Andina
Programacion 1
anon_046 de GitHub
*************************/
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 2

int main(int argc, char *argv[])
{
    long int entero;
    char entrada[MAX_DIGITOS + 1] = {"\0"};
    char dia[][10] = {"lunes",
                    "martes",
		    "miercoles",
		    "jueves",
		    "viernes",
		    "sabado",
		    "domingo"};

    printf("Ingrese un numero para el dia de la semana: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero entero\n");
	return (-1);
    }
    if (parseLong(entrada, &entero, 10) || (entero < 1 || entero > 7)){
        printf("\n*** Debe ingresar un numero entero entre 1 y 7\n");
        return (-1);
    }

    switch(entero){
        case 1: printf("%ld - %s\n", entero, dia[entero - 1]);
	    break;
        case 2: printf("%ld - %s\n", entero, dia[entero - 1]);
	    break;
        case 3: printf("%ld - %s\n", entero, dia[entero - 1]);
	    break;
        case 4: printf("%ld - %s\n", entero, dia[entero - 1]);
	    break;
        case 5: printf("%ld - %s\n", entero, dia[entero - 1]);
	    break;
        case 6: printf("%ld - %s\n", entero, dia[entero - 1]);
	    break;
        case 7: printf("%ld - %s\n", entero, dia[entero - 1]);
	    break;
	default:
	    printf("Error no considerado\n");
	    break;
    }

    return 0;
}
