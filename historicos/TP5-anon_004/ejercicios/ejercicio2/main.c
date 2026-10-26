#include <stdio.h>
#include "cadena_segura.h"
#include "slug_generator.h"

int main(void)
{
    printf("=== Ejercicio 2: Generador de Slugs Seguros ===\n");
    cadena_segura_t titulo;
    cadena_segura_t slug;

    const char *ejemplo = "Trabajo Practico 5: Memoria Dinamica & Estructuras!";
    if (!cadena_segura_crear(&titulo, ejemplo)) {
        fprintf(stderr, "Error al crear cadena segura.\n");
        return 1;
    }

    printf("Titulo original: \"%s\"\n", titulo.texto);
    if (contiene_palabra_prohibida(&titulo, "spam")) {
        printf("Aviso: el titulo contiene terminos no admitidos.\n");
    }

    if (generar_slug(&titulo, &slug)) {
        printf("Slug generado: \"%s\"\n", slug.texto);
        acotar_longitud_slug(&slug, 25);
        printf("Slug acotado (max 25): \"%s\"\n", slug.texto);
        cadena_segura_destruir(&slug);
    }

    cadena_segura_destruir(&titulo);
    return 0;
}
