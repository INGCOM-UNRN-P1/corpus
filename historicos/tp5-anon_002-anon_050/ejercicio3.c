

#include <stdio.h>

typedef struct fraccion
{
    int numerador;
    int denominador;
} fraccion_t;

/**
 * La funció muestra una fracción en pantalla.
 * @param frac, fracción a mostar.
 * @pre int válidos, denominador distinto de cero.
*/
void mostrarFraccion(fraccion_t frac)
{
    printf("%d/%d\n", frac.numerador, frac.denominador);
}

/**
 * La función calcular el máximo común divisor de una fracción.
 * @param a, número a reducir.
 * @pre int válido.
 * @param b, número para encontrar MCD.
 * @pre int mayor a cero válido.
 * @return a reducido.
 * @post int válido. 
*/
int MCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/**
 * La función simplifica una fracción.
 * @param frac, fracción a simplificar.
 * @pre int válido, mayor a cero en el denominador.
 * @return frac simplificado.
 * @post int válido, mayor a cero en el denominador.
*/
fraccion_t simplificar(fraccion_t frac)
{
    int mcd = MCD(frac.numerador, frac.denominador);
    frac.numerador /= mcd;
    frac.denominador /= mcd;
    
    return frac;
}

/**
 * La función suma fracciones.
 * @param frac1, fracción a la que se le suma otra.
 * @pre int válido, mayor a cero en el denominador.
 * @param frac2, fracción sumada a la primera.
 * @pre int válido, mayor a cero en el denominador.
 * @return resultado, de la suma.
 * @post int válido, mayor a cero en el denominador.
*/
fraccion_t sumarFracciones(fraccion_t frac1, fraccion_t frac2)
{
    fraccion_t resultado;
    
    resultado.numerador = (frac1.numerador * frac2.denominador) + 
                            (frac2.numerador * frac1.denominador);
    resultado.denominador = (frac1.denominador * frac2.denominador);

    resultado = simplificar(resultado);

    return resultado;
}

/**
 * La función multiplica fracciones.
 * @param frac1, fracción a la que se le multiplica otra.
 * @pre int válido, mayor a cero en el denominador.
 * @param frac2, fracción multiplicada a la primera.
 * @pre int válido, mayor a cero en el denominador.
 * @return resultado, de la multiplicación.
 * @post int válido, mayor a cero en el denominador.
*/
fraccion_t multiplicarFracciones(fraccion_t frac1, fraccion_t frac2)
{
    fraccion_t resultado;
    resultado.numerador = frac1.numerador * frac2.numerador;
    resultado.denominador = frac1.denominador * frac2.denominador;

    resultado = simplificar(resultado);

    return resultado;
}

/**
 * La función multiplica fracciones.
 * @param frac, fracción a la que se le suma un entero.
 * @pre int válido, mayor a cero en el denominador.
 * @param entero, se le suma a la fracción.
 * @pre int válido.
 * @return función sumarFracciones, de la suma.
 * @post int válido, mayor a cero en el denominador.
*/
fraccion_t sumarEntero(fraccion_t frac, int entero)
{
    fraccion_t entero_a_fraccion;

    entero_a_fraccion.numerador = entero;
    entero_a_fraccion.denominador = 1;

    return sumarFracciones(frac, entero_a_fraccion);
}

int main()
{
    fraccion_t fraccion1 = {1, 2};
    fraccion_t fraccion2 = {3, 4};
    fraccion_t sumar_fracciones;
    fraccion_t multiplicar_fracciones;
    fraccion_t sumar_entero;
    int entero = 5;

    printf("La primera fracción es: ");
    mostrarFraccion(fraccion1);

    printf("La segunda fracción es: ");
    mostrarFraccion(fraccion2);

    printf("La suma de las fracciones es: ");
    sumar_fracciones = sumarFracciones(fraccion1, fraccion2);
    mostrarFraccion(sumar_fracciones);

    printf("La multiplicación de las fracciones es: ");
    multiplicar_fracciones = multiplicarFracciones(fraccion1, fraccion2);
    mostrarFraccion(multiplicar_fracciones);

    printf("La suma de la primer fracción con un entero es: ");
    sumar_entero = sumarEntero(fraccion1, entero);
    mostrarFraccion(sumar_entero);

    printf("La suma de la segunda fracción con un entero es: ");
    sumar_entero = sumarEntero(fraccion2, entero);
    mostrarFraccion(sumar_entero);

    return 0;
}