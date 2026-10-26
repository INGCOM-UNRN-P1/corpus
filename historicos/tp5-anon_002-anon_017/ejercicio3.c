
#include <stdio.h>

typedef struct fraccion{
    int numerador;
    int denominador;
} fraccion_t;


void imprime_fraccion(fraccion_t fraccion);
fraccion_t suma_fracciones(fraccion_t fraccion, fraccion_t fraccion2);
fraccion_t multiplica_fracciones(fraccion_t fraccion, fraccion_t fraccion2);
fraccion_t suma_entero(fraccion_t fraccion , int numero_entero);

int main()
{
    fraccion_t fraccion1;//Declaro la fraccion del tipo fraccion_t
    fraccion_t fraccion2;
    fraccion_t fraccion_resultado;
    int numero = 0;
    int opcion = 0;
    
    printf("Ingrese 1 para sumar 2 fracciones\n");
    printf("Ingrese 2 para multiplicar 2 fracciones\n");
    printf("Ingrese 3 para sumar un numero entero con una fraccion\n");
    printf("Opcion:");
    scanf("%d",&opcion);
    
    if(opcion == 1)
    {
        printf("Ingrese el numerador de la fraccion: ");
        scanf("%d",&fraccion1.numerador);//Guardo el valor en la variable "numerador" de la estructura.
        
        printf("Ingrese el denominador de la fraccion: ");
        scanf("%d",&fraccion1.denominador);//Guardo el valor en la variable "denomidor" de la estructura.
        
        printf("Ingrese el numerador de la segunda fraccion: ");
        scanf("%d",&fraccion2.numerador);
        
        printf("Ingrese el denominador de la segunda fraccion: ");
        scanf("%d",&fraccion2.denominador);
        
        if(fraccion1.denominador == 0 || fraccion2.denominador == 0 || fraccion1.numerador == 0 || fraccion2.numerador == 0)
        {
            printf("No puede haber un 0!");
        }
        else
        {
            fraccion_resultado = suma_fracciones(fraccion1, fraccion2);
            imprime_fraccion(fraccion_resultado);
    
        }
        

    }
    else if(opcion == 2)
    {
        printf("Ingrese el numerador de la fraccion: ");
        scanf("%d",&fraccion1.numerador);
        
        printf("Ingrese el denominador de la fraccion: ");
        scanf("%d",&fraccion1.denominador);
        
        printf("Ingrese el numerador de la segunda fraccion: ");
        scanf("%d",&fraccion2.numerador);
        
        printf("Ingrese el denominador de la segunda fraccion: ");
        scanf("%d",&fraccion2.denominador);
        
        if(fraccion1.denominador == 0 || fraccion2.denominador == 0 || fraccion1.numerador == 0 || fraccion2.numerador == 0)//Si es 0 no puede multiplicar
        {
            printf("No puede haber un 0!");
        }
        else
        {
            fraccion_resultado = multiplica_fracciones(fraccion1, fraccion2);
            imprime_fraccion(fraccion_resultado);
    
        }
    }
    else if(opcion == 3)
    {
        printf("Ingrese el numerador de la fraccion: ");
        scanf("%d",&fraccion1.numerador);
        
        printf("Ingrese el denominador de la fraccion: ");
        scanf("%d",&fraccion1.denominador);
        
        printf("Ingrese el numero entero: ");
        scanf("%d",&numero);
        
        if(fraccion1.numerador == 0 || fraccion1.denominador == 0 )//Si es 0 no puede sumar
        {
            printf("No puede haber un 0 en la fraccion!");
        }
        else if(numero == 0)//Si se suma 0, queda igual
        {
            imprime_fraccion(fraccion1);
        }
        else//Si puede sumar, suma
        {
            
            fraccion_resultado = suma_entero(fraccion1, numero);
            imprime_fraccion(fraccion_resultado);
            
        }
    }
    else
    {
        printf("No es una opcion!");
    }
     

}




fraccion_t suma_fracciones(fraccion_t fraccion, fraccion_t fraccion2)
{
    fraccion_t fraccion_resultado;
    
    if(fraccion.denominador == fraccion2.denominador)//si los denominadores son iguales, suma normal
    {
        fraccion_resultado.numerador = fraccion.numerador + fraccion2.numerador;
        fraccion_resultado.denominador = fraccion.denominador;
    }
    else//Si no, tengo que encontrar el minimo comun multiplo
    {
        printf("entro al else\n");
        fraccion_resultado.denominador = fraccion.denominador * fraccion2.denominador;//Multiplico denomindores.
        fraccion_resultado.numerador = fraccion.numerador * fraccion2.denominador;//Multiplico el numerador de la primera fraccion por el de la segunda
        fraccion_resultado.numerador = fraccion_resultado.numerador + (fraccion.denominador * fraccion2.numerador);//Mutiplico el denominador de la primera por el numerador de la segunda
                                                                                                                   //Sumo las multiplicaciones.
    }
    
    
    return fraccion_resultado;//Retorna el resultado de la suma.
    
    
}



void imprime_fraccion(fraccion_t fraccion)
{
    
    printf("%d",fraccion.numerador);
    printf("\n--\n");
    printf("%d",fraccion.denominador);
}





fraccion_t multiplica_fracciones(fraccion_t fraccion, fraccion_t fraccion2)
{
    fraccion_t fraccion_resultado;
    
    
    fraccion_resultado.numerador =  (fraccion.numerador * fraccion2.numerador);//Multiplico los numeradores
    fraccion_resultado.denominador = (fraccion.denominador * fraccion2.denominador);//Multiplico los denominadores
    
    
    return fraccion_resultado;
    
    
}



fraccion_t suma_entero(fraccion_t fraccion , int numero_entero)
{
    fraccion_t fraccion_resultado;
    
    fraccion_resultado.denominador = fraccion.denominador;//El denomidor es el mismo.
    fraccion_resultado.numerador = numero_entero * fraccion.denominador;//multiplico 
    fraccion_resultado.numerador = fraccion_resultado.numerador + fraccion.numerador;//sumo el anterior valor con el otro, el numerador de la fraccion1 queda igual por que se multiplicar por 1.
    
    
    return fraccion_resultado;
}