#include <stdio.h>
#include "funciones_seguras.h"

int lee_numero_natural(char mensaje[], unsigned short intentos)
{
    int valor;
    printf("%s", mensaje);
    for(;intentos>0;intentos--)
    {
        scanf("%d", &valor);
        if (valor>=0)
        {
            return valor;
        }
        else
        {
            printf("%d no era un numero natural, quedan %d intentos\n", valor, intentos);
        }
    }
    return SIN_INTENTOS;
}
//esta funcion lee el largo de la cadena
int largo_cadena(char *cadena, int capacidad_cadena)
{
    int res = 0;
    int i = 0;
    for(i;i<capacidad_cadena;i++)
    {
        if(cadena[i] == '\n')
        {
            res = i;
            break;
        }
        else
        {
            res = CADENACORTA;
        }
    }
    return res;
}
//esta funcion inserta una cadena dentro de otra en la posicion requerida
int insercion(char *destino, int capacidad_destino, char *insertar, int posicion)
{
    int longorigen = largo_cadena(insertar, LONGCADENA);
    int longdestino = largo_cadena(destino, LONGCADENA);
    int i = 0;
    int insetado = 0;
    char copiadora[longdestino+1];
    for(i;i<=longdestino+1;i++)
    {
        copiadora[i] = destino[posicion+i];
    }
    i = 0;
    for(i;i<=longorigen;i++)
    {
        destino[posicion+i] = insertar[i];
    }
    i = 0;
    for(i;i<=longdestino+1;i++)
    {
        destino[posicion+longorigen+i] = copiadora[i];
    }
    insetado = longdestino = largo_cadena(destino, capacidad_destino);
    return insetado;
}
//Esta funcion copia una cadena dentro de otra en la posicion indicada
int copiadora(char *origen, char *destino, int capacidad_destino)
{
    int longorigen = largo_cadena(origen, LONGCADENA);
    int i, copiado;
    for(i=0;i<=longorigen+1;i++)
    {
        destino[i] = origen[i];
    }
    copiado = largo_cadena(destino, capacidad_destino);
    return copiado;
}
//Esta funcion copia solo los caracteres alfanumericos de una cadena a otra
int limpiadora(char *origen, char *destino, int capacidad_destino)
{
    int longorigen = largo_cadena(origen, LONGCADENA);
    int i, limpio;
    for(i=0;i<=longorigen+2;i++)
    {
        int comparador = alfanumerico(origen[i]);
        if(comparador > 0)
        {
            destino[i] = origen[i];
        }
        else
        {
            destino[i] = ' ';
        }
    }
    limpio = largo_cadena(destino, capacidad_destino);
    return limpio;
}
//Esta funcion Copia los valores del origen y los devueve invertidos en destino
int inversor(char* origen, char* destino, int capacidad_destino)
{
    int longorigen = largo_cadena(origen, LONGCADENA);
    int i, invertido;
    int j = 0;
    for(i=longorigen-1;i>=0;i--)
    {
        destino[j] = origen[i];
        j++;
    }
    destino[longorigen] = '\n';
    destino[longorigen+1] = '\0';
    invertido = largo_cadena(destino, capacidad_destino);
    return invertido;
}
//Esta funcion compara como deben ir ordenadas alfabeticamente las cadenas
int compara(char* primera, char *segunda)
{
    int comparador, i, mas_larga;
    int largo1 = largo_cadena(primera, LONGCADENA);
    int largo2 = largo_cadena(segunda, LONGCADENA);
    if(largo1 >= largo2)
    {
        mas_larga = largo1;
    }
    else
    {
        mas_larga = largo2;
    }
    for(i=0;i<=mas_larga;i++)
    {
        if(primera[i] == segunda[i])
        {
            comparador = 0;
        }
        if(primera[i] < segunda[i])
        {
            comparador = -1;
            break;
        }
        if(primera[i] > segunda[i])
        {
            comparador = 1;
            break;
        }
    }
    return comparador;
}
//Esta funcion revisa que la cadena indicada sea o no sea un Palindromo
int es_palindromo(char *cadena, int largo)
{
    int longitud = largo_cadena(cadena, largo);
    int mitad, i, j, pal, busca_may;
    mitad = longitud / 2;
    j = longitud - 1;
    for(i=0;i<=LONGCADENA;i++)
    {
        busca_may = alfanumerico(cadena[i]);
        if(busca_may == 2)
        {
            cadena[i] = cadena[i] + 32;
        }
    }
    for(i=0;i<mitad;i++)
    {
        if(cadena[i] == cadena[j])
        {
            pal = 1;
            j--;
        }
        else
        {
            pal = 0;
            break;
        }
    }
    if(longitud == -1)
    {
        pal = longitud;
    }
    return pal;
}
//Esta funcion devuelve un valor de 0 o 1 si el caracter es o no alfanumerico
int alfanumerico(char caracter)
{
    int res = 0;
    if(caracter >= 'a' && caracter <= 'z')
    {
        res = 1;
    }
    if(caracter >= 'A' && caracter <= 'Z')
    {
        res = 2;
    }
    if(caracter >= 0 && caracter <= 9)
    {
        res = 3;
    }
    if(caracter == '\0' || caracter == '\n')
    {
        res = 4;
    }
    return res;
}
//Esta funcion busca una cadena dentro de otra
char* busqueda(char *cadena, int largo, char *busqueda)
{
    int i, j = 0;
    char *ptr = NULL;
    int long_busq = largo_cadena(busqueda, largo);
    while(j < largo-long_busq)
    {
        for(i=0;i<=long_busq;i++)
        {
            if(busqueda[i] == cadena[j+i])
            {
                ptr = &cadena[j];
            }
            else
            {
                ptr = NULL;
                break;
            }
            if(i == long_busq-1)
            {
                return ptr;
            }
        }
        j++;
    }
    return ptr;
}