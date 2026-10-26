/**
 * @file cadena_segura.c
 * @brief Implementacion de biblioteca de cadenas dinamicas seguras en heap.
 *
 * Trabajo Practico 5 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "cadena_segura.h"

bool cadena_segura_crear(cadena_segura_t *cadena, const char *literal)
{
    if (cadena == NULL) {
        return false;
    }
    const char *fuente = (literal != NULL) ? literal : "";
    size_t len = strlen(fuente);
    size_t cap = len + 16; 

    char *buf = malloc(cap);
    if (buf == NULL) {
        cadena->texto = NULL;
        cadena->longitud = 0;
        cadena->capacidad = 0;
        return false;
    }
    memcpy(buf, fuente, len + 1);
    cadena->texto = buf;
    cadena->longitud = len;
    cadena->capacidad = cap;
    return true;
}

void cadena_segura_destruir(cadena_segura_t *cadena)
{
    if (cadena == NULL) {
        return;
    }
    free(cadena->texto);
    cadena->texto = NULL;
    cadena->longitud = 0;
    cadena->capacidad = 0;
}

bool cadena_segura_concatenar(cadena_segura_t *cadena, const char *sufijo)
{
    if (cadena == NULL || cadena->texto == NULL) {
        return false;
    }
    if (sufijo == NULL || sufijo[0] == '\0') {
        return true;
    }
    size_t len_sufijo = strlen(sufijo);
    size_t total_len = cadena->longitud + len_sufijo;

    uintptr_t u_sufijo = (uintptr_t)sufijo;
    uintptr_t u_inicio = (uintptr_t)cadena->texto;
    uintptr_t u_fin = u_inicio + (uintptr_t)cadena->capacidad;
    bool solapado = (u_sufijo >= u_inicio && u_sufijo < u_fin);
    ptrdiff_t offset = solapado ? (ptrdiff_t)(u_sufijo - u_inicio) : 0;

    if (total_len + 1 > cadena->capacidad) {
        size_t nueva_capacidad = (total_len + 1) * 2;
        char *nuevo_buf = realloc(cadena->texto, nueva_capacidad);
        if (nuevo_buf == NULL) {
            return false;
        }
        cadena->texto = nuevo_buf;
        cadena->capacidad = nueva_capacidad;
        if (solapado) {
            sufijo = cadena->texto + offset;
        }
    }
    memmove(cadena->texto + cadena->longitud, sufijo, len_sufijo + 1);
    cadena->longitud = total_len;
    return true;
}

bool cadena_segura_subcadena(const cadena_segura_t *origen, size_t inicio, size_t longitud, cadena_segura_t *destino)
{
    if (origen == NULL || origen->texto == NULL || destino == NULL) {
        return false;
    }
    if (inicio >= origen->longitud || longitud == 0) {
        if (origen == destino) {
            cadena_segura_destruir(destino);
        }
        return cadena_segura_crear(destino, "");
    }
    size_t disponible = origen->longitud - inicio;
    size_t copiar = (longitud < disponible) ? longitud : disponible;

    char *tmp = malloc(copiar + 1);
    if (tmp == NULL) {
        return false;
    }
    memcpy(tmp, origen->texto + inicio, copiar);
    tmp[copiar] = '\0';

    if (origen == destino) {
        cadena_segura_destruir(destino);
    }
    bool ok = cadena_segura_crear(destino, tmp);
    free(tmp);
    return ok;
}

bool cadena_segura_clonar(const cadena_segura_t *origen, cadena_segura_t *destino)
{
    if (origen == NULL || origen->texto == NULL || destino == NULL) {
        return false;
    }
    if (origen == destino) {
        return true;
    }
    return cadena_segura_crear(destino, origen->texto);
}

int cadena_segura_buscar(const cadena_segura_t *cadena, const char *aguja)
{
    if (cadena == NULL || cadena->texto == NULL || aguja == NULL || aguja[0] == '\0') {
        return -1;
    }
    char *pos = strstr(cadena->texto, aguja);
    if (pos == NULL) {
        return -1;
    }
    return (int)(pos - cadena->texto);
}
