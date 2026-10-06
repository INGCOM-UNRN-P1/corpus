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
    return valor >= min&& valor <= max;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    return valor >= min && valor <= max;
}

int leer_entero(const char *mensaje)
{
   int valor = 0;
   int c = 0;
   while (1)
   {
    printf("%s",mensaje);
    if (scanf("%d", &valor) == 1)
    {
        while ((c =getchar ()) != '\n' && c !=EOF);
        return valor;
    }
    printf("Entrada no valida, intente de nuevo \n");
    while((c=getchar()) != '\n' && c != EOF)
    {

    }

   }
   
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor = 0;
    while(1)
    {
        valor = leer_entero(mensaje);
        if (valor >= min && valor <= max)
        {
            return valor;
        }
        printf("El valor debe estar entre %d y %d\n",min,max);
    }
}

float leer_flotante(const char *mensaje)
{
    float valor = 0.0f;
    int c = 0;
    while(1)
    {
        printf("%s",mensaje);
        if (scanf("%f",&valor)== 1)
        {
            while ((c =getchar()) != '\n' && c != EOF);
            return valor;
        }
        printf("Intenta de nuevo por entrada invalida\n");
        while((c =getchar()) != '\n' && c != EOF)
        {
    
        }
        
    }
    
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor = 0.0f;
    while(1)
    {
        valor = leer_flotante(mensaje);
        if(valor >= min && valor <= max)
        {
            return valor;
        }
        printf("Valor debe de esta rentre %.2f y %.2f\n",min,max);
    }
}

char leer_caracter(const char *mensaje)
{
    char caracter = '\0';
    int c = 0;
    while(1)
    {
        printf("%s",mensaje);
        if(scanf(" %c",&caracter) == 1)
        {
            while ((c = getchar ())!= '\n' && c != EOF );
            return caracter;
        }
        while ((c =getchar())!= '\n' && c != EOF)
        {

        }
    }
}

bool leer_logico(const char *mensaje)
{
    char entrada = '\0';
    int c = 0;
    while (true) 
    {
        printf("%s", mensaje);
        if (scanf(" %c", &entrada) == 1) 
        {
            while ((c = getchar()) != '\n' && c != EOF)
            {

            }

            if (entrada == 's' || entrada == 'S' || entrada == '1') 
            {
                return true;
            }
            if (entrada == 'n' || entrada == 'N' || entrada == '0')
            {
                return false;
            }
        } 
        else 
        {
            while ((c = getchar()) != '\n' && c != EOF)
            {

            }
        }
        printf("Respuesta no valida. Por favor, intente de nuevo.\n");
    }
}
