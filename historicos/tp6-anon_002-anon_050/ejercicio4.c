



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        fprintf(stderr, "Opciones: %s <mombre_archivo> <cantidad> <mínimo> <máximo>.\n", argv[0]);
        return 1;
    }

    const char *nombre_archivo = argv[1];
    int cantidad = atoi(argv[2]);
    int minimo = atoi(argv[3]);
    int maximo = atoi(argv[4]);
    int numero_aleatorio;

    if (minimo >= maximo)
    {
        fprintf(stderr, "El valor mínimo no puede ser mayor o igual al valor máximo.\n");
        return 1;
    }

    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL)
    {
        perror("Error al crear el archivo.\n");
        return 1;
    }

    srand(time(NULL));

    printf("Generando archivo %s.\n", nombre_archivo);
    printf("Con %d números entre %d y %d.\n", cantidad, minimo, maximo);

    for (int i = 0; i < cantidad; i++)
    {
        numero_aleatorio = rand() % (maximo - minimo + 1) + minimo;
        fprintf(archivo, "%d\n", numero_aleatorio);
    }

    fclose(archivo);
    printf("Archivo generado exitosamente: %s.\n", nombre_archivo);

    return 0;
}