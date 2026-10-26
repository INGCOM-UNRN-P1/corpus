/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>

int main()
{
	int dia;
	printf("ingrese un numero entre 1 y 7: ");
	scanf("%d",&dia);	
	switch(dia)
	{
		case 1:
		printf("\nEl numero  pertenece al Lunes");
		break;	
		case 2: 
		printf("\nEl numero  pertenece al Martes");	
		break;	
		case 3: 
		printf("\nEl numero  pertenece al Miercoles");
		break;	
		case 4:
		printf("\nEl numero  pertenece al Jueves");
		break;	
		case 5: 
		printf("\nEl numero  pertenece al Viernes");	
		break;	
		case 6: 
		printf("\nEl numero  pertenece al Sabado");
		break;	
		case 7: 
		printf("\nEl numero  pertenece al Domindo");	
		break;	
		default:
		printf("\nNo es un numero entre 1 y 7");
	}
	
}