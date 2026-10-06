/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *dest, size_t cap, const char *src)
{
    bool verificacion = false;

    if (dest != NULL && src != NULL && cap > 0)
    {
        verificacion = true;
        char *escritura = NULL;
        escritura = dest;
        const char* lectura = NULL;
        lectura = src;
        const char *limite= NULL;
        limite = dest + cap -1;

        while (*lectura != '\0' && escritura< limite)
        {
            *escritura = *lectura;
            escritura = escritura + 1;
            lectura = lectura + 1;
        }
        *escritura = '\0';//garantizo terminador nulo
        if (*lectura == '\0')//si origen termino la copia fue exitosa (sin truncamiento)
        {
            verificacion = true;
        }
        
    }
    return verificacion;
}
bool concatenar_con_punteros(char *dest, size_t cap, const char *src)
{
    bool resultado = false;
    if (dest != NULL && src != NULL && cap > 0)
    {
        char *escritura = NULL; //puntero auxiliar para saber donde termina texto en dest
        escritura = dest;
        char *limite = NULL;
        limite = dest + cap -1;
        while (*escritura != '\0' && escritura < limite)
        {
            escritura = escritura + 1;
        }
        char *lectura = NULL;
        lectura = src; //concateno si hay espacio porque escritura estaria en '\0'
        while (*lectura != '\0' && escritura < limite)
        {
            *escritura = *lectura;
            escritura = escritura +1;
            lectura = lectura +1;
        }
        *escritura = '\0'; //garantuzo terminador nulo al final
        if (*lectura == '\0')
        {
            resultado = true;
        }
        
    }
    return resultado;
    
}
size_t longitud_con_punteros(const char *s, size_t cap)
{
    size_t longitud = 0;//variable para ir almacenando tamaño
    if (s != NULL && cap > 0)
    {
        const char *ptr = NULL;//puntero constante para recorrer cadena sin modificar
        ptr = s;
        while (*ptr != '\0' && longitud < cap -1)
        {
            longitud = longitud + 1;
            ptr = ptr + 1;
        }
    }
    return longitud;
    
}