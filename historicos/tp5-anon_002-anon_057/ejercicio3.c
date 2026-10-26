#include <stdio.h>


int main()
{
    fraccion_t fraccion1 = {1, 2};
    fraccion_t fraccion2 = {3, 4};

    printf("fraccion 1:");
    mostrar(fraccion1);

    printf("\nfraccion 2:");
    mostrar(fraccion2);

    fraccion_t resultado = suma(fraccion1, fraccion2);
    printf("\nLa suma dá: ");
    mostrar(resultado);

    resultado = multiplicacion(fraccion1, fraccion2);
    printf("\nY la multiplicacion dá: ");
    mostrar(resultado);

    return 0;
}

typedef struct fraccion
{
    int numerador;
    int denominador;
} fraccion_t;

/**
 * Realiza la suma de dos fracciones.
 *
 * @param sumando  La primera fracción que se sumará.
 * @param sumador  La segunda fracción que se sumará.
 *
 * @returns La fracción resultante de la suma.
 *
 * @pre Los valores de 'numerador' y 'denominador' de 'sumando' y 'sumador'
 * deben ser números enteros válidos.
 * @pre El denominador de 'sumando' y 'sumador' no debe ser igual a 0.
 *
 * @post La función devuelve la fracción resultante de la suma.
 */
fraccion_t suma(fraccion_t sumando, fraccion_t sumador)
{
    fraccion_t resultado;
    resultado.numerador = (sumando.numerador * sumador.denominador) +
                          (sumador.numerador * sumando.denominador);
    resultado.denominador = sumando.denominador * sumador.denominador;
    return resultado;
}

/**
 * Realiza la multiplicación de dos fracciones.
 *
 * @param multiplicando  La primera fracción que se multiplicará.
 * @param multiplicador  La segunda fracción que se multiplicará.
 *
 * @returns La fracción resultante de la multiplicación.
 *
 * @pre Los valores de 'numerador' y 'denominador' de 'multiplicando' y
 * 'multiplicador' deben ser números enteros válidos.
 * @pre El denominador de 'multiplicando' y 'multiplicador' no debe ser igual a
 * 0.
 *
 * @post La función devuelve la fracción resultante de la multiplicación.
 */
fraccion_t multiplicacion(fraccion_t multiplicando, fraccion_t multiplicador)
{
    fraccion_t resultado;
    resultado.numerador = multiplicando.numerador * multiplicador.numerador;
    resultado.denominador =
        multiplicando.denominador * multiplicador.denominador;
    return resultado;
}

/**
 * Muestra una fracción en el formato "numerador/denominador".
 *
 * @param fraccion  La fracción que se mostrará en la consola.
 *
 * @pre El valor de 'fraccion' debe ser una estructura de fracción válida.
 *
 * @post La función muestra la fracción en el formato "numerador/denominador" en
 * la consola.
 */
void mostrar(fraccion_t fraccion)
{
    printf("%d/%d", fraccion.numerador, fraccion.denominador);
}

/**
 * Realiza la suma de una fracción con un número entero.
 *
 * @param sumando  La fracción a la que se sumará el número entero.
 * @param numero   El número entero que se sumará a la fracción.
 *
 * @returns La fracción resultante de la suma.
 *
 * @pre El valor de 'sumando' debe ser una estructura de fracción válida.
 * @pre El valor de 'numero' debe ser un número entero válido.
 *
 * @post La función devuelve una fracción resultante de la suma.
 */
fraccion_t suma_entero(fraccion_t sumando, int numero)
{
    fraccion_t numero_fraccion = {numero, 1};
    return suma(sumando, numero_fraccion);
}