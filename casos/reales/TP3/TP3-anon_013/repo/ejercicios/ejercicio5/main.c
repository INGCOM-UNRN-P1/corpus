/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
{
    printf("Ejercicio 5: Cadenas seguras con punteros\n");

    //---------------------------------------------------------------------------------------------------------
    printf("\n===== COPIAR CON PUNTEROS =====\n");

    char origen[] = "Este es el arreglo a copiar";
    char destino[] = "Esto va a ser sobreescrito";

    printf("ARREGLO ORIGEN: %s\n"
        "CAPACIDAD ORIGEN: %zu\n"
        "ARREGLO DESTINO ANTES: %s\n"
        "CAPACIDAD DESTINO: %zu\n"
        , origen, sizeof(origen), destino, sizeof(destino));
    
    bool resultado = copiar_con_punteros(destino, sizeof(destino), origen);

    printf("ARREGLO DESTINO DESPUES: %s\n"
        "RESULTADO DE LA OPERACION: %s\n", destino, resultado ? "Exito" : "Fallo");

    //---------------------------------------------------------------------------------------------------------
    printf("\n===== CONCATENAR CON PUNTEROS =====\n");

    char origen2[] = "Segunda parte";
    char destino2[50] = "Primera parte - ";

    printf("ARREGLO ORIGEN: %s\n"
        "CAPACIDAD ORIGEN: %zu\n"
        "ARREGLO DESTINO ANTES: %s\n"
        "CAPACIDAD DESTINO: %zu\n"
        , origen2, sizeof(origen2), destino2, sizeof(destino2));
    
    bool resultado2 = concatenar_con_punteros(destino2, sizeof(destino2), origen2);

    printf("ARREGLO DESTINO DESPUES: %s\n"
        "RESULTADO DE LA OPERACION: %s\n", destino2, resultado2 ? "Exito" : "Fallo");
    
    return 0;
}
