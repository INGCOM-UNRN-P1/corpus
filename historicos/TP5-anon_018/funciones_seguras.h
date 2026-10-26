#ifndef FUNCIONES_SEGURAS_H
#define FUNCIONES_SEGURAS_H

#define SIN_INTENTOS -1

#define CADENACORTA -1

#define LONGCADENA 200


int lee_numero_natural(char mensaje[], unsigned short intentos);


int largo_cadena(char *cadena, int capacidad_cadena);


int insercion(char *destino, int capacidad_destino, char* insertar, int posicion);


int copiadora(char *origen, char *destino, int capacidad_destino);


int limpiadora(char *origen, char *destino, int capacidad_destino);


int inversor(char* origen, char* destino, int capacidad_destino);


int compara(char *primera, char *segunda);


int es_palindromo(char *cadena, int largo);


int alfanumerico(char caracter);


char* busqueda(char *cadena, int largo, char *busqueda);

#endif