
#include "mis_funciones.h"

#include <stdio.h>


#include <errno.h>


#include <stdlib.h>
#include <limits.h>


#define MAX_DIGITOS 12


int parse_long(const char *cadena, long *pentero, const int base) {
    char *temp;
    int retorno = OK;

    
    int errno_anterior = errno;
    
    errno = 0;

    *pentero = strtol(cadena, &temp, base);

    
    if (temp == cadena || *temp != '\0' ||
            ((*pentero == LONG_MIN || *pentero == LONG_MAX) && errno == ERANGE))
        retorno = ERROR;

    
    if (errno == 0)
        errno = errno_anterior;

    return retorno;
}


int ingreso_sin_newline(char *entrada, int size_of_entrada, FILE *stream) {
    char *pchar;
    pchar = entrada;

    if (fgets(entrada, size_of_entrada, stream) != NULL) {
        
        while(*pchar != '\0')
            pchar++;
        if (*(pchar-1) == '\n')
            *(pchar-1) = '\0';
        return OK;
    } else {
        return ERROR;
    }
}

