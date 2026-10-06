/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    char destino[50] = {0};
    char origen[50] = {0};
    char agregado[50] = {0};

    printf("Ejercicio 5: Copia y concatenación con punteros\n");
    printf("Ingrese una cadena de destino: ");
    scanf("%49s", destino);

    printf("Ingrese una cadena para copiar en el destino: ");
    scanf("%49s", origen);

    if (copiar_con_punteros(destino, sizeof(destino), origen))
    {
        printf("Copia realizada: %s\n", destino);
    }
    else
    {
        printf("La copia se truncó o hubo un error.\n");
    }

    printf("Ingrese una cadena para concatenar: ");
    scanf("%49s", agregado);

    if (concatenar_con_punteros(destino, sizeof(destino), agregado))
    {
        printf("Resultado final: %s\n", destino);
    }
    else
    {
        printf("La concatenación se truncó.\n");
    }

    return 0;
}
