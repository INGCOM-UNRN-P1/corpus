

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LARGO 20
#define DIGITOS 6
#define ERROR_EN_CONVERSION_A_NUMERO 0
#define CONVERSION_CORRECTA_A_NUMERO 1

int cargar_arreglo(int cantidad, int arreglo[]);
void muestra_arreglo(int cantidad, int arreglo[]);
float promedio(int cantidad, int arreglo[]);
int minimo(int cantidad, int arreglo[]);
int maximo(int cantidad, int arreglo[]);
void ordenar_de_menor_a_mayor(int cantidad, int arreglo[]);
void ordenar_de_mayor_a_menor(int cantidad, int arreglo[]);
void recibir_argv(int cantidad, int arreglo[], char *argv[]);

int main(int argc, char *argv[])
{
    int arreglo[LARGO];
    int cantidad;
    char cantidad_en_caracter[DIGITOS];
    int resultado_minimo;
    int resultado_maximo;
    float resultado_promedio;

    cantidad = argc - 1;                 //no contamos el argumento de la direccion
    if(cantidad > 0)                     // si le pasamos ademas de la direccion, mas argumentos para llenar un vector
    {
        recibir_argv(cantidad, arreglo, argv);
    }

    else
    {
        printf("Cuantos elementos tendra su vector? ");
    
        do
        {
            fgets(cantidad_en_caracter, DIGITOS, stdin);
            cantidad = atoi(cantidad_en_caracter); 
            if(cantidad <= 0)
            {
                printf("El tamaño del vector no puede contener caracteres y debe ser mayor a cero\n");
            }
        } while (cantidad <= 0);
        cargar_arreglo(cantidad, arreglo);
    }
    
    muestra_arreglo(cantidad, arreglo);
    resultado_promedio = promedio(cantidad, arreglo);
    printf("El promedio de los elementos del vector es de: %.2f\n", resultado_promedio);
    resultado_minimo = minimo(cantidad, arreglo);
    printf("El minimo de los elementos del vector es: %d\n", resultado_minimo);
    resultado_maximo = maximo(cantidad, arreglo);
    printf("El maximo de los elementos del vector es: %d\n", resultado_maximo);
    ordenar_de_menor_a_mayor(cantidad, arreglo);
    printf("Ordenado de menor a mayor\n");
    muestra_arreglo(cantidad, arreglo);
    ordenar_de_mayor_a_menor(cantidad, arreglo);
    printf("Ordenado de mayor a menor\n");
    muestra_arreglo(cantidad, arreglo);

    return 0;
}



int cargar_arreglo(int cantidad, int arreglo[])
{
    int i, conversion_a_int;
    char arreglo_char[DIGITOS];

    for (i = 0; i < cantidad; i++)
    {
        printf("Cargar en la posicion [%d]: ", i);
        fgets(arreglo_char, DIGITOS, stdin);
        conversion_a_int = atoi(arreglo_char);
        arreglo[i] = conversion_a_int;
        if (atoi(arreglo_char) == ERROR_EN_CONVERSION_A_NUMERO)
        {
            return ERROR_EN_CONVERSION_A_NUMERO;
        }
    }
    return CONVERSION_CORRECTA_A_NUMERO;  
}






void muestra_arreglo(int cantidad, int arreglo[])
{
    int i;
    printf("Vector: \n");
    for (i = 0; i < cantidad; i++)
    {
        printf("Posicion:[%d] = %d\n", i, arreglo[i]);
    }
}



float promedio(int cantidad, int arreglo[])
{
    int i, suma;
    float promedio;
    suma = 0;

    for (i = 0; i < cantidad; i++)
    {
        suma = suma + arreglo[i];
    }     
    promedio = suma / cantidad;

    return promedio;
}



int minimo(int cantidad, int arreglo[])
{
    int i, minimo;
    minimo = INT_MAX;

    for (i = 0; i < cantidad; i++)
    {
        if (arreglo[i] < minimo)
        {
            minimo = arreglo[i];
        }
    }     
    return minimo;
}



int maximo(int cantidad, int arreglo[])
{
    int i, maximo;
    maximo = INT_MIN;

    for (i = 0; i < cantidad; i++)
    {
        if (arreglo[i] > maximo)
        {
            maximo = arreglo[i];
        }
    }     
    return maximo;
}



void ordenar_de_menor_a_mayor(int cantidad, int arreglo[])
{
    int i, j, auxiliar;

    for (i = 0; i < cantidad -1; i++)
    { 
        for ( j = 0; j < cantidad -1; j++)
        {
            if(arreglo[j] > arreglo[j + 1])
            {
            auxiliar = arreglo[j+1];
            arreglo[j + 1] = arreglo[j];
            arreglo[j] = auxiliar; 
            }
        }   
    } 
}



void ordenar_de_mayor_a_menor(int cantidad, int arreglo[])
{
    int i, j, auxiliar;
   
    for (i = 0; i < cantidad -1; i++)
    { 
        for ( j = 0; j < cantidad -1; j++)
        {
            if(arreglo[j] < arreglo[j + 1])
            {
            auxiliar = arreglo[j+1];
            arreglo[j + 1] = arreglo[j];
            arreglo[j] = auxiliar; 
            }
        }   
    } 
}



void recibir_argv(int cantidad, int arreglo[], char *argv[])
{
    int i, conversion_a_int;

    for ( i = 1; i <= cantidad; i++)
    {        
        conversion_a_int = atoi(argv[i]);
        arreglo[i - 1] = conversion_a_int;               
    }        
}