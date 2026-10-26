

#include <stdio.h>
#include "mis_funciones.h"

#define MAX_DIGITOS   10
#define BASE_DECIMAL  10

typedef struct tiempo {
    int segundos;
    int minutos;
    int horas;
} tiempo_t;


int mostrar_tiempo(tiempo_t tiempo) {

    printf("%d:%d:%d\n",
           tiempo.horas, tiempo.minutos, tiempo.segundos);

    return OK;
}


int sumar_horas(tiempo_t* resultado, tiempo_t tiempo1, tiempo_t tiempo2) {
    resultado->horas =
        tiempo1.horas + tiempo2.horas;

    return OK;
}


int sumar_minutos(tiempo_t* resultado, tiempo_t tiempo1, tiempo_t tiempo2) {
    tiempo_t unaHora;

    unaHora.horas = 1;
    unaHora.minutos = 0;
    unaHora.segundos = 0;

    resultado->minutos =
        tiempo1.minutos + tiempo2.minutos;
    if (resultado->minutos > 59) {
        resultado->minutos = resultado->minutos - 60;
        sumar_horas(resultado, *resultado, unaHora);
    }

    return OK;
}


int sumar_segundos(tiempo_t* resultado, tiempo_t tiempo1, tiempo_t tiempo2) {
    tiempo_t unMinuto;

    unMinuto.horas = 0;
    unMinuto.minutos = 1;
    unMinuto.segundos = 0;

    resultado->segundos =
        tiempo1.segundos + tiempo2.segundos;
    if (resultado->segundos > 59) {
        resultado->segundos = resultado->segundos - 60;
        sumar_minutos(resultado, *resultado, unMinuto);
    }

    return OK;
}


int sumar_tiempos(tiempo_t* resultado, tiempo_t tiempo1, tiempo_t tiempo2) {

    sumar_segundos(resultado, tiempo1, tiempo2);
    sumar_minutos(resultado, *resultado, tiempo1);
    sumar_minutos(resultado, *resultado, tiempo2);
    sumar_horas(resultado, *resultado, tiempo1);
    sumar_horas(resultado, *resultado, tiempo2);

    return OK;
}


int crear_tiempo(tiempo_t* resultado, long int horas, long int minutos, long int segundos) {

    resultado->horas    = horas;
    resultado->minutos  = minutos;
    resultado->segundos = segundos;

    return OK;
}

int main()
{
    tiempo_t tiempo[2], resultado;
    char entrada[MAX_DIGITOS + 1] = {"\0"};
    long int numero[3];

    resultado.horas    = 0;
    resultado.minutos  = 0;
    resultado.segundos = 0;

    
    printf("Para ingresar dos tiempos, se le solicitara ingresar 2 tandas de tres numeros enteros positivos de a uno\n");
    for (int j = 0; j < 2; j++) {
        printf("Ingrese tres numeros enteros positivos de a uno\n");
        printf(" El primero para las horas, el segundo para los minutos (<60) y el tercero para los segundos (<60)\n");
        
        for (int i = 0; i < 3; i++) {
            printf("\t%d: ", i + 1);
            if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
                printf("\n*** Error en ingreso de numero entero\n");
                return ERROR;
            }
            if (parse_long(entrada, &numero[i], BASE_DECIMAL) || (numero[i] < 0)) {
                printf("\n*** Debe ingresar un numero entero mayor a 0\n");
                return ERROR;
            }
            
            if (i > 0 && numero[i] > 59) {
                printf("\n*** Debe ingresar un numero entero menor a 60\n");
                return ERROR;
            }
        }
        crear_tiempo(&tiempo[j], numero[0], numero[1], numero[2]);
        printf("* El tiempo ingresado es ");
        mostrar_tiempo(tiempo[j]);
    }

    
    printf("* La suma de los tiempos ingresados es ");
    sumar_tiempos(&resultado, tiempo[0], tiempo[1]);
    mostrar_tiempo(resultado);

    return OK;
}
