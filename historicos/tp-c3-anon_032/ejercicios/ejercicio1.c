

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define TAMANO_CADENA 100

typedef struct fraccion
{
    int numerador;
    int denominador;
} fraccion_t;

int contador_digitos(int numero)
// Precondiciones: El valor de entrada es un número entero
// Postcondiciones: Devuelve un entero que representa la cantidad de digitos del número ingresado
// Argumentos: Recibe el argumento "numero" que es de tipo número entero
// Retorno: Retorna un valor de tipo número entero
{
    int i = 0;
    while (numero != 0)
    {
        numero /= 10;
        i++;
    }
    return i;
}

void mostrar_fraccion(fraccion_t fraccion)
// Precondiciones: El valor de entrada "fraccion" tiene que ser de tipo fraccion_t
// de número enteros
// Postcondiciones: No devuelve ningún valor, imprime por consola el contenido de la fracción
// Argumentos: Recibe el argumento "fraccion" el cual es una estructura que contiene 2 valores
// enteros, "numerador" y "denominador". Esta estructura esta nombrada por el alias fraccion_t
// Retorno: Esta función no retorna ningún valor, imprime por consola el contenido de la fracción
{
    printf("%d / %d\n", fraccion.numerador, fraccion.denominador);
}

fraccion_t suma_fracciones(fraccion_t fraccion, fraccion_t otra_fraccion)
// Precondiciones: El valor de entrada "fraccion" y "otra_fraccion" tiene que ser de tipo fraccion_t
// de número enteros
// Postcondiciones: Devuelve la suma entre las dos fracciones pasadas por parametro
// Argumentos: Recibe el argumento "fraccion" y "otra_fraccion" las cuales son una estructura que
// contiene 2 valores enteros, "numerador" y "denominador". Esta estructura esta nombrada por el alias fraccion_t
// Retorno: Esta función retorna una estructura nombrada "fraccion_t" que contiene 2 valores enteros,
// "numerador" y "denominador"
{
    fraccion_t suma_fracciones = {.numerador = 0, .denominador = 0};
    if (fraccion.denominador == otra_fraccion.denominador)
    {
        suma_fracciones.numerador = fraccion.numerador + otra_fraccion.numerador;
        suma_fracciones.denominador = fraccion.denominador;
        return suma_fracciones;
    }
    else if (fraccion.denominador % otra_fraccion.denominador == 0)
    {
        suma_fracciones.numerador =
            fraccion.numerador + (otra_fraccion.numerador * (fraccion.denominador / otra_fraccion.denominador));
        suma_fracciones.denominador = fraccion.denominador;
        return suma_fracciones;
    }
    else if (otra_fraccion.denominador % fraccion.denominador == 0)
    {
        suma_fracciones.numerador =
            otra_fraccion.numerador + (fraccion.numerador * (otra_fraccion.denominador / fraccion.denominador));
        suma_fracciones.denominador = otra_fraccion.denominador;
        return suma_fracciones;
    }
    else
    {
        suma_fracciones.numerador =
            (otra_fraccion.numerador * fraccion.denominador) + (fraccion.numerador * otra_fraccion.denominador);
        suma_fracciones.denominador = fraccion.denominador * otra_fraccion.denominador;
        return suma_fracciones;
    }
}

fraccion_t producto_fracciones(fraccion_t fraccion, fraccion_t otra_fraccion)
// Precondiciones: El valor de entrada "fraccion" y "otra_fraccion" tiene que ser de tipo fraccion_t
// de número enteros
// Postcondiciones: Devuelve el producto entre las dos fracciones pasadas por parametro
// Argumentos: Recibe el argumento "fraccion" y "otra_fraccion" las cuales son una estructura que
// contiene 2 valores enteros, "numerador" y "denominador". Esta estructura esta nombrada por el alias fraccion_t
// Retorno: Esta función retorna una estructura nombrada "fraccion_t" que contiene 2 valores enteros,
// "numerador" y "denominador"
{
    fraccion_t producto_fracciones = {.numerador = 0, .denominador = 0};
    producto_fracciones.numerador = (fraccion.numerador * otra_fraccion.numerador);
    producto_fracciones.denominador = (fraccion.denominador * otra_fraccion.denominador);
    return producto_fracciones;
}

