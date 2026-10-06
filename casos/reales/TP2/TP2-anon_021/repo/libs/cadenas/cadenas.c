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

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    size_t longitud = 0 ;
    if (cadena == NULL || capacidad == 0)
    {
        longitud = 0;
    }
    else
    {
        for (size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
        {
            longitud = longitud + 1 ;
        }
    }
    return longitud;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    bool exito = false;
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        exito= false;
    }
    else
    {
        size_t indice = 0;
        while (indice < capacidad -1 && origen[indice] != '\0')
        {
            destino[indice] = origen[indice];
            indice = indice +1;
        }
        destino[indice]='\0';
        if (origen[indice] == '\0')
        {
            exito = true;
        }
        else
        {
            exito = false;
        }
    }        
    return exito;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    bool exito = false;
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        exito = false;
    }
    else
    {
        size_t indice_destino = 0;
        while (indice_destino < capacidad && destino [indice_destino] != '\0')//Busco final del texto actual en el destino '\0'
        {
            indice_destino = indice_destino + 1;
        }
        if (indice_destino >= capacidad)//si destino ya estaba lleno o malformado
        {
            exito = false;
        }
        else
        {
            size_t indice_origen = 0;
            while (indice_destino < capacidad - 1 && origen [indice_origen] != '\0')
            {
                destino[indice_destino] = origen[indice_origen];
                indice_destino= indice_destino + 1;
                indice_origen = indice_origen + 1;
            }
            destino[indice_destino]= '\0';//pongo si o si el terminador nulo en la ultima posicion segura
            if (origen[indice_origen]== '\0')//verifico que si alcanzo el final del origen
            {
                exito = true;
            }
            else
            {
                exito = false;
            }
        }
    }
        
    return exito;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t conteo_conversiones = 0;
    if (cadena == NULL || capacidad == 0)
    {
        conteo_conversiones = 0;
    }
    else
    {
        for (size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
        {
            if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - ('a' -'A');//reste diferencia entre a y A para conversion
                conteo_conversiones = conteo_conversiones + 1;
            }
        }
    }
    return conteo_conversiones;
}

bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad)
{
    bool estado = false;
    if (destino == NULL || origen == NULL || capacidad == 0 )
    {
        estado = false;
    }
    else
    {
        size_t indice_origen = 0;
        while (indice_origen < inicio && origen[indice_origen] != '\0')
        {
            indice_origen = indice_origen + 1;
        }
        
        if (origen[indice_origen] == '\0')//si inicio supera o coincide con el final del origen
        {
            destino[0] = '\0'; //dejo destino como cadena vacia
            estado = true;
        }
        else
        {
            size_t indice_destino = 0;
            size_t contador_cantidad = 0;
            while (indice_destino < capacidad -1 && contador_cantidad < cantidad && origen[indice_origen]!= '\0')
            {
                destino[indice_destino]= origen[indice_origen];
                indice_destino = indice_destino + 1;
                indice_origen = indice_origen +1 ;
                contador_cantidad = contador_cantidad + 1;
            }
            destino[indice_destino] = '\0';//pongo si o si termino nulo al final
            if (indice_destino < capacidad -1 || (origen[indice_origen]== '\0' || contador_cantidad == cantidad))
            {
                estado = true;
            }
            else
            {
                estado = false;
            }
        }

    }
    return estado;
}



 bool cadena_de_entero(char destino[], size_t capacidad, int valor)
 {
    bool conversion = false;
    if (destino == NULL || capacidad == 0)
    {
        conversion = false;
    }
    else
    {
        if (valor == 0)//caso especial del cero
        {
            if (capacidad >= 2)
            {
                destino[0] = '0';
                destino[1] = '\0';
                conversion = true;
            }
            else
            {
                if (capacidad >= 1)
                {
                    destino[0] = '\0';
                }
                conversion = false;
                
            }
            
        }
        else
        {
            bool es_negativo = false ; //aca manejo signo y valor absoluto seguro
            unsigned int valor_abs = 0;

            if (valor < 0)
            {
                es_negativo = true;
                if (valor == INT_MIN)
                {
                    valor_abs = (unsigned int)INT_MAX +1;
                    
                }
                else
                {
                    valor_abs = (unsigned int) (-valor);
                }
            }
            else
            {
                valor_abs = (unsigned int) valor;
            }
            size_t num_digitos = 0;
            unsigned int temporal = valor_abs;
            while (temporal > 0)
            {
                num_digitos = num_digitos + 1;
                temporal = temporal/10;
            }
            size_t longitud_total = num_digitos;
            if (es_negativo)
            {
                longitud_total = longitud_total+1;
            }
            if (longitud_total >= capacidad)
            {
                if (capacidad >= 1)
                {
                    destino[0]= '\0';
                }
                conversion = false;
                
            }
            else
            {
               size_t indice = longitud_total;
               destino[indice] = '\0';
               
               while (valor_abs > 0)
               {
                    indice = indice - 1;
                    destino[indice] = (valor_abs % 10) + '0';
                    valor_abs = valor_abs / 10;
               }
               if (es_negativo)
               {
                indice = indice -1;
                destino[indice] = '-';
               }
               conversion = true;
            }
            
        }
        
    }
    return conversion;
 }
