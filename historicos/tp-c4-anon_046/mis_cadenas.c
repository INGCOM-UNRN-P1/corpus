/*************************
Diego Mingorance (anon_046 de GitHub_ - anon_001
Programacion 1 - Ingenieria en computacion
*************************/
#include "mis_cadenas.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es un puntero no nulo
 *  @param capacidad la capacidad es un numero distinto a el largo de la cadena en si
                    y es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
                                  a la capacidad indicada por el argumento
 *  @post
 */
int largo_seguro(char cadena[], int capacidad) {
    int longitud = 0;

    while (longitud < capacidad && cadena[longitud] != '\0') {
        longitud = longitud + sizeof(char);
    }

    if (longitud == capacidad) {
        return CADENA_SIN_TERMINADOR;
    }

    return longitud;
}

/**
 * La funcion inserta una cadena en otra en la posicion indicada sin exceder la capacidad del arreglo destino.
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a insertar en destino
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @param capacidadOrigen la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param posicion la posicion en la que se insertara origen en destino
 *  @pre es un valor numerico entero positivo desde 0
 *  @param cadenaDestino es la direccion de la cadena con los caracteres a insertar de origen
 *  @pre cadenaDestino es un puntero no nulo que contiene al menos un '\0'
 *  @param capacidadDestino la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres del destino
         y los valores negativos, las siguientes situaciones de error:
            CADENA_NO_ENTRA cuando la cantidad de carateres de origen sumada a los caracteres
                                  de destino sea mayor a la capacidad indicada por el argumento
            CADENA_A_INSERTAR_POSTERIOR cuando la posicion a insertar es posterior a la longitud
                                  de la cadenaDestino
 *  @post
 */
int cadena_insertar(char cadenaOrigen[],  int capacidadOrigen, const int posicion,
                    char cadenaDestino[], int capacidadDestino) {
    int largoCadenaOrigen, largoCadenaDestino;
    int ultimaPosicion, contador;

    largoCadenaOrigen = largo_seguro(cadenaOrigen, capacidadOrigen);
    largoCadenaDestino = largo_seguro(cadenaDestino, capacidadDestino);

    
    if (capacidadDestino < largoCadenaDestino + largoCadenaOrigen) {
        return CADENA_NO_ENTRA;
    }

    
    
    if (largoCadenaDestino < posicion) {
        return CADENA_A_INSERTAR_POSTERIOR;
    }

    
    ultimaPosicion = largoCadenaOrigen + largoCadenaDestino;

    
    contador = 0;
    while (largoCadenaDestino + 1 - posicion - contador) {
        cadenaDestino[ultimaPosicion - 1 - contador] = cadenaDestino[largoCadenaDestino - 1 - contador];
        contador = contador + sizeof(char);
    }

    
    contador = 0;
    while (largoCadenaOrigen - contador) {
        cadenaDestino[posicion + contador] = cadenaOrigen[contador];
        contador = contador + sizeof(char);
    }

    return ultimaPosicion;
}

/**
 * La funcion copia una cadena en otra sin exceder la capacidad del arreglo destino.
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a copiar en destino
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @param capacidadOrigen la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param cadenaDestino es la direccion de la cadena con los caracteres a insertar de origen
 *  @pre cadenaDestino es un puntero no nulo que contiene al menos un '\0'
 *  @param capacidadDestino la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres del destino
         y los valores negativos, las siguientes situaciones de error:
            CADENA_NO_ENTRA cuando la cantidad de carateres de origen
                            sea mayor a la capacidad indicada por el argumento
 *  @post
 */
int cadena_copiar(char cadenaOrigen[],  int capacidadOrigen,
                  char cadenaDestino[], int capacidadDestino) {
    int longitud;

    
    cadenaDestino[0] = '\0';
    longitud = cadena_insertar(cadenaOrigen, capacidadOrigen, 0, cadenaDestino, capacidadDestino);

    return longitud;
}

/**
 * La funcion indica si el caracter esta en [A-Za-z0-9].
 *  @param caracter es el caracter a evaluar
 *  @pre caracter es de tipo char
 *  @returns int en donde:
         TRUE  (1) indica que es alfanumerico segun lo configurado
         FALSE (0) indica que no es alfanumerico segun lo configurado
 *  @post
 */
int es_alfanumerico(char caracter) {
    if ((caracter >= 'A' && caracter <= 'Z') ||
            (caracter >= 'a' && caracter <= 'z') ||
            (caracter >= '0' && caracter <= '9')) {
        return TRUE;
    }
    return FALSE;
}

