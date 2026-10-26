

#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
}fraccion_t;

void mostrar_fracciones(fraccion_t mostrar){
    printf("%i/%i\n", mostrar.numerador, mostrar.denominador);
    return ;

}



fraccion_t sumar_fracciones(fraccion_t fraccion_1, fraccion_t fraccion_2){
    fraccion_t suma;
    suma.numerador = ((fraccion_1.numerador*fraccion_2.denominador) + (fraccion_2.numerador*fraccion_1.denominador));
    suma.denominador = (fraccion_1.denominador*fraccion_2.denominador);
    return suma;
}


fraccion_t multiplicacion_fracciones(fraccion_t fraccion_1, fraccion_t fraccion_2){
    fraccion_t producto;
    producto.numerador = (fraccion_1.numerador*fraccion_2.numerador);
    producto.denominador = (fraccion_1.denominador*fraccion_2.denominador);
    return producto;

}

fraccion_t suma_entero(fraccion_t fraccion_1, int entero){
    fraccion_t resultado;
    resultado.numerador = (fraccion_1.numerador+(fraccion_1.denominador*entero));
    return resultado;
    
}

int main()
{  
    fraccion_t fraccion_1, fraccion_2, suma, mostrar, producto, sumar_entero;
    int entero;
    printf("Ingrese el numerador de la primer fraccion: \n");
    scanf("%i", &fraccion_1.numerador);
    printf("Ingrese el denominador de la primer fraccion: \n");
    scanf("%i", &fraccion_1.denominador);
    printf("Ingrese el numerador de la segunda fraccion: \n");
    scanf("%i", &fraccion_2.numerador);
    printf("Ingrese el denominador de la segunda fraccion: \n");
    scanf("%i", &fraccion_2.denominador);    
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
    scanf("%i", &entero);
    sumar_entero = suma_entero(fraccion_1, entero);
    printf("Resultado de sumar %i/%i + %i: %i/%i",fraccion_1.numerador,fraccion_1.denominador, entero, sumar_entero,fraccion_1.denominador);
    return 0;
}