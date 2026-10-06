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
    int resultado_lectura = 0;
    bool lectura_valida = false;

    while (lectura_valida == false)
    {
        printf("%s", mensaje);

        resultado_lectura = scanf("%d", &valor);

        limpiar_buffer_entrada();

        if (resultado_lectura == 1)
        {
            lectura_valida = true;
        }
        else
        {
            printf("Entrada invalida. Ingrese un numero entero.\n");
        }
    }

    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor = 0;
    bool valor_valido = false;

    while (valor_valido == false)
    {
        valor = leer_entero(mensaje);

        if (esta_en_rango_entero(valor, min, max))
        {
            valor_valido = true;
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
    int resultado_lectura = 0;
    bool lectura_valida = false;

    while (lectura_valida == false)
    {
        printf("%s", mensaje);

        resultado_lectura = scanf("%f", &valor);

        limpiar_buffer_entrada();

        if (resultado_lectura == 1)
        {
            lectura_valida = true;
        }
        else
        {
            printf("Entrada invalida. Ingrese un numero.\n");
        }
    }

    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor = 0.0f;
    bool valor_valido = false;

    while (valor_valido == false)
    {
        valor = leer_flotante(mensaje);

        if (esta_en_rango_flotante(valor, min, max))
        {
            valor_valido = true;
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
    char caracter = ' ';

    printf("%s", mensaje);

    scanf(" %c", &caracter);

    limpiar_buffer_entrada();

    return caracter;
}

bool leer_logico(const char *mensaje)
{
    char respuesta = ' ';
    bool valor_logico = false;
    bool respuesta_valida = false;

    while (respuesta_valida == false)
    {
        printf("%s [s/n]: ", mensaje);

        scanf(" %c", &respuesta);

        limpiar_buffer_entrada();

        if (respuesta == 's' || respuesta == 'S' || respuesta == '1')
        {
            valor_logico = true;
            respuesta_valida = true;
        }
        else if (respuesta == 'n' || respuesta == 'N' || respuesta == '0')
        {
            valor_logico = false;
            respuesta_valida = true;
        }
        else
        {
            printf("Respuesta invalida. Ingrese s/n o 1/0.\n");
        }
    }

    return valor_logico;
}