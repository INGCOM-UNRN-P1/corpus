
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS 10

int suma_lenta(int numero, int otronumero){
    
    if (numero < otronumero){
        otronumero += numero;
	numero = otronumero - numero;
	otronumero -= numero;
    }
    

    while (otronumero > 0){
        numero += 1;
	otronumero -= 1;
    }

    return numero;
}

int main(int argc, char *argv[])
{
    long int natural[2];
    char entrada[MAX_DIGITOS + 1] = {"\0"};

    printf("Ingrese dos numeros naturales de a uno\n");
    for (int i = 0; i < 2; i++){
        printf("\t%d: ", i + 1);
        if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)){
            printf("\n*** Error en ingreso de numero entero\n");
            return (-1);
        }
        if (parseLong(entrada, &natural[i], 10) || (natural[i] < 1)){
            printf("\n*** Debe ingresar un numero natural\n");
            return (-1);
        }
    }

    printf("Resultado de suma lenta de %ld + %ld = %ld\n", natural[0],
            natural[1], suma_lenta(natural[0], natural[1]));

    return 0;
}
