
#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
    int dato;
    struct nodo* siguiente;
}nodo_t;

nodo_t* pasar_arreglo(int arreglo[], int largo, nodo_t* lista, int posicion_lista);
void imprimir_lista(nodo_t* lista);
nodo_t* crear_nodo(int valor);
void liberar_nodo(nodo_t* nodo);
nodo_t* insertar_al_final(nodo_t* lista, int valor);
int suma_lista(nodo_t* lista);
int largo_de_lista(nodo_t* lista);
nodo_t* invierte_lista(nodo_t* actual, nodo_t* anterior);



int main()
{
    int arreglo[5] = {10,20,30,40,50};
    int capacidad = 5;
    int recorre = 0;
    int total_suma = 0;
    int largo_lista = 0;
    
    nodo_t* lista = NULL;
    
    lista = pasar_arreglo(arreglo, capacidad, lista, recorre);
    imprimir_lista(lista);
    
    total_suma = suma_lista(lista);
    printf("La suma de los datos de la lista es: %d\n",total_suma);
    
    largo_lista = largo_de_lista(lista);
    printf("El largo de la lista es de: %d \n",largo_lista);
    
    printf("\n\nLista invertida\n\n");
    lista = invierte_lista(lista, NULL);

    imprimir_lista(lista);
    
    
    //Libero la lista.
    while (lista != NULL)
    {
        nodo_t* nodo_eliminar = lista;
        lista = lista->siguiente;
        liberar_nodo(nodo_eliminar);
    }
    
}


/**
 * La funcion pasa un arreglo a una lista enlazada.
 *  @param arreglo es el arreglo que se va a pasar.
 *  @pre tiene que ser un arreglo valido.
 *  @param largo es el largo de la lista.
 *  @pre tiene que ser un numero entero positivo.
 *  @param lista es la lista que se va a imprimir
 *  @pre tiene que ser una lista valida. 
 *  @param recorre es la poscion actual del arreglo que se va a guardar en la lista.
 *  @pre tiene que ser un numero entero.
 *  @post se espera que se impriman los nodos de una lista.
 */
 
nodo_t* pasar_arreglo(int arreglo[], int largo, nodo_t* lista, int recorre)
{
    if(recorre < largo)
    {
        lista = insertar_al_final(lista, arreglo[recorre]);
        pasar_arreglo(arreglo ,largo, lista, recorre + 1);
    }
    
    return lista;
}

/**
 * La funcion recorre una lista nodo por nodo e imprime su valor.
 *  @param lista es la lista que se va a imprimir
 *  @pre tiene que ser una lista valida. 
 *  @post se espera que se impriman los nodos de una lista.
 */

void imprimir_lista(nodo_t* lista)
{
    nodo_t* nodoactual = lista;//Esto recorre la lista.
    
    while (nodoactual != NULL) 
    {
        printf("VALOR: %d\n", nodoactual->dato);
        nodoactual = nodoactual->siguiente;
    }
}


/**
 * La funcion inserta un nodo al final de la lista 
 *  @param valor es el valor que se va a guardar en el nodo
 *  @pre tiene que ser un numero entero
 *  @param lista es la lista donde se va a guardar el nodo
 *  @pre tiene que ser una lista valida.
 *  @returns retorna NULL en caso de no haber podido asignar memoria para el nodo o retorna la lista con el nuevo nodo.
 *  @post se espera que se agregue un nodo al final de la lista.
 */


nodo_t* insertar_al_final(nodo_t* lista, int valor)
{
    nodo_t* nuevo_nodo = crear_nodo(valor);//Creo el nodo que va a ir al final
    nodo_t* recorre_nodo = lista;//Este nodo va a recorrer la lista.
    
    if(nuevo_nodo != NULL)//Si se pudo crear
    {
        
        if(lista != NULL)//Si la lista no esta vacia.
        {
            nuevo_nodo->siguiente = NULL; // Establece el siguiente del nuevo nodo como NULL
            
            while(recorre_nodo->siguiente != NULL)//Esto va a recorrer la lista hasta encontrar el nodo que apunta a null, que es el ultimo.
            {
                recorre_nodo = recorre_nodo->siguiente;//Al nodo que apunta, es el nodo actual.
            }
            
            //Cuando llegue a null, estoy al final.
            
            recorre_nodo->siguiente = nuevo_nodo;//Apunta al final, esto es por que el recorre_nodo, estaria iterando la lista, entonces en la ultima posicion apunta al nuevo nodo.
        }
        else//Si la lista esta vacia, solo retornaria el nuevo nodo.
        {
            lista = nuevo_nodo;
        }

        
    }

    return lista;//Retorno la nueva lista.
   
}


