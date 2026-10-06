#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"
#include "texto_dinamico.h"

int main(void)
{
    printf("ejercicio 2: normalizacion dinamica de texto en heap\n\n");

    char buffer[256];
    printf("ingrese una cadena (agregue espacios al inicio o final para probar): ");
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        printf("error al leer la entrada.\n");
        return EXIT_FAILURE;
    }

    char *recortada = cadena_recortar_espacios(buffer);
    
    if (recortada != NULL)
    {
        printf("cadena original (con enter al final) : [%s]\n", buffer);
        printf("cadena recortada y limpia            : [%s]\n\n", recortada);
        
        size_t repeticiones = 0;
        bool entrada_valida = false;
        char entrada_rep[256];

        while (entrada_valida == false)
        {
            printf("ingrese la cantidad de veces a repetir la cadena limpia: ");
            if (fgets(entrada_rep, sizeof(entrada_rep), stdin) != NULL)
            {
                char *fin_ptr;
                long valor = strtol(entrada_rep, &fin_ptr, 10);
                
                if (fin_ptr != entrada_rep && valor >= 0)
                {
                    repeticiones = (size_t)valor;
                    entrada_valida = true;
                }
                else
                {
                    printf("entrada invalida. ingrese un numero entero positivo o cero.\n");
                }
            }
            else
            {
                cadena_liberar_segura(&recortada);
                return EXIT_FAILURE;
            }
        }

        char *repetida = cadena_repetir(recortada, repeticiones);
        if (repetida != NULL)
        {
            printf("resultado de la repeticion: [%s]\n", repetida);
            cadena_liberar_segura(&repetida);
        }
        else
        {
            printf("hubo un error al generar la repeticion.\n");
        }

        cadena_liberar_segura(&recortada);
    }
    else
    {
        printf("la cadena estaba vacia o solo contenia espacios.\n");
    }

    printf("\nmemoria dinamica liberada correctamente.\n");
    return EXIT_SUCCESS;
}