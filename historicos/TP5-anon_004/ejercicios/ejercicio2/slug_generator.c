/**
 * @file slug_generator.c
 * @brief Implementacion del generador y normalizador de slugs para URLs legibles.
 *
 * Trabajo Practico 5 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#include <ctype.h>
#include <stdlib.h>
#include "slug_generator.h"

bool contiene_palabra_prohibida(const cadena_segura_t *texto, const char *palabra)
{
    if (texto == NULL || texto->texto == NULL || palabra == NULL) {
        return false;
    }
    return cadena_segura_buscar(texto, palabra) >= 0;
}

bool generar_slug(const cadena_segura_t *titulo, cadena_segura_t *slug)
{
    if (titulo == NULL || titulo->texto == NULL || slug == NULL) {
        return false;
    }

    cadena_segura_t res;
    if (!cadena_segura_crear(&res, "")) {
        return false;
    }

    char temp[2] = { '\0', '\0' };
    bool ultimo_fue_guion = true; 

    for (size_t i = 0; i < titulo->longitud; i++) {
        unsigned char c = (unsigned char)titulo->texto[i];
        if (isalnum(c)) {
            temp[0] = (char)tolower(c);
            if (!cadena_segura_concatenar(&res, temp)) {
                cadena_segura_destruir(&res);
                return false;
            }
            ultimo_fue_guion = false;
        } else if (!ultimo_fue_guion) {
            temp[0] = '-';
            if (!cadena_segura_concatenar(&res, temp)) {
                cadena_segura_destruir(&res);
                return false;
            }
            ultimo_fue_guion = true;
        }
    }

    
    while (res.longitud > 0 && res.texto[res.longitud - 1] == '-') {
        res.texto[res.longitud - 1] = '\0';
        res.longitud--;
    }

    if (slug == titulo) {
        cadena_segura_destruir(slug);
    }
    *slug = res;
    return true;
}

bool acotar_longitud_slug(cadena_segura_t *slug, size_t max_longitud)
{
    if (slug == NULL || slug->texto == NULL) {
        return false;
    }
    if (slug->longitud <= max_longitud) {
        return true;
    }
    cadena_segura_t recortado;
    if (!cadena_segura_subcadena(slug, 0, max_longitud, &recortado)) {
        return false;
    }
    
    while (recortado.longitud > 0 && recortado.texto[recortado.longitud - 1] == '-') {
        recortado.texto[recortado.longitud - 1] = '\0';
        recortado.longitud--;
    }
    cadena_segura_destruir(slug);
    *slug = recortado;
    return true;
}
