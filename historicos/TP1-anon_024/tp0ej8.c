/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024 de GitHub
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[]){

int cont, numero1, numero2;
unsigned long long int resultado;
resultado=1;
cont=0;
numero2=1;
while (numero1<100){

printf("ingrese su numero entero mayor a 100 ");

scanf("%d" ,&numero1);
}
while (cont<=numero1){
	
	printf("\n Los numeros de la sucesion de fibonacci menor a %d son %d\n" ,numero1 ,cont);
	
	cont=numero2;
	
	numero2=resultado;
	
	resultado=numero2+cont;
	

}

return 0;
}