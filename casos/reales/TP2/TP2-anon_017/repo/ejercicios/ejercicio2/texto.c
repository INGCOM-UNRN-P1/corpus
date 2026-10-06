#include "texto.h"
#include "cadenas.h"

bool unir_con_separador(char destino[], size_t capacidad, const char primero[], const char segundo[], const char separador[])
{
    bool se_unio = false;
    if ((destino != NULL) && (capacidad > 0) &&
        (primero != NULL) && (segundo != NULL) && (separador != NULL)) 
    {
        //destino anexo primero --> destino anexo separdor --> destino anexo segundo
        se_unio = cadena_copiar(destino, capacidad, primero);
        if(se_unio == true)
        {
            se_unio = cadena_concatenar(destino, capacidad, separador);
            if(se_unio == true)
            {
                se_unio = cadena_concatenar(destino, capacidad, segundo);
            }
        }
    }

    return se_unio;
}
