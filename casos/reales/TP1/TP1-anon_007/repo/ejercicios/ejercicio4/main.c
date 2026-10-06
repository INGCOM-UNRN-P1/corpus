#include <stdbool.h>
#include <stdio.h>

#include "consola.h"
#include "triangulo.h"

static void mostrar_clasificacion(int tipo)
{
    switch (tipo)
    {
        case TIPO_EQUILATERO:
            printf("Tipo: Equilátero.\n");
            break;
        case TIPO_ISOSCELES:
            printf("Tipo: Isósceles.\n");
            break;
        case TIPO_ESCALENO:
            printf("Tipo: Escaleno.\n");
            break;
        default:
            printf("Tipo: No clasificable.\n");
            break;
    }
}

static void procesar_triangulo(float a, float b, float c)
{
    if (es_triangulo_valido(a, b, c))
    {
        int tipo = clasificar_triangulo(a, b, c);
        bool rectangulo = es_triangulo_rectangulo(a, b, c);

        printf("Los lados forman un triángulo válido.\n");
        mostrar_clasificacion(tipo);
        if (rectangulo)
        {
            printf("Es un triángulo rectángulo.\n");
        }
        else
        {
            printf("NO es un triángulo rectángulo.\n");
        }
    }
    else
    {
        printf("Los lados ingresados NO forman un triángulo válido.\n");
    }
}

int main(void)
{
    bool continuar = false;
    do
    {
        float lado_a = leer_flotante("Ingrese longitud del lado A: ");
        float lado_b = leer_flotante("Ingrese longitud del lado B: ");
        float lado_c = leer_flotante("Ingrese longitud del lado C: ");
        
        procesar_triangulo(lado_a, lado_b, lado_c);

        continuar = leer_logico("¿Desea evaluar otro triángulo? (s/n): ");
    } while (continuar);

    return 0;
}
