

#include <stdio.h>
#include <stdlib.h>

int esta_ordenado(int arreglo[], int capacidad);

void archivo_a_arreglo(char archivo[], int arreglo[], int capacidad);


int main(int argc, char *argv[])
{
    FILE *archivo;
    int capacidad;
    int res; 
    
    //SE OBTIENE LA CAPACIDAD (PRIMER NUMERO DEL ARCHIVO)
    archivo = fopen(argv[1], "r");   //argv[1] -> archivo_numeros.txt
    int x;
    fscanf(archivo, "%d", &x);
    fflush(stdin);

    capacidad = x;
    fclose(archivo);
    
    int arreglo[capacidad];
    
    //LEE DEL ARCHIVO Y GUARDA EN UN ARREGLO
    archivo_a_arreglo(argv[1], arreglo, capacidad);

    //LEE EL ARREGLO Y CHEQUEA SI ESTA ORDENADO
    res = esta_ordenado(arreglo, capacidad);
    printf("\nRes es: %d", res);
    
    if (res == 1)
    {
        printf("\nLos números en el archivo están ordenados de forma ascendente");
    }
    else if (res == -1)
    {
        printf("\nLos números en el archivo están ordenados de forma descendente");
    }
    else
    {
        printf("\nLos números en el archivo no están ordenados");
    }

    return 0;
}


int esta_ordenado(int arreglo[], int capacidad)
{
    int i = 0;
    int orden = 2;
    
    //PREGUNTA COMO EMPIEZA
    while (orden == 2)
    {
        if (arreglo[i] > arreglo[i+1])         
        {
            orden = -1;   //DESCENDENTE
        }
        else if (arreglo[i] < arreglo[i+1])
        {
            orden = 1;    //ASCENDENTE
        }
        else
        {
            orden = 2;     //IGUALES
            i++;
        }
    }
    
    i++;   //ITERA AL SIGUIENTE

    if (orden == -1)
    {
        for (i; i < capacidad-1; i++)                //RECORRE EL ARREGLO
        {
            if (arreglo[i] < arreglo[i+1])         //PREGUNTA SI SIGUE DESCENDENTE
            {
                return 0;                           //EMPEZO DESCENDENTE PERO NO SIGUE DESCENDENTE
            }
        }
    }
    else if (orden == 1)
    {
        for (i; i < capacidad-1; i++)                //RECORRE EL ARREGLO
        {
            if (arreglo[i] > arreglo[i+1])         //PREGUNTA SI SIGUE DESCENDENTE
            {
                return 0;                           //EMPEZO DESCENDENTE PERO NO SIGUE DESCENDENTE
            }
        }
    }

    return orden;
}

void archivo_a_arreglo(char archivo[], int arreglo[], int capacidad)
{
    FILE *arch = fopen(archivo, "r");

    int x;
    int i = 0;

    fscanf(arch, "%d", &x);
    fflush(stdin);

    while (!feof(arch) && i < capacidad)
    {
        fscanf(arch, "%d", &x);
        fflush(stdin);
        
        arreglo[i] = x;
        i++;
    }
    fclose(arch);
}