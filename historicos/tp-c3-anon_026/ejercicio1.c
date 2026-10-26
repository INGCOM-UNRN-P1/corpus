

#include <stdio.h>

typedef struct fraccion{
    int numerador;
    int denominador;
}fraccion_t;

void print_fraccion (fraccion_t A); // fraccion_t es tipo de dato y A es la variable
fraccion_t multiplicaFraccion (fraccion_t A, fraccion_t B);
fraccion_t suma_fraccion(fraccion_t A, fraccion_t B);
fraccion_t suma_entero(fraccion_t A, int entero);

int main()
{    
    fraccion_t A; //variable de primera fraccion
    fraccion_t B;// variable segunda fraccion
    int entero = 0;
    
    printf("Ingrese numerador de la primer fracción: ");
    scanf("%d", &A.numerador);
    
    printf("Ingrese denominador de la primer fracción: ");
    scanf("%d", &A.denominador);
    
    printf("Ingrese numerador de la segunda fracción: ");
    scanf("%d", &B.numerador);
    
    printf("Ingrese denominador de la segunda fracción: ");
    scanf("%d", &B.denominador);
    
    printf("Ingrese entero:      ");
    scanf("%d", &entero);
    
    printf("Primera fraccion \n");    
    print_fraccion(A); //la primer fracción
    printf("Segunda fraccion \n");
    print_fraccion(B);//imprime la segunda fracción

    
    fraccion_t guardarmulti = multiplicaFraccion (A, B);
    fraccion_t guardarsuma = suma_fraccion(A, B);
    fraccion_t guardarsumaEntero = suma_entero(A, entero);
    
    if(guardarmulti.numerador % guardarmulti.denominador == 0) //ciclo donde si el resultado de la fraccion devuelve un entero
    {
        guardarmulti.numerador = guardarmulti.numerador / guardarmulti.denominador;
        guardarmulti.denominador = 1;
        printf("Multiplicacion de fracciones: \n%d\n", guardarmulti.numerador);
    }
    else
    {
        printf("Multiplicacion de fracciones: \n%d\n--\n%d\n", guardarmulti.numerador, guardarmulti.denominador);
    }
    
    if(guardarsuma.numerador % guardarsuma.denominador == 0) //ciclo donde si el resultado de la fraccion devuelve un entero
    {
        guardarsuma.numerador = guardarsuma.numerador / guardarsuma.denominador;
        guardarsuma.denominador = 1;
        printf("Suma de fracciones: \n%d\n", guardarsuma.numerador);
    }
    else
    {
        printf("Suma de fracciones: \n%d\n--\n%d\n", guardarsuma.numerador, guardarsuma.denominador);
    }
    
    if (guardarsumaEntero.numerador % guardarsumaEntero.denominador == 0) //ciclo donde si el resultado de la fraccion devuelve un entero
    {
        guardarsumaEntero.numerador = guardarsumaEntero.numerador / guardarsumaEntero.denominador;
        guardarsumaEntero.denominador = 1;
        printf("Suma de fraccion y entero: \n%d\n", guardarsumaEntero.numerador);
    }
    else
    {
        printf("Suma de entero y fraccion: \n%d\n--\n%d\n", guardarsumaEntero.numerador, guardarsumaEntero.denominador);
    }
    
    return 0;  
}

//funcion que imprime en pantalla las fracciones
void print_fraccion (fraccion_t A)
//precondicion recibe dos valores ingresados por el usuario.
//poscondicion muestra en pantalla los valores en fraccion.
{
    printf("%d\n--\n%d\n", A.numerador, A.denominador);
}
 
//funcion que multiplica dos fracciones.
fraccion_t multiplicaFraccion (fraccion_t A, fraccion_t B)//fraccion_t como tipo de dato
//precondicion recibe cuatro valores ingresados por el usuario.
//poscondicion devuelve el resultado de la multiplicacion de dos fracciones.
{
    fraccion_t multiplicacion;
    multiplicacion.numerador = A.numerador * B.numerador;
    multiplicacion.denominador = A.denominador * B.denominador;
        
    return multiplicacion; 
}

//funcion que suma dos fracciones.
fraccion_t suma_fraccion(fraccion_t A, fraccion_t B)
//precondicion recibe cuatro valores ingresados por el usuario.
//poscondicion devuelve el resultado de la suma de dos fracciones.
{    
    fraccion_t suma;
    suma.numerador = (A.numerador * B.denominador) + (B.numerador * A.denominador);
    suma.denominador = A.denominador * B.denominador;
    
    return suma;
}
 
//funcion que suma un entero y una fraccion.
fraccion_t suma_entero(fraccion_t A, int entero)
//precondicion recibe tres valores ingresados por el usuario.
//poscondicion devuelve el resultado de la suma entre un entero y una fraccion.
{    
    fraccion_t sumaEntero;
    sumaEntero.numerador = (A.numerador * 1) + (entero * A.denominador);
    sumaEntero.denominador = A.denominador * 1;
    
    return sumaEntero;
} 




