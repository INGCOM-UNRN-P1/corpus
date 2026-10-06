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
    
    int valor;
    int resultado;
    while (true)
    {
        printf("%s", mensaje);
        resultado = scanf("%d", &valor);
        limpiar_buffer_entrada();
        if (resultado == 1)
        {
            return valor;
        }
        printf("Error: entrada no valida. Intente nuevamente.\n");
    }
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    
    int valor;
    while (true)
    {
        valor = leer_entero(mensaje);
        if (esta_en_rango_entero(valor, min, max))
        {
            return valor;
        }
        printf("Error: el valor debe estar comprendido entre %d y %d.\n", min, max);
    }
}

float leer_flotante(const char *mensaje)
{
    
    float valor;
    int resultado;
    while (true)
    {
        printf("%s", mensaje);
        resultado = scanf("%f", &valor);
        limpiar_buffer_entrada();
        if (resultado == 1)
        {
            return valor;
        }
        printf("Error: entrada no valida. Intente nuevamente.\n");
    }
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    
    float valor;
    while (true)
    {
        valor = leer_flotante(mensaje);
        if (esta_en_rango_flotante(valor, min, max))
        {
            return valor;
        }
        printf("Error: el valor debe estar comprendido entre %.2f y %.2f.\n", min, max);
    }
}

char leer_caracter(const char *mensaje)
{
    
    char c;
    printf("%s", mensaje);
    scanf(" %c", &c);
    limpiar_buffer_entrada();
    return c;
}

bool leer_logico(const char *mensaje)
{
    
    while (true)
    {
        char c = leer_caracter(mensaje);
        if (c == 's' || c == 'S' || c == '1')
        {
            return true;
        }
        if (c == 'n' || c == 'N' || c == '0')
        {
            return false;
        }
        printf("Error: opcion no valida. Ingrese 's'/'n' o '1'/'0'.\n");
    }
}
