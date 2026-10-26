



#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    if (argc != 5)
    {
        fprintf(stderr, "Opciones: %s <nombre_archivo> <cantidad> <valor_inicial> <paso>.\n", argv[0]);
        return 1;
    }

    const char *nombre_archivo = argv[1];
    int cantidad = atoi(argv[2]); //podrían haberle puesto mejor nombre
    int valor_inicial = atoi(argv[3]);
    int paso = atoi(argv[4]);

    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL)
    {
        perror("Error al crear el archivo.\n");
        return 1;
    }

    printf("Genrando el archivo %s.\n", nombre_archivo);
    printf("Con %d números desde %d aumentando de a %d.\n", cantidad, valor_inicial, paso);

    for (int i = 0; i < cantidad; i++)
    {
        fprintf(archivo, "%d\n", valor_inicial + i * paso);
    }

    fclose(archivo);
    printf("Archivo generado exitosamente: %s.\n", nombre_archivo);

    return 0;
}