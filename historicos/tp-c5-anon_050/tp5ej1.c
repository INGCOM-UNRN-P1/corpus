

#include <stdio.h>

int obtener_orden(int a, int b)
{
    if (a < b)
    {
        return 1;
    }
    else if (b < a)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int esta_ordenado (FILE* archivo)
{
    int i;
    int cantidad;
    int a;
    int b;
    int orden;
    int temp;

    fscanf(archivo, "%d", &cantidad);
    if (cantidad <= 1)
    {
        return 1;
    }
    fscanf(archivo, "%d", &a);
    fscanf(archivo, "%d", &b);

    orden = obtener_orden(a, b);

    for (i = 2; i < cantidad; i++)
    {
        a = b;
        fscanf(archivo, "%d", &b);

        temp = obtener_orden(a, b);
        if (orden == 0)
        {
            // no sabemos el orden aún
            orden = temp;
        }

        if (a != b && temp != orden)
        {
            return 0;
        }
    }

    if (orden == 0)
    {
        // nunca supimos el orden, todos los elementos son iguales
        // asumir ordenado de orden ascendente
        return 1;
    }

    return orden;
}

int main(int argc, char *argv[])
{
    int resultado;
    FILE* file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Archivo no disponible.\n");
        return 0;
    }
    resultado = esta_ordenado(file);
    switch (resultado)
    {
    case -1:
        printf("Si - descendente\n");
        break;
    case 0:
        printf("No\n");
        break;
    case 1:
        printf("Si - ascendente\n");
        break;
    default:
        break;
    }
    fclose(file);
    return 0;
}