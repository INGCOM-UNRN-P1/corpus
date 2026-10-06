#include "lista_dinamica.h"
#include "lista_dinamica.h"


char **lista_cadenas_crear(void)
{
    char **retorno = NULL;
    return retorno;
}
bool lista_cadenas_agregar(char ***lista, size_t *cantidad, const char *cadena, size_t capacidad)
{
    if (lista == NULL || cantidad == NULL || cadena == NULL || capacidad == 0)
    {
        return false;
    }

    char *duplicada = cadena_duplicar_segura(cadena, capacidad);
    if (duplicada == NULL)
    {
        return false;
    }

    char **auxiliar = realloc(*lista, (*cantidad + 1) * sizeof(char*));
    if (auxiliar == NULL)
    {
        cadena_liberar_segura(&duplicada);
        return false;
    }
    
    *lista = auxiliar;
    (*lista)[*cantidad] = duplicada;
    (*cantidad)++;

    return true;
}

void lista_cadenas_destruir(char **lista, size_t cantidad)
{
    if (lista == NULL)
    {
        return;
    }
    
    for (size_t i = 0; i < cantidad; i++)
    {
        cadena_liberar_segura(&lista[i]);
    }
    free(lista);
    lista = NULL;
}

