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
    return valor >= min && valor <= max;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    return valor >= min && valor <= max;
}

int leer_entero(const char *mensaje)
{
    int valor;
    int resultado;

    while (1) {
        printf("%s", mensaje);
        resultado = scanf("%d", &valor);
        limpiar_buffer_entrada();

        if (resultado == 1) {
            return valor;
        }

        printf("entrada invalida. Por favor ingrese un numero entero.\n");
    }
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor;

    {
        valor = leer_entero(mensaje);
        if (!esta_en_rango_entero(valor, min, max)) {
            printf("el valor debe estar entre %d y %d.\n", min, max);
        }
    }
    while (!esta_en_rango_entero(valor, min, max));

    return valor;
}

float leer_flotante(const char *mensaje)
{
    float valor;
    int resultado;

    while (1) {
        printf("%s", mensaje);
        resultado = scanf("%f", &valor);
        limpiar_buffer_entrada();

        if (resultado == 1) {
            return valor;
        }

        printf("entrada invalida. Por favor ingrese un numero.\n");
    }
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor;

    do {
        valor = leer_flotante(mensaje);
        if (!esta_en_rango_flotante(valor, min, max)) {
            printf("el valor debe estar entre %.2f y %2.f.\n", min, max);
        }
    }
    while (!esta_en_rango_flotante(valor, min, max));

    return valor; 
}

char leer_caracter(const char *mensaje)
{
    char valor;
    int resultado;

    while (1) {
        printf("%s", mensaje);
        resultado = scanf(" %c", &valor);
        limpiar_buffer_entrada();
        
        if (resultado == 1) {
            return valor;
        }

        printf("entrada invalida. Por favor ingrese un caracter.\n");
    }
}

bool leer_logico(const char *mensaje)
{
    char respuesta;

    while (1) {
        respuesta = leer_caracter(mensaje);
        respuesta = tolower((unsigned char)respuesta);
        
        if (respuesta == 's' || respuesta == '1') {
            return true;
        }
        if (respuesta == 'n' || respuesta == '0') {
            return false;
        }

        printf("respuesta invalida. Ingrese 's'/'n' o '1'/'0'.\n");
    }
}