fraccion_t suma_fraccion_entero(fraccion_t fraccion, int numero)
// Precondiciones: El valor de entrada "fraccion" tiene que ser de tipo fraccion_t
// de número enteros y el valor de entrada de "numero" debe ser un número entero
// Postcondiciones: Devuelve la suma entre la fracción y el número entero pasados por parámetros
// Argumentos: Recibe el argumento "fraccion" el cual es una estructura que contiene 2 valores enteros,
// "numerador" y "denominador". Esta estructura esta nombrada por el alias fraccion_t. Tambien recibe
// el parámetro "numero" el cual es un numero de tipo entero
// Retorno: Esta función retorna una estructura nombrada "fraccion_t" que contiene 2 valores enteros,
// "numerador" y "denominador"
{
    fraccion_t suma_fraccion_entero = {.numerador = 0, .denominador = 0};
    suma_fraccion_entero.numerador = (numero * fraccion.denominador) + fraccion.numerador;
    suma_fraccion_entero.denominador = fraccion.denominador;
    return suma_fraccion_entero;
}

void mostrar_fraccion_con_operaciones_completo(fraccion_t fraccion, fraccion_t otra_fraccion, char operacion[], int numero)
// Precondiciones: Los valores de entrada son: "fraccion" y "otra_fraccion" de tipo fraccion_t,
// "operacion" de tipo string(arreglo de caracteres) y "numero" de tipo entero
// Postcondiciones: Según el string ingresado en "operacion", la función muestra por consola:
// "MOSTRAR": Una sola fracción ingresada por parámetro
// "SUM_FRACCION": Las dos fracciones ingresadas, con su operador correspondiente y una fraccion
// resultante de la suma entre las fracciones ingresadas
// "PRODUCTO": Las dos fracciones ingresadas, con su operador correspondiente y una fraccion
// resultante de la multiplicación entre las fracciones ingresadas
// "SUM_ENTERO": La fraccion ingresada, el número entero ingresado convertido a fracción con su
// operador correspondiete y una fraccion resultante de la suma entre la fraccion y el entero
// Argumentos: Recibe los argumentos "fraccion" y "otra_fraccion" los cuales son una estructura que contiene
// 2 valores enteros, "numerador" y "denominador". El argumento "operacion" es una cadena de caracteres
// y "numero" es un numero de tipo entero
// Retorno: Esta función no retorna ningún valor, imprime por consola el contenido de la opción seleccionada
{
    char signoOperacion = ' ';
    fraccion_t fraccion1 = fraccion;
    fraccion_t fraccion2 = otra_fraccion;
    fraccion_t resultado = {.numerador = 0, .denominador = 0};

    int diferenciaDeDigitos;

    int cantidadDeDigitosNumeradorFraccion = 0;
    int cantidadDeDigitosDenominadorFraccion = 0;
    int diferenciaDeDigitosFraccion = 0;
    char cantidadSeparadoresFraccion[TAMANO_CADENA] = {""};
    char cantidadEspaciosNumeradorFraccion[TAMANO_CADENA] = {""};
    char cantidadEspaciosDenominadorFraccion[TAMANO_CADENA] = {""};

    int cantidadDeDigitosNumeradorOtraFraccion = 0;
    int cantidadDeDigitosDenominadorOtraFraccion = 0;
    int diferenciaDeDigitoOtraFraccion = 0;
    char cantidadSeparadoresOtraFraccion[TAMANO_CADENA] = {""};
    char cantidadEspaciosNumeradorOtraFraccion[TAMANO_CADENA] = {""};
    char cantidadEspaciosDenominadorOtraFraccion[TAMANO_CADENA] = {""};

    int cantidadDeDigitosNumeradorResultado = 0;
    int cantidadDeDigitosDenominadorResultado = 0;
    int diferenciaDeDigitoResultado = 0;
    char cantidadSeparadoresResultado[TAMANO_CADENA] = {""};
    char cantidadEspaciosNumeradorResultado[TAMANO_CADENA] = {""};
    char cantidadEspaciosDenominadorResultado[TAMANO_CADENA] = {""};

    if (strcmp(operacion, "MOSTRAR") == 0)
    {
        resultado = fraccion1;
    }
    else if (strcmp(operacion, "SUM_FRACCION") == 0)
    {
        resultado = suma_fracciones(fraccion1, fraccion2);
        signoOperacion = '+';
    }
    else if (strcmp(operacion, "PRODUCTO") == 0)
    {
        resultado = producto_fracciones(fraccion1, fraccion2);
        signoOperacion = '*';
    }
    else if (strcmp(operacion, "SUM_ENTERO") == 0)
    {
        resultado = suma_fraccion_entero(fraccion1, numero);
        fraccion2.numerador = numero;
        fraccion2.denominador = 1;
        signoOperacion = '+';
    }
    cantidadDeDigitosNumeradorFraccion = contador_digitos(fraccion1.numerador);
    cantidadDeDigitosDenominadorFraccion = contador_digitos(fraccion1.denominador);
    cantidadDeDigitosNumeradorOtraFraccion = contador_digitos(fraccion2.numerador);
    cantidadDeDigitosDenominadorOtraFraccion = contador_digitos(fraccion2.denominador);
    cantidadDeDigitosNumeradorResultado = contador_digitos(resultado.numerador);
    cantidadDeDigitosDenominadorResultado = contador_digitos(resultado.denominador);

    if (cantidadDeDigitosNumeradorFraccion >= cantidadDeDigitosDenominadorFraccion)
    {
        diferenciaDeDigitos = cantidadDeDigitosNumeradorFraccion - cantidadDeDigitosDenominadorFraccion;
        for (int i = 0; i < diferenciaDeDigitos / 2; i++)
        {
            strcat(cantidadEspaciosDenominadorFraccion, " ");
        }
        for (int i = 0; i < cantidadDeDigitosNumeradorFraccion; i++)
        {
            strcat(cantidadSeparadoresFraccion, "─");
        }
    }
    else
    {
        diferenciaDeDigitos = cantidadDeDigitosDenominadorFraccion - cantidadDeDigitosNumeradorFraccion;
        for (int i = 0; i < diferenciaDeDigitos / 2; i++)
        {
            strcat(cantidadEspaciosNumeradorFraccion, " ");
        }
        for (int i = 0; i < cantidadDeDigitosDenominadorFraccion; i++)
        {
            strcat(cantidadSeparadoresFraccion, "─");
        }
    }
    if (cantidadDeDigitosNumeradorOtraFraccion >= cantidadDeDigitosDenominadorOtraFraccion)
    {
        diferenciaDeDigitos = cantidadDeDigitosNumeradorOtraFraccion - cantidadDeDigitosDenominadorOtraFraccion;
        for (int i = 0; i < diferenciaDeDigitos / 2; i++)
        {
            strcat(cantidadEspaciosDenominadorOtraFraccion, " ");
        }
        for (int i = 0; i < cantidadDeDigitosNumeradorOtraFraccion; i++)
        {
            strcat(cantidadSeparadoresOtraFraccion, "─");
        }
    }
    else
    {
        diferenciaDeDigitos = cantidadDeDigitosDenominadorOtraFraccion - cantidadDeDigitosNumeradorOtraFraccion;
        for (int i = 0; i < diferenciaDeDigitos / 2; i++)
        {
            strcat(cantidadEspaciosNumeradorOtraFraccion, " ");
        }
        for (int i = 0; i < cantidadDeDigitosDenominadorOtraFraccion; i++)
        {
            strcat(cantidadSeparadoresOtraFraccion, "─");
        }
    }
    if (cantidadDeDigitosNumeradorResultado >= cantidadDeDigitosDenominadorResultado)
    {
        diferenciaDeDigitos = cantidadDeDigitosNumeradorResultado - cantidadDeDigitosDenominadorResultado;
        for (int i = 0; i < diferenciaDeDigitos / 2; i++)
        {
            strcat(cantidadEspaciosDenominadorResultado, " ");
        }
        for (int i = 0; i < cantidadDeDigitosNumeradorResultado; i++)
        {
            strcat(cantidadSeparadoresResultado, "─");
        }
    }
    else
    {
        diferenciaDeDigitos = cantidadDeDigitosDenominadorResultado - cantidadDeDigitosNumeradorResultado;
        for (int i = 0; i < diferenciaDeDigitos / 2; i++)
        {
            strcat(cantidadEspaciosNumeradorResultado, " ");
        }
        for (int i = 0; i < cantidadDeDigitosDenominadorResultado; i++)
        {
            strcat(cantidadSeparadoresResultado, "─");
        }
    }
    if (strcmp(operacion, "MOSTRAR") == 0)
    {
        printf("%s%d\n%s\n%s%d\n", cantidadEspaciosNumeradorFraccion, fraccion1.numerador, cantidadSeparadoresFraccion,
                cantidadEspaciosDenominadorFraccion, fraccion1.denominador);
    }
    else
    {
        printf("%s%d%s   %s%d%s   %s%d%s\n%s %c %s = %s\n%s%d%s   %s%d%s   %s%d%s\n",
                cantidadEspaciosNumeradorFraccion, fraccion1.numerador, cantidadEspaciosNumeradorFraccion,
                cantidadEspaciosNumeradorOtraFraccion, fraccion2.numerador, cantidadEspaciosNumeradorOtraFraccion,
                cantidadEspaciosNumeradorResultado, resultado.numerador, cantidadEspaciosNumeradorResultado,
                cantidadSeparadoresFraccion, signoOperacion, cantidadSeparadoresOtraFraccion, cantidadSeparadoresResultado,
                cantidadEspaciosDenominadorFraccion, fraccion1.denominador, cantidadEspaciosDenominadorFraccion,
                cantidadEspaciosDenominadorOtraFraccion, fraccion2.denominador, cantidadEspaciosDenominadorOtraFraccion,
                cantidadEspaciosDenominadorResultado, resultado.denominador, cantidadEspaciosDenominadorResultado);
    }
}

