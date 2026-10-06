#ifndef CONSOLA_H
#define CONSOLA_H

#include <stdbool.h>


void limpiar_buffer_entrada(void);


int leer_entero(const char *mensaje);





int leer_entero_entre(const char *mensaje, int min, int max);


float leer_flotante(const char *mensaje);


float leer_flotante_entre(const char *mensaje, float min, float max);


char leer_caracter(const char *mensaje);


bool leer_logico(const char *mensaje);


bool esta_en_rango_entero(int valor, int min, int max);


bool esta_en_rango_flotante(float valor, float min, float max);

#endif 
