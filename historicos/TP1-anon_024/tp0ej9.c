/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024 de GitHub
*************************/
#include <stdio.h>
 
 
int main(int argc, char *argv[]){

int numero1;
numero1=0;

printf("Ingrese su numero entero mayor a 100 ");
scanf("%d" ,&numero1);

while (numero1<=100){
printf("\n El numero %d es menor a 100 ingrese un numero mayor a 100 : \n" ,numero1);
scanf("%d" ,&numero1);

}

printf("\n El numero %d es mayor a 100 \n" ,numero1);

	
return 0;

}