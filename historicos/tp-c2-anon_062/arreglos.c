

#include <stdio.h>
#include <stdlib.h>

#define LONG_CADENA 1000

// Ejercicios 1

void cargar_arreglo(int cantidad, int arreglo[])

// Pre condicion: ingresa un arreglo vacío y una cantidad determinada de posiciones a completar
// post condicion: retorna el arreglo cangado

{
    int i = 0;
    int numero = 0;

    for (i = 0; i < cantidad; i++)
    {
        printf("Ingrese un numero cualquiera :  \n\t");
        scanf("%d", &numero);
        arreglo[i] = numero;
    }
}

// -----
void muestra_arreglo(int cantidad, int arreglo[])

//precondicion: ingresa un arreglo y la cantidad de posiciones
//post condicion: deveulve impreso cada valor en el arreglo
{

    int i = 0;
    
    for (i = 0; i < cantidad; i++)
    {
        printf("%d  ", arreglo[i]);
    }
}


// -------------------------------------------------
// Ejercicios 2

int promedio(int arreglo[], int cantidad)

//precondicion: recibe el arreglo y calcula el promedio
{
    int i = 1;
    int espromedio = 0;
    int acumulador = 0;

    for (i = 1; i < cantidad + 1; i++)
    {
        acumulador = acumulador + arreglo[i - 1];
    }
    
    espromedio = acumulador / (i - 1);
    return espromedio;
}


// --------------------------------------------------
int minimo(int arreglo[], int cantidad)

// precondición: recibe un arreglo con una cantidad definida de posiciones
// post condición: devuelve el valor mínimo que encuentra en el arreglo

{
    int esminimo = 0;
    int i = 0;

    esminimo = arreglo[0];
    for (i = 0; i < cantidad; i++)
    {
        if (arreglo[i] < esminimo)
            {
            esminimo = arreglo[i];
            }
    }

    return esminimo;
}



// -----------------------------------------------
int maximo(int arreglo[], int cantidad)

// precondición: recibe un arreglo con una cantidad definida de posiciones
// post condición: devuelve el valor maximo que encuentra en el arreglo

{
    int esmaximo = 0;
    int i = 0;

    esmaximo = arreglo[0];
    for (i = 0; i < cantidad; i++)
    {
        if (esmaximo < arreglo[i])
            {
            esmaximo = arreglo[i];
            }
    }

    return esmaximo;
}



// ---------------------------------------------
int menor_a_mayor(int arreglo[], int cantidad)

// precondición: recibe un arreglo con una cantidad definida de posiciones
// post condición: devuelve el arreglo ordenado de menor a mayor

{
    int i = 0;
    int j = 0;
    int aux = 0;

    for (i = 0; i < cantidad; i++)             //comparo cada elemento con
        {
        for (j = i; j < cantidad; j++)         //todo el vector
            {
            if (arreglo[j] <= arreglo[i])      //si existe un elemento mas chico
                {
                aux = arreglo[i];              //los intercambio de lugar
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
                }
            }
        j = i;                                 //vuelvo a la posicion hasta donde
                                               //sé que los valores están ordenados
                                               //para empezar la prox comparacion
        }
}



// ------------------------------------------------
void mayor_a_menor(int arreglo[], int cantidad)

// precondición: recibe un arreglo con una cantidad definida de posiciones
// post condición: devuelve el arreglo ordenado de mayor a menor

{
    int i = 0;
    int j = 0;
    int aux = 0;

    for (i = 0; i < cantidad; i++)             //comparo cada elemento con
        {
        for (j = i; j < cantidad; j++)         //todo el vector
            {
            if (arreglo[i] <= arreglo[j])      //si existe un elemnto grande
                {
                aux = arreglo[i];              //los intercambio de lugar
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
                }
            }
        j = i;                                 //vuelvo a la posicion hasta donde
                                               //sé que los valores están ordenados
                                               //para empezar la prox comparacion
        }
}



// -------------------------------------------------
// Ejercicio 3

int carga_como_argumentos(int arreglo[]);
// implementado en el MAIN


// -------------------- MAIN ---------------

void main(int argc, char *argv[])
{
    int i = 0;
    int cantidad = 0;
    int arreglo[LONG_CADENA];



    cantidad = argc - 1;            //argc detecta la cantidad de elementos del vector
    
    if (cantidad != 0);
        {
        for (i = 0; i < cantidad; i++)
            {
            arreglo[i] = atoi(argv[i +1]);
            }
    else
        {
        printf("Cantidad de elementos: \n\t");
        scanf("%d", &cantidad);
        cargar_arreglo(cantidad, arreglo);
        }
        }

        muestra_arreglo(cantidad, arreglo);

        printf("promedio: %d \n\t", promedio(arreglo, cantidad));

        printf("Ordenado de MAYOR a menor \n\t");
        mayor_a_menor(arreglo, cantidad);
        muestra_arreglo(cantidad, arreglo);
    
        printf("Ordenado de menor a MAYOR \n\t");
        menor_a_mayor(arreglo, cantidad);
        muestra_arreglo(cantidad, arreglo);

        printf("máximo: %d \n\t", maximo(arreglo, cantidad));
        printf("mínimo: %d \n\t", minimo(arreglo, cantidad));
}