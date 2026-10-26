
 
 #include <stdio.h>
 
 int main()
 {	
	int a = 0, b = 1;
	int ingreso_entero;
	int sucesion_fib = 0; 
	int i; 
	
	printf("Ingrese un numero entero mayor a 10: ");
	scanf("%d", &ingreso_entero);
	
	if(ingreso_entero > 10)
	{	
		printf("Los numeros de la sucesion de fibonacci menor a %d son:", ingreso_entero);
		
		for(i = 1; i < ingreso_entero; i++)
		{
			printf(" %d", sucesion_fib);
			a = b;
			b = sucesion_fib;
			sucesion_fib = a + b;
			i = sucesion_fib;
		}
	}
	else 
	{
		printf("Usted no ha cumplido con los requisitos solicitados!");
	}
	
	return 0;
 }