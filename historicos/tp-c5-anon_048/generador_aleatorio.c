

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARCHIVO_ENTRADA 1
#define CANT_NUMS_ALEATORIOS_SOLICITADOS 2
#define MINIMO_SOLICITADO 3
#define MAXIMO_SOLICITADO 4

/**
 *  La funcion genera un numero entero al azar.
 *  @param  minimo es el minimo del rango de nuestro numero aleatorio 
 *  @pre es un entero
 *  @param maximo es el maximo del rango de nuestro numero aleatorio
 *  @pre es un entero
 *  @returns int 
 *  @post la funciona genera un numero aleatorio dentro de un rango especificado
 */
int generador_aleatorio(int minimo, int maximo);


int main(int argc, char *argv[])
{
    int numero_aleatorio_generado;
    int *arreglo_enteros;
    char *arreglo_enteros_conv_en_char;
    int i;
    int cant_numeros_aleatorios;
    int minimo;
    int maximo;
    int cant_chars = 0;
    FILE *archivo;

    srand(time(NULL));
    
    cant_numeros_aleatorios = atoi(argv[CANT_NUMS_ALEATORIOS_SOLICITADOS]);
    minimo = atoi(argv[MINIMO_SOLICITADO]);
    maximo = atoi(argv[MAXIMO_SOLICITADO]);

    arreglo_enteros = (int *)malloc(sizeof(int) * cant_numeros_aleatorios);
    
    if (arreglo_enteros == NULL)
    {
        abort();
    }

    for (i = 0; i < cant_numeros_aleatorios; i++)
    {
        numero_aleatorio_generado = generador_aleatorio(minimo, maximo);
        arreglo_enteros[i] = numero_aleatorio_generado;
    }

    archivo = fopen(argv[ARCHIVO_ENTRADA], "w+");

    if (archivo == NULL)
    {
        printf("Error en la apertuda del archivo\n");
    }

    else
    {
        printf("Generando %s\n", argv[ARCHIVO_ENTRADA]);
        printf("Con %d numeros entre %d y %d \n", cant_numeros_aleatorios, minimo, maximo);


        for (i = getc(archivo); i != EOF; i = getc(archivo))   //contamos los chars para pedir la memoria justa para el arreglo 
        {
            cant_chars = cant_chars + 1;  
        }
        
        arreglo_enteros_conv_en_char = (char *)malloc(sizeof(char) * cant_chars);

        if (arreglo_enteros_conv_en_char == NULL)
        {
            abort();
        }
        
        for (i = 0; i < cant_numeros_aleatorios; i++)
        {
            sprintf(arreglo_enteros_conv_en_char, "%d", arreglo_enteros[i]);
            fputs(arreglo_enteros_conv_en_char, archivo);
            fputc('\n', archivo);
        }
    }

    fclose(archivo);

    free(arreglo_enteros);
    free(arreglo_enteros_conv_en_char);

    return 0;
}


int generador_aleatorio(int minimo, int maximo)
{
    int azar = 0;
    azar = minimo + rand() % (maximo - minimo + 1);

    return azar;
}