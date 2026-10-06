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
    bool retorno = false;
    if (valor >= min && valor <= max)
    {
        retorno = true;
    }
    return retorno;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    bool retorno = false;
    if (valor >= min && valor <= max)
    {
        retorno = true;
    }
    return retorno;
}

int leer_entero(const char *mensaje)
{
    
    int valor = 0;
    int retorno_scanf = 0;
    do
    {
        printf ("%s", mensaje);
        retorno_scanf = scanf ("%d", &valor);
        if (retorno_scanf != 1)
        {
            printf ("Error. Entrada invalida.\n");
            limpiar_buffer_entrada();
        }
    } while (retorno_scanf != 1);
    limpiar_buffer_entrada();
    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    
    int valor = 0;
    do
    {
        valor = leer_entero(mensaje);
        if (!esta_en_rango_entero(valor, min, max))
        {
            printf ("Error. No esta en el rango entre %d y %d.\n", min, max);
        }
    } while (!esta_en_rango_entero(valor, min, max));
    return valor;
}

float leer_flotante(const char *mensaje)
{
    
    float valor = 0.0f;
    int retorno_scanf = 0;
    do
    {
        printf ("%s", mensaje);
        retorno_scanf = scanf ("%f", &valor);
        if (retorno_scanf != 1)
        {
            printf ("Error. Entrada invalida.\n");
            limpiar_buffer_entrada();
        }
    } while (retorno_scanf != 1);
    limpiar_buffer_entrada();
    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    
    float valor = 0.0f;
    do
    {
        valor = leer_flotante(mensaje);
        if (!esta_en_rango_flotante(valor, min, max))
        {
            printf ("Error. No esta en el rango entre %f y %f.\n", min, max);
        }
    } while (!esta_en_rango_flotante(valor, min, max));
    return valor;
}

char leer_caracter(const char *mensaje)
{
    
    char caracter = '0';
    printf ("%s", mensaje);
    scanf (" %c", &caracter);
    limpiar_buffer_entrada();
    return caracter;
}

bool leer_logico(const char *mensaje)
{
    
    char opcion = '0';
    bool si_no = false;
    bool salir = false;
    do
    {
        opcion = leer_caracter(mensaje);
        switch (opcion)
        {
            case '1':
                si_no = true;
                salir = true;
                break;
            case 's':
                si_no = true;
                salir = true;
                break;
            case 'S':
                si_no = true;
                salir = true;
                break;
            case '0':
                si_no = false;
                salir = true;
                break;
            case 'n':
                si_no = false;
                salir = true;
                break;
            case 'N':
                si_no = false;
                salir = true;
                break;
            default:
                printf ("Error. Entrada invalida.\n");
                salir = false;
        }
    }while (!salir);
    return si_no;
}
