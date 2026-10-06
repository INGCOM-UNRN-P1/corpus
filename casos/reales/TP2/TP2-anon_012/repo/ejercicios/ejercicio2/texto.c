#include "texto.h"
#include "cadenas.h"

bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[])
{
    bool exito = false;

    if (destino != NULL && capacidad > 0 &&
        primero != NULL && segundo != NULL && separador != NULL)
    {
        exito = cadena_copiar(destino, capacidad, primero) &&
                cadena_concatenar(destino, capacidad, separador) &&
                cadena_concatenar(destino, capacidad, segundo);
    }

    return exito;
}