/**
 * La funcion crea un nodo y lo retorna
 *  @param valor es el valor que se va a guardar en el nodo
 *  @pre tiene que ser un numero entero
 *  @returns retorna NULL en caso de no haber podido asignar memoria para el nodo o retorna el nodo.
 *  @post se espera que se cree un nodo
 */

nodo_t* crear_nodo(int valor)
{
    nodo_t* nuevo_nodo = (nodo_t*) malloc(sizeof(nodo_t));//Asigno memoria del tamaño de la estructura y la casteo al tipo de dato de la estructura
    
    if(nuevo_nodo != NULL)//Si la asignacion de memoria es valida
    {
        nuevo_nodo -> dato = valor;//Guardo el valor en el dato del nuevo nodo
        nuevo_nodo -> siguiente = NULL;//Siguente es null, indicando que es el ultimo nodo creado
    }
    
    return nuevo_nodo;//Retorno la estructura
}

/**
 * La funcion libera la memoria asignada.
 *  @param nodo es el nodo que se va a liberar
 *  @pre tiene que ser un puntero valido
 *  @post se libera memoria.
 */

void liberar_nodo(nodo_t* nodo)
{
    free(nodo);//Libero la memoria del nodo
}


/**
 * La funcion suma los datos de una lista de forma recursiva.
 *  @param lista es la lista de la cual se van a sumar los datos.
 *  @pre tiene que ser una lista valida.
 *  @returns retorna la suma de los datos de la lista.
 *  @post se espera que se sumen los datos de la lista.
 */
 
 
int suma_lista(nodo_t* lista)
{
    int retorno = 0;
     
    //Mientras la lista sea "valida"
    if(lista != NULL)
    {
        retorno = lista->dato + suma_lista(lista->siguiente);//Sumo el dato del nodo actual y muvo la lista al nodo que le sigue.
    }
    
    
    return retorno;
}


/**
 * La funcion calcula la longitud de una lista de forma recursiva
 *  @param lista es la lista de la cual se va a ver el largo.
 *  @pre tiene que ser una lista valida.
 *  @returns retorna el total de nodos de la lista.
 *  @post se espera que se cuenten la cantidad de nodos de una lista.
 */
 
int largo_de_lista(nodo_t* lista)
{
    int retorno = 0;
    
    if(lista!= NULL)
    {
        retorno = 1 + largo_de_lista(lista->siguiente);//Voy sumando 1 cada vez que se pueda mover.
    }
    
    return retorno;
}



/**
 * La funcion invierte una lista enlazada de forma recursiva.
 *  @param actual es el nodo actual de la lista, al principio seria el primero.
 *  @pre tiene que ser un nodo valido.
 *  @param anteiror es el nodo que le va a seguir al actual, por eso se llama con NULL
 *  @pre tiene que ser un nodo valido.
 *  @returns retorna la lista de forma invertida o NULL.
 *  @post se espera que se invierta una lista.
 */
 
nodo_t* invierte_lista(nodo_t* actual, nodo_t* anterior)
{
    nodo_t* proximo = NULL;//Esto es para guardar el siguente del nodo actual. 
    
    if (actual == NULL) //Cuando actual es nullo, o esta vacia la lista, o se llego al final
    {
        return anterior;//Seria el primero de la lista.
    }

    proximo = actual->siguiente;//Aca guardo el nodo que le sigue al actual
    actual->siguiente = anterior;//Guardo el nodo anterior como el  actual.

    return invierte_lista(proximo, actual);
}