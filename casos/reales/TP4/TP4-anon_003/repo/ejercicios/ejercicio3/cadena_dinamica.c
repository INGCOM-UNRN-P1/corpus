/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 * 
 * @brief *clonar_cadena
 *        duplica una cadena y aloja la mem en heap/
 *        Calcula la longitud de origen, reserva, y copia.
 *        en puntero destino.
 * 
 * @param origen no debe ser null.
 * 
 * @return Puntero destino a la cad copiada.
 *         NULL si origen es nukll,o falla malloc.
 * 
 * -----------------------------------------------------------
 * @brief concatena dos cadenas en una mem dinamica en heap./
 *        
 * @param primera puntero a primer cadeina
 * @param segunda puntero a segunda cadena
 * @return char destino puntero a cadena concatenada.
 *         Si algun puntero es null retorna NULL
 *         Si falla malloc retorna null.
 * 
 * 
 * 
 * 
 * 
 */

#include "cadena_dinamica.h"

char *clonar_cadena (const char *origen){
if (origen == NULL){
    return NULL;
}

size_t longitud = 0;

for (int i = 0; origen [i]!= '\0' ; i++){
    longitud++;
}
char *destino = malloc((longitud+1)*sizeof(char));
if (destino== NULL){
    return NULL;

}

for (int a = 0 ; a < longitud ; a++){
    destino [a] = origen[a];


}
destino [longitud] = '\0';
return destino;
}



char *unir_cadenas_dinamicas(const char *primera, const char *segunda){
    if (primera == NULL || segunda == NULL){
        return NULL;
    }
size_t longitud_primera = 0;

for (int i = 0; primera [i]!= '\0' ; i++){
    longitud_primera++;
}

size_t longitud_segunda = 0;

for (int i = 0; segunda [i]!= '\0' ; i++){
    longitud_segunda++;
}

size_t longitud_tot = longitud_primera + longitud_segunda+1;

char *destino = malloc(longitud_tot*sizeof(char));

if (destino == NULL){
    return NULL;

}

for(size_t i = 0 ; i < longitud_primera && primera [i]!= '\0' ; i++ ){
    destino [i] = primera [i];

}
size_t a = 0;
for(size_t i = longitud_primera ; segunda[a]!= '\0' ;i ++ ){
    destino [i] = segunda[a];
    a++;
}

destino [longitud_primera + longitud_segunda] = '\0';
return destino;
}