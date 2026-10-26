

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
    int dato;
    struct nodo* siguiente;
}nodo_t;


nodo_t* crear_nodo(int valor);
void liberar_nodo(nodo_t* nodo);
nodo_t* insertar_al_principio(nodo_t* lista, int valor);
nodo_t* insertar_al_final(nodo_t* lista, int valor);
nodo_t* insertar_en_posicion(nodo_t* lista, int dato, int posicion);
nodo_t* eliminar_del_principio(nodo_t* lista);
nodo_t* eliminar_del_final(nodo_t* lista);
nodo_t* eliminar_en_posicion(nodo_t* lista, int posicion);
int tamano_lista(nodo_t* lista);
int es_lista_vacia(nodo_t* lista);
int obtener_valor_en_posicion(nodo_t* lista, int posicion);
void imprimir_lista(nodo_t* lista);
nodo_t* fusionar_lista(nodo_t* lista_1, nodo_t* lista_2);
nodo_t* ordenar_ascendente(nodo_t* lista);
nodo_t* ordenar_descendente(nodo_t* lista);

int main()
{
    int valor = 0;
    int posicion = 0;
    int largo = 0;
    int opcion = 0;
    int numero = 0;
    int cantidad = 0;
    int contador = 0;
    int orden = 0;
    
    
    
    nodo_t* lista =NULL;
    nodo_t* lista_2 = NULL;
    nodo_t* nuevo_nodo = NULL;
    nodo_t* lista_fusionada = NULL;
    
    printf("Ordenar archivo (1) o usar listas (2): ");
    scanf("%d",&opcion);
    
    if(opcion == 1)
    {
        FILE *nombre_archivo = fopen("numeros.txt","r");//Abro el archivo en modo lectura 
        
        if(nombre_archivo != NULL)
        {
            fscanf(nombre_archivo, "%d", &cantidad);//El primer numero es la cantidad de elementos.
            
            fscanf(nombre_archivo, "%d", &valor);//Aca guardo el valor del archivo para crear el primer nodo
            lista = crear_nodo(valor);//Esto es para incializar la lista, no guardo la cantidad por que no quiero que este.
            
            
            for(contador = 0; contador < cantidad-1; contador++ )//recorro el archivo y voy guardando los numeros., Le resto 1 a cantidad por que guarda el ultimo valor 2 veces
            {
                fscanf(nombre_archivo, "%d", &valor);//Aca guardo el valor del archivo.
                lista = insertar_al_final(lista, valor);//Voy guardando en los nodos los numeros del archivo, al final de la lista.
                
            }
            imprimir_lista(lista);
            
            fclose(nombre_archivo);//Cierro el archivo.
                
            printf("Ordenar el archivo en ascendente(1) o descendente(2) : ");
            scanf("%d",&orden);
            
            
            FILE* nuevo_archivo = fopen("numeros.txt","w");//W para reescribir el archivo
            
            if(nuevo_archivo != NULL)
            {
                if(orden == 1)
                {           
                    lista = ordenar_ascendente(lista);//Ordeno la lista
                                    
                    nodo_t* nodo_contador = lista;
                    
                    fprintf(nuevo_archivo,"%d", cantidad);//Guardo la cantidad como primer dato
                    
                    while(nodo_contador != NULL)//Recorro la lista
                    {
                        fprintf(nuevo_archivo, "\n");//Imprimo un salto de linea en el archivo
                        fprintf(nuevo_archivo,"%d",nodo_contador->dato);//Imprimo el dato de la lista.
                        nodo_contador = nodo_contador ->siguiente;
                    }
                }
                else if(orden == 2)
                {
                                
                    lista = ordenar_descendente(lista);//Ordeno la lista.
                    
                    nodo_t* nodo_contador = lista;
                    
                    fprintf(nuevo_archivo,"%d", cantidad);//Guardo la cantidad como primer dato
                    
                    while(nodo_contador != NULL)//Recorro la lista
                    {
                        fprintf(nuevo_archivo, "\n");//Imprimo un salto de linea en el archivo
                        fprintf(nuevo_archivo,"%d",nodo_contador->dato);//Imprimo el dato de la lista.
                        nodo_contador = nodo_contador ->siguiente;
                    }
                                
                }
                else
                {
                    printf("No es una opcion.\n");
                }


                fclose(nuevo_archivo);//Cierro el nuevo archivo.
            }
            else
            {
                perror("No se pudo abrir el archivo");
            }
                        
            
        
        }
        else
        {
            perror("No se pudo abrir el archivo");
        }
        
        
    }
    else if(opcion == 2)
    {
        printf("Valor del primer nodo : ");
        scanf("%d",&valor);
        
        
        lista = crear_nodo(valor);
        lista_2 = crear_nodo(valor);
        
        
        printf("Ingrese un valor para insertar al principio de la lista: ");
        scanf("%d",&valor);
        
        lista = insertar_al_principio(lista, valor);
        
        //Esto es para fusionar la lista.
        lista_2 = insertar_al_final(lista_2, 99);
        lista_2 = insertar_al_final(lista_2, 98);
        lista_2 = insertar_al_final(lista_2, 97);
        
        printf("Ingrese un valor para insertar al final de la lista: ");
        scanf("%d",&valor);
        
        lista = insertar_al_final(lista, valor);
        
        
        printf("Ingrese una posicion para insertar en lista: ");
        scanf("%d",&posicion);
        
        printf("Ingrese un valor para insertar en la posicion [%d] de la lista: ",posicion);
        scanf("%d",&valor);
        
        
        lista = insertar_en_posicion(lista, valor, posicion); 
        
        
        printf("Ingrese una posicion para obtener su valor en lista: ");
        scanf("%d",&posicion);
        
        
        valor = obtener_valor_en_posicion(lista, posicion);
        
        printf("El valor en la posicion [%d] es : %d\n",posicion, valor);
        
        largo = es_lista_vacia(lista);
        
        
        if(largo == 1)
        {
            printf("La lista esta vacia\n");
        }
        else
        {
            printf("La lista no esta vacia\n");
        }
        
        
        lista_fusionada = fusionar_lista(lista, lista_2);
        largo = tamano_lista(lista);
        
        printf("El largo de la lista es de %d nodo/s\n",largo);
        
        
        printf("Ingrese la posicion a eliminar: ");
        scanf("%d",&posicion);
        
        lista = eliminar_en_posicion(lista, posicion);
        
        lista = eliminar_del_principio(lista);
        lista = eliminar_del_final(lista);
    }
    else
    {
        printf("No es una opcion valida.");
    }
    
    
    

    // Libero los nodos 1 por 1
    while (lista != NULL)
    {
        nodo_t* nodo_eliminar = lista;
        lista = lista->siguiente;
        liberar_nodo(nodo_eliminar);
    }
    //Libero lista2
    while (lista_2 != NULL)
    {
        nodo_t* nodo_eliminar = lista;
        lista = lista->siguiente;
        liberar_nodo(nodo_eliminar);
    }
    //Libero lista fusionada.
    while (lista_fusionada != NULL)
    {
        nodo_t* nodo_eliminar = lista;
        lista = lista->siguiente;
        liberar_nodo(nodo_eliminar);
    }
    
 
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
    if(nodo != NULL)//Si es diferente a NULL
    {
        free(nodo);//Libero la memoria del nodo
    }        
}


