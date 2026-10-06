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
    
    int valor = 0;
    int aceptados = 0;
    bool validacion = false;

    while (!validacion)
    {
        printf("%s", mensaje);
        aceptados = scanf("%d", &valor);

        limpiar_buffer_entrada();

        if (aceptados == 1)
        {
            validacion = true;
        }
            else
        {
        printf("Error: Debe ingresar un numero entero valido.\n");
        }

    }

    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    
    int valor = 0;
    bool validacion = false;

    while (!validacion)
    {
        valor = leer_entero(mensaje);

        if (esta_en_rango_entero(valor, min, max))
        {
            validacion = true;
        } else
        {
            printf("Error: El valor ingresado debe estar entre %d y %d.\n", min, max);
        }
    }
    return valor;
}

float leer_flotante(const char *mensaje)
{
    

    float valor = 0.0f;
    int aceptados = 0;
    bool validacion = false;

    while (!validacion)
    {
        printf("%s", mensaje);
        aceptados = scanf("%f", &valor);

        limpiar_buffer_entrada();

        if (aceptados == 1)
        {
            validacion = true;
        }
            else
        {
        printf("Error: Debe ingresar un numero entero valido.\n");
        }

    }

    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    

    float valor = 0.0f;
    bool validacion = false;

    while (!validacion)
    {
        valor = leer_flotante(mensaje);

        if (esta_en_rango_flotante(valor, min, max))
        {
            validacion = true;
        } else
        {
            printf("Error: El valor ingresado debe estar entre %.2f y %.2f.\n", min, max);
        }
    }
    return valor;
}

char leer_caracter(const char *mensaje)
{
    

    char caracter = ' ';
    int aceptados = 0;
    bool validacion = false;

    while (!validacion)
    {
        printf("%s", mensaje);
        aceptados = scanf("%c", &caracter);

        limpiar_buffer_entrada();

        if (aceptados == 1)
        {
            validacion = true;
        }
            else
        {
        printf("Error: Debe ingresar un numero entero valido.\n");
        }

    }

    return caracter;
}

bool leer_logico(const char *mensaje)
{
    

    bool resultado = false;
    bool validacion = false;
    char respuesta = ' ';
    int aceptados = 0;

    while (!validacion)
    {
        printf("Ingresar confirmacion: [s/n] ");
        aceptados = scanf("%c", &respuesta);

        limpiar_buffer_entrada();

        if (aceptados == 1)
        {
            if (respuesta == 's' || respuesta == 'S' || respuesta == 1)
            {
                resultado = true;
                validacion = true;
            } else if (respuesta == 'n' || respuesta == 'N' || respuesta == 0)
            {
                resultado = false;
                validacion = true;
            } else 
            {
                printf("Error: Ingrese 's'/'S'/'1' para afirmativo o 'n'/'N'/'0' para negativo.\n");
            }
        } else
        {
            printf("Error: Ingrese 's'/'S'/'1' para afirmativo o 'n'/'N'/'0' para negativo.\n");
        }
        
    }
    return resultado;
}