void mostrar_fraccion_v2(fraccion_t fraccion)
// Precondiciones: El valor de entrada "fraccion" tiene que ser de tipo fraccion_t
// Postcondiciones: No devuelve ningún valor, imprime por consola el contenido de la fracción
// Argumentos: Recibe el argumento "fraccion" el cual es una estructura que contiene 2 valores
// enteros, "numerador" y "denominador".
// Retorno: Esta función no retorna ningún valor, imprime por consola el contenido de la fracción
{
    fraccion_t fraccionVacia = {.numerador = 0, .denominador = 0};
    mostrar_fraccion_con_operaciones_completo(fraccion, fraccionVacia, "MOSTRAR", 0);
}

void mostrar_suma_fracciones(fraccion_t fraccion, fraccion_t otra_fraccion)
// Precondiciones: El valor de entrada "fraccion" y "otra_fraccion" tienen que ser de tipo fraccion_t
// Postcondiciones: No devuelve ningún valor, imprime por consola las dos fracciones ingresadas,
// con su operador correspondiente y una fraccion resultante de la suma entre las fracciones ingresadas
// Argumentos:Recibe el argumento "fraccion" y "otra_fraccion" los cuales son una estructura que contiene
// 2 valores enteros, "numerador" y "denominador".
// Retorno: Esta función no retorna ningún valor, imprime por consola las dos fracciones ingresadas,
// con su operador correspondiente y una fraccion resultante de la suma entre las fracciones ingresadas
{
    mostrar_fraccion_con_operaciones_completo(fraccion, otra_fraccion, "SUM_FRACCION", 0);
}

