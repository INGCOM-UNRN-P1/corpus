/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_049
*************************/
#include <stdio.h>
 
int main(){
	int numero, dias_de_semana;
	
	printf("Ingrese un numero del 1 al 7: ");
	scanf("%d", &numero);
	
	switch(numero){
		case 1:
			printf("1- Lunes");
			break;
		
		case 2:
			printf("2- Martes");
			break;
		
		case 3:
			printf("3- Miercoles");
			break;
		
		case 4:
			printf("4- Jueves");
			break;
		
		case 5:
			printf("5- VIERNES!!");
			break;
		
		case 6:
			printf("6- Sabado");
			break;
		
		case 7:
			printf("7- Domingo");
			break;
		
		default:
			printf("Numero ingresado fuera de rango!!!");
			break;
	}
	
	
	 
	return 0;

}
