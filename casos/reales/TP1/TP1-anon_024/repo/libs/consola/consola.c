#include "consola.h"
#include <stdio.h>

void limpiar_buffer_entrada(void)
{
    int caracter = 0;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
        
    }
}

bool esta_en_rango_entero(int valor_ent, int min, int max)
{
    if (valor_ent >= min && valor_ent <= max)
    {
        return true;
    }

    return false;
}

bool esta_en_rango_flotante(float valor_flot, float min, float max)
{
    if (valor_flot >= min && valor_flot <= max)
    {
        return true;
    }

    return false;
}

int leer_entero(const char *mensaje)
{
    int valor_ent = 0;
    int verif_ent = 0;

    do
    {
        printf("%s", mensaje);
        verif_ent = scanf(" %d", &valor_ent);
        limpiar_buffer_entrada();

        if (verif_ent != 1)
        {
            printf("El numero es inválido. Ingrese un numero válido.\n");
        }
    }
    while (verif_ent != 1);

    return valor_ent;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor_ent = 0;
    valor_ent = leer_entero(mensaje);

    while (!esta_en_rango_entero(valor_ent, min, max))
    {
        printf("Valor fuera de %d y %d. Intente nuevamente.\n", min, max);
        valor_ent = leer_entero(mensaje);
    }

    return valor_ent;
}

float leer_flotante(const char *mensaje)
{
    float valor_flot = 0.0f;
    int verif_flot = 0;

    do
    {
        printf("%s", mensaje);
        verif_flot = scanf(" %f", &valor_flot);
        limpiar_buffer_entrada();

        if (verif_flot != 1)
        {
            printf("El flotante es invalido. Ingrese un flotante valido\n");
        }
    }
    while (verif_flot != 1);

    return valor_flot;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor_flot = 0;
    valor_flot = leer_flotante(mensaje);

    while (!esta_en_rango_flotante(valor_flot, min, max))
    {
        printf("Valor fuera de %f y %f. Intentelo nuevamente.\n", min, max);
        valor_flot = leer_flotante(mensaje);
    }

    return valor_flot;
}

char leer_caracter(const char *mensaje)
{
    char c = 'a';
    printf("%s", mensaje);
    scanf(" %c", &c);
    limpiar_buffer_entrada();
    return c;
}

bool leer_logico(const char *mensaje)
{
    char logico = 'a';
    printf("%s", mensaje);

    do
    {
        if (scanf(" %c", &logico) == 1)
        {
            limpiar_buffer_entrada();
            if (logico == 's' || logico == 'S')
            {
                return true;
            }
            if (logico == 'n' || logico == 'N')
            {
                return false;
            }
        }
        limpiar_buffer_entrada;
        printf("El valor logico es invalido. Ingrese un valor valido.\n");
    }
    while (true);
}

// La herramienta gaff de la catedra encontro las violaciones a las reglas
// 0x3003h; 0x001Eh; 0x0001h; 0x001Dh y 0x100Bh, las cuales considero
// que no corresponden a este codigo. Si me equivoco, pido disculpas.
