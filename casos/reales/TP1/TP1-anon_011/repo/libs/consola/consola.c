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
    bool res = false;
    
    if (min <= valor && max >= valor)
    {
        res = true;
    }
    return res;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    bool res = false;
    
    if (min <= valor && max >= valor)
    {
        res = true;
    }
    return res;
}

int leer_entero(const char *mensaje)
{

    

    printf("%s", mensaje);
    
    int valor = 0;
    int es_entero = 0;

    while(es_entero != 1)
    {
        es_entero = scanf("%d", &valor);
        limpiar_buffer_entrada();
        if(es_entero != 1)
        {
            printf("El mensaje ingresado no es valido, ingresar un numero entero valido.\n");
        }
    }
    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{

    

    int num = leer_entero(mensaje);

    while(esta_en_rango_entero(num, min, max) != true)
    {
        printf("hubo un error, el numero esta fuera de rango.\n");
        num = leer_entero(mensaje);
    }
    
    return num;
}

float leer_flotante(const char *mensaje)
{
    

    printf("%s", mensaje);

    float valor = 0;
    float es_flotante = 0;

    while(es_flotante != 1)
    {
        es_flotante = scanf("%f", &valor);

        limpiar_buffer_entrada();

        if(es_flotante != 1)
        {
            printf("El mensaje ingresado no es valido, ingresar un numero flotante valido.\n");
        }
    }
    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    

    float num = leer_flotante(mensaje);

    while(esta_en_rango_flotante(num, min, max) != true)
    {
        printf("hubo un error, el numero esta fuera de rango.\n");
        num = leer_flotante(mensaje);
    }
    
    return num;
}

char leer_caracter(const char *mensaje)
{
    

    printf("%s", mensaje);

    char valor;
    scanf(" %c", &valor);
    limpiar_buffer_entrada();

    return valor;
}

bool leer_logico(const char *mensaje)
{
    

    bool res = false;
    bool valido = false;
    char confirmacion;

    while(valido == false)
    {
        printf("%s", mensaje);
        scanf(" %c", &confirmacion);
        limpiar_buffer_entrada();

        switch(confirmacion)
        {
            case 'S':
            case 's':
            case '1':
                res = true;
                valido = true;
                break;

            case 'N':
            case 'n':
            case '0':
                res = false;
                valido = true;
                break;

            default:
                printf("El caracter ingresado no es valido, intente de nuevo.\n");
        }
    }

    return res;
}