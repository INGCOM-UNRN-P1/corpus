

#include <stdio.h>

typedef struct fraccion{
    int numerador;
    int denominador;
}fraccion_t;// esto seria como un tipo de dato y llamar atributos como numerador o denominador

void print_fraccion (fraccion_t A); // fraccion_t es tipo de dato y A es la variable
fraccion_t multiplicaFraccion (fraccion_t A, fraccion_t B);
fraccion_t suma_fraccion(fraccion_t A, fraccion_t B);
fraccion_t suma_entero(fraccion_t A, int entero);

int main()
{    
    fraccion_t A; //variable de primera fraccion
    fraccion_t B;// variable segunda fraccion
    int entero = 0;
    
    printf("Ingrese numerador   1: ");
    scanf("%d", &A.numerador);
    
    printf("Ingrese denominador 1: ");
    scanf("%d", &A.denominador);
    
    printf("Ingrese numerador   2: ");
    scanf("%d", &B.numerador);
    
    printf("Ingrese denominador 2: ");
    scanf("%d", &B.denominador);
    
    printf("Ingrese entero:        ");
    scanf("%d", &entero);
    
    printf("Primera fraccion \n");    
    print_fraccion(A); //imprime a numerador y denominador de la primera fraccion 
    printf("Segunda fraccion \n");
    print_fraccion(B);//imprime a numerador y denominador de la segunda fraccion

    
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


void print_fraccion (fraccion_t A)
{
    printf("%d\n--\n%d\n", A.numerador, A.denominador);
}


fraccion_t multiplicaFraccion (fraccion_t A, fraccion_t B)//fraccion_t como tipo de dato

{
    fraccion_t multiplicacion;
    multiplicacion.numerador = A.numerador * B.numerador;
    multiplicacion.denominador = A.denominador * B.denominador;
        
    return multiplicacion; 
}


fraccion_t suma_fraccion(fraccion_t A, fraccion_t B)
{    
    fraccion_t suma;
    suma.numerador = (A.numerador * B.denominador) + (B.numerador * A.denominador);
    suma.denominador = A.denominador * B.denominador;
    
    return suma;
}


fraccion_t suma_entero(fraccion_t A, int entero)
{
    fraccion_t sumaEntero;
    sumaEntero.numerador = (A.numerador * 1) + (entero * A.denominador);
    sumaEntero.denominador = A.denominador * 1;
    
    return sumaEntero;
} 