/**
 * La funcion inserta un nodo al principio de la lista 
 *  @param valor es el valor que se va a guardar en el nodo
 *  @pre tiene que ser un numero entero
 *  @param lista es la lista donde se va a guardar el nodo
 *  @pre tiene que ser una lista valida.
 *  @returns retorna NULL en caso de no haber podido asignar memoria para el nodo o retorna la lista con el nuevo nodo.
 *  @post se espera que se agregue un nodo al principio de la lista.
 */

nodo_t* insertar_al_principio(nodo_t* lista, int valor)
{
    nodo_t* nuevo_nodo = crear_nodo(valor);
    
    if(nuevo_nodo != NULL)//Veo que se haya podido crear el nodo.
    {       
        nuevo_nodo->dato = valor;//Copio el valor en el nuevo nodo.
        
        nuevo_nodo->siguiente = lista;//El siguiente del nuevo nodo va a apuntar al principio de la lista.
        
        lista = nuevo_nodo; //La lista es el nuevo nodo, saque lo de apuntar por que al salir de la funcion perderia la referencia.
        
    }
    
    return lista;

    
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
    
    nuevo_nodo->siguiente = NULL; // Establece el siguiente del nuevo nodo como NULL
    
    while(recorre_nodo->siguiente != NULL)//Esto va a recorrer la lista hasta encontrar el nodo que apunta a null, que es el ultimo.
    {
        recorre_nodo = recorre_nodo->siguiente;//Al nodo que apunta, es el nodo actual.
    }
    
    //Cuando llegue a null, estoy al final.
    
    recorre_nodo->siguiente = nuevo_nodo;//Apunta al final, esto es por que el recorre_nodo, estaria iterando la lista, entonces en la ultima posicion apunta al nuevo nodo.
    
    return lista;//Retorno la nueva lista.
   
}

