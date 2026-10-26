

#include <stdio.h>
#include <stdlib.h>

int esta_ordenado(int arreglo[], int capacidad);

void archivo_a_arreglo(char archivo[], int arreglo[], int capacidad);

void ordena(char archivo_entrada[], int orden, char archivo_salida[], int capacidad);


int main(int argc, char *argv[])
{
    FILE *archivo_in;
    int capacidad;
    int res;
    int orden;

    
    
    //SE OBTIENE LA CAPACIDAD (PRIMER NUMERO DEL ARCHIVO)
    archivo_in = fopen(argv[1], "r");
    int x;
    fscanf(archivo_in, "%d", &x);
    fflush(stdin);

    capacidad = x;
    fclose(archivo_in);
    
    //USUARIO ELIGE COMO ORDENAR
    orden = atoi(argv[2]);                 //1 = ASCENDENTE  //2 = DESCENDENTE

    //ORDENA
    ordena(argv[1], orden, argv[3], capacidad);
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
    arreglo[i] = x;
    i++;

    while (!feof(arch) && i <= capacidad)
    {
        fscanf(arch, "%d", &x);
        fflush(stdin);
        
        arreglo[i] = x;
        i++;
    }
    fclose(arch);
}

void ordena(char archivo_entrada[], int orden, char archivo_salida[], int capacidad)
{
    int arreglo[capacidad];
    int i = 0;
    int ordenado;
    int auxiliar;
    
    // los numeros en archivo se transfieren a arreglo
    archivo_a_arreglo(archivo_entrada, arreglo, capacidad);
    
    
    // se abre el archivo de salida y se escribe la cantidad de números del archivo (primer línea)
    FILE *archivo_s = fopen(archivo_salida, "w");
    fprintf(archivo_s, "%d\n", arreglo[i]);
    i++;

    // se ordena arreglo (segun orden)

    //ASCENDENTE
    if (orden == 1)
    { 
        ordenado = 1;

        while (ordenado == 1)
        {
            ordenado = 0;
            while (i <= capacidad+1)
            {
                if (arreglo[i] > arreglo[i+1])
                {
                    auxiliar = arreglo[i];
                    arreglo[i] = arreglo[i+1];
                    arreglo[i+1] = auxiliar;
                    ordenado = 1;
                }
                i++;
            }
            i = 1;
        }
    }

    //DESCENDENTE
    else
    {
        ordenado = 1;

        while (ordenado)
        {
            ordenado = 0;
            while (i <= capacidad+1)
            {
                if (arreglo[i] < arreglo[i+1])
                {
                    auxiliar = arreglo[i];
                    arreglo[i] = arreglo[i+1];
                    arreglo[i+1] = auxiliar;
                    ordenado = 1;
                }
                i++;
            }
            i = 1;
        }
    }  

    // arreglo se guarda en archivo
    for (i = 1; i <= capacidad+1; i++)
    {
        fprintf(archivo_s, "%d\n", arreglo[i]);
    }
    
    // se cierra archivo de salida
    fclose(archivo_s);
}