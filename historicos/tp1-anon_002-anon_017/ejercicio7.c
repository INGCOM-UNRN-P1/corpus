

#include <stdio.h>

int es_primo(int numero);


int main()
{
    int numero = 0;// Inicio de variables
    int retorno = 0;//
    
    
    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("                      Es primo?                      \n");
    printf("-----------------------------------------------------\n");
    printf("\n");
    
    
    printf("Ingrese un numero para saber si es primo: ");
    scanf("%d",&numero);//Guardo el numero 
    
    retorno = es_primo(numero); //Gurdo el retorno en "retorno"
    
    printf("\n");
    printf("%d\n",retorno);//Imprimo el retorno
    
    
}


//pre:Se necesita un numero entero.
//post:Se retornara 1 o un -1 dependiendo de la cantidad de veces que se pueda dividir.

int es_primo(int numero)
{
    int contador_div = 0; //Variable donde se guarda cuantas veces se pudo dividir el numero
    int contador = 1; //Por lo que se va a dividir
    
    if (numero <= 1)//Si es 1 o menor no es primo
    {
        return -1;
    }
    
    while(contador <= numero)//Mientras contador sea menor o igual a numero que siga dividiendo
    {
        if(numero % contador == 0)//Aca divide el numero y si da resto 0 suma 1 vez 
        {
            contador_div++;
        }
        contador++;
    }
    
    if (contador_div == 2)//Si solo se pudo dividir 2 veces (por 1 y por si mismo) es primo
    {
        return 1;
    }
    else  //Si no , no es primo
    {
        return -1;
    }
    
}