/**
 * La funcion inserta un nodo en una posicion de la lista, en caso de que la posicion sea mayor al largo, se insertara a lo ultimo.
 *  @param valor es el dato que se va a guardar en el nodo
 *  @pre tiene que ser un numero entero
 *  @param lista es la lista donde se va a guardar  el nodo
 *  @pre tiene que ser una lista valida. 
 *  @param posicion es la posicion donde se va a insertar el nodo.
 *  @pre tiene que ser un numero entero positivo
 *  @returns retorna NULL en caso de no haber podido asignar memoria para el nodo o retorna la lista con el nuevo nodo.
 *  @post se espera que se agregue un nodo en una posiscion de la lista.
 */
 
nodo_t* insertar_en_posicion(nodo_t* lista, int dato, int posicion)
{
    nodo_t* nuevo_nodo = crear_nodo(dato);//Creo el nodo que va a ir en la posicion seleccionada.
    nodo_t* recorre_nodo = lista;//Este nodo va a recorrer la lista, para ver si se pasa de largo.
    int contador = 0;//Cuenta las posiciones.
    
    
    if(nuevo_nodo != NULL)//Si pudo crear el nuevo nodo, sigue.
    {
        if(posicion == 0)//Si es la posicion 0, inserta al principio.
        {
            nuevo_nodo->siguiente = lista;
            lista = nuevo_nodo;
        }
        else
        {
            //Este while va moviendo el nodo hasta la posicion, o hasta que no hayan mas nodos.
            while(recorre_nodo->siguiente != NULL && contador < posicion - 1)//Posicion -1 por que si no se pasa de largo.
            {
                recorre_nodo = recorre_nodo->siguiente;
                contador++;
            }
            
            //Cuando sale del bucle, o llego al final de los nodos, o a la posicion deseada.
            
            
            nuevo_nodo->siguiente = recorre_nodo->siguiente;
            recorre_nodo->siguiente = nuevo_nodo;
        }
    }
    
    return lista;
      
}

/**
 * La funcion elimina el primer nodo de una lista.
 *  @param lista es la lista de donde se va a eliminar el nodo.
 *  @pre tiene que ser una lista valida. 
 *  @returns retorna NULL en caso de que no quede lista, o la lista sin la primera posicion.
 *  @post se espera que se elimine el primer nodo de la lista.
 */
 
nodo_t* eliminar_del_principio(nodo_t* lista)
{
    nodo_t* nodo_a_eliminar = lista;//El nodo que se elimina.
    
    lista = lista->siguiente;//hago que la empieze en el otro nodo.
    
    liberar_nodo(nodo_a_eliminar);//Borro el nodo.
    
    return lista;
    
}


/**
 * La funcion elimina el ultimo nodo de una lista.
 *  @param lista es la lista de donde se va a eliminar el nodo.
 *  @pre tiene que ser una lista valida. 
 *  @returns retorna NULL en caso de que no quede lista, o la lista sin la ultima posicion.
 *  @post se espera que se elimine el ultimo nodo de la lista.
 */
 
 
nodo_t* eliminar_del_final(nodo_t* lista)
{
    nodo_t* nodo_a_eliminar = lista;//El nodo que se elimina.
    nodo_t* nodo_anterior= lista;//Esto lo voy a usar para guardar el nodo antes del NULL.
    
    
    while(nodo_a_eliminar->siguiente != NULL)
    {
        nodo_anterior = nodo_a_eliminar;//Aca guardo antes de que apunte a NULL.
        nodo_a_eliminar = nodo_a_eliminar->siguiente;//Voy moviendo el nodo que se elimina hasta que apunte a NULL, que es el ultimo nodo.
    }
    
    nodo_anterior->siguiente = NULL;//Hago que apunte a NULL.
    
    liberar_nodo(nodo_a_eliminar);//Elimina el nodo de la memoria
    
   
    
    return lista;
}

