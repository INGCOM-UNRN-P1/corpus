
#include <stdio.h>

const char* nombre_dia(int numero)
{
    switch (numero)
    {
    case 1:
        return "lunes";
    case 2:
        return "martes";
    case 3:
        return "miercoles";
    case 4:
        return "jueves";
    case 5:
        return "viernes";
    case 6:
        return "sabado";
    case 7:
        return "domingo";
    default:
        return NULL;
    }
}

int main()
{
    printf("Ingrese día de la semana: ");
    int numero = 0;
    if (scanf("%d", &numero) != 1)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    const char* const nombre = nombre_dia(numero);
    if (nombre)
        puts(nombre);
    else
        puts("Nombre fuera de rango.");
    return 0;
}
