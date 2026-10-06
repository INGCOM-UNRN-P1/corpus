/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen)
{
    if (origen == NULL ){
        return NULL;
    }
size_t longitud = 0;
   while (origen [longitud] != '\0'){
    longitud++;
   }
   if (longitud == 0){
    return NULL;
   }

   size_t inicio_char = 0;
   while (origen [inicio_char] == ' ' && inicio_char < longitud){
    inicio_char ++;
   }

   if (inicio_char == longitud){
    return NULL;
   }

   size_t fin_char = longitud -1;
   while (fin_char >= inicio_char && origen [fin_char] == ' '){
    fin_char--;
   }

   size_t largo_malloc = fin_char - inicio_char +1;

   char *ptr_dest = malloc((largo_malloc +1)*sizeof(char));
   if (ptr_dest == NULL){
    return NULL;

   }
   for (size_t i = 0 ; i < largo_malloc ; i++ ){
    ptr_dest [i] = origen [inicio_char + i];

   }
   ptr_dest[largo_malloc] = '\0';


    return ptr_dest;
}

char *cadena_repetir(const char *origen, size_t veces)
{
    if (origen == NULL){
        return NULL;
    }
    if (veces == 0){
        char *errror = malloc(1*sizeof(char));
        return errror;
    }
    size_t largo_or = 0;
    while(origen [largo_or] != '\0'){
        largo_or++;
    }
    size_t largo_absoluto = (largo_or * veces) +1;
    
    char *destino = malloc(largo_absoluto * sizeof (char));
    size_t a = 0;
    for(size_t otrav = 0; otrav< veces ; otrav++) {   
        for (size_t i = 0 ; i <largo_or ; i++){
        
            destino [a] = origen [i];
            a++;    
        }
    }
    
    destino [a] = '\0';
    return destino;
}