void mostrar_producto_fracciones(fraccion_t fraccion, fraccion_t otra_fraccion)
// Precondiciones: El valor de entrada "fraccion" y "otra_fraccion" tienen que ser de tipo fraccion_t
// Postcondiciones: No devuelve ningún valor, imprime por consola las dos fracciones ingresadas,
// con su operador correspondiente y una fraccion resultante del producto entre las fracciones ingresadas
// Argumentos:Recibe el argumento "fraccion" y "otra_fraccion" los cuales son una estructura que contiene
// 2 valores enteros, "numerador" y "denominador".
// Retorno: Esta función no retorna ningún valor, imprime por consola las dos fracciones ingresadas,
// con su operador correspondiente y una fraccion resultante del producto entre las fracciones ingresadas
{
    mostrar_fraccion_con_operaciones_completo(fraccion, otra_fraccion, "PRODUCTO", 0);
}

void mostrar_suma_fraccion_entero(fraccion_t fraccion, int numero)
// Precondiciones: El valor de entrada "fraccion" tiene que ser de tipo fraccion_t y "numero" de tipo entero
// Postcondiciones: No devuelve ningún valor, imprime por consola la fraccion ingresada, el número entero
// ingresado convertido a fracción con su operador correspondiete y una fraccion resultante
// de la suma entre la fraccion y el entero
// Argumentos:Recibe el argumento "fraccion" el cual es una estructura que contiene 2 valores enteros,
// "numerador" y "denominador". Tambien recibe el argumento "numero" que es un número de tipo entero
// Retorno: Esta función no retorna ningún valor, imprime por consola la fraccion ingresada, el número entero
// ingresado convertido a fracción con su operador correspondiete y una fraccion resultante
// de la suma entre la fraccion y el entero
{
    fraccion_t fraccionVacia = {.numerador = 0, .denominador = 0};
    mostrar_fraccion_con_operaciones_completo(fraccion, fraccionVacia, "SUM_ENTERO", numero);
}

