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
    bool resultado = false;
    if (valor <= max && valor >= min)
    {
        resultado = true;
    }
    return resultado;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    bool resultado = false;
    if (valor <= max && valor >= min)
    {
        resultado = true;
    }
    return resultado;
}

int leer_entero(const char *mensaje)
{
    
    bool validacion = false;
    int valor;
    printf("%s", mensaje);
    while (validacion == false)
    {

        if (scanf("%d", &valor))
        {
            validacion = true;
        }
        else
        {
            printf("Error de validacion, ingresar nuevamente: ");
        }
        limpiar_buffer_entrada();
    }
    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    
    int valor;
    bool validacion = false;
    
    while (validacion != true)
    {
        valor = leer_entero(mensaje);
        limpiar_buffer_entrada();
        if (esta_en_rango_entero(valor, min, max) == true)
        {
            validacion = true;
        }
        else
        {
            printf("Numero ingresado debe estar entre %d y %d\nIngrese nuevamente el numero: ",min, max);
            limpiar_buffer_entrada();
        }
    }
    return valor;
}

float leer_flotante(const char *mensaje)
{
    
    printf("%s",mensaje);
    float valor;
    bool validacion = false;
    while (validacion != true)
    {
        if (scanf("%f", &valor) == 1)
        {
            validacion = true;
            limpiar_buffer_entrada();
        }
        else
        {
            printf("Numero ingresado incorrectamente!\nVuelva a ingresar: ");
            limpiar_buffer_entrada();
        }
    }    
    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    
    float valor = leer_flotante(mensaje);
    while (!esta_en_rango_flotante(valor, min, max))
    {
        printf("Numero ingresado debe estar entre %.2f y %.2f\nIngrese nuevamente el numero: ", min, max);
        limpiar_buffer_entrada();
        valor = leer_flotante(mensaje);
    }
    return valor;
}

char leer_caracter(const char *mensaje)
{
    
    char valor;
    printf("%s", mensaje);
    scanf("%c", &valor);
    limpiar_buffer_entrada();
    return valor;
}

bool leer_logico(const char *mensaje)
{
    
    char valor;
    bool validacion = false;
    bool confirmacion = false;
    printf("%s", mensaje);
    while (validacion != true)
    {
        scanf("%c", &valor);
        if (isalpha(valor))
        {
            if (isupper(valor))
            {
                if(valor == 'S')
                {
                    validacion = true;
                    confirmacion = true;
                }
                else if(valor == 'N')
                {
                    validacion = true;
                    confirmacion = false;
                }
                else
                {
                    printf("Error de validacion, ingresar nuevamente: ");
                }
                limpiar_buffer_entrada();
            }
            else if(islower(valor))
            {
                if(valor == 's')
                {
                    validacion = true;
                    confirmacion = true;
                }
                else if(valor == 'n')
                {
                    validacion = true;
                    confirmacion = false;
                }
                else
                {
                    printf("Error de validacion, ingresar nuevamente: ");
                }
                limpiar_buffer_entrada();
            }
        }
        else if (isdigit(valor))
        {
            if (valor == '1')
            {
                validacion = true;
                confirmacion = true;
            }
            else if (valor == '0')
            {
                validacion = true;
                confirmacion = false;
            }
            else
            {
                printf("Error de validacion, ingresar nuevamente: ");
            }
            limpiar_buffer_entrada();
        }
        else
        {
            printf("Error de validacion, ingresar nuevamente: ");
            limpiar_buffer_entrada();
        }
    }
    return confirmacion;
}
