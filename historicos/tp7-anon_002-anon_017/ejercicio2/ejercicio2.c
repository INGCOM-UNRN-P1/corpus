

#include <stdio.h>
#include <stdlib.h>
#include "ascendente.c"//Aca esta la funcion que ordena el arreglo.
#define ERROR_MEMORIA -1
#define MAXIMO 100

int* reserva_arreglo_enteros(int tamano);
void libera_arreglo_enteros(int* arreglo);
int* duplica_arreglo(int* origen, int tamano);
int* elimina_elemento(int* arreglo, int tamano, int posicion);
int* insertaElemento(int* arreglo, int* tamano, int posicion, int valor);
int* fusiona_arreglos(int* arreglo1, int tamano1, int* arreglo2, int tamano2);



int main(int argc, char *argv[])
{
    
    int *arreglo;//Aca guardo el "arreglo" cargado.
    int *arreglo2;
    int *arreglo_retorno;
    
    int tamaño = 0;
    int opcion = 0;
    int posicion = 0;
    int valor = 0;
    
    
    printf("Ingrese 1 para duplicar un arreglo\n");
    printf("Ingrese 2 para eliminar una posicion del arreglo\n");
    printf("Ingrese 3 para insertar un valor en una posicion\n");
    printf("Ingrese 4 para fusionar 2 arreglos y ordenarlos ascendentemente\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d",&tamaño);
    
    if(opcion == 1)
    {
        arreglo = reserva_arreglo_enteros(tamaño);
        arreglo2 = duplica_arreglo(arreglo, tamaño);
        libera_arreglo_enteros(arreglo);
        libera_arreglo_enteros(arreglo2);
        
    }
    
    else if (opcion == 2)
    {
        printf("Ingrese la posicion que se quiera eliminar: ");
        scanf("%d",&posicion);
        
        arreglo = reserva_arreglo_enteros(tamaño);
        
        arreglo_retorno= elimina_elemento(arreglo, tamaño, posicion);
       
        
        libera_arreglo_enteros(arreglo);
        libera_arreglo_enteros(arreglo_retorno);
        
    }
    else if(opcion == 3)
    {
        printf("Ingrese un valor a insertar: ");
        scanf("%d",&valor);
        
        
        printf("Ingrese la posicion donde se insertara el valor: ");
        scanf("%d",&posicion);
        
        
        arreglo = reserva_arreglo_enteros(tamaño);
        
        arreglo_retorno = insertaElemento(arreglo, &tamaño, posicion, valor);
        
        libera_arreglo_enteros(arreglo);
        libera_arreglo_enteros(arreglo_retorno);
    }
    else if(opcion == 4)
    {
        
        arreglo = reserva_arreglo_enteros(tamaño);
        
        printf("----Segundo arreglo----");
        printf("\n\n\n\n");
        arreglo2 = reserva_arreglo_enteros(tamaño);
        
        
        arreglo_retorno = fusiona_arreglos(arreglo, tamaño, arreglo2, tamaño);
        
        libera_arreglo_enteros(arreglo);
        libera_arreglo_enteros(arreglo2);
        libera_arreglo_enteros(arreglo_retorno);
        
    }

   
   
}

/**
 * La funcion reserva espacio para un arreglo de numeros enteros de n tamaño y lo carga.
 *  @param tamano es el tamaño que va a tener el arreglo, por lo que decide la cantidad de memoria que se va a reservar.
 *  @pre tiene que ser un numero entero mayor a 1.
 *  @returns retorna NULL en caso de que no pueda asignarle memoria o el puntero con el arreglo cargado.
 *  @post se espera que se reserve espacio y cargue un arreglo .
 */

int* reserva_arreglo_enteros(int tamano)
{
    int *arreglo = (int *)calloc(tamano, sizeof(int));//Calloc inicializa los valores y retorna un puntero tipo void, por eso el int*, para que sea un puntero entero?
    int contador = 0;
    
    
    if(arreglo == NULL)
    {
        perror("ERROR AL RESERVAR MEMORIA");
    }
    else
    {
        if(tamano > 1)
		{
			while(contador < tamano && contador < MAXIMO)
			{
            
				printf("Ingrese un valor para la posicion [%d]: ",contador);
				scanf("%d",&arreglo[contador]);
				contador++;

			}
			
		}

    }

    return arreglo;
    
  
}


/**
 * La funcion libera memoria de un puntero
 *  @param arreglo es el puntero que tiene que ser liberado.
 *  @pre tiene que ser un puntero valido.
 *  @post se espera que se libere el espacio de un puntero.
 */

void libera_arreglo_enteros(int* arreglo)
{
    free(arreglo);
}

/**
 * La funcion crea un puntero con los valores de otro arreglo reservados en memoria.
 *  @param origen es el puntero que contiene el arreglo en memoria.
 *  @pre tiene que ser un puntero valido.
 *  @param tamano es el tamaño que tiene el arreglo
 *  @pre tiene que ser un numero entero mayor a 1.
 *  @returns retorna una copia del arreglo cargado en memoria o retorna NULL en caso de no poder reservar memoria para la copia.
 *  @post se espera que se copie un arreglo en la memoria en otro.
 */

int* duplica_arreglo(int* origen, int tamano)
{
    int *salida = (int *)calloc(tamano, sizeof(int));//Arreglo de salida
    int contador = 0;
    
    if(salida == NULL)
    {
        perror("ERROR AL RESERVAR MEMORIA");
    }
    else
    {
        if(tamano > 1)
		{
			while(contador < tamano && contador < MAXIMO)
			{
            
				salida[contador] = origen[contador];
				contador++;

			}
			
		}

    }

    return salida;
       
    
}

