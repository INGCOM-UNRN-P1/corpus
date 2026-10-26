/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int divide_lento(int dividendo, int divisor)
{	
	int restar;
	int resta;
	int cantidad;
	restar=1;
	cantidad=0;
	if(dividendo<0 || divisor <0){
		return 0;
	}
	while(restar)
	{
		if(dividendo>=0){
			resta= dividendo-divisor;
			if(resta>=0)
			{
				cantidad= cantidad+1;
				dividendo= resta;
			}else{
				restar=0;
			}		
		}else
		{
			restar=0;
		}	
	}
	return cantidad;
}
int resto_lento(int dividendo, int divisor)
{
	int restar;
	int resta;
	int cantidad;
	int resto;
	restar=1;
	cantidad=0;
	resto=0;
	if(dividendo<0 || divisor <0 || divisor>dividendo){
		return 0;
	}
	while(restar)
	{	resta= dividendo-divisor;
		if(dividendo>=0 && resta<dividendo ){
			if(resta<dividendo)
			{
				resto=dividendo;
			}else if(resta>dividendo){
				resto=0;
			}
			if(resta>=0)
			{
				cantidad= cantidad+1;
				dividendo= resta;
			}else{
							
				restar=0;
			}	
		}else
		{
			restar=0;
		}
	}
	return resto;
}
int main(int argc, char *argv[])
{	
	int dividendo;
	int divisor;
	int division;
	int restolento;
	printf("Ingresa un numero dividendo: ");
	scanf("%d", &dividendo);
	printf("\nIngresa un numero divisor: ");
	scanf("%d", &divisor);
	division=divide_lento(dividendo,divisor);
	restolento=resto_lento(dividendo,divisor);
	printf("\nLa division lenta entre %d y %d es %d\n",dividendo,divisor,division);
	printf("\nEl resto entre %d y %d es %d",dividendo,divisor,restolento);
	return 0;
}
