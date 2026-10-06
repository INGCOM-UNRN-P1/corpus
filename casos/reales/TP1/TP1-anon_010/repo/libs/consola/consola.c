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
    int entero_valor = 0;
    int resultado = 0;

    do
    {
        printf("%s", mensaje);
        resultado = scanf("%d", &entero_valor);
        limpiar_buffer_entrada();

        if(resultado != 1)
        {
            printf("Entrada invalida. Pruebe de nuevo.\n");
        }        
    } while (resultado != 1);

    return entero_valor;
}


int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor_entero = 0;
    bool valido = 0;
   
    do
    {
        valor_entero = leer_entero(mensaje);
        valido = esta_en_rango_entero(valor_entero, min, max);
        if (valido == false)
        {
            printf("El valor debe estar entre %d y %d.\n", min, max);
        }
    } while(valido == false);

    return valor_entero;
}


float leer_flotante(const char *mensaje)
{
    float float_valor = 0.0f;
    int resultado = 0;

    do
    {
        printf("%s", mensaje);
        resultado = scanf("%f", &float_valor);
        limpiar_buffer_entrada();

        if(resultado != 1)
        {
            printf("Entrada invalida. Pruebe de nuevo.\n");
        }        
    } while (resultado != 1);

    return float_valor;
}


float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor_float = 0.0f;
    bool valido = 0;

    do
    {
        valor_float = leer_flotante(mensaje);
        valido = esta_en_rango_flotante(valor_float, min, max);
        if (valido == false)
        {
            printf("El valor debe estar entre %.2f y %.2f.\n", min, max);
        }
    } while(valido == false);

    return valor_float;
}


char leer_caracter(const char *mensaje)
{
    char caracter_valor = 'a';
    int resultado = 0;

    do
    {
        printf("%s", mensaje);
        resultado = scanf(" %c", &caracter_valor);
        limpiar_buffer_entrada();

        if(resultado != 1)
        {
            printf("Entrada invalida. Pruebe de nuevo.\n");
        }        
    } while (resultado != 1);

    return caracter_valor;
}


bool leer_logico(const char *mensaje)
{
    char opcion = 'a';
    bool valido = false;
    bool opcion_elegida = false;
    
   
    
    do
    {
        opcion = leer_caracter(mensaje);
        if (opcion == 's' ||opcion == 'S' ||opcion == '1')
        {
            valido = true;
            opcion_elegida = true;
        }
        else if (opcion == 'n' ||opcion == 'N' ||opcion == '0')
        {
            valido = true;
            opcion_elegida = false;
        }
        else
        {
            printf("Respuesta invalida. Ingrece alguna de las opciones ofrecidas.\n");
            valido = false;
        }
    } while (valido != true);
    return opcion_elegida;
}
