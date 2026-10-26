
#include <stdio.h>

typedef struct fraccion
{
    int numerador;
    int denominador;
}fraccion_t;

fraccion_t sumafraccion(fraccion_t f1, fraccion_t f2)
{
    
    fraccion_t resultadosuma;
    if (f1.denominador != f2.denominador)
    {
        resultadosuma.denominador = f1.denominador * f2.denominador;
        resultadosuma.numerador = (f1.numerador * f2.denominador) + (f1.denominador * f2.numerador);
    }
    else if(f1.denominador == f2.denominador)
    {
        resultadosuma.numerador = f1.numerador + f2.numerador;
        resultadosuma.denominador = f1.denominador;
    }
    if (resultadosuma.numerador % resultadosuma.denominador == 0)
    {
        resultadosuma.numerador = resultadosuma.numerador / resultadosuma.denominador;
        resultadosuma.denominador = 1;
    }
    return resultadosuma;
    
}
fraccion_t multiplicarfraccion(fraccion_t f1, fraccion_t f2)
{
    
    fraccion_t resultadomulti;
    resultadomulti.numerador = f1.numerador * f2.numerador;
    resultadomulti.denominador = f1.denominador * f2.denominador;
    if (resultadomulti.numerador % resultadomulti.denominador == 0)
    {
        resultadomulti.numerador = resultadomulti.numerador / resultadomulti.denominador;
        resultadomulti.denominador = 1;
    }
    return resultadomulti;
}
fraccion_t sumarentero(fraccion_t f1, int entero)
{
    
    fraccion_t sumaentero;
    fraccion_t numentero;
    numentero.numerador = entero;
    numentero.denominador = 1;
    
    if (f1.denominador != numentero.denominador)
    {
        sumaentero.denominador = f1.denominador * numentero.denominador;
        sumaentero.numerador = (f1.numerador * numentero.denominador) + (f1.denominador * numentero.numerador);
    }
    else if(f1.denominador == numentero.denominador)
    {
        sumaentero.numerador = f1.numerador + numentero.numerador;
        sumaentero.denominador = f1.denominador;
    }
    if (sumaentero.numerador % sumaentero.denominador == 0)
    {
        sumaentero.numerador = sumaentero.numerador / sumaentero.denominador;
        sumaentero.denominador = 1;
    }
    return sumaentero;
}

int main()
{   
    fraccion_t f1;
    fraccion_t f2;
    fraccion_t sumaenter;
    f1.denominador = 0;
    f2.denominador = 0;
    int entero = 0;
    int eleccion = 0;
    
    printf("Ingrese un numerador: \n");
    scanf(" %d", &f1.numerador);
    while (f1.denominador == 0)
    {
        printf("Ingrese un denominador distinto de 0: \n");
        scanf(" %d", &f1.denominador);
    }
    printf("Ingrese un numerador: \n");
    scanf(" %d", &f2.numerador);
    
    while (f2.denominador == 0)
    {
        printf("Ingrese un denominador distinto de 0: \n");
        scanf(" %d", &f2.denominador);
    }
    if (f1.numerador <0 && f1.denominador < 0)
    {
        f1.numerador = f1.numerador *-1;
        f1.denominador = f1.denominador *-1;
    }
    if (f2.numerador <0 && f2.denominador < 0)
    {
        f2.numerador = f2.numerador *-1;
        f2.denominador = f2.denominador *-1;
    }
    
    while (eleccion > 2 || eleccion < 1)
    {
        printf("Elija una fraccion para sumarle un numero entero : <1> o <2>: \n");
        scanf(" %d", &eleccion);
    }    
        
    printf("Ingrese un entero para sumar a la funcion elegida \n");
    scanf(" %d", &entero);
    
    if (eleccion == 1)
    {
        sumaenter = sumarentero(f1, entero);
    }
    else if (eleccion == 2)
    {
        sumaenter = sumarentero(f2, entero);
    }
    
    printf("Fraccion 1 : %d/%d \n", f1.numerador, f1.denominador);
    printf("Fraccion 2 : %d/%d \n", f2.numerador, f2.denominador);
    
    fraccion_t suma = sumafraccion(f1, f2);
    
    if (suma.denominador != 1)
    {
        printf("El resultado de la suma da : %d/%d \n", suma.numerador, suma.denominador);
    }
    else
    {
        printf("El resultado de la suma es un entero : %d \n", suma.numerador);
    }
    fraccion_t multiplicacion = multiplicarfraccion(f1,f2);
    if (multiplicacion.denominador != 1)
    {
        printf("El resultado de la multiplicacion da : %d/%d \n", multiplicacion.numerador, multiplicacion.denominador);
    }
    else
    {
        printf("El resultado de la multiplicacion es un entero : %d \n", multiplicacion.numerador);
    }
    if (sumaenter.denominador != 1)
    {
        printf("La suma entre la fraccion numero %d y el entero %d es : %d/%d \n", eleccion, entero, sumaenter.numerador, sumaenter.denominador);
    }
    else
    {
        printf("La suma entre el entero de la fraccion numero %d y el entero %d es %d", eleccion, entero, sumaenter.numerador);
    }
    return 0;
}
