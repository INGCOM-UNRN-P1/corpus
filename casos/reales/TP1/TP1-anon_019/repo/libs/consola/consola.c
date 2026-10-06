#include "consola.h"
#include <stdio.h>
#include <stdbool.h>

void limpiar_buffer_entrada(void)
{
    int caracter = 0;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
        
    }
}

bool esta_en_rango_entero(int valor, int min, int max)
{
    if (valor >= min && valor <= max)
    {
        return true;
    }
    return false;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    if (valor >= min && valor <= max)
    {
        return true;
    }
    return false;
}

int leer_entero(const char *mensaje)
{
    int valor = 0;
    int elementos_leidos = 0;

    do
    {
        printf("%s", mensaje);
        elementos_leidos = scanf("%d", &valor);
        limpiar_buffer_entrada();

        if (elementos_leidos != 1)
        {
            printf("Error: Entrada invalida. Por favor, ingrese un numero entero.\n");
        }
    } while (elementos_leidos != 1);

    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor = 0;

    do
    {
        valor = leer_entero(mensaje);

        if (esta_en_rango_entero(valor, min, max) == false)
        {
            printf("Error: El valor debe estar entre %d y %d.\n", min, max);
        }
    } while (esta_en_rango_entero(valor, min, max) == false);

    return valor;
}

float leer_flotante(const char *mensaje)
{
    float valor = 0.0f;
    int elementos_leidos = 0;

    do
    {
        printf("%s", mensaje);
        elementos_leidos = scanf("%f", &valor);
        limpiar_buffer_entrada();

        if (elementos_leidos != 1)
        {
            printf("Error: Entrada invalida. Por favor, ingrese un numero decimal.\n");
        }
    } while (elementos_leidos != 1);

    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor = 0.0f;

    do
    {
        valor = leer_flotante(mensaje);

        if (esta_en_rango_flotante(valor, min, max) == false)
        {
            printf("Error: El valor debe estar entre %.2f y %.2f.\n", min, max);
        }
    } while (esta_en_rango_flotante(valor, min, max) == false);

    return valor;
}

char leer_caracter(const char *mensaje)
{
    char valor = ' ';
    
    printf("%s", mensaje);
    scanf(" %c", &valor);
    limpiar_buffer_entrada();
    
    return valor;
}

bool leer_logico(const char *mensaje)
{
    char respuesta = ' ';
    bool resultado = false;
    bool entrada_valida = false;

    do
    {
        respuesta = leer_caracter(mensaje);

        if (respuesta == 's' || respuesta == 'S' || respuesta == '1')
        {
            resultado = true;
            entrada_valida = true;
        }
        else if (respuesta == 'n' || respuesta == 'N' || respuesta == '0')
        {
            resultado = false;
            entrada_valida = true;
        }
        else
        {
            printf("Error: Respuesta invalida. Ingrese 's' (Si) o 'n' (No).\n");
        }
    } while (entrada_valida == false);

    return resultado;
}