int main()
{
    int numerador = 0;
    float numeradorFloat = 0.0;
    int denominador = 0;
    float denominadorFloat = 0.0;
    int numero = 0;
    float numeroFloat = 0.0;
    int selector = 0;
    float selectorFloat = 0.0;
    fraccion_t fraccion = {.numerador = 0, .denominador = 0};
    fraccion_t otra_fraccion = {.numerador = 0, .denominador = 0};
    fraccion_t suma_de_fracciones = {.numerador = 0, .denominador = 0};
    fraccion_t producto_de_fracciones = {.numerador = 0, .denominador = 0};
    fraccion_t suma_de_fraccion_entero = {.numerador = 0, .denominador = 0};
    printf("\nEjercicio 1: Fracciones\n");
    printf("Mediante el ingreso de dos fracciones de números enteros, realizar diferentes operaciones\n\n");
    printf("Fraccion N°1\n");
    printf("Introduzca el numerador: ");
    fflush(stdout);
    scanf("%f", &numeradorFloat);
    numerador = numeradorFloat;
    if (numeradorFloat - numerador)
    {
        printf("Error! Debes ingresar un número entero\n");
        return FALSE;
    }
    else
    {
        printf("Introduzca el denominador: ");
        fflush(stdout);
        scanf("%f", &denominadorFloat);
        denominador = denominadorFloat;
        if (denominadorFloat - denominador)
        {
            printf("Error! Debes ingresar un número entero\n");
            return FALSE;
        }
        else
        {
            fraccion_t fraccion = {.numerador = numerador, .denominador = denominador};
            printf("\nFraccion N°2\n");
            printf("Introduzca el numerador: ");
            fflush(stdout);
            scanf("%f", &numeradorFloat);
            numerador = numeradorFloat;
            if (numeradorFloat - numerador)
            {
                printf("Error! Debes ingresar un número entero\n");
                return FALSE;
            }
            else
            {
                printf("Introduzca el denominador: ");
                fflush(stdout);
                scanf("%f", &denominadorFloat);
                denominador = denominadorFloat;
                if (denominadorFloat - denominador)
                {
                    printf("Error! Debes ingresar un número entero\n");
                    return FALSE;
                }
                else
                {
                    fraccion_t otra_fraccion = {.numerador = numerador, .denominador = denominador};
                    printf("\nMostrar fracciones\n");
                    printf("Fracción N°1\n");
                    mostrar_fraccion(fraccion);
                    printf("\nFracción N°2\n");
                    mostrar_fraccion(otra_fraccion);
                    suma_de_fracciones = suma_fracciones(fraccion, otra_fraccion);
                    printf("\nSuma de fracciones\n");
                    mostrar_fraccion(suma_de_fracciones);
                    producto_de_fracciones = producto_fracciones(fraccion, otra_fraccion);
                    printf("\nProducto de fracciones\n");
                    mostrar_fraccion(producto_de_fracciones);
                    printf("\nSuma de fraccion con número entero\n");
                    printf("Introduzca un número entero: ");
                    fflush(stdout);
                    scanf("%f", &numeroFloat);
                    numero = numeroFloat;
                    if (numeroFloat - numero)
                    {
                        printf("Error! Debes ingresar un número entero\n");
                        return FALSE;
                    }
                    else
                    {
                        printf("Opción 1: ");
                        mostrar_fraccion(fraccion);
                        printf("Opción 2: ");
                        mostrar_fraccion(otra_fraccion);
                        printf("Ingrese el número de la opción de la fracción que desea sumar: ");
                        fflush(stdout);
                        scanf("%f", &selectorFloat);
                        selector = selectorFloat;
                        if (selectorFloat - selector)
                        {
                            printf("Error! Debes ingresar un número entero\n");
                            return FALSE;
                        }
                        else
                        {
                            switch (selector)
                            {
                            case 1:
                                suma_de_fraccion_entero = suma_fraccion_entero(fraccion, numero);
                                mostrar_fraccion(suma_de_fraccion_entero);
                                break;
                            case 2:
                                suma_de_fraccion_entero = suma_fraccion_entero(otra_fraccion, numero);
                                mostrar_fraccion(suma_de_fraccion_entero);
                                break;
                            default:
                                printf("Error! Debes ingresar una opción existente\n");
                                return FALSE;
                            }
                            return TRUE;
                        }
                    }
                }
            }
        }
    }
}