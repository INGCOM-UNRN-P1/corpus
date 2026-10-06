#include "texto.h"
#include "cadenas.h"

bool unir_con_separador(
    char destino[],
    size_t capacidad,
    const char primero[],
    const char segundo[],
    const char separador[]
)
{
    if (destino == NULL || capacidad == 0 ||
        primero == NULL || segundo == NULL ||
        separador == NULL)
    {
        return false;
    }

    if (!cadena_copiar(destino, capacidad, primero))
    {
        return false;
    }

    if (!cadena_concatenar(destino, capacidad, separador))
    {
        return false;
    }

    if (!cadena_concatenar(destino, capacidad, segundo))
    {
        return false;
    }

    return true;
}