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
    int numero_leido = 0;

    bool lectura_valida = false;

    while (lectura_valida == false)
    {
        printf("%s", mensaje);

        if (scanf("%d", &numero_leido) == 1)
        {
            lectura_valida = true;
        }
        else
        {
            printf("Error: Entrada no valida. Intente nuevamente.\n");
        }
        limpiar_buffer_entrada();
    }
    return numero_leido;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor_leido = 0;

    bool rango_valido = false;

    valor_leido = leer_entero(mensaje);

    while (rango_valido == false)
    {
        if (esta_en_rango_entero(valor_leido, min, max))
        {
            rango_valido = true;
        }
        else
        {
            printf("Error: El valor debe estar entre %d y %d. Intente nuevamente.\n", min, max);
            valor_leido = leer_entero(mensaje);
        }
    }
    return valor_leido;
}

float leer_flotante(const char *mensaje)
{
    bool valor_flotante = false;
    float numero_flotante = 0.0f;

    while ( valor_flotante == false)
    {
        printf("%s", mensaje);

        if (scanf("%f", &numero_flotante) == 1)
        {
            valor_flotante = true;
        }
        else 
        {
            printf("Error: Entrada no valida. Intente nuevamente.\n");
        }
        limpiar_buffer_entrada();
    }
     
    return numero_flotante;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float flotante_entre = 0.0f;
    bool valor_entre = false;

    while (valor_entre == false)
    {
        flotante_entre = leer_flotante(mensaje);

        if (esta_en_rango_flotante(flotante_entre, min, max) == true)
        {
            valor_entre = true;
        }
        else
        {
            printf("Error: El valor debe estar entre %f y %f. Intente nuevamente.\n", min, max);
        }
    }
    return flotante_entre;
}

char leer_caracter(const char *mensaje)
{
    char valor_caracter = 0;

    printf("%s", mensaje);

    scanf(" %c", &valor_caracter);

    limpiar_buffer_entrada();

    return valor_caracter;
}

bool leer_logico(const char *mensaje)
{
    char valor_logico = 0;
    bool entrada_valida = false;
    bool resultado_entrada = false;

    while (entrada_valida == false)
    {
        printf("%s", mensaje);

        scanf(" %c", &valor_logico);
        limpiar_buffer_entrada();

        if (valor_logico == 's' || valor_logico == 'S' || valor_logico == '1')
        {
            resultado_entrada = true;
            entrada_valida = true;
        }
        else if (valor_logico == 'n' || valor_logico == 'N' || valor_logico == '0')
        {
            resultado_entrada = false;
            entrada_valida = true;
        }
        else
        {
            printf("Error. Ingrese un caracter o numero valido ('s', 'S', '1' / 'n', 'N', '0'): ");
        }
    }
    return resultado_entrada;
}