/**
 * La funcion limpia una cadena de caracteres no alfanumericos hasta el \0 en otra cadena.
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a limpiar en destino
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @param cadenaDestino es la direccion de la cadena con los caracteres limpiados hasta el \0
 *  @pre cadenaDestino es un puntero no nulo con un '\0' al inicio
 *  @param capacidadDestino la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres del destino
         y los valores negativos, las siguientes situaciones de error:
            CADENA_NO_ENTRA cuando la cantidad de carateres de origen
                            sea mayor a la capacidad indicada por el argumento
 *  @post
 */
int cadena_limpiar(char cadenaOrigen[],
                   char cadenaDestino[], int capacidadDestino) {
    int pOrigen = 0;
    int pDestino = 0;

    while (cadenaOrigen[pOrigen] != '\0' && pDestino < capacidadDestino) {
        if (es_alfanumerico(cadenaOrigen[pOrigen])) {
            cadenaDestino[pDestino] = cadenaOrigen[pOrigen];
            pDestino = pDestino + 1;
        }
        pOrigen = pOrigen + 1;
    }

    
    if (pDestino == capacidadDestino) {
        cadenaDestino[0] = '\0';
        return CADENA_NO_ENTRA;
    }

    
    cadenaDestino[pDestino] = '\0';

    return pDestino;
}

/**
 * La funcion invierte una cadena de caracteres hasta el \0 en otra cadena.
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a invertir en destino
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @param capacidadOrigen la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param cadenaDestino es la direccion de la cadena con los caracteres invertidos hasta el \0
 *  @pre cadenaDestino es un puntero no nulo con un '\0' al inicio
 *  @param capacidadDestino la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres del destino
         y los valores negativos, las siguientes situaciones de error:
            CADENA_NO_ENTRA cuando la cantidad de carateres de origen
                            sea mayor a la capacidad indicada por el argumento
 *  @post
 */
int cadena_invertir(char cadenaOrigen[],  int capacidadOrigen,
                    char cadenaDestino[], int capacidadDestino) {
    int longitud, contador;

    longitud = largo_seguro(cadenaOrigen, capacidadOrigen);
    if (longitud < 0) {
        return longitud;
    }

    
    if (longitud > capacidadDestino) {
        return CADENA_NO_ENTRA;
    }

    
    contador = 0;
    while (longitud > contador) {
        *(cadenaDestino + contador) = *(cadenaOrigen + longitud - 1 - contador);
        contador = contador + sizeof(char);
    };

    return contador;
}

/**
 * La funcion compara dos cadenas de caracteres solo con caracteres [a-z].
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a comparar con destino
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @param cadenaDestino es la direccion de la cadena con los caracteres a comparar con origen
 *  @pre cadenaDestino es un puntero no nulo con un '\0' al inicio
 *  @param capacidadDestino la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde
         CADENA1_MENOR_A_CADENA2 (-1) la primera cadena va antes que la segunda
         CADENA1_IGUAL_A_CADENA2 ( 0) ambas cadenas son iguales
         CADENA1_MAYOR_A_CADENA2 ( 1) la primera cadena va despues que la segunda
 *  @post
 */
int cadena_comparar(char cadenaOrigen[],
                    char cadenaDestino[], int capacidadDestino) {
    int posicion = 0;

    while (cadenaOrigen[posicion] != '\0' &&
            posicion < capacidadDestino &&
            cadenaOrigen[posicion] == cadenaDestino[posicion]) {
        posicion = posicion + 1;
    }

    if (cadenaOrigen[posicion] > cadenaDestino[posicion]) {
        return CADENA1_MAYOR_A_CADENA2;
    }

    if (cadenaOrigen[posicion] < cadenaDestino[posicion]) {
        return CADENA1_MENOR_A_CADENA2;
    }

    return CADENA1_IGUAL_A_CADENA2;
}

/**
 * La funcion cuenta los caracteres de tipo [A-Za-z0-9].
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a contar
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @returns int en donde los valores positivos incluyendo el cero representan
         la cantidad de caracteres buscados
 *  @post
 */
int cadena_contar_caracteres_alfa(char cadenaOrigen[]) {
    int posicion = 0;
    int alfanumericos = 0;

    while (cadenaOrigen[posicion] != '\0') {
        if (es_alfanumerico(cadenaOrigen[posicion])) {
            alfanumericos = alfanumericos + 1;
        }
        posicion = posicion + 1;
    }

    return alfanumericos;
}

/**
 * La funcion cuenta los caracteres de simbolo ![A-Za-z0-9].
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a contar
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @returns int en donde los valores positivos incluyendo el cero representan
         la cantidad de caracteres buscados
 *  @post
 */
