#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void largo(char cadena[], int capacidad){
	int i;
	for(i=0;i<capacidad;i++){
		printf("%c", cadena[i]);
		printf("\t");
	}
	i = i+1;
	printf("La capacidad es %d\n", i);
}

void insercion(char cadena[],char cadenaDos[], char cadenaNueva[], int eleccion, int capacidadTotal){
	int i;
	int j=0;
	int len = strlen(cadenaDos);
	int pos;
	printf("\n%d len de cadena\n", len);
	for(i=0;i<capacidadTotal;i++){
		if(i<eleccion){
			cadenaNueva[i]=cadena[i];
			pos=i;
		}
		else if(i>=eleccion && j<len){
			cadenaNueva[i]=cadenaDos[j];
			j++;
		}
		else{
			cadenaNueva[i]=cadena[pos];
			pos=pos+1;
		}
		
	}
	printf("\n Cadena nueva: %s", cadenaNueva);
}


int main(int argc, char *argv[])
{
	printf("%d\n",argc);
	char *cadenaDos;
	char *cadena;
	cadena = argv[1];
	int capacidad=1;
	while(cadena[capacidad] != '\0'){
		capacidad= capacidad + 1;
	}
	cadena= (char *) malloc(sizeof(char) * capacidad);
	largo(cadena, capacidad);
	free(cadena);
	/******************************************************/
	int eleccion;
	cadena = argv[1];
	cadenaDos= argv[2];
	capacidad=1;
	while(cadena[capacidad] != '\0'){
		capacidad= capacidad + 1;
	}
	int capacidadDos=1;
	while(cadena[capacidadDos] != '\0'){
		capacidadDos= capacidadDos + 1;
	}
	int capacidadTotal;
	capacidadTotal = capacidad + capacidadDos;
	char *cadenaNueva;
	cadenaNueva= (char *) malloc(sizeof(char) * capacidadTotal);
	
	printf("Eliga posicion:");
	scanf("%d", &eleccion);
	
	insercion(cadena, cadenaDos, cadenaNueva, eleccion, capacidadTotal);
	free(cadenaNueva);
	
	
	
return 0;
}
