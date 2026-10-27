
#include <stdio.h>

typedef struct fraccion{
    int numerador ;
    int denominador ;
} fraccion_t;


fraccion_t resultado_fraccion(fraccion_t res_fraccion);
fraccion_t suma_fraccion(fraccion_t fraccion1, fraccion_t fraccion2);
fraccion_t mult_fraccion(fraccion_t fraccion1_mult,fraccion_t fraccion2_mult);
void imprime_fraccion();


int main()
{
    fraccion_t fraccion1;
    fraccion_t fraccion2;
    fraccion_t fraccion1_mult;
    fraccion_t fraccion2_mult;
    fraccion_t res_fraccion;
    int opcion;
    
    printf("ingrese 1 para sumar fracciones, 2 para multiplicar fracciones y 3 para sumar fraccion con entero \n");
    scanf("%d",&opcion);
    
    if (opcion == 1)
    {
        printf("Ingrse el numerador mayor a 0 de la primera fraccion: \n");
        scanf("%d",&fraccion1.numerador);
    
        printf("Ingrse el denominador mayor a 0  de la primera fraccion: \n");
        scanf("%d",&fraccion1.denominador);
    
        printf("Ingrse el numerador mayor a 0  de la segunda fraccion: \n");
        scanf("%d",&fraccion2.numerador);
    
        printf("Ingrse el denominador mayor a 0  de la segunda fraccion: \n");
        scanf("%d",&fraccion2.denominador);
      
        res_fraccion =suma_fraccion(fraccion1, fraccion2);
    
        imprime_fraccion(res_fraccion);
    }
    else if (opcion == 2)
    {
        printf("Ingrse el numerador mayor a 0 de la primera fraccion: \n");
        scanf("%d",&fraccion1_mult.numerador);
    
        printf("Ingrse el denominador mayor a 0 de la primera fraccion: \n");
        scanf("%d",&fraccion1_mult.denominador);
    
        printf("Ingrse el numerador mayor a 0 de la segunda fraccion: \n");
        scanf("%d",&fraccion2_mult.numerador);
    
        printf("Ingrse el denominador mayor a 0 de la segunda fraccion: \n");
        scanf("%d",&fraccion2_mult.denominador);
        
        res_fraccion = mult_fraccion(fraccion1_mult, fraccion2_mult);
        imprime_fraccion(res_fraccion);
        
    }
    else if (opcion == 3)
    {
        printf("Ingrse el numerador mayor a 0 de la fraccion: \n");
        scanf("%d",&fraccion1.numerador);
    
        printf("Ingrse el denominador mayor a 0 de la fraccion: \n");
        scanf("%d",&fraccion1.denominador);
        
        printf("ingrese el numero entero : \n");
        scanf("%d",&fraccion2.numerador);
        
        fraccion2.denominador = 1;
        
        res_fraccion = suma_fraccion(fraccion1, fraccion2);
        imprime_fraccion(res_fraccion);
    }
    else
    {
        printf("no es una opcion correcta.\n");
    }
        
}


fraccion_t suma_fraccion(fraccion_t fraccion1,fraccion_t fraccion2)
{
    int aux = 0;
    fraccion_t res_fraccion;
    
    if (fraccion1.denominador == fraccion2.denominador)
    {
        res_fraccion.denominador = fraccion1.denominador; 
        res_fraccion.numerador = fraccion1.numerador + fraccion2.numerador; 
        
        return res_fraccion;
    }
    
    else
    {
        res_fraccion.denominador = fraccion1.denominador * fraccion2.denominador; 
        res_fraccion.numerador = fraccion1.numerador * fraccion2.denominador; 
        aux = fraccion1.denominador * fraccion2.numerador; 
        res_fraccion.numerador= aux + res_fraccion.numerador; 
        
        return res_fraccion;
    }
    
}


fraccion_t mult_fraccion(fraccion_t fraccion1_mult, fraccion_t fraccion2_mult)
{
    fraccion_t res_fraccion;
    
    res_fraccion.numerador = fraccion1_mult.numerador * fraccion2_mult.numerador; 
    res_fraccion.denominador = fraccion1_mult.denominador * fraccion2_mult.denominador; 
    
    return res_fraccion;
    
}



void imprime_fraccion(fraccion_t res_fraccion)
{
    printf("\n %d \n",res_fraccion.numerador);
    printf("--- \n");
    printf("%d \n",res_fraccion.denominador);
}