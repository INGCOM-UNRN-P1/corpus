

#include <stdio.h>
#include "mis_funciones.h"
#include "mis_cadenas.h"


#include <string.h>
//#include <strings.h>

#define MAX_CARACTERES 100
#define MAX_CARACTERES_CADENA 100
#define POSICION_INSERCION 4

#define BASE_DECIMAL 10

#define ARCHIVO_ASCENDENTE   1
#define ARCHIVO_NO_ORDENADO  0
#define ARCHIVO_DESCENDENTE -1
#define UNKNOWN             -2

#define ARCHIVO_INEXISTENTE    -4
#define ERROR_CANTIDAD_NUMEROS -5

int main(int argc, char *argv[]) {
    FILE *archivo;
    char *filename = NULL;
    char linea[22] = {"\0"};

    int estadoLinea = OK;
    int cantidadNumeros = 0;
    int numero[2] = {0};
    int i = 0;
    int orden = UNKNOWN;
    int salida = UNKNOWN;

    switch(argc) {
        case 1:
            printf("ERROR: Debe ingresar el nombre del archivo a revisar\n");
            break;
        case 2:
            filename = argv[1];
            break;
        default:
            printf("ERROR: Debe ingresar solo nombre del archivo a revisar\n");
            break;
    }

    archivo = fopen(filename, "r");
    if (archivo == NULL) {
        printf("ERROR: archivo inexistente o faltan permisos\n");
        return ARCHIVO_INEXISTENTE;
    }

    estadoLinea = ingreso_sin_newline(linea, MAX_DIGITOS, archivo);
    if (estadoLinea == OK) {
        estado = parse_long(linea, cantidadNumeros, BASE_DECIMAL);
        if (estado == ERROR) {
            fclose(archivo);
            return ERROR_CANTIDAD_NUMEROS;
        }
    }

    while (salida == UNKNOWN && estadoLinea == OK) {
        estadoLinea = ingreso_sin_newline(linea, MAX_DIGITOS, archivo);
        if (estadoLinea == OK) {
            estado = parse_long(linea, numero[i % 2], BASE_DECIMAL);
            if (estado == ERROR) {
                fclose(archivo);
                return ERROR_CANTIDAD_NUMEROS;
            }
        }
        
        if (i == 1) {
            if (numero[1] > numero[0]) {
                orden = ARCHIVO_ASCENDENTE;
            }
            if (numero[1] < numero[0]) {
                orden = ARCHIVO_DESCENDENTE;
            }
            if (numero[1] == numero[0]) {
                orden = ARCHIVO_NO_ORDENADO;
            }
        }
        if (orden == ARCHIVO_ASCENDENTE && numero[i] < numero[i - 1]) {
            orden = ARCHIVO_NO_ORDENADO;
        }

        i = i + 1;
    }


    fclose(archivo);

    return salida;
}
