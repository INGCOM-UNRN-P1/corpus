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
    if(valor <= max && valor >= min)
    {
        return true;
    }
    return false;
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    if(valor <= max && valor >= min)
    {
        return true;
    }
    return false;
}

int leer_entero(const char *mensaje)
{

    int valor = 0;
    int leido = 0; 
    do 
    {
        printf("%s", mensaje); 
        leido = scanf("%d", &valor);
        limpiar_buffer_entrada();

        if(leido != 1)
        {
          printf("Error: debe ingresar un numero entero valido.\n");  
        }
    }
    while (leido != 1);
    
    return valor;

    
    
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor = 0;
    
    do
    {
        valor = leer_entero(mensaje);
        if (esta_en_rango_entero(valor, min,max) == false)
        {
            printf("Error. Ingrese un valor entre %d y %d \n", min, max);
        } 
    }
    while (esta_en_rango_entero(valor, min,max) == false);

    return valor;
    
    
    
}

float leer_flotante(const char *mensaje)
{

    float valor = 0.0f;
    int leido = 0; 
    do 
    {
        printf("%s", mensaje); 
        leido = scanf("%f", &valor);
        limpiar_buffer_entrada();

        if(leido != 1)
        {
          printf("Error: debe ingresar un numero flotante valido.\n");  
        }
    }
    while (leido != 1);
    
    return valor;
    
    
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor = 0.0f;
   
    do
    {
        valor = leer_flotante(mensaje);
        if (esta_en_rango_flotante(valor, min,max) == false)
        {
            printf("Error. Ingrese un valor entre %f y %f \n", min, max);
        } 
    }
    while (esta_en_rango_flotante(valor, min,max) == false);

    return valor;
    

}

char leer_caracter(const char *mensaje)
{
    char c;
    printf("%s", mensaje);
    scanf(" %c", &c);
    limpiar_buffer_entrada();
    
    return c;
}

bool leer_logico(const char *mensaje)
{
    char c;
    do 
    {
        printf("%s, [s / n]: \n", mensaje);
        scanf("%s", &c);
        limpiar_buffer_entrada();

        if(c == 's' || c == 'S')
        {
            return true;
        }
        else if (c == 'n' || c == 'N')
        {
            return false;
        }
        printf("Error: ingrese 's' para SI o 'n' para NO. \n");
        
    }

    while (true);
    
    
    
}
