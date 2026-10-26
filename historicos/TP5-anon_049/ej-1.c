/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * florenciadevalucero
 *************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
	
	// variables
	int i, maxInt, minInt, maxChar, minChar, maxDouble, minDouble;
	int variableInt;
	double variableDouble;
	char variableChar;
	
	// punteros
	int *pInt;
	double *pDouble;
	char *pChar;
	
	pInt = &variableInt;
	pDouble = &variableDouble;
	pChar = &variableChar;
	
	maxInt = 100;
	minInt = -100;
	maxDouble = 1000;
	minDouble = -1000;
	maxChar = 122;
	minChar = 97;
	// numeros y caracteres random
	srand(time(NULL));
	variableInt = rand() % (maxInt - minInt + 1) + minInt;
	variableDouble = rand() % (maxDouble - minDouble + 1) + minDouble;
	variableChar = rand() % (maxChar - minChar + 1) + minChar;
	
	//muestra las direcciones de memoria de las variables
	printf("La direccion de la variable int: 0x% x", &variableInt);
	printf("\t\nLa direccion de la variable double: 0x% x", &variableDouble);
	printf("\t\nLa direccion de la variable char: 0x% x", &variableChar);
	//muestra las direcciones de memoria de los punteros
	printf("\t\nLa direccion del int*: 0x% x", *pInt);
	printf("\t\nLa direccion del double*: 0x% x", *pDouble);
	printf("\t\nLa direccion del char*: 0x% x\n", *pChar);
	//muestra en pantalla las variables inicializadas
	printf("\t\nEl valor de int: %d", variableInt);
	printf("\t\nEl valor de doble: %.1f", variableDouble);
	printf("\t\nEl valor de char: %c", variableChar);
	//muestra el valor que apunta el puntero
	printf("\t\nEl valor de int*: 0x% x", pInt);
	printf("\t\nEl valor de doble*: 0x% x", pDouble);
	printf("\t\nEl valor de char*: 0x% x\n", pChar);
	//muestra en pantalla el tamaño de las variables
	printf("\t\nEl tamanio de la variable int: %d", sizeof(variableInt));
	printf("\t\nEl tamanio de la variable doble: %d", sizeof(variableDouble));
	printf("\t\nEl tamanio de la variable char: %d", sizeof(variableChar));
	//muestra el tamanio del puntero
	printf("\t\nEl tamanio del int*: %d", sizeof(pInt));
	printf("\t\nEl tamanio del doble*: %d", sizeof(pDouble));
	printf("\t\nEl tamanio del char*: %d", sizeof(pChar));
	
	return 0;

}
