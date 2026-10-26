

#include <stdio.h>
#include <string.h>

/**
 * La función verifica si el contenido de una cadena se encuentra en otra.
 *  @param cadena, cadena a revisar.
 *  @pre char válido.
 *  @param capacidad_cadena, largo de la cadena.
 *  @pre int sin signo válido.
 *  @param buscar, cadena con los caracteres a buscar.
 *  @pre char válido.
 *  @param capacidad_busqueda, largo de la cadena.
 *  @pre int sin signo válido.
 *  @return la posición donde empieza la concordancia de las cadenas, o NULL.
 *  @post la posición donde empieza la concordancia, o NULL si no hay ninguna
**/
char* busqueda(char cadena[], int capacidad_cadena, char buscar[], int capacidad_busqueda)
{
    int j = 0;
    int ret;
    
    if (capacidad_busqueda > capacidad_cadena)
    {
        return NULL;
    }
    else
    {
        for (int i = 0; i <= capacidad_cadena - capacidad_busqueda; i++)
        {
            while (j < capacidad_busqueda && cadena[i+j] == buscar[j])
            {
                j++;
            }
            if (j == capacidad_busqueda)
            {
                return cadena + i;
            }
        }
    }
    return NULL;
}

// variables renombradas debido a quejas del compilador
int main()
{
    char cadena[] = "Que ganas de dormir";
    int capacidad_cadena = strlen(cadena);
    char buscar[] = "dormir";
    int capacidad_busqueda = strlen(buscar);
    char* resultado = busqueda(cadena, capacidad_cadena, buscar, capacidad_busqueda);
    
    if (resultado == NULL)
    {
        printf("Sin resultados");
    }
    else
    {
        printf("La busqueda se encuentra en la posición %ld.\n", resultado - cadena);
    }
    return 0;
}