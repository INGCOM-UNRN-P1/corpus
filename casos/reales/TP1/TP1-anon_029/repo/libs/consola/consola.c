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
    if (valor >= min && valor <= max)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    if (valor >= min && valor <= max)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int leer_entero(const char *mensaje)
{
    int valor;
    int resultado;
    do
    {
        printf("%s", mensaje);
        resultado = scanf("%d", &valor);
        if (resultado != 1)
        {
            printf("Error, dato ingresado erroneo, vuelva a intentar");
        }
        limpiar_buffer_entrada();
    } while (resultado != 1);

    limpiar_buffer_entrada();
    return valor;
    return 0;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor;
    bool rango;
    do
    {
        valor = leer_flotante(mensaje);
        rango = esta_en_rango_entero(valor, min, max);
        if (!rango)
        {
            printf("Error, numero fuera del rango (%d y %d).\n", min, max);
        }
    } while (!rango); // Si el valor esta fuera del rango, se repite el bucle
    return valor;
    return 0;
}

float leer_flotante(const char *mensaje)
{
    int resultado;
    float valor;
    do
    {
        printf("%s", mensaje);
        resultado = scanf("%f", &valor);
        if (resultado != 1)
        {
            printf("Error de ingreso. vuelva a intentarlo.\n");
            limpiar_buffer_entrada();
        }
    } while (resultado != 1);
    return resultado;
    return 0.0f;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor;
    bool rango;
    do
    {
        valor = leer_flotante(mensaje);
        rango = esta_en_rango_flotante(valor, min, max);
        if (!rango)
        {
            printf("Error, numero fuera del rango (%.2f y %.2f).\n", min, max);
        }
    } while (!rango); // Si el valor esta fuera del rango, see repite el bucle
    return valor;
    return 0.0f;
}

char leer_caracter(const char *mensaje)
{
    char caracter;
    printf("%s", mensaje);
    scanf(" %c", &caracter);
    if (scanf(" %c", &caracter) == 1)
    {
        limpiar_buffer_entrada();
        return caracter;
    }
    limpiar_buffer_entrada();
    return ' ';
}

bool leer_logico(const char *mensaje)
{
    char caracter = '\0';
    do
    {
        printf(" %c", leer_caracter(mensaje));
        if (caracter == 's' || caracter == 'S')
        {
            return 1; // Verdadero
        }
        else if (caracter == 'n' || caracter == 'N')
        {
            return 0; // falso
        }
        printf("Error, debe ingresar 's' para 'SI' o 'n' para 'NO'."
               "Vuelva a intentar.\n");
        limpiar_buffer_entrada();
    } while (1);
    return false;
}
