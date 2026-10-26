/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
void dibujar_linea(int cantidad_caracteres)
{
    int i;
    for(i=0;i<cantidad_caracteres;i++){
		printf("*");
	}
}
int main(int argc, char *argv[])
{	
	int naturala;

	printf("Ingrese un numero natural: ");
	scanf("%d",&naturala);
	
	if(naturala>0)
	{
		dibujar_linea(naturala);
	}else{
		printf("El numero ingresado %d no es un numero natural",naturala);
	}	
	return 0;	
}
