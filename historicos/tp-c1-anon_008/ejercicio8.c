/*
8. Palíndromo
Juan Bautista Mangold Moro - 2022
Programacion 1 - Ingenieria en computacion
*/

#include<stdio.h>

int main(int argc, char *argv[])
{ char cadena[30];
	int posicion1,posicion2,aux,aux2;
 
	printf("Ingresar Palabra :\n");
 
	gets(cadena);
 
	posicion1 = strlen(cadena);
 
	for ( posicion2 = 0; posicion2 < posicion1; posicion2++)
 	{ 
 	}
 	aux = 0;
 	aux2 = posicion1-1;
 	for(posicion2 = 0; posicion2 < posicion1 / 2; posicion2++)
	{ 	
		if (cadena[posicion2]==' ' && cadena[aux2]!=' ' ) 
    {  
		posicion2++; 
		if (cadena[posicion1]!=cadena[aux2]) 
		aux++;
	}        
  		if(cadena[aux2]==' ' && cadena[posicion2]!=' ')  
    {  
		aux2--; 
		if (cadena[posicion2]!=cadena[aux2]) 
		aux++; 
	}  
  		if (cadena[posicion2]!=cadena[aux2]) 
	{ 
	aux++;
	}
    aux2--; 
}
	if(aux==0)  printf("True");
	else  printf("False");

	return 0;
}
