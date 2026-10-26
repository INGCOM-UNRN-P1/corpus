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
    return (valor >= min && valor <= max);
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    return (valor >= min && valor <= max);
}

int leer_entero(const char *mensaje)
{
    (void)mensaje;
    
    return 0;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    (void)mensaje;
    (void)min;
    (void)max;
    
    return 0;
}

float leer_flotante(const char *mensaje)
{
    (void)mensaje;
    
    return 0.0f;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    (void)mensaje;
    (void)min;
    (void)max;
    
    return 0.0f;
}

char leer_caracter(const char *mensaje)
{
    (void)mensaje;
    
    return ' ';
}

bool leer_logico(const char *mensaje)
{
    (void)mensaje;
    
    return false;
}
