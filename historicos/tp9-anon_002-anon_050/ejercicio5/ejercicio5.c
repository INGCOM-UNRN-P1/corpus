



#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int datos;
    struct Nodo *siguiente;
};

struct Nodo *arreglo_a_lista(int arre[], int tamaño)
{
    if (tamaño == 0)
    {
        return NULL;
    }
    else 
    {
        struct Nodo *cabezera = (struct Node *) malloc(sizeof(struct Nodo));
        cabezera->datos = arre[0];
        cabezera->siguiente = arreglo_a_lista(arre + 1, tamaño - 1);
        return cabezera;
    }
}

int sumar_lista(struct Nodo *cabezera)
{
    int ret;
    if (cabezera == NULL)
    {
        ret = 0;
    }
    else
    {
        ret = cabezera->datos + sumar_lista(cabezera->siguiente);
    }
    return ret;
}

int largo_lista(struct Nodo *cabezera)
{
    int ret;
    if (cabezera == NULL)
    {
        ret = 0;
    }
    else 
    {
        ret = 1 + largo_lista(cabezera->siguiente);
    }
    return ret;
}

struct Nodo *invertir_lista(struct Nodo *cabezera)
{
    if (cabezera == NULL || cabezera->siguiente == NULL)
    {
        return cabezera;
    }
    else 
    {
        struct Nodo *resto = invertir_lista(cabezera->siguiente);
        cabezera->siguiente->siguiente = cabezera;
        cabezera->siguiente = NULL;
        return resto;
    }
}

void mostrar_lista(struct Nodo *cabezera)
{
    while (cabezera != NULL)
    {
        printf("%d ", cabezera->datos);
        cabezera = cabezera->siguiente;
    }
    printf("\n");
}

int main()
{
    int arre[] = {1, 2, 3, 4, 5};
    int tamaño = sizeof(arre) / sizeof(arre[0]);
    struct Nodo *lista = arreglo_a_lista(arre, tamaño);
    printf("Lista: ");
    mostrar_lista(lista);
    printf("Suma de elementos: %d\n", sumar_lista(lista));
    printf("Longitud de la lista: %d\n", largo_lista(lista));
    printf("Lista invertida: ");
    mostrar_lista(invertir_lista(lista));
    return 0;
}