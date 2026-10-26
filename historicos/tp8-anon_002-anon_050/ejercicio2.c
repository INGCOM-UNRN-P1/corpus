



#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo* siguiente;
} nodo_t;

typedef struct cola
{
    nodo_t* frente;
    nodo_t* final;
} cola_t;

/**
 * Crea una cola vacía.
 * @return Puntero a la cola recién creada.
 */
cola_t* crear_cola()
{
    cola_t* nueva_cola = (cola_t*)malloc(sizeof(cola_t));
    nueva_cola->frente = NULL;
    nueva_cola->final = NULL;
    return nueva_cola;
}

/**
 * Verifica si la cola está vacía.
 * @param cola Puntero a la cola.
 * @return 1 si la cola está vacía, 0 si no lo está.
 */
int esta_vacia(cola_t* cola)
{
    return cola->frente == NULL;
}

/**
 * Agrega un elemento al final de la cola.
 * @param cola Puntero a la cola.
 * @param dato Valor a encolar.
 * @pre La cola debe estar inicializada.
 * @post Un nuevo nodo con el valor dado se agrega al final de la cola.
 */
void encolar(cola_t* cola, int dato)
{
    nodo_t* nuevo_nodo = (nodo_t*)malloc(sizeof(nodo_t));
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = NULL;
    if (esta_vacia(cola))
    {
        cola->frente = nuevo_nodo;
        cola->final = nuevo_nodo;
    }
    else
    {
        cola->final->siguiente = nuevo_nodo;
        cola->final = nuevo_nodo;
    }
}

/**
 * Elimina el elemento del frente de la cola.
 * @param cola Puntero a la cola.
 * @pre La cola no debe estar vacía.
 * @post El primer nodo de la cola es eliminado.
 * @return Valor del nodo eliminado.
 */
int desencolar(cola_t* cola)
{
    if (esta_vacia(cola))
    {
        printf("La cola ya está vacía.\n");
        return -1;
    }
    nodo_t* temp = cola->frente;
    int dato = temp->dato;
    cola->frente = cola->frente->siguiente;
    free(temp);
    return dato;
}

/**
 * Obtiene el valor del elemento del frente de la cola sin eliminarlo.
 * @param cola Puntero a la cola.
 * @pre La cola no debe estar vacía.
 * @return Valor del nodo en el frente de la cola.
 */
int frente_cola(cola_t* cola)
{
    if (esta_vacia(cola))
    {
        printf("La cola ya está vacía.\n");
        return -1;
    }
    return cola->frente->dato;
}

/**
 * Vacía la cola liberando la memoria ocupada por todos los nodos.
 * @param cola Puntero a la cola.
 * @post Todos los nodos de la cola son liberados de la memoria.
 */
void vaciar_cola(cola_t* cola)
{
    while (!esta_vacia(cola))
    {
        desencolar(cola);
    }
}

int main()
{
    cola_t* farmacia = crear_cola();
    

    encolar(farmacia, 1);
    encolar(farmacia, 2);
    encolar(farmacia, 3);
    encolar(farmacia, 4);

    printf("Cliente actual en la farmacia: %d\n", frente_cola(farmacia));

    int cliente_atendido = desencolar(farmacia);
    printf("Cliente atendido: %d\n", cliente_atendido);

    printf("Siguiente cliente en la farmacia: %d\n", frente_cola(farmacia));

    vaciar_cola(farmacia);
    free(farmacia);

    return 0;
}
