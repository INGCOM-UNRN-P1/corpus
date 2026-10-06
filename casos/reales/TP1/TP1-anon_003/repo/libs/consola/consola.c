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
    bool en_rango_entero = false;
        if (valor >= min && valor <= max){
            en_rango_entero = true;
            return en_rango_entero;
        } else{
    return en_rango_entero;
        }
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    bool en_rango_float = false;
        if(valor >= min && valor <= max){
            en_rango_float = true;
        } 
    return en_rango_float;
}

int leer_entero(const char *mensaje)
{
    
    int valor = 0;
    int valor_aceptado = 0;
    do
    {
        printf("%s", mensaje);
        valor_aceptado = scanf("%d", &valor);
        limpiar_buffer_entrada();
        if (valor_aceptado != 1) {
            printf("Error, debe ingesar un numero entero valido.");
        }
    } while (valor_aceptado != 1);
    
    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    

    int valor = 0;
    do
    {
        valor = leer_entero(mensaje);
        if (esta_en_rango_entero(valor, min, max)== false){
            printf("Error! El valor debe estar entre los valores enteros %d, y %d\n", min, max);  
        }
    } while (esta_en_rango_entero(valor, min, max) == false);


    return valor;
}

float leer_flotante(const char *mensaje)
{
    

    float valor = 0.0f;
    int valor_aceptado = 0;
    do
    {
        printf("%s", mensaje);
        valor_aceptado = scanf("%f", &valor);
        limpiar_buffer_entrada();
        if (valor_aceptado != 1) {
            printf("Error, debe ingesar un numero entero valido.");
        }
    } while (valor_aceptado != 1);
    
    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    
    float valor = 0.0f;
    do
    {
        valor = leer_flotante(mensaje);
        if (esta_en_rango_flotante(valor, min, max) == false){
            printf("Error! El valor debe estar entre los valores flotantes %f, y %f\n", min, max);  
        }
    } while (esta_en_rango_flotante (valor, min, max) == false);


    return valor;

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
    
    bool entrada_valida = false;
    char ingreso_user = ' ';
    bool respuesta_correcta = false;
     do
     {
        ingreso_user = leer_caracter(mensaje);
        if (ingreso_user == 's' || ingreso_user == 'S' || ingreso_user == '1'){
           
            printf("Entrada valida.\n");
            entrada_valida = true;
            respuesta_correcta = true;

        } else if (ingreso_user == 'n'|| ingreso_user == 'N' || ingreso_user == '0'){
            
            printf("Entrada valida.\n");
            entrada_valida = true;
            respuesta_correcta = false;
        } else {
            printf("Entrada incorrecta. Ingrese nuevamente.");
        }


    } while (entrada_valida == false);
     
    return respuesta_correcta;
}
