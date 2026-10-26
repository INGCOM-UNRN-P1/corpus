

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO_ENTRADA 1
#define CANTIDAD_NUMS_A_GENERAR 2
#define VALOR_INICIAL 3
#define PASOS 4

/**
 *  La funcion genera un arreglo de enteros consecutivos.
 *  @param  vector_de_numeros[] es la direccion del vector 
 *  @pre vector_de_numeros[] es un puntero no nulo
 *  @param cant_numeros_a_generar es la cantidad total de numeros enteros que vamos a generar.
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param valor_inicial es el numero desde donde se iniciara el arreglo 
 *  @pre tiene que ser un entero
 *  @param pasos son los parametros que debe seguir nuestro arreglo 
 *  @returns 0 todo ok.
 *  @post La funcion genera un arreglo con determinados parametros
 */
int generador_lineal(int arreglo_enteros[], int cant_nums_a_generar, int valor_inicial, int pasos);


int main(int argc, char *argv[])
{
    int valor_inicial;
    int cant_nums_a_generar;
    int pasos;
    int *arreglo_enteros;
    char *arreglo_enteros_conv_en_char;
    int i;
    int cant_chars = 0;
    FILE *archivo;

    cant_nums_a_generar = atoi(argv[CANTIDAD_NUMS_A_GENERAR]);
    valor_inicial = atoi(argv[VALOR_INICIAL]);
    pasos = atoi(argv[PASOS]);

    archivo = fopen(argv[ARCHIVO_ENTRADA], "w+");

    if (archivo == NULL)
    {
        printf("Fallo al abrir el archivo\n");
    }
    else
    {
        arreglo_enteros = (int *)malloc(sizeof(int) * cant_nums_a_generar);

        if (arreglo_enteros == NULL)
        {
            abort();
        }

        for (i = getc(archivo); i != EOF; i = getc(archivo))   //contamos los chars para pedir la memoria justa para el arreglo 
        {
            cant_chars = cant_chars + 1;  
        }
        arreglo_enteros_conv_en_char = (char *)malloc(sizeof(char) * cant_chars);
        
        if (arreglo_enteros_conv_en_char == NULL)
        {
            abort();
        }

        printf("Generando %s\n", argv[ARCHIVO_ENTRADA]);
        printf("Con %d numeros desde %d aumentado de a %d \n", cant_nums_a_generar, valor_inicial, pasos);

        generador_lineal(arreglo_enteros, cant_nums_a_generar, valor_inicial, pasos);

        for (i = 0; i < cant_nums_a_generar; i++)
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

int generador_lineal(int arreglo_enteros[], int cant_nums_a_generar, int valor_inicial, int pasos)
{
    int i;

    for (i = 0; i < cant_nums_a_generar; i++)
    {
        if (i == 0)
        {
            arreglo_enteros[i] = valor_inicial;
        }

        else
        {
            valor_inicial = valor_inicial + pasos;
            arreglo_enteros[i] = arreglo_enteros[i] + valor_inicial;
        }
    }

    return 0;
}
