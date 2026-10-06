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
    int valor = 0;
    bool entrada_valida = false;

    while (!entrada_valida)
    {
        printf("%s", mensaje);
        if (scanf("%d", &valor) == 1)
        {
            entrada_valida = true;
        }
        else
        {
            printf("Entrada invalida. Debe ingresar un numero entero.\n");
        }
        limpiar_buffer_entrada();
    }

    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor = 0;
    bool entrada_valida = false;

    while (!entrada_valida)
    {
        valor = leer_entero(mensaje);
        if (esta_en_rango_entero(valor, min, max))
        {
            entrada_valida = true;
        }
        else
        {
            printf("El valor debe estar entre %d y %d.\n", min, max);
        }
    }

    return valor;
}

float leer_flotante(const char *mensaje)
{
    float valor = 0.0f;
    bool entrada_valida = false;

    while (!entrada_valida)
    {
        printf("%s", mensaje);
        if (scanf("%f", &valor) == 1)
        {
            entrada_valida = true;
        }
        else
        {
            printf("Entrada invalida. Debe ingresar un numero decimal.\n");
        }
        limpiar_buffer_entrada();
    }

    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor = 0.0f;
    bool entrada_valida = false;

    while (!entrada_valida)
    {
        valor = leer_flotante(mensaje);
        if (esta_en_rango_flotante(valor, min, max))
        {
            entrada_valida = true;
        }
        else
        {
            printf("El valor debe estar entre %.2f y %.2f.\n", min, max);
        }
    }

    return valor;
}

char leer_caracter(const char *mensaje)
{
    char caracter = '\0';
    bool entrada_valida = false;

    while (!entrada_valida)
    {
        printf("%s", mensaje);
        if (scanf(" %c", &caracter) == 1)
        {
            entrada_valida = true;
        }
        else
        {
            printf("Entrada invalida. Debe ingresar un caracter.\n");
        }
        limpiar_buffer_entrada();
    }

    return caracter;
}

bool leer_logico(const char *mensaje)
{
    char respuesta = '\0';
    bool entrada_valida = false;
    bool resultado = false;

    while (!entrada_valida)
    {
        respuesta = leer_caracter(mensaje);
        if (respuesta == 's' || respuesta == 'S')
        {
            resultado = true;
            entrada_valida = true;
        }
        else if (respuesta == 'n' || respuesta == 'N')
        {
            resultado = false;
            entrada_valida = true;
        }
        else
        {
            printf("Respuesta invalida. Ingrese 's' o 'n'.\n");
        }
    }

    return resultado;
}
