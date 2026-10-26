
#include <stdio.h>

long factorial(int numero);

//pre:se necesitara un numero entero
//post:Se devovlera el factorial del numero ingresado

int main()
{
    int numero = 0;
    int resultado = 0;
    
    
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("                      Factorial                     \n");
    printf("----------------------------------------------------\n");
    printf("\n");
    
    
    
    printf("Ingrese un numero para calcular su factorial: ");
    scanf("%d",&numero);//Guardo el numero ingresado
    
    resultado = factorial(numero); //LLamo a la funcion y guardo el retorno
    
    printf("----------------------------------------------------\n");
    printf("El factoria de %d es: %d\n",numero,resultado);
    printf("----------------------------------------------------\n");

}
//pre: se necesita un numero entero.
//post: se multiplicaran todos los numeros entre el 1 y el numero ingresado para despues retornarlo.


long factorial(int numero)
{
    int contador = 1;
    int resultado = 1;
    
    while (contador <= numero)//mientras el contador sea menor o igual a numero, sigue multiplicando
    {
        resultado = resultado * contador; //Multiplica el resultado anterior * contador y sobreescribe el resultado,
        contador++;
    }
    
    return resultado;
   
}


