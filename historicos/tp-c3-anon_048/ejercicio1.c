

#include <stdio.h>
#define CANTIDAD_MAX_FRACCIONES 50

typedef struct fraccion
{
    int numerador;
    int denominador;
} fraccion_t;


int solicitar_numerador();

int solicitar_denominador();

void mostrar_fraccion(fraccion_t resultado, int opcion_elegida);

fraccion_t cargar_fraccion();

void cargar_fracciones(fraccion_t fracciones[], int cant_fracciones);

fraccion_t sumar_fraccion(fraccion_t fraccion1, fraccion_t fraccion2);

fraccion_t sumar_fracciones(fraccion_t fracciones[], int cant_fracciones);

fraccion_t multiplicar_fraccion(fraccion_t fraccion1, fraccion_t fraccion2);

fraccion_t multiplicar_fracciones(fraccion_t fracciones[], int cant_fracciones);

fraccion_t sumar_numero_entero(fraccion_t fracciones[], int cant_fracciones, int numero_entero);

void mostrar_menu();

int main()
{
    fraccion_t fracciones[CANTIDAD_MAX_FRACCIONES];
    fraccion_t resultado_suma;
    fraccion_t resultado_multiplicacion;
    fraccion_t resultado_sumar_entero;
    int cant_fracciones;
    int numero_entero;
    int opcion_elegida;

    printf("¿Cuantas fracciones va a ingresar? ");
    scanf("%d", &cant_fracciones);
    printf("\n");
    cargar_fracciones(fracciones, cant_fracciones);
    mostrar_menu();
    printf("Seleccione las operaciones: ");
    scanf("%d", &opcion_elegida);
    printf("\n");

    switch (opcion_elegida)
    {
    case 0:
        resultado_suma = sumar_fracciones(fracciones, cant_fracciones);
        mostrar_fraccion(resultado_suma, opcion_elegida);
        break;
    case 1:
        resultado_multiplicacion = multiplicar_fracciones(fracciones, cant_fracciones);
        mostrar_fraccion(resultado_multiplicacion, opcion_elegida);
        break;
    case 2:
        printf("Numero entero: ");
        scanf("%d", &numero_entero);
        resultado_sumar_entero = sumar_numero_entero(fracciones, cant_fracciones, numero_entero);
        mostrar_fraccion(resultado_sumar_entero, opcion_elegida);
        break;

    default:
        printf("Opcion no valida\n");
        break;
    }

    return 0;
}

int solicitar_numerador()
{
    int numerador;

    printf("Digite el numerador: ");
    scanf("%d", &numerador);

    return numerador;
}

int solicitar_denominador()
{
    int denominador;

    do
    {
        printf("Digite el denominador: ");
        scanf("%d", &denominador);
        if (denominador == 0)
        {
            printf("----El denominador no puede ser cero----\n");
        }
    } while (denominador == 0);

    printf("\n");

    return denominador;
}

void mostrar_fraccion(fraccion_t resultado, int opcion_elegida)
{
    printf("Resultado:\n");
    printf("  %d\n", resultado.numerador);
    printf("-----\n");
    printf("  %d\n", resultado.denominador);
}
fraccion_t cargar_fraccion()
{
    fraccion_t fraccion;
    fraccion.numerador = solicitar_numerador();
    fraccion.denominador = solicitar_denominador();

    return fraccion;
}

void cargar_fracciones(fraccion_t fracciones[], int cant_fracciones)
{
    int i;

    for (i = 0; i < cant_fracciones; i++)
    {
        printf("Fraccion [%d]\n", i + 1);
        fracciones[i] = cargar_fraccion();
    }
}

fraccion_t sumar_fraccion(fraccion_t fraccion1, fraccion_t fraccion2)
{
    fraccion_t resultado;

    resultado.numerador = ((fraccion1.numerador * fraccion2.denominador) + (fraccion2.numerador * fraccion1.denominador));
    resultado.denominador = fraccion1.denominador * fraccion2.denominador;

    return resultado;
}

fraccion_t sumar_fracciones(fraccion_t fracciones[], int cant_fracciones)
{
    fraccion_t resultado_suma;
    int i;

    resultado_suma.numerador = 0;
    resultado_suma.denominador = 1;

    for (i = 0; i < cant_fracciones; i++)
    {
        resultado_suma = sumar_fraccion(resultado_suma, fracciones[i]);
    }
    return resultado_suma;
}

fraccion_t multiplicar_fraccion(fraccion_t fraccion1, fraccion_t fraccion2)
{
    fraccion_t resultado;

    resultado.numerador = fraccion1.numerador * fraccion2.numerador;
    resultado.denominador = fraccion1.denominador * fraccion2.denominador;

    return resultado;
}

fraccion_t multiplicar_fracciones(fraccion_t fracciones[], int cant_fracciones)
{
    int i;
    fraccion_t resultado_multiplicacion;
    resultado_multiplicacion.numerador = 1;
    resultado_multiplicacion.denominador = 1;

    for (i = 0; i < cant_fracciones; i++)
    {
        resultado_multiplicacion = multiplicar_fraccion(resultado_multiplicacion, fracciones[i]);
    }

    return resultado_multiplicacion;
}

fraccion_t sumar_numero_entero(fraccion_t fracciones[], int cant_fracciones, int numero_entero)
{
    fraccion_t resultado;
    resultado = sumar_fracciones(fracciones, cant_fracciones);
    resultado.numerador = (resultado.denominador * numero_entero) + resultado.numerador;

    return resultado;
}

void mostrar_menu()
{
    printf("Opcion 0: Sumar fracciones\n");
    printf("Opcion 1: Multiplicar fracciones\n");
    printf("Opcion 2: Sumar un numero entero a fracciones\n");
    printf("\n");
}