/**
 * La funcion elimina un nodo de una posicion.
 *  @param lista es la lista de donde se va a eliminar el nodo.
 *  @pre tiene que ser una lista valida. 
 *  @returns retorna la lista sin modificar en caso de que la posicion sea demasiado grande , o retorna la lista sin la posicion.
 *  @post se espera que se elimine un nodo en una posicion n de la lista.
 */
 

nodo_t* eliminar_en_posicion(nodo_t* lista, int posicion)
{
    nodo_t* nodo_a_eliminar = lista;//Este nodo va a recorrer la lista, para ver si se pasa de largo.
    nodo_t* nodo_anterior= lista;//Esto lo voy a usar para guardar el nodo antes del NULL.
    int contador = 0;//Cuenta las posiciones.
    int largo = 0;
    
    if(largo > posicion)
    {
        //Este while va moviendo el nodo hasta la posicion, o hasta que no hayan mas nodos.
        while(nodo_a_eliminar->siguiente != NULL && contador < posicion)
        {
            nodo_anterior = nodo_a_eliminar;//Para que no llegue al null.
            nodo_a_eliminar = nodo_a_eliminar->siguiente;
            contador++;
        }

            
        //Cuando sale del bucle, o llego al final de los nodos, o a la posicion deseada.
        nodo_anterior->siguiente = nodo_a_eliminar->siguiente;//Ahora el nodo anterior apunta al nodo siguiente del que va a ser eliminado.
        
        liberar_nodo(nodo_a_eliminar);//Libero el nodo de la memoria
    }
      
    return lista;
      
}

/**
 * La funcion cuenta cuantos nodos tiene una lista.
 *  @param lista es la lista de donde se cuentan los nodos.
 *  @pre tiene que ser una lista valida. 
 *  @returns retorna la cantidad de nodos de la lista.
 *  @post se espera que se cuenten los nodos de la lista..
 */


int tamano_lista(nodo_t* lista)
{
    int contador = 0;
    nodo_t* recorre_nodo = lista;
    
    
    if(lista != NULL)//Si no hay nodos, el contador queda en 0.
    {
        contador++;//Si la lista no esta vacia, significa que hay almenos 1 nodo, esto lo agrego por que si solo hay 1, el recorre_nodo->siguiente va a apuntar a NULL.
        while(recorre_nodo->siguiente != NULL)
        {
            contador++;
            recorre_nodo = recorre_nodo->siguiente; //Aca hago que se mueva el "recorre nodo" al nodo que le sigue.
        }
    }

    
    
    return contador;
    
    
}

/**
 * La funcion comprueba si una lista esta vacia o no.
 *  @param lista es la lista que se va a verificar si esta vacia.
 *  @pre tiene que ser una lista valida. 
 *  @returns retorna retorna el resultado de la comparacion de la lista con NULL, si es NULL, retorna 1, en caso contrario retorna 0.
 *  @post se espera que se elimine un nodo en una posicion n de la lista.
 */

int es_lista_vacia(nodo_t* lista)
{
    return (lista == NULL); //Si la lista es NULL, el retorno es 1, si no es NULL, el retorno es 0, se retorna la comparacion. 
}

/**
 * La funcion obtiene el valor de un nodo.
 *  @param lista es la lista de la cual se va a obtener el valor de un nodo.
 *  @pre tiene que ser una lista valida. 
 *  @param posicion es el nodo que se va a obtener su valor.
 *  @pre tiene que ser un numero entero positivo.  
 *  @returns En caso de que la posicion sea mayor al largo de la lista, retorna el valor del ultimo nodo, en caso contrario retorna el valor del nodo en la posicion.
 *  @post se espera que se retorne el valor de un nodo de la lista.
 */

