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
    int verificacion_entero = 0;

    do
    {
        printf("%s", mensaje);
        verificacion_entero = scanf("%d", &valor);

        limpiar_buffer_entrada();

        if (verificacion_entero != 1)
        {
            printf("ERROR: Ingrese un número entero.\n");
        }
    } while (verificacion_entero != 1);
    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor = 0;
    bool verificacion_rango = false;

    do
    {
        valor = leer_entero(mensaje);
        verificacion_rango = esta_en_rango_entero(valor, min, max);

        if (!verificacion_rango)
        {
            printf("ERROR: El valor debe estar entre %d y %d.\n", min, max);
        }
    } while (!verificacion_rango);
    return valor;
}

float leer_flotante(const char *mensaje)
{
    float valor = 0.0f;
    int verificacion_flotante = 0;

    do
    {
        printf("%s", mensaje);

        verificacion_flotante = scanf("%f", &valor);

        limpiar_buffer_entrada();

        if (verificacion_flotante != 1)
        {
            printf("ERROR: Ingrese un numero flotante.\n");
        }
        
    } while (verificacion_flotante != 1);
    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor = 0.0f;
    bool verificacion_rango = false;

    do
    {
        valor = leer_flotante(mensaje);
        verificacion_rango = esta_en_rango_flotante(valor, min, max);

        if (!verificacion_rango)
        {
            printf("ERROR: El valor debe estar entre %f y %f.\n", min, max);
        }
    } while (!verificacion_rango);
    return valor;
}

char leer_caracter(const char *mensaje)
{
    char c = '\0';

    printf("%s", mensaje);
    scanf(" %c", &c);

    limpiar_buffer_entrada();

    return c;
}

bool leer_logico(const char *mensaje)
{
    char opcion = '\0';
    bool confirmacion = false;
    bool entrada_valida = false;

    do
    {
        printf("%s", mensaje);
        scanf(" %c", &opcion);

        limpiar_buffer_entrada();

        if (opcion == 's' || opcion == 'S' || opcion == '1')
        {
            confirmacion = true;
            entrada_valida = true;
        }
        else if (opcion == 'n' || opcion == 'N' || opcion == '0')
        {
            confirmacion = false;
            entrada_valida = true;
        }
        else
        {
            printf("ERROR: Ingrese una opcion valida ('s'/'n' o '1'/'0').\n");
        }

    } while (!entrada_valida);

    return confirmacion;
}
