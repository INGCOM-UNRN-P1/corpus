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
    bool validar = ((min <= valor) && (valor <= max));
    return validar;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    bool validar = ((min <= valor) && (valor <= max));
    return validar;
}

int leer_entero(const char *mensaje)
{   
    int valor = 0; 

    printf("&s", mensaje);
    
    while((scanf("%d", &valor) != 1))
    {
        printf("%d no es un ingreso válido. Ingrese un número entero.\n", valor);
        limpiar_buffer_entrada();
    }

    limpiar_buffer_entrada();

    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor = 0;
    
    valor = leer_entero(mensaje);

    while(esta_en_rango_entero(valor, min, max) != 1)
    {
        printf("%d no se encuentra en el rango. Ingrese un número entero entre %d y %d", valor, min, max);
        limpiar_buffer_entrada();
    }

    limpiar_buffer_entrada();
    
    return valor;
}

float leer_flotante(const char *mensaje)
{
    float valor = 0; 

    printf("&s", mensaje);
    
    while((scanf("%f", &valor) != 1))
    {
        printf("%f no es un ingreso válido. Ingrese un número.\n", valor);
        limpiar_buffer_entrada();
    }

    limpiar_buffer_entrada();

    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor = 0;
    
    valor = leer_flotante(mensaje);

    while(esta_en_rango_entero(valor, min, max)!=1)
    {
        printf("%f no se encuentra en el rango. Ingrese un número entre %f y %f", valor, min, max);
        limpiar_buffer_entrada();
    }

    limpiar_buffer_entrada();
    
    return valor;
}

char leer_caracter(const char *mensaje)
{
    
    char caracter;

    printf("%s", mensaje);

    scanf("%c", &caracter);

    limpiar_buffer_entrada();

    return caracter;
}

bool leer_logico(const char *mensaje)
{
    
    bool logico;
    char respuesta;

    printf("%s : [s/]\n", mensaje);
    scanf("%c", &respuesta);

    //Esta variable pretende hacer más legible las condiciones, pero no es necesaria
    bool respuesta_valida = ((respuesta == 's' || respuesta == 'S') || (respuesta == 'n' || respuesta == 'N'));

    while(!respuesta_valida)
    {
        printf("%c no es una respuesta válida\n", respuesta);
        printf("%s : [s/]\n", mensaje);
    }
    
    if((respuesta == 's') || (respuesta == 'S'))
    {
        logico = true;
    }else
    {
        logico = false; 
    }

    return logico;
}
