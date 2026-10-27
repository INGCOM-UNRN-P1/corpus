#include <stdio.h>



typedef struct
{
    int numerador;          
    int denominador;        
} fraccion_t;



/**
 *  Funcion que imprime en pantalla el numerador y denominador de las fracciones.
 * 
 * @param mostrar. De tipo struct fraccion_t, recibe los parametros a mostrar
 * @pre El numerador y denominador tiene que ser un numero valido. El denominador no puede ser 0
 * @post Mostrar correctamente la fraccion.
 * 
*/
void mostrar_fracciones(fraccion_t mostrar)
{
    printf("%d/%d\n", mostrar.numerador, mostrar.denominador);
}



/**
 * La funcion "sumar_fracciones" toma dos fracciones como entrada y devuelve su suma como una fraccion.
 * 
 * @param fraccion_1 La primera fraccion que se suma.
 * @param fraccion_2 La segunda fraccion que se suma.
 * 
 * @return una fraccion con nombre suma de tipo (fraccion_t) que representa la suma de dos fracciones.
 */
fraccion_t sumar_fracciones(fraccion_t fraccion_1, fraccion_t fraccion_2)
{
    fraccion_t suma;
    suma.numerador = ((fraccion_1.numerador * fraccion_2.denominador) + (fraccion_2.numerador * fraccion_1.denominador));
    suma.denominador = (fraccion_1.denominador * fraccion_2.denominador);
    return suma;
}


/**
 * La funcion multiplica dos fracciones y devuelve el producto.
 * 
 * @param fraccion_1 La primera fracción a multiplicar.
 * @param fraccion_2 La segunda fraccion a multiplicar
 * @pre Los parametros tienen que ser numeros validos
 * @post La fraccion a retornar debe ser la multiplicacion correcta.
 * @return una variable de tipo "fracción_t" con nombre producto, que representa una fracción.
 */
fraccion_t multiplicacion_fracciones(fraccion_t fraccion_1, fraccion_t fraccion_2)
{
    fraccion_t producto;
    producto.numerador = (fraccion_1.numerador * fraccion_2.numerador);
    producto.denominador = (fraccion_1.denominador * fraccion_2.denominador);
    return producto;
}


/**
 * La función  toma una fracción y un número entero como entrada y devuelve la suma como una fracción.
 * 
 * @param fraccion_1 Una fraccion representada por una estructura de tipo fraccion_t.
 * @param entero Un valor entero que se sumara al numerador de la fracción.
 * 
 * @return una variable de tipo "fracción_t" con el resultado de la suma.
 */
fraccion_t suma_entero(fraccion_t fraccion_1, int entero)
{
    fraccion_t resultado;
    resultado.numerador = (fraccion_1.numerador + (fraccion_1.denominador * entero));
    return resultado;
}



int main()
{
    fraccion_t fraccion_1, fraccion_2, suma, mostrar, producto, sumar_entero;
    int entero;
    printf("Ingrese el numerador de la primer fraccion: \n");
    scanf("%d", &fraccion_1.numerador);
    printf("Ingrese el denominador de la primer fraccion: \n");
    scanf("%d", &fraccion_1.denominador);
    printf("Ingrese el numerador de la segunda fraccion: \n");
    scanf("%d", &fraccion_2.numerador);
    printf("Ingrese el denominador de la segunda fraccion: \n");
    scanf("%d", &fraccion_2.denominador);
    printf("Primera fraccion: ");
    mostrar_fracciones(fraccion_1);
    printf("Segunda fraccion: ");
    mostrar_fracciones(fraccion_2);
    suma = sumar_fracciones(fraccion_1, fraccion_2);
    producto = multiplicacion_fracciones(fraccion_1, fraccion_2);
    printf("Suma entre fracciones: ");
    mostrar_fracciones(suma);
    printf("Producto entre fracciones: ");
    mostrar_fracciones(producto);
    printf("Ingrese un entero: ");
    scanf("%d", &entero);
    sumar_entero = suma_entero(fraccion_1, entero);
    printf("Resultado de sumar %d/%d + %d: %d/%d", fraccion_1.numerador, fraccion_1.denominador, entero, sumar_entero, fraccion_1.denominador);
    return 0;
}