int cadena_contar_simbolos(char cadenaOrigen[]) {
    int posicion = 0;
    int simbolos = 0;

    while (cadenaOrigen[posicion] != '\0') {
        if (!es_alfanumerico(cadenaOrigen[posicion])) {
            simbolos = simbolos + 1;
        }
        posicion = posicion + 1;
    }

    return simbolos;
}

/**
 * La funcion cambia a minusculas los caracteres de [A-Z], devuelve la cantidad
 * de caracteres cambiados
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a cambiar
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @returns int en donde los valores positivos incluyendo el cero representan
         la cantidad de caracteres cambiados
 *  @post
 */
int cadena_a_minusculas(char cadenaOrigen[]) {
    int posicion = 0;
    int cambios = 0;

    while (cadenaOrigen[posicion] != '\0') {
        if (cadenaOrigen[posicion] >= 'A' && cadenaOrigen[posicion] <= 'Z') {
            cadenaOrigen[posicion] = cadenaOrigen[posicion] - 'A' + 'a';
            cambios = cambios + 1;
        }
        posicion = posicion + 1;
    }

    return cambios;
}

/**
 * La funcion cambia a mayusculas los caracteres de [A-Z], devuelve la cantidad
 * de caracteres cambiados
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a cambiar
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @returns int en donde los valores positivos incluyendo el cero representan
         la cantidad de caracteres cambiados
 *  @post
 */
int cadena_a_mayusculas(char cadenaOrigen[]) {
    int posicion = 0;
    int cambios = 0;

    while (cadenaOrigen[posicion] != '\0') {
        if (cadenaOrigen[posicion] >= 'a' && cadenaOrigen[posicion] <= 'z') {
            cadenaOrigen[posicion] = cadenaOrigen[posicion] - 'a' + 'A';
            cambios = cambios + 1;
        }
        posicion = posicion + 1;
    }

    return cambios;
}

/**
 * La funcion cambia a mayusculas los caracteres de [A-Z], devuelve la cantidad
 * de caracteres cambiados
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a cambiar
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @param capacidadOrigen la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan
         la cantidad de caracteres cambiados
 *  @post
 */
int palindromo_seguro_con_memoria_dinamica(char cadenaOrigen[], int capacidadOrigen) {
    char *pCadena;
    int longitud;
    int comparacion;

    cadena_a_minusculas(cadenaOrigen);

    longitud = largo_seguro(cadenaOrigen, capacidadOrigen);

    pCadena = calloc(1, longitud + 1);
    if (pCadena ==NULL) {
        return NOT_ENOUGH_MEMORY;
    }

    cadena_invertir(cadenaOrigen, capacidadOrigen,
                    pCadena, longitud + 1);

    comparacion = cadena_comparar(cadenaOrigen, pCadena, longitud + 1);
    free(pCadena);

    if (longitud > 0 && comparacion == CADENA1_IGUAL_A_CADENA2) {
        return TRUE;
    }

    return FALSE;
}

/**
 * La funcion cambia a mayusculas los caracteres de [A-Z], devuelve la cantidad
 * de caracteres cambiados
 *  @param cadenaOrigen es la direccion de la cadena con los caracteres a cambiar
 *  @pre cadenaOrigen es un puntero no nulo que contiene al menos un '\0'
 *  @param capacidadOrigen la capacidad es el tamanio en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan
         la cantidad de caracteres cambiados
 *  @post
 */
int palindromo_seguro(char cadenaOrigen[], int capacidadOrigen) {
    int longitud, posicion = 0;
    char izquierda, derecha;

    longitud = largo_seguro(cadenaOrigen, capacidadOrigen);

    while (posicion < longitud / 2) {
        
        if (cadenaOrigen[posicion] >= 'A' &&
                cadenaOrigen[posicion] <= 'Z') {
            izquierda = cadenaOrigen[posicion] - 'A' + 'a';
        } else {
            izquierda = cadenaOrigen[posicion];
        }
        
        if (cadenaOrigen[longitud - posicion - 1] >= 'A' &&
                cadenaOrigen[longitud - posicion - 1] <= 'Z') {
            derecha = cadenaOrigen[longitud - posicion - 1] - 'A' + 'a';
        } else {
            derecha = cadenaOrigen[longitud - posicion - 1];
        }
        if (izquierda != derecha) {
            return FALSE;
        }
        posicion = posicion + 1;
    }

    if (longitud == 0) {
        return FALSE;
    }

    return TRUE;
}
