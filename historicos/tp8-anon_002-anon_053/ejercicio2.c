

#include <stdio.h>
#include <stdlib.h>

#define ERROR 1
#define VACIA -1

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

cola_t* crear_cola();
int esta_vacia(cola_t* cola);
void encolar(cola_t* cola, int dato);
int desencolar(cola_t* cola);
int frente_cola(cola_t* cola);
void vaciar_cola(cola_t* cola);


int main() 
{
    cola_t* la_cola = crear_cola();

    encolar(la_cola, 1);
    encolar(la_cola, 2);
    encolar(la_cola, 3);

    printf("Frente de la cola: %d\n", frente_cola(la_cola));

    printf("Desencolando elementos: ");
    while (!esta_vacia(la_cola)) 
    {
        printf("%d ", desencolar(la_cola));
    }
    printf("\n");

    vaciar_cola(la_cola);

    return 0;
}


cola_t* crear_cola() 
{
    int salida = 0;
    cola_t* nueva_cola = (cola_t*)malloc(sizeof(cola_t));
    if (nueva_cola == NULL) 
    {
        salida = ERROR; //error si no se puede asignar memoria
    }
    nueva_cola->frente = NULL;
    nueva_cola->final = NULL;
    return nueva_cola;
}


int esta_vacia(cola_t* cola) 
{
    return cola->frente == NULL;
}


void encolar(cola_t* cola, int dato) 
{
    int salida = 0;
    nodo_t* nuevo_nodo = (nodo_t*)malloc(sizeof(nodo_t));
    if (nuevo_nodo == NULL) 
    {
        salida = ERROR; // error si no se puede asignar memoria
    }
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = NULL;
    if (cola->final == NULL) 
    {
        // Si la cola está vacía, el nuevo nodo es tanto el frente como el final de la cola
        cola->frente = nuevo_nodo;
        cola->final = nuevo_nodo;
    } 
    else 
    {
        // Si la cola no está vacía, enlazar el nuevo nodo al final y actualizar el puntero al final
        cola->final->siguiente = nuevo_nodo;
        cola->final = nuevo_nodo;
    }
}


int desencolar(cola_t* cola) 
{
    int valor = 0;
    if (esta_vacia(cola)) 
    {
        valor = VACIA; // la cola está vacía
    }
    // Obtiene el valor del frente de la cola y mueve el puntero al frente
    valor = cola->frente->dato;
    nodo_t* temp = cola->frente;
    cola->frente = cola->frente->siguiente;
    free(temp); // Liberar la memoria del nodo desencolado
    if (cola->frente == NULL) 
    {
        cola->final = NULL; // Si la cola está vacía, también actualizar el puntero al final
    }
    return valor;
}


int frente_cola(cola_t* cola) 
{
    int salida = 0;
    if (esta_vacia(cola)) 
    {
        salida = VACIA; // la cola está vacía
    }
    return cola->frente->dato;
}


void vaciar_cola(cola_t* cola) 
{
    while (!esta_vacia(cola)) 
    {
        desencolar(cola);
    }
    free(cola); // Libera la memoria de la estructura de la cola
}


