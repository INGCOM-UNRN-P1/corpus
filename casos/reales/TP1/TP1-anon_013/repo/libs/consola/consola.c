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
    bool pertenece_al_rango = (valor >= min) && (valor <= max);
    return pertenece_al_rango;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    bool pertenece_al_rango = (valor >= min) && (valor <= max);
    return pertenece_al_rango;
}

int leer_entero(const char *mensaje)
{
    
    int valor = 0;
    int verificar = 0;
    do
    {
        printf("%s", mensaje);
        int verificar = scanf("%d", &valor);
        limpiar_buffer_entrada();
        if (verificar != 1)
        {
            printf("ERROR: valor no es entero\n");
        }
    } while (verificar != 1);
    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    
    int numero_entero = 0;
    bool esta_en_rango = false;
    do
    {
        numero_entero = leer_entero(mensaje);
        esta_en_rango = esta_en_rango_entero(numero_entero, min, max);
        if (esta_en_rango == false)
        {
            printf("ERROR: numero fuera de rango (%d - %d)\n", min, max);
        }
    } while (esta_en_rango == false);
    return numero_entero;
}

float leer_flotante(const char *mensaje)
{
    
    float valor = 0;
    int verificar = 0;
    do
    {
        printf("%s", mensaje);
        int verificar = scanf("%f", &valor);
        limpiar_buffer_entrada();
        if (verificar != 1)
        {
            printf("ERROR: valor no es flotante\n");
        }
    } while (verificar != 1);
    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    
    float numero_flotante = 0;
    bool esta_en_rango = false;
    do
    {
        numero_flotante = leer_entero(mensaje);
        esta_en_rango = esta_en_rango_flotante(numero_flotante, min, max);
        if (esta_en_rango == false)
        {
            printf("ERROR: numero fuera de rango (%f - %f)\n", min, max);
        }
    } while (esta_en_rango == false);
    return numero_flotante;
}

char leer_caracter(const char *mensaje)
{
    
    char caracter = ' ';
    printf("%s", mensaje);
    scanf(" %c", &caracter);
    limpiar_buffer_entrada();
    return caracter;
}

bool leer_logico(const char *mensaje)
{
    
    char caracter = ' ';
    while (1)
    {
        caracter = leer_caracter(mensaje);
        limpiar_buffer_entrada();

        switch (caracter)
        {
        case 's':
        case 'S':
        case '1':
            return true;
        
        case 'n':
        case 'N':
        case '0':
            return false;
        
        default:
            printf("ERROR: Caracter invalido\n");
            break;
        }
    }
}
