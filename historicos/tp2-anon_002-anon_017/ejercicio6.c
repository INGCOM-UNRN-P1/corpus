
#include <stdio.h>


int es_primo(int numero);//Aca veo si es primo
int suma_de_primos(int tope);

//pre: se necesita 1 numero entero
//post: se imprime el resultado de la suma de todos los numero primos del 1 hasta el numero ingresado.

int main()
{
    int numero = 0;//Aca guardo el numero ingresado.
    int total = 0;//Aca se guarda la suma de los numeros 
    
    printf("\n");
    printf("------------------------------------------------------------------\n");
    printf("                      Suma de Números Primos                      \n");
    printf("------------------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese el numero: ");
    scanf("%d",&numero);//Guardo el numero
    
    total = suma_de_primos(numero);
    
    printf("El total de la suma de numero primos es de: %d",total);
    
}



int suma_de_primos(int tope)
{
    
    int contador = 0;
    int resultado = 0;
    int total = 0;
    
    while (contador <= tope)
    {
        resultado = es_primo(contador);//Llamo para ver si el numero es primo
        if(resultado == 1)//si el numero es primo
        {
            total = total + contador;//sumo el numero primo anterior con el proximo;
        }
        contador++;
    }
    
    return total;
    
    
}




int es_primo(int numero)
{
    int contador_div = 0; //Variable donde se guarda cuantas veces se pudo dividir el numero
    int contador = 1; //Por lo que se va a dividir
    int retorno = 0;
    
    
    if (numero <= 1)//Si es 1 o menor no es primo
    {
        retorno = -1;
    }
    //Contar todos los numeros primos hasta numero
    
    
    while(contador <= numero)//Mientras contador sea menor o igual a numero que siga dividiendo
    {
        if(numero % contador == 0)//Aca divide el numero y si da resto 0 suma 1 vez 
        {
            contador_div++;
        }
        contador++;
    }
    
    if(contador_div == 2)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    
    return retorno;
}