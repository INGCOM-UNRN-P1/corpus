#include "consola.h"
#include <stdio.h>

void limpiar_buffer_entrada(void)
{
    int caracter = 0;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
        
    }
}

bool esta_en_rango_entero(int valor, int min, int max)
{
    return false;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    return false;
}

int leer_entero(const char *mensaje)
{
    
    return 0;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    
    return 0;
}

float leer_flotante(const char *mensaje)
{
    
    return 0.0f;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    
    return 0.0f;
}

char leer_caracter(const char *mensaje)
{
    
    return ' ';
}

bool leer_logico(const char *mensaje)
{
    
    return false;
}
