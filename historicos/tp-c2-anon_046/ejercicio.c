

#include <stdio.h>
#include <limits.h>

#include "mis_funciones.h"

#define MAX_ELEMENTOS 10
#define MAX_DIGITOS   10
#define BASE_DECIMAL  10
#define FALSE 0
#define TRUE  1


int cargar_arreglo(int cantidad, long int arreglo[]) {
    char entrada[MAX_DIGITOS + 1] = {"\0"};
    int posicion = 0;
    int retry = FALSE;

    printf("Ingrese hasta %d enteros de a uno o un punto para finalizar\n",
           cantidad);
    while (posicion < cantidad && entrada[0] !='.') {
        printf("\t%d: ", posicion + 1);
        if (ingreso_sin_newline(entrada, sizeof(entrada), stdin)) {
            printf("\n*** Error en ingreso de numero entero. Reintente.\n");
            retry = TRUE;
        }
        if (entrada[0] == '.') {
            return posicion;
        }
        if (!retry && parse_long(entrada, &arreglo[posicion], BASE_DECIMAL)) {
            printf("\n*** Debe ingresar un numero entero. Reintente.\n");
            retry = TRUE;
        }
        if (retry) {
            retry = FALSE;
        } else {
            posicion++;
        }
    }

    return posicion;
}


int muestra_arreglo(int cantidad, long int arreglo[]) {
    printf("* Mostrando arreglo de %d elementos\n", cantidad);
    for (int i = 0; i < cantidad; i++) {
        printf("Elemento %d: %ld\n", i + 1, arreglo[i]);
    }

    return OK;
}


int promedio(int cantidad, long int arreglo[], float* promedio) {
    if (cantidad == 0) {
        return ERROR;
    }

    *promedio = 0;
    for (int i = 0; i < cantidad; i++) {
        *promedio = *promedio + arreglo[i];
    }
    *promedio = *promedio / cantidad;

    return OK;
}


int minimo(int cantidad, long int arreglo[], long int* minimo) {
    if (cantidad == 0) {
        return ERROR;
    }

    *minimo = LONG_MAX;
    for (int i = 0; i < cantidad; i++) {
        if (arreglo[i] < *minimo) {
            *minimo = arreglo[i];
        }
    }

    return OK;
}


int maximo(int cantidad, long int arreglo[], long int* maximo) {
    if (cantidad == 0) {
        return ERROR;
    }

    *maximo = LONG_MIN;
    for (int i = 0; i < cantidad; i++) {
        if (arreglo[i] > *maximo) {
            *maximo = arreglo[i];
        }
    }

    return OK;
}


int ordenar_de_menor_a_mayor(int cantidad, long int arreglo[]) {
    long int temp;

    for(int j = 0; j < cantidad - 1; j++) {
        for (int i = 0; i < (cantidad - 1 - j); i++) {
            if(arreglo[i] > arreglo[i + 1]) {
                
                temp = arreglo[i + 1];
                arreglo[i + 1] = arreglo[i];
                arreglo[i] = temp;
            }
        }
    }

    return OK;
}


int ordenar_de_mayor_a_menor(int cantidad, long int arreglo[]) {
    long int temp;

    for(int j = 0; j < cantidad - 1; j++) {
        for (int i = 0; i < (cantidad - 1 - j); i++) {
            if(arreglo[i] < arreglo[i + 1]) {
                
                temp = arreglo[i];
                arreglo[i] = arreglo[i + 1];
                arreglo[i + 1] = temp;
            }
        }
    }

    return OK;
}


int cargar_parametros_en_arreglo_de_enteros(int cantidad, char** parametros, long int arreglo[]) {
    int posicion = 0;
    int fallidos = 0;

    while (posicion < cantidad) {
        if (parse_long(parametros[posicion], &arreglo[posicion - fallidos], BASE_DECIMAL)) {
            fallidos++;
        }
        posicion++;
    }
    if (fallidos > 0) {
        printf("* %d de %d no pudieron registrarse como enteros\n", fallidos, cantidad);
    } else {
        printf("* Se registraron %d enteros en el arreglo\n", posicion - fallidos);
    }

    return cantidad - fallidos;
}

int main(int argc, char* argv[])
{
    long int array[MAX_ELEMENTOS] = {0};
    int elementos_cargados = 0;
    float fresultado;
    long int liresultado;

    
    if (argc == 1) {
        elementos_cargados = cargar_arreglo(MAX_ELEMENTOS, array);
        if (elementos_cargados == 0) {
            printf("No se cargaron elementos en el arreglo\n");
            return OK;
        } else {
            muestra_arreglo(elementos_cargados, array);
        }
    } else {
        elementos_cargados = cargar_parametros_en_arreglo_de_enteros(argc - 1, &argv[1], array);
        if (elementos_cargados == 0) {
            printf("No se cargaron elementos en el arreglo\n");
            return OK;
        } else {
            muestra_arreglo(elementos_cargados, array);
        }
    }

    if (!promedio(elementos_cargados, array, &fresultado)) {
        printf("\n* El promedio de los elementos del arreglo es: %.02f\n", fresultado);
    }

    if (!minimo(elementos_cargados, array, &liresultado)) {
        printf("* El minimo de los elementos del arreglo es: %ld\n", liresultado);
    }

    if (!maximo(elementos_cargados, array, &liresultado)) {
        printf("* El maximo de los elementos del arreglo es: %ld\n", liresultado);
    }

    ordenar_de_menor_a_mayor(elementos_cargados, array);
    printf("\n* Elementos del arreglo ordenados de menor a mayor:\n");
    muestra_arreglo(elementos_cargados, array);

    ordenar_de_mayor_a_menor(elementos_cargados, array);
    printf("\n* Elementos del arreglo ordenados de mayor a menor:\n");
    muestra_arreglo(elementos_cargados, array);

    return OK;
}
