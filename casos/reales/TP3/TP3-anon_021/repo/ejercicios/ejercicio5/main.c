/**
 * @file main.c
 * @brief Programa principal del Ejercicio 5.
 */

#include <stdio.h>
#include "puntero_cadena.h"

int main(void)
int main(void)
{
    printf("Cadenas Seguras con Aritmética de Punteros \n");

    
    const char *mensaje_base = "Universidad Nacional de Rio Negro";
    size_t capacidad_analisis = 50;
    
    printf("longitud_con_punteros\n");
    printf("Texto analizado: \"%s\"\n", mensaje_base);
    size_t len = longitud_con_punteros(mensaje_base, capacidad_analisis);
    printf("Longitud calculada de forma segura: %zu caracteres.\n\n", len);

    printf(" copiar_con_punteros \n");
    char buffer_destino[30];
    const char *origen_copia = "Programacion 1";
    
    printf("Copiando \"%s\" en un buffer de capacidad 30...\n", origen_copia);
    bool exito_copia = copiar_con_punteros(buffer_destino, sizeof(buffer_destino), origen_copia);
    
    if (exito_copia)
    {
        printf("Copia exitosa sin truncar\n");
        printf("Resultado en destino: \"%s\"\n\n", buffer_destino);
    }
    else
    {
        printf("Hubo truncamiento durante la copia.\n\n");
    }

    printf("concatenar_con_punteros \n");
    char buffer_concat[40] = "Hola, ";
    const char *origen_concat = "bienvenidos al TP3.";
    
    printf("Texto inicial en buffer: \"%s\"\n", buffer_concat);
    printf("Concatenando: \"%s\"\n", origen_concat);
    
    bool exito_concat = concatenar_con_punteros(buffer_concat, sizeof(buffer_concat), origen_concat);
    
    if (exito_concat)
    {
        printf("Concatenación exitosa sin truncar\n");
        printf("Resultado final combinado: \"%s\"\n\n", buffer_concat);
    }
    else
    {
        printf("Hubo truncamiento durante la concatenación.\n\n");
    }

    printf("Prueba de límite y truncamiento forzado \n");
    char buffer_pequeno[10]; 
    const char *texto_largo = "CadenaDemasiadoLarga";
    
    printf("Intentando copiar \"%s\" en un buffer de solo %zu bytes...\n", texto_largo, sizeof(buffer_pequeno));
    bool resultado_truncado = copiar_con_punteros(buffer_pequeno, sizeof(buffer_pequeno), texto_largo);
    
    if (!resultado_truncado)
    {
        printf("Se detectó el truncamiento correctamente (retornó false).\n");
    }
    printf("Contenido resultante seguro en buffer truncado: \"%s\"\n", buffer_pequeno);

    return 0;
}