

#include <stdio.h>

/**
 * La función solicita al usuario cargar valores en un arreglo de largo especificado previamente.
 *  @param arreglo la cadena a llenar con números enteros.
 *  @pre int válido con signo.
 *  @param capacidad la capacidad del arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @returns 0.
 *  @post 0.
 */
int cargar_arreglo(int capacidad, int arreglo[])
{
    for (int i = 0; i < capacidad; i++)
    {
        printf("Ingrese el elemento número %d: ", i+1);
        scanf("%d", &arreglo[i]);
    }
    return 0;
}

/**
 * La función muestra en pantalla un arreglo de largo especificado previamente.
 *  @param arreglo la cadena a mostrar en pantalla.
 *  @pre int válido con signo.
 *  @param capacidad la capacidad del arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @returns 0.
 *  @post 0.
 */
int muestra_arreglo(int capacidad, int arreglo[])
{
    printf("El arreglo es:\n");
    for (int i = 0; i < capacidad; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n");
    return 0;
}

/**
 * La función muestra en pantalla un arreglo de largo especificado previamente.
 *  @param arreglo1 la primer cadena a fusionar.
 *  @pre int válido con signo.
 *  @param capacidad1 la capacidad del primer arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param arreglo2 la segunda cadena a fusionar.
 *  @pre int válido con signo.
 *  @param capacidad2 la capacidad del segundo arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param arreglo_final la cadena fusionada.
 *  @pre int válido con signo.
 *  @returns 0.
 *  @post 0.
 */
int fusionar_arreglos(int capacidad1, int capacidad2, int capacidad_final, int arreglo1[], int arreglo2[], int arreglo_final[])
{
    int i;
    for (i = 0; i < capacidad1; i++)
    {
        arreglo_final[i] = arreglo1[i];
    }
    for (i = 0; i < capacidad2; i++)
    {
        arreglo_final[capacidad1 + i] = arreglo2[i];
    }
    return 0;
}

/**
 * La función saca el promedio de un arreglo dado.
 *  @param arreglo la cadena a promediar.
 *  @pre int válido con signo.
 *  @param capacidad la capacidad del arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @returns promedio de los valores del arreglo.
 *  @post flotante, promedio de los valores del arreglo.
 */
float promedio_arreglo(int capacidad, int arreglo[])
{
    float sumatoria = 0;
    for (int i = 0; i < capacidad; i++)
    {
        sumatoria = sumatoria + arreglo[i];
    }
    return sumatoria / capacidad;
}

/**
 * La función encuentra el valor mínimo en un arreglo dado.
 *  @param arreglo la cadena a revisar.
 *  @pre int válido con signo.
 *  @param capacidad la capacidad del arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param minimo almacena el valor mínimo del arreglo.
 *  @pre int válido.
 *  @returns minimo, el valor menor en el arreglo.
 *  @post int, el valor menor en el arreglo.
 */
int minimo_arreglo(int capacidad, int arreglo[])
{
    int minimo = arreglo[0];
    for (int i = 0; i < capacidad; i++)
    {
        if (arreglo[i] < minimo)
        {
            minimo = arreglo[i];
        }
    }
    return minimo;
}

/**
 * La función encuentra la posición del valor máximo en un arreglo dado.
 *  @param arreglo la cadena a revisar.
 *  @pre int válido con signo.
 *  @param capacidad la capacidad del arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param maximo almacena el valor máximo del arreglo.
 *  @pre int válido.
 *  @returns posicion, la posición que contiene el mayor valor en el arreglo.
 *  @post int sin signo, la posición en el arreglo.
 */
int posicion_mayor(int capacidad, int arreglo[])
{
    int maximo = arreglo[0];
    int posicion = 0;
    for (int i = 1; i < capacidad; i++)
    {
        if (arreglo[i] > maximo)
        {
            maximo = arreglo[i];
            posicion = i;
        }
    }
    return posicion + 1;
}

/**
 * La función encuentra la posición del valor máximo en un arreglo dado.
 *  @param arreglo la cadena a revisar.
 *  @pre int válido con signo.
 *  @param capacidad la capacidad del arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param temp temporal para intercambio de valores entre arreglos.
 *  @pre int válido
 *  @returns 0.
 *  @post 0.
 */
int ordernar_arreglo(int capacidad, int arreglo[])
{
    int temp;
    int i;
    int j;
    for (i = 0; i < capacidad - 1; ++i)
    {
        for (j = i + 1; j < capacidad; ++j)
        {
            if (arreglo[i] > arreglo[j])
            {
                temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
    return 0;
}

int main()
{
    int opcion;
    int subopcion;
    int capacidad;
    int capacidad2;
    int capacidad_final;
    int arreglo[64];
    int arreglo2[64];
    int arreglo_final[128];

    printf("Lista de opciones:\n\n1.Cargar arreglo.\n2.Imprimir arreglo.\n");
    printf("3.Fusionar arreglos.\n4.Operar arreglos.\n0.Salir.\n");

    printf("Carga obligatoria de arreglo.\n");
    printf("Por favor ingrese el largo de la cadena a cargar: ");
    scanf("%d", &capacidad);
    cargar_arreglo(capacidad, arreglo);

    do
    {
        printf("Seleccione la operación a realizar: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:
            break;
        case 1:
            printf("1.Cargar arreglo.\n");
            printf("Por favor ingrese el largo de la cadena a cargar: ");
            scanf("%d", &capacidad);
            if (capacidad > 64)
            {
                printf("Capacidad máxima superada.");
                return 1;
            }
            cargar_arreglo(capacidad, arreglo);
            
            printf("Por favor elija otra opción a realizar: ");
            scanf("%d", &opcion);
            break;
        case 2:
            printf("2.Imprimir arreglo.\n");
            muestra_arreglo(capacidad, arreglo);
            
            printf("Por favor elija otra opción a realizar: ");
            scanf("%d", &opcion);
            break;
        case 3:
            printf("3.Fusionar arreglo\n");
            printf("Por favor ingrese el largo de la segunda cadena a cargar: ");
            scanf("%d", &capacidad2);
            capacidad_final = capacidad + capacidad2;
            cargar_arreglo(capacidad2, arreglo2);

            fusionar_arreglos(capacidad, capacidad2, capacidad_final, arreglo, arreglo2, arreglo_final);
            muestra_arreglo(capacidad_final, arreglo_final);

            printf("Por favor elija otra opción a realizar: ");
            scanf("%d", &opcion);
            break;
        case 4:
            printf("4. Operar arreglo.\n");
            printf("El promedio del arreglo es: %.2f.\n", promedio_arreglo(capacidad, arreglo));
            printf("El valor mínimo dentro del arreglo es: %d.\n", minimo_arreglo(capacidad, arreglo));
            printf("La posición donde se encuentra el valor máximo dentro del arreglo es: %d.\n", posicion_mayor(capacidad, arreglo));
            ordernar_arreglo(capacidad, arreglo);
            muestra_arreglo(capacidad, arreglo);

            printf("Por favor elija otra opción a realizar: ");
            scanf("%d", &opcion);
            break;            
        }
    } while (opcion > 0);

    return 0;
}