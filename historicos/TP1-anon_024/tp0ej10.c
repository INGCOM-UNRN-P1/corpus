/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024 de GitHub
*************************/
#include <stdio.h>
 
 
int main(int argc, char *argv[]){

int semana;
printf("intrduca un numero entre 1 y 7 ");

scanf("%d" ,&semana);
while (semana<1 || semana>7)
{
	printf("Numero no valido, dije entre 1 y 7 ");
scanf("%d" ,&semana);
}
switch (semana)
{
	 case 1:
	 printf("lunes");
	 break;
	 case 2:
	 printf("martes");
	 break;
	 case 3:
	 printf("Miercoles");
	 break;
	 case 4:
	 printf("Jueves");
	 break;
	 case 5:
	 printf("Viernes");
	 break;
	 case 6:
	 printf("Sabado");
	 break;
	 case 7:
	 printf("Domingo");
	 break;

}

	
return 0;

}