

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define TAMANO_CADENA 100
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

int cargar_arreglo(int cantidad, int arreglo[])
// Precondiciones: El valor de entrada "cantidad" tiene que ser de tipo entero y el arreglo tambien debe ser
// de número enteros
// Postcondiciones: Devolverá 1 si el ingreso de valores fue correcto, de caso contrario devolvera 0
{
    int numeroIngresado;
    float numeroIngresadoFloat;
    printf("Complete el arreglo mediante el ingreso de %d números enteros\n", cantidad);
    for (int i = 0; i < cantidad; i++)
    {

        printf("(%d/%d) Ingrese un número entero: ", i + 1, cantidad);
        fflush(stdout);
        scanf("%f", &numeroIngresadoFloat);
        numeroIngresado = numeroIngresadoFloat;
        if (numeroIngresadoFloat - numeroIngresado)
        {
            printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero" ANSI_COLOR_RESET "\n");
            return FALSE;
        }
        else
        {
            arreglo[i] = numeroIngresado;
        }
    }
    return TRUE;
}

void muestra_arreglo(int cantidad, int arreglo[])
// Precondiciones: El valor de entrada "cantidad" tiene que ser de tipo entero y el arreglo tambien debe ser
// de número enteros
// Postcondiciones: No devuelve ningín valor, imprime por consola el contenido del arreglo
{
    printf("Arreglo ingresado: \n");
    for (int j = 0; j < cantidad; j++)
    {
        printf("    Arreglo[%d] = %d\n", j, arreglo[j]);
    }
}

float promedio_arreglo(int cantidad, int arreglo[])
// Precondiciones: El valor de entrada "cantidad" tiene que ser de tipo entero y el arreglo tambien debe ser
// de número enteros
// Postcondiciones: Devolverá el promedio de los elementos del arreglo con una precisión de 2 decimales
{
    float suma = 0;
    float promedio;
    for (int i = 0; i < cantidad; i++)
    {
        suma = suma + arreglo[i];
    }
    promedio = suma / cantidad;
    return promedio;
}

int minimo_arreglo(int cantidad, int arreglo[])
// Precondiciones: El valor de entrada "cantidad" tiene que ser de tipo entero y el arreglo tambien debe ser
// de número enteros
// Postcondiciones: Devolverá el menor elemento del array
{
    int menor = arreglo[0];
    for (int i = 0; i < cantidad; i++)
    {
        if (arreglo[i] < menor)
        {
            menor = arreglo[i];
        }
    }
    return menor;
}

int maximo_arreglo(int cantidad, int arreglo[])
// Precondiciones: El valor de entrada "cantidad" tiene que ser de tipo entero y el arreglo tambien debe ser
// de número enteros
// Postcondiciones: Devolverá el mayor elemento del array
{
    int mayor = arreglo[0];
    for (int i = 0; i < cantidad; i++)
    {
        if (arreglo[i] > mayor)
        {
            mayor = arreglo[i];
        }
    }
    return mayor;
}

void ordenar_arreglo_ascendente(int cantidad, int arreglo[])
// Precondiciones: El valor de entrada "cantidad" tiene que ser de tipo entero y el arreglo tambien debe ser
// de número enteros
// Postcondiciones: No devuelve ningín valor, imprime por consola el contenido del arreglo ordenado de mayor a menor
{
    int arrayOrdenadoAscendente[TAMANO_CADENA];
    int contadorMenores = 0;
    int contadorRepetidos = 0;
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < cantidad; j++)
        {
            if (arreglo[i] > arreglo[j])
            {
                contadorMenores = contadorMenores + 1;
            }
            if (arreglo[i] == arrayOrdenadoAscendente[j])
            {
                contadorRepetidos = contadorRepetidos + 1;
            }
        }
        if (arreglo[i] == arrayOrdenadoAscendente[contadorMenores])
        {
            arrayOrdenadoAscendente[contadorMenores + contadorRepetidos] = arreglo[i];
        }
        else
        {
            arrayOrdenadoAscendente[contadorMenores] = arreglo[i];
        }
        contadorMenores = 0;
        contadorRepetidos = 0;
    }
    for (int j = 0; j < cantidad; j++)
    {
        printf("    ArregloAscendente[%d] = %d\n", j, arrayOrdenadoAscendente[j]);
    }
}

