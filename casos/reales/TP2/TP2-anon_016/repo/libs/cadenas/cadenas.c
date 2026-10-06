/**
 * @file cadenas.c
 * @brief Esqueleto de implementación para la biblioteca libcadenas.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Las funciones provistas son esqueletos iniciales para ser completados
 * íntegramente por los estudiantes como parte de la entrega.
 */

#include "cadenas.h"
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
 if(cadena == NULL || capacidad == 0)
 {
    return 0;
 }   

 size_t contador = 0;

 while (contador < capacidad && cadena[contador] != '\0')
 {
    contador++;
 }

 return contador;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
   if(destino == NULL || origen == NULL || capacidad == 0)
   {
    return false;
   }

   size_t indice = 0;
   bool completo = true;

   while(origen[indice] != '\0' && completo)
   {
    if (indice < capacidad - 1)
    {
        destino[indice] = origen[indice];
    }
    else
    {
        completo = false;
    }
    indice++;
   }
   if(indice < capacidad)
   {
    destino[indice] = '\0';
   }
   else
   {
    destino[capacidad - 1] = '\0';
   }
   
   return completo;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if(destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    size_t largo_base = cadena_longitud(destino, capacidad);

    if(largo_base >= capacidad)
    {
        destino[capacidad - 1] = '\0';
        return false;
    }

    size_t i_origen = 0;
    size_t i_destino = largo_base;
    bool completo = true;

    while(origen[i_origen] != '\0' && completo)
    {
        if (i_destino < capacidad -1)
        {
            destino[i_destino] = origen[i_origen]; 
            i_destino++;
        }
        else
        {
            completo = false;
        }
        i_origen++;
    }

    destino[i_destino] = '\0';
    return completo;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if(cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t convertidos = 0;
    size_t indice = 0;

    while (indice < capacidad && cadena[indice] != '\0')
    {
        unsigned char c = (unsigned char)cadena[indice];

        if( c >= 'a' && c <= 'z')
        {
            cadena[indice] = (char)toupper(c);
            convertidos++;
        }
        indice++;
    }
    return convertidos; 
}



 bool cadena_subcadena(char destino[], size_t capacidad, 
                       const char origen[], size_t inicio, size_t cantidad)
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    size_t largo_origen = cadena_longitud(origen, SIZE_MAX);

    if(inicio >= largo_origen)
    {
        destino[0] = '\0';
        return true;
    }

    size_t copiados = 0;
    bool completo = true;

    while (copiados < cantidad && origen[inicio + copiados] != '\0' && completo)
    {
        if(copiados < capacidad - 1)
        {
            destino[copiados] = origen[inicio + copiados];
            copiados++;
        }
        else
        {
            completo = false;
        }
    }
    destino[copiados] = '\0';
    return completo;
}



 bool cadena_de_entero(char destino[], size_t capacidad, int valor)
 {
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    if(valor == 0)
    {
        if(capacidad < 2)
        {
            destino[0] = '\0';
            return false;
        }
        destino[0] = '0';
        destino[1] = '\0';
        return true;
    }

    if(valor == INT_MIN)
    {
        if (capacidad < 12)
        {
            destino[0] = '\0';
            return false;
        }
        const char *texto = "-2147483648";
       
        for(int i = 0; i< 12; i++)
        {
            destino[i] = texto[i];
            return true;
        }
    }

    bool negativo = false;
    int numero = valor;

    if (valor < 0)
    {
        negativo = true;
        numero = -valor;
    }

    int temp = numero;
    int digitos = 0;

    while (temp > 0)
    {
        digitos++;
        temp = temp/10;
    }

    int necesario = digitos + 1;
    if(negativo)
    {
        necesario++;
    }

    if((int)capacidad < necesario)
    {
        destino[0] = '\0';
        return false;
    }

    int pos = necesario - 1;
    destino[pos] = '\0';
    pos--;

    while(numero > 0)
    {
        int digito = numero % 10;
        destino[pos] = '0' + digito;
        numero = numero / 10;
        pos--;
    }

    if(negativo)
    {
        destino[0] = '-';
    }
    return true;

 }