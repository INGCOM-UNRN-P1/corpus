
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int compara(int numero, int otronumero){
    if (numero < otronumero)
        return -1;
    if (numero == otronumero)
        return 0;
    
    return 1;
}

int main(int argc, char *argv[])
{
    long int numero[2];
    char entrada[MAX_DIGITOS + 1] = {"\0"};
    char valor;

    printf("Ingrese dos numeros de a uno\n");
    for (int i = 0; i < 2; i++){
        printf("\t%d: ", i + 1);
        if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
            printf("\n*** Error en ingreso de numero\n");
            return (-1);
        }
        if (parseLong(entrada, &numero[i], 10)){
            printf("\n*** Debe ingresar un numero\n");
            return (-1);
        }
    }

    switch(compara(numero[0], numero[1])){
        case  0:
	    valor = '=';
	    break;
        case  1:
	    valor = '>';
	    break;
	default:
	    valor = '<';
	    break;
    }
    printf("Resultado de la comparación: %ld %c %ld\n",
            numero[0], valor, numero[1]);

    return 0;
}
