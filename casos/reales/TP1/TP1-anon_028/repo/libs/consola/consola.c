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
    if (min > max){
        return false;
    }
    return (valor >= min && valor <= max);
}

bool esta_en_rango_flotante(float valor, float min, float max)
{
    if (min > max){
        return false;
    }
    return (valor >= min && valor <= max);
}

int leer_entero(const char *mensaje)
{
    int valor;
    int leido;

    do {
        printf("%s", mensaje);
        leido = scanf("%d", &valor);
        limpiar_buffer_entrada();

        if (leido !=1){
            printf("entrada no valida. ingrese un numero entero\n");
        }
    } while (leido !=1);

    return valor;
}

int leer_entero_entre(const char *mensaje, int min, int max)
{
    int valor;
    bool en_rango;

    do{
        valor = leer_entero(mensaje);
        en_rango = esta_en_rango_entero(valor, min, max);

        if (!en_rango){
            printf("error el valor tiene que estar entre %d y %d\n", min, max);
        }
        
    } while (!en_rango);
    return valor;
}

float leer_flotante(const char *mensaje)
{
    float valor;
    int leidos;

    do
    {
        printf("%s", mensaje);
        leidos = scanf("%f", &valor);
        limpiar_buffer_entrada();

        if (leidos !=1){
            printf("numero no valido. ingrese un numero decimal\n");
        }
    } while (leidos !=1);
    return valor;
}

float leer_flotante_entre(const char *mensaje, float min, float max)
{
    float valor;
    bool en_rango;
    do
    {
        valor = leer_flotante(mensaje);
        en_rango = esta_en_rango_flotante(valor, min, max);

        if (!en_rango){
            printf("el valor tiene que estar entre %.2f y %.2f\n", min, max);
        }
    } while (!en_rango);

    return valor;
}

char leer_caracter(const char *mensaje)
{
    char caracter;
    int leidos;
    do
    {
        printf("%s", mensaje);
        leidos = scanf(" %c", &caracter);
        limpiar_buffer_entrada();

        if (leidos !=1){
            printf("entrada no valida\n");
        }
    } while (leidos !=1);

    return caracter;
}

bool leer_logico(const char *mensaje)
{
    char respuesta;
    do
    {
        respuesta = leer_caracter(mensaje);

        if (respuesta == 's' || respuesta == 'S' || respuesta == '1'){
            return true;
        }else if (respuesta == 'n' || respuesta == 'N' || respuesta == '0'){
            return false;
        }
        printf("error ingrese una opcion valida\n");
        
    } while (true);
    
    return false;
}
