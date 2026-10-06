#include "consola.h"
#include <stdio.h>

void limpiar_buffer_entrada(void)
{
    int caracter = 0;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
        
    }
}

//Segun el .md esta funcion estaba provista pero la tuve que implementar
bool esta_en_rango_entero(int valor, int min, int max)
{
    if (valor >= min && valor <= max)
    {
        return true;
    }
    return false;
}

//Segun el .md esta funcion estaba provista pero la tuve que implementar
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
    printf("%s", mensaje);
    int valor = 0;
    bool leyendo_valor = true;

    while (leyendo_valor)
    {
        int entrada = scanf("%d", &valor);
        if (entrada == 1)
        {
            leyendo_valor = false;
        }
        else
        {
            printf("ERROR: la entrada no es valida\n");
            limpiar_buffer_entrada();
        }
    }

    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    bool leyendo_valor = true;
    int valor = 0;

    while(leyendo_valor)
    {
        int valor = leer_entero(mensaje);
        if (esta_en_rango_entero(valor, min, max))
        {
            leyendo_valor = false;
        }
        else
        {
            printf(
                "ERROR: El numero ingresado no esta dentro del rango (%d-%d)\n",
                 min, max);
        }
    }

    return valor;
}

float leer_flotante(const char *mensaje)
{
    printf("%s", mensaje);
    float valor = 0.0f;

    bool leyendo_valor = true;
    while(leyendo_valor)
    {
        int entrada = scanf("%f", &valor);
        if (entrada == 1)
        {
            leyendo_valor = false;
        }
        else
        {
            limpiar_buffer_entrada();
            printf("ERROR: La entrada no es valida\n");
        }
    }

    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    bool leyendo_valor = true;
    float valor = 0;

    while(leyendo_valor)
    {
        valor = leer_flotante(mensaje);
        if (esta_en_rango_flotante(valor, min, max))
        {
            leyendo_valor = false;
        }
        else
        {
            printf(
                "ERROR: El numero ingresado no esta dentro del rango (%f-%f)\n",
                 min, max);
        }
    }

    return valor;
}

char leer_caracter(const char *mensaje)
{
    printf("%s", mensaje);
    char caracter = 0;
    bool leyendo_caracter = true;

    while (leyendo_caracter)
    {
        int entrada = scanf("%c", &caracter);
        if (entrada == 1)
        {
            leyendo_caracter = false;
        }
        else
        {
            printf("ERROR: la entrada no es valida\n");
            limpiar_buffer_entrada();
        }
    }

    return caracter;
}

bool leer_logico(const char *mensaje)
{
    char respuesta = 'a';
    bool leyendo_respuesta = true;

    while (leyendo_respuesta)
    {
        respuesta = leer_caracter(mensaje);
        if (respuesta == 's' ||
            respuesta == 'S')
        {
            leyendo_respuesta = false;
        }
        else if (respuesta == 'n' ||
                respuesta == 'N')
        {
            respuesta = false;
            leyendo_respuesta = false;
        }
        else
        {
            printf("ERROR: la entrada no es valida\n");
            limpiar_buffer_entrada();
        }
    }

    return respuesta;
}
