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
    return (valor >= min && valor <= max);
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    return (valor >= min && valor <= max);
}

int leer_entero(const char *mensaje)
{
    int valor = 0;
    while(1)
    {
        printf("%s", mensaje);
        if(scanf("%d", &valor) == 1)
        {
            limpiar_buffer_entrada();
            return valor;
        }
        limpiar_buffer_entrada();
        printf("Valor invalido. ingrese el valor nuevamente \n");
    }

    
    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor = leer_entero(mensaje);
    while(valor < min || valor > max)
    {
        printf("Error, el numero esta fuerda del rango \n");
        valor = leer_entero(mensaje);
    }
    return valor;


    
}

float leer_flotante(const char *mensaje)
{
    float valor = 0;
    while(1)
    {
        printf("%s", mensaje);
        if(scanf("%d", &valor) == 1)
        {
            limpiar_buffer_entrada();
            return valor;
        }
        limpiar_buffer_entrada();
        printf("Valor invalido. ingrese el valor nuevamente \n");
    }


    
    return 0.0f;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    int valor = leer_flotante(mensaje);
    printf("rango de valores %f - %f \n", min, max);
    while(esta_en_rango_flotante(valor, min, max))
    {
        printf("Error, el numero esta fuerda del rango \n");
        valor = leer_flotante(mensaje);
    }
    return valor;

    
}

char leer_caracter(const char *mensaje)
{
    char caracter;
    printf("%s, mensaje\n");
    scanf(" %c", &caracter);
    limpiar_buffer_entrada();
    return caracter;
    
}

bool leer_logico(const char *mensaje)
{
    char respuesta;

    while (true)
    {
        printf("%s [s/n]: ", mensaje);
        if (scanf(" %c", &respuesta) == 1)
        {
            if (respuesta == 's' || respuesta == 'S' || respuesta == '1')
            {
                return true;
            }
            else if (respuesta == 'n' || respuesta == 'N' || respuesta == '0')
            {
                return false;
            }
        }
        printf("Respuesta invalidal, por favor ingrese un caracter valido (s, n ,1 o 0).\n");
    }

    
    return false;
}
