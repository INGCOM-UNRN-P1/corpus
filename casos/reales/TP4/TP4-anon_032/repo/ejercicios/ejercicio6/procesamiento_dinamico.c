#include "procesamiento_dinamico.h"
// Defino un macro para el tamano del buffer (y por lo tanto de cada linea de 
// entrada) porque me parecio la mejor manera de mantener el programa seguro
#define TAMANO_BUFFER 2048


bool contiene_subcadena(const char *pajar, size_t capacidad_pajar, const char *aguja, size_t capacidad_aguja)
{
    if (pajar == NULL || aguja == NULL ||
        capacidad_aguja == 0 || capacidad_pajar == 0)
    {
        return false;
    }
    size_t largo_aguja = 0;
    while (largo_aguja < capacidad_aguja && aguja[largo_aguja] != '\0')
    {
        largo_aguja++;
    }
    size_t largo_pajar = 0;
    while (largo_pajar < capacidad_pajar && pajar[largo_pajar] != '\0')
    {
        largo_pajar++;
    }
    if (largo_aguja > largo_pajar)
    {
        return false;
    }

    for (size_t i = 0; i <= (largo_pajar - largo_aguja); i++)
    {
        size_t j = 0;
        bool buscando_aguja = true;
        while (j < largo_aguja && buscando_aguja == true)
        {
            if (pajar[i + j] != aguja[j])
            {
                buscando_aguja = false;
            }
            else
            {
                j++;
            }
        }
        if (j == largo_aguja)
        {
            return true;
        }
    }

    return false;
}

bool leer_lineas(char ***lista, size_t *cantidad)
{
    if (lista == NULL || cantidad == NULL)
    {
        return false;
    }
    
    char buffer[TAMANO_BUFFER];
    while (fgets(buffer, TAMANO_BUFFER, stdin) != NULL)
    {
        if (lista_cadenas_agregar(lista, cantidad, buffer, TAMANO_BUFFER) == false)
        {
            return false;
        }
    }

    return true;
}

void filtrar_lineas(char **lista, size_t cantidad, const char *subcadena, size_t capacidad)
{
    if (lista == NULL || cantidad == 0 || subcadena == NULL)
    {
        return;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        if (contiene_subcadena(lista[i], TAMANO_BUFFER, subcadena, capacidad))
        {
            printf("%s", lista[i]);
        }    
    }
}