/**
 * La funcion copia todos los elementos de un arreglo excepto el elemento en la posicion indicada
 *  @param arreglo es el puntero que contiene el arreglo en memoria.
 *  @pre tiene que ser un puntero valido.
 *  @param tamano es el tamaño que tiene el arreglo
 *  @pre tiene que ser un numero entero mayor a 1.
 *  @param posicion es la posicion que no se va a copiar en el nuevo arreglo.
 *  @pre tiene que ser un numero entero mayor a 0 y menor al tamaño.
 *  @returns retorna una copia del arreglo cargado en memoria sin el elemento en la posicion o retorna NULL en caso de no poder reservar memoria para la copia.
 *  @post se espera que se copie un arreglo en la memoria sin una posicion.
 */


int* elimina_elemento(int* arreglo, int tamano, int posicion)
{
    int *arreglo_aux = (int*) calloc(tamano - 1, sizeof(int));//tamaño menos 1 ya que le tengo que quitar un elemento al arreglo.
    int contador = 0;
    
    if(arreglo_aux != NULL)
    {
          
        if(posicion > 0 && tamano > posicion)
        {
            while(contador < tamano)
            {
                if(contador != posicion)//Si encuentra la posicion, se saltea el if, por lo que no copia el numero en el arreglo auxiliar.
                {
                    arreglo_aux[contador] = arreglo[contador];
                }
                contador++; 
            }
            
        }
     
    }
    else
    {
        perror("ERROR AL RESERVAR MEMORIA");
    }
    
    
    return arreglo_aux;
    
   
}

/**
 * La funcion crea un puntero con los valores de otro arreglo reservados en memoria y le agrega un valor en una posicion.
 *  @param arreglo es el puntero que contiene el arreglo en memoria.
 *  @pre tiene que ser un puntero valido.
 *  @param tamano es el tamaño que tiene el arreglo
 *  @pre tiene que ser un numero entero mayor a 1.
 *  @param posicion es la posicion donde se va a agregar el nuevo valor.
 *  @pre tiene que ser un numero entero mayor a 0 y menor al tamaño.
 *  @param valor es el valor que se va insertar en el arreglo.
 *  @pre tiene que ser un numero entero.
 *  @returns retorna una copia del arreglo cargado en memoria con un nuevo valor o retorna NULL en caso de no poder reservar memoria para la copia.
 *  @post se espera que se copie un arreglo en la memoria con un nuevo elemento.
 */


int* insertaElemento(int* arreglo, int* tamano, int posicion, int valor)
{
    *tamano = *tamano + 1;//Le sumo 1 por que voy a agregar un elemento.
	int *arreglo_aux = (int*) calloc(*tamano, sizeof(int));//En este arreglo voy a guardar el arreglo insertado.
    int contador = 0;   
    int contador_aux = 0;
    
    
    if(arreglo_aux != NULL)
    {
          
        if(posicion > 0 && *tamano > posicion)
        {
            while(contador < *tamano)
            {
 
                if(contador == posicion)//Cuando encuentre la posicion
                {
                    arreglo_aux[posicion] = valor;//Inserto el valor.
                    contador_aux++;//Este contador es para que desplace 1 mas en donde se esta insertando el arreglo, si no, sobreescribe el valor insertado
                }
                 
                arreglo_aux[contador_aux] = arreglo[contador];//Sigue copiando
                
                contador++;
                contador_aux++;

            }
            
        }
     
    }
    else
    {
        perror("ERROR AL RESERVAR MEMORIA");
    }
    
    return arreglo_aux;
    
    
}

/**
 * La funcion fusiona 2 arreglos en 1 arreglo nuevo.
 *  @param arreglo1 es el puntero que contiene el primer arreglo en memoria.
 *  @pre tiene que ser un puntero valido.
 *  @param tamano1 es el tamaño que tiene el arreglo1
 *  @pre tiene que ser un numero entero mayor a 1.
 *  @param arreglo2 es el puntero que contiene el segundo arreglo en memoria.
 *  @pre tiene que ser un puntero valido.
 *  @param tamano2 es el tamaño que tiene el arreglo2
 *  @pre tiene que ser un numero entero mayor a 1.
 *  @returns retorna la fusion entre ambos arreglos cargados en memoria o retorna NULL en caso de no poder reservar memoria para la copia.
 *  @post se espera que se copien ambos arreglos en uno solo.
 */

int* fusiona_arreglos(int* arreglo1, int tamano1, int* arreglo2, int tamano2)
{
    int *arreglo_mix = (int*) calloc(tamano1 + tamano2, sizeof(int));//En este arreglo voy a guardar la fusion de amnos arreglos, por eso el tamaño es la suma de los 2.
    int tamaño_mix = tamano1 + tamano2;
    int contador = 0;//Este contador recorre el arreglo1 y el arreglo donde se fusiona
    int contador_arreglo2 = 0;//Este contador sirve para recorre el segundo arreglo.
    
    while(contador < tamaño_mix)
    {
    
        if(contador < tamano1)//Mientras sea menor al tamaño del primer arreglo, copia los elementos del arreglo1
        {
            arreglo_mix[contador] = arreglo1[contador];

        }
        else//Cuando se pase del tamaño del arreglo1, empieza a copiar los elementos del segundo arreglo
        {
            arreglo_mix[contador] = arreglo2[contador_arreglo2];
            contador_arreglo2++;
        }
        
        contador++;
    }
    


    arreglo_mix = ordena_arreglo(arreglo_mix, tamaño_mix);//Llamo a que ordene el arreglo, de ejercicios anteriores, en la "libreria" ascendente.c
    
    return arreglo_mix;
    
}

