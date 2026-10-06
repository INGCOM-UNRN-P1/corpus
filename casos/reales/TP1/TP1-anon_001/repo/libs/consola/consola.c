#include "consola.h"
#include <stdio.h>
#include <ctype.h>

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
    bool leido = false;
    int valor = 0;
    do
    {
        printf("%s", mensaje);
        leido = (scanf("%d", &valor) == 1);
        limpiar_buffer_entrada();
        if (!leido)
        {
            printf("Entrada inválida, reintente\n");
        }
    } while (!leido);
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
            printf("Entrada inválida, ingrese un valor entre %d y %d\n", min, max);
        }
    } while (!esta_en_rango_entero(valor, min, max));
    return valor;
}    


float leer_flotante(const char *mensaje)
{
    bool leido = false;
    float valor = 0;
    do
    {
        printf("%s", mensaje);
        leido = (scanf("%f", &valor) == 1);
        limpiar_buffer_entrada();
        if (!leido)
        {
            printf("Entrada inválida, reintente.\n");
        }
    } while (!leido);
    return valor;

}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    
    float valor = 0;
    do
    {
        valor = leer_flotante(mensaje);
        if (!esta_en_rango_flotante(valor, min, max))
        {
            printf("Entrada inválida, ingrese un valor entre %f y %f\n", min, max);
        }
    } while (!esta_en_rango_flotante(valor, min, max));
    return valor;
}

char leer_caracter(const char *mensaje)
{
    char caracter = 'a';
    printf("%s", mensaje);
    scanf(" %c", &caracter);
    limpiar_buffer_entrada();
    return caracter;
}

bool leer_logico(const char *mensaje)
{
    char entrada = ' ';
    bool opcion = true;
    do
    {
        entrada =  tolower(leer_caracter(mensaje));
        if(entrada == 's')
        {
            opcion = true;
        }
        else if(entrada == 'n')
        {
            opcion = false;
        }
        else
        {
            printf("Entrada invalida, reintente.\n");
        }
    } while ((entrada != 's') && (entrada != 'n'));
    return opcion;
}

