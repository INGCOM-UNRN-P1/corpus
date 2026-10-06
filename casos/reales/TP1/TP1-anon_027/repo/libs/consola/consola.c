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
    if((valor >= min) && (valor <= max))
    {
        return true;
    }
    
    else
    {
        return false;
    }
}





bool esta_en_rango_flotante(float valor, float min, float max)
{
    if((valor >= min) && (valor <= max))
    {
        return true;
    }
    
    else
    {
        return false;
    }
}






int leer_entero(const char *mensaje)
{
    int valor = 0;

    do
    {
        printf("%s", mensaje);

        if (scanf(" %d", &valor) == 1)
        {
            limpiar_buffer_entrada();
            return valor;
        }
        else
        {
            limpiar_buffer_entrada();
            printf("Error: debe ingresar un numero entero.\n");
        }
    }
    while (1);
}





int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor = 0;

    do
    {
        valor = leer_entero(mensaje);
        
        if(esta_en_rango_entero(valor,min,max))
        {
            return valor;
        }
        
        else
        {   
            printf("Tenes que ingresar un valor que este entre %d y %d si o si!\n",min,max);
        }
    }    
    
    while(1);    
}





float leer_flotante(const char *mensaje)
{
    float valor = 0.0;

    do
    {
        printf("%s",mensaje);

        if(scanf(" %f",&valor) == 1)
        {
            limpiar_buffer_entrada();
            return valor;
        }
        limpiar_buffer_entrada();
        printf("ERROR!! INGRESE UN VALOR FLOTANTE CORRECTO!!\n");
    }
    
    while(1);
}





float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor = 0.0;

    leer_flotante(mensaje);
    esta_en_rango_flotante(valor,min,max);

    while((valor < min) || (valor > max))
    {
        printf("El valor debe estar entre %f y %f, ingrese nuevamente",min,max);
        leer_flotante(mensaje);
    }
        return valor;
}




char leer_caracter(const char *mensaje)
{
    char caracter = 'a';
    
    printf("%s",mensaje);
    scanf("%c",&caracter);
    
    limpiar_buffer_entrada();
    
    return caracter;
}




bool leer_logico(const char *mensaje)
{
    char caracter = 'a';

    do
    {
        printf("%s",mensaje);
        scanf(" %c",&caracter);
        
        limpiar_buffer_entrada();
        
        if((caracter == 's') || (caracter == 'S') || (caracter == '1'))
        {
            return true;
        }

        else if((caracter == 'n') || (caracter == 'N') || (caracter == '0'))
        {
            return false;
        }
        
        printf("ERROR!, ingrese 's' , 'S' , '1' para confirmar\n 'n', 'N', '0' para salir!\n\n");  
    }
    
    while (1);
}