/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 3 - Operadores Aritméticos 
*************************/
#include <stdio.h>
 
 int operaciones(int A, int B);
 
 int main(int argc, char *argv[])
{
	int a;
	int b;
	printf("Ingrese entero A \n");
	scanf("%d",&a);
	printf("Ingrese entero B \n");
	scanf("%d",&b);
	printf("Primer numero: A = %d \n", a);
	printf("Segundo numero: B = %d \n", b);
	int resultado = operaciones(a,b);
	return 0;
}

int operaciones(int A, int B)
{
	int producto = 0;
	int division = 0;
	int resto = 0;
	if (A==0)
    {
		producto = 0;
		resto = 0;	
		printf("Operador multiplicacion: A*B = %d \n", producto);
		printf("Operador resto: A%B = %d \n", resto);
    	if (B==0)
	    division = 0;
		printf("Operador division: A/B = 0 \n");
	}
	else
	{
		if (B==0)
		{
			producto = 0;
			resto = 0;	
			printf("Operador multiplicacion: A*B = %d \n", producto);
			printf("Operador resto: A%B = %d \n", resto);
			printf("Division invalida, B=0 \n");
		}
		else
		{
			producto = A*B;
			resto = A%B;
			division = A/B;
			printf("Operador multiplicacion: A*B = %d \n", producto);
			printf("Operador resto: A%B = %d \n", resto);
			printf("Operador division: A/B = %d \n", division);			
		}		
	}
    return 0;
}


