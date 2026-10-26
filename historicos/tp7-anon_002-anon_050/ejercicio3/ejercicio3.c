



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parte A - Concatenación dinámica

/**
 * @param cadena1 Primera cadena de caracteres a concatenar.
 * @param cadena2 Segunda cadena de caracteres a concatenar.
 * @pre Ambas cadenas deben ser dinámicas y terminar con el carácter nulo '\0'.
 * @post Concatena las dos cadenas y devuelve una nueva cadena dinámica resultante.
 * @return Puntero a la nueva cadena resultante o NULL si falla la asignación de memoria.
 */
char* concatenaCadenas(char* cadena1, char* cadena2) 
{
    int tamano1 = strlen(cadena1);
    int tamano2 = strlen(cadena2);

    char* resultado = (char*)malloc((tamano1 + tamano2 + 1) * sizeof(char));
    if (resultado == NULL) 
    {
        return NULL;
    }

    strcpy(resultado, cadena1);
    strcat(resultado, cadena2);

    return resultado;
}

// Parte B - Deduplicador

/**
 * @param cadena Cadena de caracteres en la que se eliminarán los caracteres duplicados.
 * @param tamano Puntero al tamaño de la cadena (se actualiza después de la eliminación).
 * @pre La cadena debe ser dinámica y terminar con el carácter nulo '\0'.
 * @post Elimina los caracteres duplicados de la cadena y devuelve una nueva cadena dinámica resultante.
 * @return Puntero a la nueva cadena resultante o NULL si falla la asignación de memoria.
 */
char* elimina_duplicados(char* cadena, int* tamano) 
{
    int i;
    int j;
    int k;
    int longitud = strlen(cadena);

    for (i = 0; i < longitud; i++) 
    {
        for (j = i + 1; j < longitud; j++) 
        {
            if (cadena[i] == cadena[j]) 
            {
                for (k = j; k < longitud; k++) 
                {
                    cadena[k] = cadena[k + 1];
                }
                longitud--;
                j--;
            }
        }
    }

    char* resultado = (char*)malloc((longitud + 1) * sizeof(char));
    if (resultado == NULL) 
    {
        return NULL;
    }

    strcpy(resultado, cadena);
    *tamano = longitud;

    return resultado;
}

int main() 
{
    char* cadena1 = "Hola, ";
    char* cadena2 = "mundo!";
    char* resultado_concatenacion = concatenaCadenas(cadena1, cadena2);

    if (resultado_concatenacion != NULL) 
    {
        printf("Concatenación: %s\n", resultado_concatenacion);
        free(resultado_concatenacion);
    } 
    else 
    {
        printf("Error: No se pudo concatenar las cadenas.\n");
    }

    char* cadena_duplicados = "programacion";
    int tamano = strlen(cadena_duplicados);
    char* resultado_deduplicado = elimina_duplicados(cadena_duplicados, &tamano);

    if (resultado_deduplicado != NULL) {

        printf("Deduplicado: %s\n", resultado_deduplicado);
        free(resultado_deduplicado);
    } 
    else 
    {
        printf("Error: No se pudo deduplicar la cadena.\n");
    }

    return 0;
}