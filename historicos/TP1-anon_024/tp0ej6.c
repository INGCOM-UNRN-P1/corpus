/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024 de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[]){

int cont, numeroentero, resultado=1;

printf("ingrese su numero entero ");

scanf("%d" ,&numeroentero);

cont=numeroentero;

while (cont>=1){

resultado=resultado*cont;
cont--;
}
printf("El factorial de %d es: " ,numeroentero);
printf(" %d "  ,resultado);


return 0;
}