int obtener_valor_en_posicion(nodo_t* lista, int posicion)
{
    nodo_t* recorre_nodo = lista;//Este nodo va a recorrer la lista.
    int contador = 0;//Cuenta hasta la posicion.
    
    while(recorre_nodo->siguiente != NULL || contador < posicion)//Esto hace que no se pase del largo de la lista, y cuando llegue a contador, es la posicion deseada.
    {
        recorre_nodo = recorre_nodo->siguiente;//Muevo el nodo "recorre".
        contador++;
    }
    
    return recorre_nodo->dato;//retorno el dato del nodo al que se llego.

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
 * La funcion fusiona 2 listas y retorna la fusion. En caso de que la primera este vacia, retorna la segunda.
 *  @param lista_1 es la lista que se va a fusionar
 *  @pre tiene que ser una lista valida.  
 *  @param lista_2 es la otra lista con la que se va a fusionar
 *  @pre tiene que ser una lista valida. 
 *  @returns retorna la fusion entre ambas listas.
 *  @post se espera que se fusione una lista con otra.
 */


nodo_t* fusionar_lista(nodo_t* lista_1, nodo_t* lista_2)
{
    nodo_t* ultimo_nodo = lista_1;//Recorre la lista hasta el ultimo nodo.
    
    
    
    if(lista_1 == NULL)
    {
        lista_1 = lista_2;
    }
    else
    {
        while(ultimo_nodo->siguiente != NULL)
        {
            ultimo_nodo = ultimo_nodo->siguiente;
        }
        
        ultimo_nodo->siguiente = lista_2; //El ultimo nodo de la lista 1 va a apuntar al primer nodo de la lista2.
    }
    
    
    return lista_1;
}

/**
 * La funcion ordena una lista de forma ascendente. 
 *  @param lista es la lista que se va a ordenar
 *  @pre tiene que ser una lista valida.  
 *  @returns retorna la lista ordenada de menor a mayor.
 *  @post se espera que se ordene la lista de forma ascendente.
 */


nodo_t* ordenar_ascendente(nodo_t* lista)
{
    nodo_t* nodo_recorre = lista;//Recorre la lista.
    nodo_t* nodo_minimo = NULL;//Aca voy a guardar el valor minimo
    nodo_t* nodo_contador = NULL;//Esto va a recorrer la lista para comparar con el otro contador.
    
    int valor_temporal = 0; //Esto es para hacer el intercambio.
    
    while(nodo_recorre != NULL)
    {
        
        nodo_minimo = nodo_recorre;//Agarro el primer nodo.
        nodo_contador = nodo_recorre->siguiente;//Esto es lo que se va a comparar con el nodo que recorre 
        
        while(nodo_contador != NULL)//Esto compara a partir del siguiente, sin contar el actual.
        {
            if(nodo_contador->dato < nodo_minimo->dato)//Si el dato que se compara es mayor, significa que el otro es menor
            {
                //Aca intercambio los valores.
                valor_temporal = nodo_recorre->dato;
                nodo_recorre->dato = nodo_contador->dato;
                nodo_contador->dato = valor_temporal;                
            }
           
            
            
            nodo_contador = nodo_contador->siguiente;//Muevo el contador
            
        }
        
        nodo_recorre = nodo_recorre->siguiente;//Muevo el contador
    }
    
    return lista;
    
}
/**
 * La funcion ordena una lista de forma descendente. 
 *  @param lista es la lista que se va a ordenar
 *  @pre tiene que ser una lista valida.  
 *  @returns retorna la lista ordenada de mayor a menor.
 *  @post se espera que se ordene la lista de forma descendente.
 */



nodo_t* ordenar_descendente(nodo_t* lista)
{
    nodo_t* nodo_recorre = lista;//Recorre la lista.
    nodo_t* nodo_max = NULL;//Aca voy a guardar el valor maximo
    nodo_t* nodo_contador = NULL;//Esto va a recorrer la lista para comparar con el otro contador.
    
    int valor_temporal = 0; //Esto es para hacer el intercambio.
    
    while(nodo_recorre != NULL)
    {
        
        nodo_max = nodo_recorre;//Agarro el primer nodo.
        nodo_contador = nodo_recorre->siguiente;//Esto es lo que se va a comparar con el nodo que recorre 
        
        while(nodo_contador != NULL)//Esto compara a partir del siguiente, sin contar el actual.
        {
            if(nodo_contador->dato > nodo_max->dato)//Si el dato que se compara es menor, significa que el otro es mayor
            {
                //Aca se hace el intercambio
                valor_temporal = nodo_recorre->dato;
                nodo_recorre->dato = nodo_contador->dato;
                nodo_contador->dato = valor_temporal;                
            }
           
            
            
            nodo_contador = nodo_contador->siguiente;//Muevo el contador
            
        }
        
        nodo_recorre = nodo_recorre->siguiente;//Muevo el contador
    }
    
    return lista;
    
}