void ordenar_arreglo_descendente(int cantidad, int arreglo[])
// Precondiciones: El valor de entrada "cantidad" tiene que ser de tipo entero y el arreglo tambien debe ser
// de número enteros
// Postcondiciones: No devuelve ningín valor, imprime por consola el contenido del arreglo ordenado de mayor a menor
{
    int arrayOrdenadoDescendente[TAMANO_CADENA];
    int contadorMayores = 0;
    int contadorRepetidos = 0;
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < cantidad; j++)
        {
            if (arreglo[i] < arreglo[j])
            {
                contadorMayores = contadorMayores + 1;
            }
            if (arreglo[i] == arrayOrdenadoDescendente[j])
            {
                contadorRepetidos = contadorRepetidos + 1;
            }
        }
        if (arreglo[i] == arrayOrdenadoDescendente[contadorMayores])
        {
            arrayOrdenadoDescendente[contadorMayores + contadorRepetidos] = arreglo[i];
        }
        else
        {
            arrayOrdenadoDescendente[contadorMayores] = arreglo[i];
        }
        contadorMayores = 0;
        contadorRepetidos = 0;
    }
    for (int j = 0; j < cantidad; j++)
    {
        printf("    ArregloDescendente[%d] = %d\n", j, arrayOrdenadoDescendente[j]);
    }
}

int main(int argc, char *argv[])
{
    int cantidad;
    float cantidadFloat;
    int arreglo[TAMANO_CADENA];
    int cargaArregloExitosa = FALSE;
    float promedioArreglo;
    int minimoArreglo;
    int maximoArreglo;
    if (argc > 1)
    {
        printf(ANSI_COLOR_CYAN "\nEjercicio 3: Carga como argumentos\n");
        printf("Carga del arreglo realizada por consola" ANSI_COLOR_RESET "\n");
        cantidad = argc - 1;
        printf("%d - cantidad\n", cantidad);
        for (int i = 1; i < argc; i++)
        {
            arreglo[i - 1] = atoi(argv[i]);
        }
    }
    else
    {
        printf(ANSI_COLOR_CYAN "\nEjercicio 1: Cargador de arreglos" ANSI_COLOR_RESET "\n\n");
        printf(ANSI_COLOR_YELLOW "Función cargar arreglo" ANSI_COLOR_RESET "\n");
        printf("Ingrese la cantidad de elementos del arreglo: ");
        fflush(stdout);
        scanf("%f", &cantidadFloat);
        cantidad = cantidadFloat;
        if (cantidadFloat - cantidad && cantidad <= 0)
        {
            printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero mayor a 0" ANSI_COLOR_RESET "\n");
        }
        else if (cantidadFloat - cantidad)
        {
            printf(ANSI_COLOR_RED "Error! Debes ingresar un número entero" ANSI_COLOR_RESET "\n");
        }
        else if (cantidad <= 0)
        {
            printf(ANSI_COLOR_RED "Error! Debes ingresar un número mayor a 0" ANSI_COLOR_RESET "\n");
        }
        else
        {
            cargaArregloExitosa = cargar_arreglo(cantidad, arreglo);
        }
    }
    if (cargaArregloExitosa == TRUE || argc > 1)
    {
        printf(ANSI_COLOR_YELLOW "\nFunción mostrar arreglo" ANSI_COLOR_RESET " \n");
        muestra_arreglo(cantidad, arreglo);
        printf(ANSI_COLOR_CYAN "\nEjercicio 2: Operaciones con arreglos" ANSI_COLOR_RESET "\n\n");
        printf(ANSI_COLOR_YELLOW "Función promedio arreglo" ANSI_COLOR_RESET "\n");
        promedioArreglo = promedio_arreglo(cantidad, arreglo);
        printf("El promedio de los elementos del arreglo es: %.2f", promedioArreglo);
        printf(ANSI_COLOR_YELLOW "\n\nFunción minimo arreglo" ANSI_COLOR_RESET "\n");
        minimoArreglo = minimo_arreglo(cantidad, arreglo);
        printf("El menor elemento del arreglo es: %d", minimoArreglo);
        printf(ANSI_COLOR_YELLOW "\n\nFunción maximo arreglo" ANSI_COLOR_RESET "\n");
        maximoArreglo = maximo_arreglo(cantidad, arreglo);
        printf("El mayor elemento del arreglo es: %d", maximoArreglo);
        printf(ANSI_COLOR_YELLOW "\n\nFunción ordenar arreglo ascendente" ANSI_COLOR_RESET "\n");
        ordenar_arreglo_ascendente(cantidad, arreglo);
        printf(ANSI_COLOR_YELLOW "\nFunción ordenar arreglo descendente" ANSI_COLOR_RESET "\n");
        ordenar_arreglo_descendente(cantidad, arreglo);
    }
    else
    {
        printf(ANSI_COLOR_RED "Error! La carga del arreglo falló" ANSI_COLOR_RESET "\n");
    }
    return 0;
}