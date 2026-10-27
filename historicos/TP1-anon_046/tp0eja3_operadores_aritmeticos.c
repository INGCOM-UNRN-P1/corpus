
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 12

int main(int argc, char *argv[])
{
    char entrada[MAX_DIGITOS + 1] = {'\0'};
    long int enteroA, enteroB;
    char *pchar;

    printf("primer numero: A = ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero entero\n");
        return (-1);
    }
    if (parseLong(entrada, &enteroA, 10)){
        printf("\n*** Debe ingresar un numero entero\n");
        return (-1);
    }

    
    pchar = entrada;
    while(*pchar != '\0'){
	*pchar = '\0';
        pchar++;
    }
    printf("segundo numero: B = ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
        printf("\n*** Error en ingreso de numero entero\n");
        return (-1);
    }
    if (parseLong(entrada, &enteroB, 10)){
        printf("\n*** Debe ingresar un numero entero\n");
        return (-1);
    }

    printf("Operador multiplicacion: A*B = %d\n", enteroA*enteroB);
    printf("Operador division: A/B = %d\n", enteroA/enteroB);
    printf("Operador resto: A%%B = %d\n", enteroA%enteroB);

    return 0;
}
