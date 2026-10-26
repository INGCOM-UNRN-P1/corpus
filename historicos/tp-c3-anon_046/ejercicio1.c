

#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS   10
#define BASE_DECIMAL  10

typedef struct fraccion {
    int numerador;
    int denominador;
} fraccion_t;


int mostrar_fraccion(fraccion_t fraccion) {

    printf("%d / %d\n",
           fraccion.numerador, fraccion.denominador);

    return OK;
}


int sumar_fracciones(fraccion_t* resultado, fraccion_t fraccion1, fraccion_t fraccion2) {

    resultado->denominador =
        fraccion1.denominador * fraccion2.denominador;
    resultado->numerador =
        fraccion1.numerador * fraccion2.denominador +
        fraccion2.numerador * fraccion1.denominador;

    return OK;
}


int multiplicar_fracciones(fraccion_t* resultado, fraccion_t fraccion1, fraccion_t fraccion2) {

    resultado->denominador =
        fraccion1.denominador * fraccion2.denominador;
    resultado->numerador =
        fraccion1.numerador * fraccion2.numerador;

    return OK;
}


int sumar_entero_a_fraccion(fraccion_t* resultado, long int entero, fraccion_t fraccion) {

    resultado->denominador = fraccion.denominador;
    resultado->numerador =
        entero * fraccion.denominador + fraccion.numerador;

    return OK;
}

int main()
{
    fraccion_t fraccion1, fraccion2, resultado;
    char entrada[MAX_DIGITOS + 1] = {"\0"};
    long int liresultado;

    printf("Ingrese primer numerador: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de datos\n");
        return ERROR;
    }
    if (parse_long(entrada, &liresultado, BASE_DECIMAL)) {
        printf("\n*** Debe ingresar un numero entero\n");
        return ERROR;
    }
    fraccion1.numerador = liresultado;

    printf("Ingrese primer denominador: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de datos\n");
        return ERROR;
    }
    if (parse_long(entrada, &liresultado, BASE_DECIMAL)) {
        printf("\n*** Debe ingresar un numero entero\n");
        return ERROR;
    }
    fraccion1.denominador = liresultado;

    printf("Ingrese segundo numerador: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de datos\n");
        return ERROR;
    }
    if (parse_long(entrada, &liresultado, BASE_DECIMAL)) {
        printf("\n*** Debe ingresar un numero entero\n");
        return ERROR;
    }
    fraccion2.numerador = liresultado;

    printf("Ingrese segundo denominador: ");
    if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
        printf("\n*** Error en ingreso de datos\n");
        return ERROR;
    }
    if (parse_long(entrada, &liresultado, BASE_DECIMAL)) {
        printf("\n*** Debe ingresar un numero entero\n");
        return ERROR;
    }
    fraccion2.denominador = liresultado;

    
    printf("* Primer fraccion ingresada: ");
    mostrar_fraccion(fraccion1);
    printf("* Segunda fraccion ingresada: ");
    mostrar_fraccion(fraccion2);

    
    sumar_fracciones(&resultado, fraccion1, fraccion2);
    printf("* La suma de las fracciones es: ");
    mostrar_fraccion(resultado);

    
    multiplicar_fracciones(&resultado, fraccion1, fraccion2);
    printf("* La multiplicacion de las fracciones es: ");
    mostrar_fraccion(resultado);

    
    sumar_entero_a_fraccion(&resultado, fraccion1.numerador, fraccion2);
    printf("* La suma del primer numerador con la segunda fracion es: ");
    mostrar_fraccion(resultado);

    return OK;
}
