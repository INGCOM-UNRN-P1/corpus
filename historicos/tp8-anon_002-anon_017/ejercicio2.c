

#include <stdio.h>
#include <stdlib.h>
#define VACIO -1  

typedef struct nodo {
    int dato;
    struct nodo* siguiente;
} nodo_t;

typedef struct cola {
    nodo_t* frente;
    nodo_t* final;
} cola_t;


nodo_t* crear_nodo(int valor);
cola_t* crear_cola();
void vaciar_cola(cola_t* cola);
int esta_vacia(cola_t* cola);
void encolar(cola_t* cola, int dato);
int desencolar(cola_t* cola);
int frente_cola(cola_t* cola);


int main()
{ 
    int en_linea = 1;
    
    while(en_linea == 1)
    {
        
        cola_t* cola = NULL;
        int turno = 0;
        int posicion = 0;
        int valor_eliminado = 0;
        int opcion = 0;
        int a_atender = 0;
        int esta_atendido = 0;
        int sigue_trabajo = 1;
        int cola_valida = 0;
        
        cola = crear_cola();
        
        if(cola == NULL)
        {
            printf("No se pudo crear la cola :( ");
        }
        else
        {
            while(sigue_trabajo == 1)
            {
                
                printf("¿Sacar turno? SI: (1) NO:(2) : ");
                scanf("%d",&opcion);

                if(opcion == 1)
                {
                    encolar(cola, turno);//Guardo el turno en la cola
                    posicion = turno;//Es para mostrar el turno que tiene.
                    
                    printf("Tiene el turno %d\n",turno);
                    
                    turno++;//Si se saco turno, incremento para el otro numero.
                }   
                
                //Veo si se quieren seguir sacando turnos.
                printf("¿Seguir sacando turnos? SI: (1) NO:(0) ");
                scanf("%d",&sigue_trabajo);
                
                
            }
        }
       
        
        if(cola != NULL)//Si se creo la cola
        {
            printf("----Turnos--- ");
            printf("\n");
            
            
            while(cola_valida == 0)//Cuando valga 1, va a salir.
            {
                esta_atendido = frente_cola(cola);
                
                printf("¿Se atendio a : %d ? SI(1) NO(2) ",esta_atendido);
                scanf("%d",&opcion);
                
                if(opcion == 1)//Si se atendio, lo saco de la cola
                {
                    valor_eliminado = desencolar(cola);//Elimino el primero en la cola.
                    printf("Se atendio a %d\n",valor_eliminado);
                    
                    cola_valida = esta_vacia(cola);//Veo si la cola esta vacia, para salir del while.
                }
                
            }
               
            
        }
        
        
        printf("Fin de los turnos!\n");
       
       
        //Vacio la cola
        vaciar_cola(cola);
        
        printf("¿Volver a sacar turnos? SI(1) NO(0) : ");
        scanf("%d",&en_linea);
        
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//Como para limpiar un poco la consola 
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
 * La funcion crea una cola y la retorna, en caso de no poder, retorna NULL.
 *  @returns retorna NULL en caso de no haber podido asignar memoria para la cola o retorna la cola.
 *  @post se espera que se cree una cola.
 */


cola_t* crear_cola()
{
    cola_t* nueva_cola = (cola_t*)malloc(sizeof(cola_t)); //Reservo memoria para crear la cola
    
    if (nueva_cola != NULL)//Si asigno memoria bien
    {
        nueva_cola->frente = NULL;//El frente es NULL
        nueva_cola->final = NULL;//El final es NULL
    }
    else
    {
        perror("malloc() error");
    }
    
    return nueva_cola;
}    


/**
 * La funcion libera la cola nodo por nodo.
 *  @param cola es la cola a liberar
 *  @pre tiene que ser un puntero valido.
 *  @post se espera que se libere la cola
 */

void vaciar_cola(cola_t* cola)
{
    nodo_t* nodo_a_eliminar = NULL;
    
    while (cola->frente != NULL)//Si el frente esta vacio, no hay elementos.
    {
        nodo_a_eliminar = cola->frente;//Elimina desde el frente.
        cola->frente = cola->frente->siguiente; //Muevo el puntero del frente al nodo que le sigue, asi puedo elimnar el anterior y no perder la referencia.
        free(nodo_a_eliminar); //Libero el nodo
    }

    free(cola);//Libero la cola.
}


/**
 * La funcion comprueba si la cola esta vacia o no.
 *  @param cola que se verifica si esta vacia.
 *  @pre tiene que ser un puntero valido.
 *  @returns retorna 1 indicando que esta vacia, o 0 indicando que no lo esta.
 *  @post se espera que verifique si la cola esta vacia o no.
 */

int esta_vacia(cola_t* cola)
{
    return (cola->frente == NULL);//Retorno comparacion del frente de la cola con NULL, 1 indica que esta vacia y 0 que no.
}


/**
 * La funcion agrega un nodo al final de la cola. Si la cola esta vacia, se agrega el nodo como frente y final de la cola. En caso de no poder agregarlo no modifica nada.
 *  @param cola es donde se va a agregar el nuevo nodo con el dato.
 *  @pre tiene que ser un puntero valido.
 *  @param dato es el dato que se va a agregar.
 *  @pre tiene que ser un numero entero.
 *  @post se espera que se agregue un elemento a la cola.
 */
 
//Agregar al final 
void encolar(cola_t* cola, int dato)
{
    nodo_t* nuevo_nodo = crear_nodo(dato);//Esto agrega un nodo al final de la cola.
    
    if(nuevo_nodo != NULL)//Si se pudo crear
    {
        nuevo_nodo->dato = dato;//Guardo el dato en el nodo.
        nuevo_nodo->siguiente = NULL; //Hago que siguiente apunte a NULL, marcando que es el final.

        if(cola->frente == NULL)//Si el frente esta vacio, significa que no hay elementos, por lo que solo agrego el nodo.
        {
            cola->frente = nuevo_nodo;//El frente y final son el unico nodo.
            cola->final = nuevo_nodo;
        }
        else
        {
            cola->final->siguiente = nuevo_nodo;//Esto conecta el nuevo nodo a la cola.
            cola->final = nuevo_nodo; //Aca el puntero del final, ahora apunta al ultimo nodo que se creo.
        }
    }
    else
    {
        perror("crear_nodo() error.");
    }

    
}


/**
 * La funcion quita le primer nodo de una cola y retorna el dato eliminado, en caso de que la cola este vacia, retorna -1 indicando error.
 *  @param cola es donde se va a quitar el primer nodo.
 *  @pre tiene que ser un puntero valido.
 *  @return retorna -1 si la cola esta vacia o retorna el dato del nodo que se elimino.
 *  @post se espera que se elimine el primer nodo de la cola.
 */
 

//Sacar el del frente.
int desencolar(cola_t* cola)
{
    int retorno = 0;
    nodo_t* nodo_a_eliminar = cola->frente;//El primer elemento es el nodo que se elimina.

    
    if(cola->frente == NULL)//Si esta vacia
    {
        retorno = VACIO;//Retorna que no se pudo desencolar
    }
    else//Si no, saco el frente, que es el primer nodo.
    {
        retorno = cola->frente->dato;//Si no hay error, el retorno es el valor eliminado.
        
        cola->frente = cola->frente->siguiente;//Esto hace que el frente ahora sea el proximo nodo al que estaba apuntando (por eso el frente-> siguiente), esto sacaria el nodo a eliminar de la cola
        
        free(nodo_a_eliminar);//Elimino el nodo 
    }
    
    
    return retorno;//Retorna el error(si es que hubo)
}

/**
 * La funcion retorna el dato del primer nodo, en caso de que no haya primer nodo en la cola, devuelve -1, indicando que eta vacia.
 *  @param cola es donde se va a leer el dato del primer nodo
 *  @pre tiene que ser un puntero valido.
 *  @return retorna -1 si la cola esta vacia o retorna el dato del primer nodo.
 *  @post se espera que se retorne el dato del primer nodo.
 */
 
int frente_cola(cola_t* cola)
{
    int dato_frente = 0;//Aca voy a guardar el dato del nodo.
    
    if(cola->frente == NULL)//Si esta vacia.
    {
        dato_frente = VACIO;//El retorno es que esta vacio.
    }
    else
    {
        dato_frente = cola->frente->dato; //Aca guardo el dato del frente de la cola.
    }
    
    return dato_frente;//Retorno el dato (o vacio)
}