/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>

int main()

{
	int numero1;
	int numero2;
	int contador;
	printf("ingrese el primer numero: ");
	scanf("%d",&numero1);
	printf("ingrese el segundo numero:");
	scanf("%d",&numero2);
	
	if (numero1>numero2)	
	{ 
     contador=numero2;
	 
		while (contador <= numero1)
		{ 
     
		printf("%d \n",contador);
		contador=contador+1;
		}
	}	   
	else if (numero1<numero2)
	{
	   contador=numero1;
		while (contador<=numero2)
	    { 
         
         printf("%d\n", contador);		 
		 contador= contador+1;
	    }   
	}
	else
	printf("no hay distancia entre 2 valores iguales");

}


 