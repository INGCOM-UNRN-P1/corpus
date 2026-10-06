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
{    bool salida = false;
    if((valor >= min) && (valor <= max))
    {
        salida = true;
    }
    return salida;

}

bool esta_en_rango_flotante(float valor, float min, float max)
{ 
    bool salida = false;
    if((valor >= min) && (valor <= max))
    {
        salida = true;
    }
    return salida; 
}

int leer_entero(const char *mensaje)
{
    
    
    int numero_entero = 0;
    int estado_scanf = 0;

    printf("%s\n", mensaje);
    while(estado_scanf == 0)
    {
        printf("Ingrese un numero entero\n");
        estado_scanf = scanf(" %d", &numero_entero);
    }
    limpiar_buffer_entrada();

    return numero_entero;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    
    int pedir_numero = 0;
    bool terminar = false; 
    printf("Ingrese un numero entero que se encuentre entre %d y %d\n", min, max);
    
    do
    {
        pedir_numero = leer_entero(mensaje);
        terminar = esta_en_rango_entero(pedir_numero, min, max);
        if(terminar == false)
        {
            printf("El numero ingresado se escapa de los limites dados. Ingrese de nuevo el numero en un rango desde  %d hasta %d\n", min, max);
        }
    }while(terminar == false);

    return pedir_numero;
}

float leer_flotante(const char *mensaje)
{
    
    printf("%s\n", mensaje);
    float valor = 0.0;
    int estado_scanf = 0;
    bool bandera_salir = false;
    while(bandera_salir == false)
    {
	printf("Ingrese un numero de punto flotante\n");
	estado_scanf = scanf(" %f", &valor);
        if(estado_scanf == 0)
        { 
            printf("La lectura del numero flotante fallo, volver a intentarlo\n");
        }
	else
	{
	    bandera_salir = true;
	}
        limpiar_buffer_entrada();
    }
    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    
    float flotante_entrada = 0.0;
    bool terminar = false;
    while(terminar == false)
    {
        flotante_entrada = leer_flotante(mensaje);
        terminar = esta_en_rango_flotante(flotante_entrada, min, max);
    
        if(terminar == false)
	{
	    printf("Debe de ingresar un numero flotante entre %f y %f\n", min, max);
	}
    }
    return flotante_entrada;
}

char leer_caracter(const char *mensaje)
{
    
    printf("%s\n", mensaje);
    char caracter = '\0';
    limpiar_buffer_entrada();
    return caracter;
}

bool leer_logico(const char *mensaje)
{
    
    bool terminar = false;
    bool estado_respuesta = false;
    printf("[s/n]\n");
    char respuesta = '\0';
    while(terminar == false)
    {  
        respuesta = leer_caracter(mensaje);
        switch(respuesta)
        {
            case 's':
            case 'S':
            case '1':
                terminar = true;
                estado_respuesta = true;
                break;
	    case 'n': 
	    case 'N': 
	    case '0':
                terminar = true;
                estado_respuesta = false;
                break;
            default:
                printf("No a ingresado un caracter valido. Intentelo de nuevo\n");
                terminar = false; 
                break;
	}
    }
    return estado_respuesta;
}
