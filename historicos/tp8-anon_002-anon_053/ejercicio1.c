

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define FUERA_RANGO -2

// Definición de la estructura del nodo
typedef struct nodo 
{
    int valor;
    struct nodo* siguiente;
} nodo_t;

// Prototipos de funciones
nodo_t* crear_nodo(int valor);
void liberar_nodo(nodo_t* lista);
void insertar_al_principio(nodo_t** lista, int valor);
void insertar_al_final(nodo_t** lista, int valor);
void insertar_en_posicion(nodo_t** lista, int dato, int posicion);
void eliminar_del_principio(nodo_t** lista);
void eliminar_del_final(nodo_t** lista);
void eliminar_en_posicion(nodo_t** lista, int posicion);
int tamano_lista(nodo_t* lista);
int es_lista_vacia(nodo_t* lista);
int obtener_valor_en_posicion(nodo_t* lista, int posicion);
void imprimir_lista(nodo_t* lista);
void fusionar_lista(nodo_t** lista_1, nodo_t* lista_2);
void ordenar_ascendente(nodo_t** lista);
void ordenar_descendente(nodo_t** lista);

int main() 
{
    nodo_t* lista = NULL;
    
    insertar_al_final(&lista, 3);
    insertar_al_final(&lista, 1);
    insertar_al_final(&lista, 4);
    insertar_al_final(&lista, 2);

    printf("Lista original: ");
    imprimir_lista(lista);

    insertar_en_posicion(&lista, 10, 2);
    printf("Lista después de insertar 10 en la posición 2: ");
    imprimir_lista(lista);

    eliminar_en_posicion(&lista, 3);
    printf("Lista después de eliminar el elemento en la posición 3: ");
    imprimir_lista(lista);

    printf("Valor en la posición 1: %d\n", obtener_valor_en_posicion(lista, 1));

    nodo_t* lista2 = NULL;
    insertar_al_final(&lista2, 8);
    insertar_al_final(&lista2, 5);
    insertar_al_final(&lista2, 7);

    printf("Segunda lista: ");
    imprimir_lista(lista2);

    fusionar_lista(&lista, lista2);
    printf("Lista después de fusionar con la segunda lista: ");
    imprimir_lista(lista);

    ordenar_ascendente(&lista);
    printf("\nLista ordenada ascendentemente: ");
    imprimir_lista(lista);

    ordenar_descendente(&lista);
    printf("Lista ordenada descendente: ");
    imprimir_lista(lista);

    liberar_nodo(lista);

    return 0;
}



nodo_t* crear_nodo(int valor) 
{
    int salida = 0;
    nodo_t* nuevo_nodo = (nodo_t*)malloc(sizeof(nodo_t));
    if (nuevo_nodo == NULL) 
    {
        salida = ERROR;
    }
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}



void liberar_nodo(nodo_t* lista) 
{
    while (lista != NULL) 
    {
        nodo_t* temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
}


void insertar_al_principio(nodo_t** lista, int valor) 
{
    nodo_t* nuevo_nodo = crear_nodo(valor);
    nuevo_nodo->siguiente = *lista;
    *lista = nuevo_nodo;
}


void insertar_al_final(nodo_t** lista, int valor) 
{
    nodo_t* nuevo_nodo = crear_nodo(valor);
    if (*lista == NULL) 
    {
        *lista = nuevo_nodo;
    } 
    else 
    {
        nodo_t* temp = *lista;
        while (temp->siguiente != NULL) 
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo_nodo;
    }
}


void insertar_en_posicion(nodo_t** lista, int dato, int posicion) 
{
    int salida = 0;
    if (posicion == 0) 
    {
        insertar_al_principio(lista, dato);
    }
    nodo_t* nuevo_nodo = crear_nodo(dato);
    nodo_t* temp = *lista;

    for (int i = 0; i < posicion - 1 && temp != NULL; i++) 
    {
        temp = temp->siguiente;
    }
    if (temp == NULL) 
    {
        salida = FUERA_RANGO;
        free(nuevo_nodo);
    }

    nuevo_nodo->siguiente = temp->siguiente;
    temp->siguiente = nuevo_nodo;
}


void eliminar_en_posicion(nodo_t** lista, int posicion) 
{
    int salida = 0;
    if (*lista == NULL) 
    {
        salida = ERROR;//lista vacia 
    }

    nodo_t* temp = *lista;
    if (posicion == 0) 
    {
        *lista = temp->siguiente;
        free(temp);
    }
    for (int i = 0; temp != NULL && i < posicion - 1; i++) 
    {
        temp = temp->siguiente;
    }
    if (temp == NULL || temp->siguiente == NULL) 
    {
        salida = FUERA_RANGO;
    }

    nodo_t* nodo_a_eliminar = temp->siguiente;
    temp->siguiente = nodo_a_eliminar->siguiente;
    free(nodo_a_eliminar);
}


int tamano_lista(nodo_t* lista) 
{
    int tamano = 0;
    while (lista != NULL) 
    {
        tamano++;
        lista = lista->siguiente;
    }
    return tamano;
}


int es_lista_vacia(nodo_t* lista) 
{
    return lista == NULL;
}


int obtener_valor_en_posicion(nodo_t* lista, int posicion) 
{
    int salida = 0;
    if (posicion < 0 || lista == NULL || posicion >= tamano_lista(lista)) 
    {
        salida = FUERA_RANGO;
    }
    for (int i = 0; i < posicion; i++) 
    {
        lista = lista->siguiente;
    }
    return lista->valor;
}


void imprimir_lista(nodo_t* lista) 
{
    while (lista != NULL) 
    {
        printf("%d ", lista->valor);
        lista = lista->siguiente;
    }
    printf("\n");
}


void fusionar_lista(nodo_t** lista_1, nodo_t* lista_2) 
{
    if (*lista_1 == NULL) 
    {
        *lista_1 = lista_2;
    } 
    else 
    {
        nodo_t* temp = *lista_1;
        while (temp->siguiente != NULL) 
        {
            temp = temp->siguiente;
        }
        temp->siguiente = lista_2;
    }
}


void ordenar_ascendente(nodo_t** lista) 
{
    int salida = 0;
    if (*lista == NULL || (*lista)->siguiente == NULL) 
    {
        salida = ERROR;
    }
    nodo_t* i = *lista;
    while (i != NULL) 
    {
        nodo_t* j = i->siguiente;
        while (j != NULL) 
        {
            // Si el valor de i es mayor que el valor de j, intercambiar los valores
            if (i->valor > j->valor) 
            {
                intercambiar_valores(&(i->valor), &(j->valor));
            }
            j = j->siguiente;
        }
        i = i->siguiente;
    }
}


void ordenar_descendente(nodo_t** lista) 
{
    int salida = 0;
    if (*lista == NULL || (*lista)->siguiente == NULL) 
    {
        salida = ERROR;
    }
    nodo_t* i = *lista;
    while (i != NULL) 
    {
        nodo_t* j = i->siguiente;
        while (j != NULL) 
        {
            // Si el valor de i es menor que el valor de j, intercambiar los valores
            if (i->valor < j->valor) 
            {
                intercambiar_valores(&(i->valor), &(j->valor));
            }
            j = j->siguiente;
        }
        i = i->siguiente;
    }
}


