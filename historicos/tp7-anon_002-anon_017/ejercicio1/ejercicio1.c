
#include <stdio.h>
#include <stdlib.h>
#include "suma_lenta.c"//El ejercicio 5 del tp1, que tiene la funcion de suma lenta
#include "division_lenta.c"//Ejercicio de division_lenta
#include "resta_lenta.c"//Ejercicio de resta lenta.
#include "multiplicacion_lenta.c" //Ejercicio de multiplicacion_lenta.
#define ERROR_MEMORIA -1


int* reserva_entero(int valor);
int libera_entero(int* valor);
int opera(int valor1, int valor2, char operador, int *resto);


int main(int argc, char *argv[])
{
 
    char *primer_numero = argv[1];//En la posicion 1 se deberia encontrar el primer valor.
    char *operador = argv[2]; //En la posicion 2 tendria que encontrarse el operador.
    char *segundo_numero = argv[3]; //En la posicion 3 se deberia encontrar el primer valor.
 
    
    int numero1 = atoi(primer_numero);//Convierto de char a int
    int numero2 = atoi(segundo_numero);
    
    int *ptr_valor1 = NULL;//Donde se va a guardar los valores en la memoria
    int *ptr_valor2 = NULL;
    
    int resultado = 0;
    int resto = 0;
    
    if(argc < 3)
    {
        printf("Faltan argumentos!");
    }
    else
    {
        ptr_valor1 = reserva_entero(numero1);
        ptr_valor2 = reserva_entero(numero2);
        
        numero1 = libera_entero(ptr_valor1);
        numero2 = libera_entero(ptr_valor2);
        
        resultado = opera(numero1, numero2, *operador, &resto);//El operador lo mando como puntero, por que solo me interesa la primera posicion.
                                                               //Como no puedo retornar 2 veces para la division, mando la direccion de memoria del resto como puntero.
        
        printf("El resultado es: %d y el resto: %d",resultado, resto);
    }

}

/**
 * La funcion genera un puntero al que se le asigna la cantidad de memoria necesaria para guardar un entero y lo guarda, despues se retorna este puntero.
 *  @param valor es el valor que se va a guardar en la memoria
 *  @pre tiene que ser numero entero
 *  @return retorna el error correspondiente (No pudo asignar memoria) o el puntero con el valor.
 *  @post se espera que se cargue un puntero en memoria con un valor.
 */

int* reserva_entero(int valor)
{
    int *ptr_valor = malloc(sizeof(int));//Reservo espacio para un entero en ptr_valor.
    
    if(ptr_valor == NULL)//Verifico que pudo reservar la memoria
    {
        perror("No se pudo asignar la Memoria!");
        *ptr_valor = ERROR_MEMORIA;
    }
    else
    {
            
        *ptr_valor = valor; //Le asigno el numero.
        
    }
      
    return ptr_valor;//retorno el valor 
}

/**
 * La funcion extrae el valor de un puntero en memoria y despues libera esa memoria, retornando el numero extraido del puntero.
 *  @param valor es el valor guardado en memoria
 *  @pre tiene que ser un puntero valido.
 *  @return retorna el valor que estaba en la memoria.
 *  @post se espera que se libere la memoria de un puntero.
 */


int libera_entero(int* valor)
{
    int numero = *valor;//El numero es lo que vale el puntero

    free(valor);//libero la memoria del puntero
    
    return numero;//Retorno el numero extraido
    
}


/**
 * La funcion 
 *  @param valor1 es el valor con el que se va a operar
 *  @pre tiene que ser un numero entero
 *  @param valor2 es el otro valor con el que se va a operar
 *  @pre tiene que ser un numero entero
 *  @param operador es el operador que viene como argumento del main, es el que decide que operacion se va a hacer
 *  @param tiene que ser un caracter.
 *  @param resto es un puntero donde se guarda el resto en caso de que haya una division
 *  @pre tiene que ser un puntero valido.
 *  @return retorna el valor despues de una operacion.
 *  @post se espera que se haga una operacion entre 2 numeros.
 */
 
 

int opera(int valor1, int valor2, char operador, int *resto)
{
    int resultado = 0;
    
    if(operador == 'x')
    {
        resultado = multiplicacion_lenta(valor1, valor2);
    }
    else if(operador == '+')
    {
        resultado = suma_lenta(valor1, valor2);//Llamo a suma_lenta
    }
    else if(operador == '-')
    {
        resultado = resta_lenta(valor1, valor2);//Llamo a resta_lenta
    }    
    else if(operador == '/' && valor2 != 0)
    {
        ////Llamo a la division lenta
        resultado = cociente_lento(valor1, valor2);//Hago el cociente
        *resto = division_lenta(valor1, valor2);//Hago el resto y lo guardo en el puntero.
        
    }
    
    
    
    return resultado;
    
}