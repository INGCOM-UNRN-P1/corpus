

#include <stdio.h>

int suma(int numero1, int numero2);
int producto(int numero1, int numero2);
int potencia(int numero1, int numero2);



int main()
{
    int numero1 = 0;
    int numero2 = 0;
    
    
    int ret_suma = 0;
    int ret_mult = 0;
    int ret_potencia = 0;
    
    
    printf("Ingrese el primer termino: ");
    scanf("%d",&numero1);
    
    printf("Ingrese el segundo termino: ");
    scanf("%d",&numero2);
    
    ret_suma= suma(numero1, numero2);
    ret_mult = producto(numero1, numero2);
    ret_potencia = potencia(numero1, numero2);
    
    printf("%d + %d = %d\n",numero1, numero2, ret_suma);
    printf("%d * %d = %d\n",numero1, numero2, ret_mult);
    printf("%d ^ %d = %d\n",numero1, numero2, ret_potencia);
    
    
    
}

/**
 * La funcion suma 2 terminos adicionando de a 1 de forma recursiva.
 *  @param numero1 es el valor que se va a sumar
 *  @pre tiene que ser un numero entero 
 *  @param numero2 es el segundo valor que se va a sumar y al que se le va a descontar 1 para salir del bucle de llamadas
 *  @pre tiene que ser un numero entero
 *  @returns retorna la suma de los numeros
 *  @post se espera que se sumen 2 numeros.
 */
 
int suma(int numero1, int numero2)
{
    int retorno = 0;
    
    if(numero2 < 0)//por si el segundo numero es negativo
    {
        if(numero2 == 0)
        {
            retorno = numero1;//Cuando el numero2 sea igual a 0, se retorna el total, que se guarda en el numero1
            
        }
        else
        {
            retorno = suma(numero1 - 1, numero2 + 1);//Si el numero 2 no es 0, le resto 1 al total, por que el segundo termino es negativo
        }
    }
    else
    {
        if(numero2 == 0)
        {
            retorno = numero1;//Cuando el numero2 sea igual a 0, se retorna el total, que se guarda en el numero1
        }
        else
        {
            retorno = suma(numero1 + 1, numero2 - 1);//Si el numero 2 no es 0, le suma 1 al total, por que el segundo termino es positvio.
        }
    }
    
    return retorno;
    
    
}

/**
 * La funcion multiplica 2 terminos mediante sumas de forma recursiva.
 *  @param numero1 es el valor que se va a multiplicar
 *  @pre tiene que ser un numero entero distinto de 0
 *  @param numero2 es cuantas veces se va a sumar el primer numero a si mismo y se va descontando (o sumando) hasta que sea 0.
 *  @pre tiene que ser un numero entero distinto de 0
 *  @returns retorna el producto dentre 2 numeros
 *  @post se espera que se multipliquen 2 numeros
 */

int producto(int numero1, int numero2)
{
    int retorno = 0;//Aca guardo el retorno
    
    if(numero2 < 0)//Parte negativa
    {
        if(numero2 != 0)//Si es diferente a 0, multiplica
        {
            retorno = -numero1 - producto(numero1, numero2 + 1);//al guardarlo en retorno, no se modifica el numero 1 y se guarda el resultado en "retorno"
            
        }
        
    }
    else//Parte positiva
    {
        if(numero2 != 0)
        {
            retorno = numero1 + producto(numero1, numero2 - 1);//al guardarlo en retorno, no se modifica el numero 1 y se guarda el resultado en "retorno"
        }
    
    }

    return retorno;//Retorno el producto
    
    
}

/**
 * La funcion calcula la potencia de 2 numeros de forma recursiva.
 *  @param numero1 es la base.
 *  @pre tiene que ser un numero entero distinto de 0
 *  @param numero2 es el exponente de la potencia
 *  @pre tiene que ser un numero entero
 *  @returns retorna la potencia entre numero1 como base y numero2 como exponente
 *  @post se espera que se calcule la potencia.
 */

int potencia(int numero1, int numero2)
{
    int retorno = 0;//Aca guardo el retorno

    if(numero2 == 0)
    {
        retorno = 1;//potencia de 0 es 1
    }
    else
    {
        retorno = numero1 * potencia(numero1, numero2 - 1);//Voy guardando el resultado en retorno y descuento al numero2 que es como el contador.
  
    }


    return retorno;//Retorno el producto
}