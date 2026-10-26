
#include <stdio.h>

int cuenta_digitos(int numero);

//Pre: se necesita que se ingrese un numero entero.
//post: se retornara la cantidad de veces que se pudo dividir el numero por 10.

int main()
{
    int numero_ingresado = 0;//Aca guardo el numero ingresado.
    int resultado = 0; //Aca guardo el retorno de la funcion.
    
    printf("\n");
    printf("-------------------------------------------------------------\n");
    printf("                     Contador de digitos                     \n");
    printf("-------------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese un numero para contar sus digitos: ");
    scanf("%d",&numero_ingresado);
    
    resultado = cuenta_digitos(numero_ingresado);
    
    printf("La cantidad de digitos es: %d",resultado);
    
    
}



int cuenta_digitos (int numero)
{
    
    int contador = 0;

    while (numero > 0)//Mientras sea divisible.
    {
        numero = numero / 10; //Aca me quedo con la parte entera de la division (el cociente);
        contador++; //Por cada vez que se puede dividir numero, se suma un digito. 
    }
    
    return contador;
}