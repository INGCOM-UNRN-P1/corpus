

#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS  10
#define BASE_DECIMAL 10
#define CONV_CAF      1
#define CONV_FAC      2



float convertir_a_fahrenheit(float temperatura)
{
    float resultado;

    resultado = temperatura *9 / 5 + 32;

    return resultado;
}


float convertir_a_centigrados(float temperatura)
{
    float resultado;

    resultado = (temperatura - 32) * 5 /9;

    return resultado;
}

int main()
{
    float resultado;
    float temperatura;
    long int caf_o_fac;
    char entrada[MAX_DIGITOS + 1] = {"\0"}, seleccion;

    printf("1 - para convertir de escala centigrada a fahrenheit\n");
    printf("2 - para convertir de escala fahrenheit a centigrada\n");
    printf("Ingrese la conversion de temperatura a realizar: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de datos\n");
        return (-1);
    }
    if (parse_long(entrada, &caf_o_fac, BASE_DECIMAL) ||
            !(caf_o_fac == CONV_CAF || caf_o_fac == CONV_FAC)) {
        printf("\n*** Debe ingresar la opcion 1 o 2\n");
        return (-1);
    }
    seleccion = caf_o_fac;

    printf("Ingrese la temperatura a convertir: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de datos\n");
        return (-1);
    }
    if (parse_float(entrada, &temperatura)) {
        printf("\n*** Debe ingresar un numero\n");
        return (-1);
    }

    if (seleccion == CONV_FAC) {
        resultado = convertir_a_centigrados(temperatura);
        printf("\n%.02f fahrenheit son %.02f centigrados\n", temperatura, resultado);
    }
    if (seleccion == CONV_CAF) {
        resultado = convertir_a_fahrenheit(temperatura);
        printf("\n%.02f centigrados son %.02f fahrenheit\n", temperatura, resultado);
    }

    return 0;
}
