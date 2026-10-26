
 
 #include <stdio.h>
 
 int main() 
 {
	int ingreso_entero;
	int i;
	
	printf("Ingrese un numero entero mayor a 100: A = ");
	scanf("%d", &ingreso_entero);
	
	if (ingreso_entero >= 100)
	{
		for (i = 2; i < 7; i++)
		{
			if (ingreso_entero % i != 0)
			{
				printf("Es multiplo de %d: NO \n", i);
			}
			else
			{
				printf("Es multiplo de %d: SI \n", i);
			}
		}	
	}
	else
	{
		printf("\n No ingresaste un numero mayor a 100!");
	}
	return 0;
 }