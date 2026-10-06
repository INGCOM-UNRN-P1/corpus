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
    

    int valor;
    int resultado;

    printf("%s", mensaje);
    resultado = scanf("%d", &valor);
    limpiar_buffer_entrada();

    while (resultado != 1)
    {
        printf("Entrada invalida, intentá de nuevo. \n");
        printf("%s", mensaje);
        resultado = scanf("%d", &valor);
        limpiar_buffer_entrada();
    }
    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    

    int valor;

    valor = leer_entero(mensaje);

    while (!esta_en_rango_entero(valor, min, max))
    {
        printf("Error: el valor tiene que estar entre %d y %d. \n", min, max);
        valor = leer_entero(mensaje);
    }
    return valor;
}

float leer_flotante(const char *mensaje)
{
    

    float valor;
    int resultado;

    printf("%s", mensaje);
    resultado = scanf("%f", &valor);
    limpiar_buffer_entrada();

    while (resultado != 1)
    {
        printf("Entrada invalida, intentá de nuevo. \n");
        printf("%s", mensaje);
        resultado = scanf("%f", &valor);
        limpiar_buffer_entrada();
    }
    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    

    float valor;

    valor = leer_flotante(mensaje);

    while (!esta_en_rango_flotante(valor, min, max))
    {
        printf("Error: el valor debe estar entre %f y %f. \n",min, max);
        valor = leer_flotante(mensaje);
    }

    return valor;
}

char leer_caracter(const char *mensaje)
{
    

    char caracter;

    printf("%s", mensaje);
    scanf(" %c", &caracter);
    limpiar_buffer_entrada();

    return caracter;
}

bool leer_logico(const char *mensaje)
{
    

    char caracter;
    bool valido;
    
    valido = false;

    do
    {
        printf("%s", mensaje);
        scanf(" %c", &caracter);
        limpiar_buffer_entrada();
        
        if (caracter == 's' || caracter == 'S')
        {
            valido = true;
            return true;
        }
        else if (caracter == 'n' || caracter == 'N')
        {
            valido = true;
            return false;
        }
        else
        {
            printf("Respuesta invalida, ingrese: 's' o 'n'. \n");
        }

    } while (!valido);

    return false; 
}
