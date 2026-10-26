

#include <stdio.h>

typedef struct fraccion{
    int numerador;
    int denominador;
} fraccion_t;

void cargar_fraccion(fraccion_t *fracc);
void mostrar_fraccion(fraccion_t fracc);
fraccion_t suma_fracciones(fraccion_t frac1, fraccion_t frac2);
fraccion_t multipl_fracciones(fraccion_t frac1, fraccion_t frac2);
fraccion_t suma_entero(fraccion_t frac, int entero);


int main()
{
    fraccion_t fraccion;
    fraccion_t frac_asumar;
    fraccion_t frac_sumada;
    fraccion_t frac_amultipl;
    fraccion_t frac_multiplicada;
    int entero;
    
    printf("Ingrese una fraccion\n");
    cargar_fraccion(&fraccion);
    printf("\nLa fraccion es:\n");
    mostrar_fraccion(fraccion);
    
    printf("Ingrese una fraccion a sumar\n");
    cargar_fraccion(&frac_asumar);
    printf("\nLa fraccion a sumar es:\n\n");
    mostrar_fraccion(frac_asumar);

    frac_sumada = suma_fracciones(fraccion, frac_asumar);
    printf("La suma de ambas fracciones es:\n");
    mostrar_fraccion(frac_sumada);
    
    printf("\nIngrese una fraccion a multiplicar con el resultado:\n");
    cargar_fraccion(&frac_amultipl);
    printf("\nLa fraccion a multiplicar es:\n");
    mostrar_fraccion(frac_amultipl);

    frac_multiplicada = multipl_fracciones(frac_sumada, frac_amultipl);
    printf("El producto es:\n");
    mostrar_fraccion(frac_multiplicada);

    printf("\nIngrese un entero a sumar con el resultado -> ");
    scanf("%d", &entero);
    fflush(stdin);

    frac_sumada = suma_entero(frac_multiplicada, entero);
    printf("El resultado de sumarle %d es:\n", entero);
    mostrar_fraccion(frac_sumada);
    
    return 0;
}

void cargar_fraccion(fraccion_t *fracc)
{
    printf("Numerador de fraccion -> ");
    scanf("%d", &fracc->numerador);
    fflush(stdin);

    printf("Denominador de fraccion -> ");
    scanf("%d", &fracc->denominador);
    fflush(stdin);
}

void mostrar_fraccion(fraccion_t fracc)
{
    printf("\n %d", fracc.numerador);
    printf("\n---");
    printf("\n %d\n\n", fracc.denominador);
}

fraccion_t suma_fracciones(fraccion_t frac1, fraccion_t frac2)
{
    fraccion_t result;
    int contt;
    
    if (frac1.denominador == frac2.denominador)
    {
        result.denominador = frac1.denominador;
        result.numerador = frac1.numerador + frac2.numerador;
    }
    else
    {
                                                                        
        result.denominador = frac1.denominador * frac2.denominador;     
        frac1.numerador = frac1.numerador * frac2.denominador;          
        frac2.numerador = frac2.numerador * frac1.denominador;          
        
        result.numerador = frac1.numerador + frac2.numerador;
    }

    contt = result.denominador;
    
    while (contt >= 2)
    {
        if (result.denominador % contt == 0 && result.numerador % contt == 0)
        {
            result.denominador = result.denominador / contt;
            result.numerador = result.numerador / contt;
            contt = 1;
        }
        contt--;
    }
    
    return result;
}

fraccion_t multipl_fracciones(fraccion_t frac1, fraccion_t frac2)
{
    fraccion_t result;
    int contt;

    
    result.numerador = frac1.numerador * frac2.numerador;
    result.denominador = frac1.denominador * frac2.denominador;
    
    
    contt = result.denominador;
    
    while (contt >= 2)
    {
        if (result.denominador % contt == 0 && result.numerador % contt == 0)
        {
            result.denominador = result.denominador / contt;
            result.numerador = result.numerador / contt;
            contt = 1;
        }
        contt--;
    }
    
    return result;
}

fraccion_t suma_entero(fraccion_t frac, int entero)
{
    fraccion_t result;
    fraccion_t frac_de_entero;
    int contt;
    
    frac_de_entero.numerador = entero;
    frac_de_entero.denominador = 1;


    if (frac.denominador == frac_de_entero.denominador)
    {
        result.denominador = frac.denominador;
        result.numerador = frac.numerador + frac_de_entero.numerador;
    }
    else
    {
                                                                        
        result.denominador = frac.denominador * frac_de_entero.denominador;     
        frac.numerador = frac.numerador * frac_de_entero.denominador;          
        frac_de_entero.numerador = frac_de_entero.numerador * frac.denominador;          
        
        result.numerador = frac.numerador + frac_de_entero.numerador;
    }

    contt = result.denominador;
    
    while (contt >= 2)
    {
        if (result.denominador % contt == 0 && result.numerador % contt == 0)
        {
            result.denominador = result.denominador / contt;
            result.numerador = result.numerador / contt;
            contt = 1;
        }
        contt--;
    }
    
    return result;
}