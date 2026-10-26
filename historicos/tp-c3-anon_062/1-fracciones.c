

#include<stdio.h>

typedef struct fraccion{
    int numerador;
    int denominador;
}fraccion_t;

//typedef struct fraccion fraccion_t;
//otra opción para definir las variables del tipo 'fraccion_t'

// ---------------------------------------------
void mostrar_fraccion(fraccion_t fracc)
// recibe un número tipo fracción_t con numerador y denominador
// devuelve la impresión de la fracción por consola
{
    printf("\n");
    printf(" %d \n", fracc.numerador);
    printf("----\n");
    printf(" %d \n", fracc.denominador);
}

// ----------------------------------------------
fraccion_t sumar_dos_fracciones(fraccion_t fracc1, fraccion_t fracc2)
// recibe dos números tipo fracción_t con numerador y denominador
// devuelve la suma de las fracciones
{
    fraccion_t fraccionsuma;

    fraccionsuma.denominador = fracc1.denominador * fracc2.denominador;
    fraccionsuma.numerador = fracc1.numerador * fracc2.denominador + fracc2.numerador * fracc1.denominador;
    
    return fraccionsuma;
}

// ----------------------------------------------
fraccion_t producto_de_fracciones(fraccion_t fracc1, fraccion_t fracc2)
// recibe dos números tipo fracción_t con numerador y denominador
// devuelve producto de las fracciones
{
    fraccion_t fraccionproducto;

    fraccionproducto.denominador = fracc1.denominador * fracc2.denominador;
    fraccionproducto.numerador = fracc1.numerador * fracc2.numerador;
    
    return fraccionproducto;
}

// ----------------------------------------------
fraccion_t sumar_un_entero(int numero, fraccion_t fracc)
// recibe dos números tipo fracción_t con numerador y denominador
// devuelve la suma de las fracciones
{
    fraccion_t fraccionsuma;

    fraccionsuma.denominador = fracc.denominador;
    fraccionsuma.numerador = numero * fracc.denominador + fracc.numerador;
    
    return fraccionsuma;
}

//--------------------------------------------
//----------------- MAIN ---------------------
void main()
{
    fraccion_t numeroa;
    fraccion_t numerob;
    fraccion_t numeroc;
    int numeroentero = 0;
     
    printf("-- PRIMERA FRACCION -- \n");
    printf("Ingrese Numerador: ");
    scanf("%d", &numeroa.numerador);
    printf("Ingrese denominador: ");
    scanf("%d", &numeroa.denominador);
    printf("\n");        //salto de linea

    printf("-- SEGUNDA FRACCION -- \n");
    printf("Ingrese Numerador: ");
    scanf("%d", &numerob.numerador);
    printf("Ingrese denominador: ");
    scanf("%d", &numerob.denominador);
    printf("\n");        //salto de linea

    printf("Primera fraccion \n");
    mostrar_fraccion(numeroa);
    printf("Segunda fraccion \n");
    mostrar_fraccion(numerob);
    printf("suma de las fracciones \n");   
    mostrar_fraccion(sumar_dos_fracciones(numeroa, numerob));   //muestra la suma de dos fracciones
    printf("producto de las fracciones \n");   
    mostrar_fraccion(producto_de_fracciones(numeroa, numerob));   //muestra el producto de dos fracciones
 
    printf("-- AHORA INGRESE UN ENTERO Y UNA FRACCIÓN PARA OPERAR -- \n");
    printf("Ingrese el entero: ");
    scanf("%d", &numeroentero);
    printf("-- de la fracción \n");
    printf("Ingrese Numerador: ");
    scanf("%d", &numeroc.numerador);
    printf("Ingrese denominador: ");
    scanf("%d", &numeroc.denominador);
    printf("\n");        //salto de linea
    mostrar_fraccion(sumar_un_entero(numeroentero, numeroc));   //muestra la suma de un entero y una fraccion
}