

#include <stdio.h>

int signo(int numero);

//pre:se necesita que se ingrese un numero entero
//post: se imprimira un numero que indique el signo del mismo

int main()
{
    int numero = 0; //Donde se va a guarda el numero que se ingrese.
    int respuesta = 0; //Donde se va a guarda el retorno de la funcion que se llame.
    
    printf("\n");
    printf("-------------------------------------------------------------\n");
    printf("                Números positivos y negativos                \n");
    printf("-------------------------------------------------------------\n");
    printf("\n");
    
    printf("ingrese un numero para sbaer si es negativo, posito o 0 : ");
    scanf("%d",&numero);//Guarda el numero ingresado en "numero".
    
    respuesta = signo(numero); //Guardo en "respuesta" el retorno de la funcion llamada.
    
    printf("\n");
    printf("%d",respuesta);//Imprimo el retorno de la funcion "signo".  
    printf("\n");
    printf("-------------------------------------------------------------\n");


}

//pre: se necesita un numero entero.
//post: se retornara un numero dependiendo si el numero es 0, menor a 0 o mayor a 0.
    
int signo(int numero)
{
    if (numero < 0)//Si "numero" es menor a 0 (negativo) retorna "-1".
    {
        return -1; 
    }
    else if (numero > 0)//Si "numero" es mayor a 0 (positivo) retorna "1".
    {
        return 1;
    }
    else //Si "numero" no es mayor ni menor a 0 significa que es 0 y lo retorna.
    {
        return 0;
    }
    
}